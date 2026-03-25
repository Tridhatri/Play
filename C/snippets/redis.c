#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 6379
#define BUFFER_SIZE 1024
#define MAX_KEYS 100

// Simple key-value store
typedef struct {
    char key[256];
    char value[256];
} KVPair;

KVPair store[MAX_KEYS];
int store_count = 0;

// Function to set a key-value pair
void set_key(const char *key, const char *value) {
    for (int i = 0; i < store_count; i++) {
        if (strcmp(store[i].key, key) == 0) {
            strncpy(store[i].value, value, sizeof(store[i].value) - 1);
            return;
        }
    }
    if (store_count < MAX_KEYS) {
        strncpy(store[store_count].key, key, sizeof(store[store_count].key) - 1);
        strncpy(store[store_count].value, value, sizeof(store[store_count].value) - 1);
        store_count++;
    }
}

// Function to get a value by key
const char* get_key(const char *key) {
    for (int i = 0; i < store_count; i++) {
        if (strcmp(store[i].key, key) == 0) {
            return store[i].value;
        }
    }
    return NULL;
}

// Function to delete a key
void del_key(const char *key) {
    for (int i = 0; i < store_count; i++) {
        if (strcmp(store[i].key, key) == 0) {
            store[i] = store[store_count - 1]; // Replace with last element
            store_count--;
            return;
        }
    }
}

int main() {
    int server_fd, client_fd;
    struct sockaddr_in address;
    char buffer[BUFFER_SIZE];
    int opt = 1;
    socklen_t addrlen = sizeof(address);

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Allow reuse of address
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Bind to port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Mini Redis clone running on port %d...\n", PORT);

    while (1) {
        if ((client_fd = accept(server_fd, (struct sockaddr *)&address, &addrlen)) < 0) {
            perror("Accept failed");
            continue;
        }

        memset(buffer, 0, BUFFER_SIZE);
        read(client_fd, buffer, BUFFER_SIZE - 1);

        char cmd[16], key[256], value[256];
        int args = sscanf(buffer, "%15s %255s %255[^\n]", cmd, key, value);

        if (strcasecmp(cmd, "SET") == 0 && args == 3) {
            set_key(key, value);
            write(client_fd, "+OK\n", 4);
        } else if (strcasecmp(cmd, "GET") == 0 && args >= 2) {
            const char *val = get_key(key);
            if (val) {
                char resp[300];
                snprintf(resp, sizeof(resp), "$%zu\n%s\n", strlen(val), val);
                write(client_fd, resp, strlen(resp));
            } else {
                write(client_fd, "$-1\n", 4);
            }
        } else if (strcasecmp(cmd, "DEL") == 0 && args >= 2) {
            del_key(key);
            write(client_fd, ":1\n", 3);
        } else {
            write(client_fd, "-ERR unknown command\n", 22);
        }

        close(client_fd);
    }

    return 0;
}
