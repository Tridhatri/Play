#include <stdio.h>
// Let's implement a simple LRU (Least Recently Used) cache using a doubly linked list and a hash map for O(1) access.
#include <stdlib.h>

// LRU Cache description : 
// The LRU cache will have the following properties:
// 
//
// 1. We will use a doubly linked list to keep track of the order of usage. The most recently used item will be at the head, and the least recently used item will be at the tail.
// 2. We will use a hash map (implemented as an array of pointers) to store the key-value pairs for O(1) access.
// 3. When we access an item, we will move it to the head of the list. When we add a new item, if the cache is full, we will remove the tail item (the least recently used one).
// 4. The cache will have a fixed capacity, and we will implement functions to get and put items in the cache.


// First, let's define the structure for the doubly linked list node for each element in the cache.
typedef struct Node {
    int key; // The key represents the unique identifier for the cache item. It allows us to quickly access the value associated with that key in the hash map.
    int value; // The value represents the actual data stored in the cache. It is the information that we want to retrieve when we access the cache using the key.
    struct Node* prev; // Pointer to the previous node in the doubly linked list. This allows us to easily move nodes around when we access or add items to the cache.
    struct Node* next; // Pointer to the next node in the doubly linked list. 
                       // This also helps us maintain the order of usage in the cache, allowing us to quickly identify the least recently used item when we need to evict an item from the cache. 
} Node;

// Second, let's define the structure for the LRU Cache itself.
#define HASH_SIZE 10007 // Prime number for better hash distribution

typedef struct LRUCache {
    int capacity; // So, the LRU cache will have a fixed capacity and we will update the cache when we add new items or access existing items.
    int size; // Keeping track of the number of items currently in the cache.
    Node* head; // Pointer to the head of the doubly linked list (most recently used item).
    Node* tail; // Pointer to the tail of the doubly linked list (least recently used item).
    Node** hashMap; // Hash map to store key-node pairs for O(1) access. This is a Pointer to an array of pointers to nodes. 
                    // Why do we do this? Because we want to quickly access the nodes in the linked list based on their keys, and using a hash map allows us to do that efficiently.
                    // We implement a hashmap as an array of pointers to nodes, where the index in the array corresponds to the key. 
                    // This in terms of the Node is the key field in the Node structure. 
                    // The value stored at that index in the hash map will be a pointer to the corresponding node in the doubly linked list.
                    // This allows us to quickly access the node associated with a given key in O(1) time.
} LRUCache;

// Hash function to map arbitrary keys to hash table indices
int hash(int key) {
    return abs(key) % HASH_SIZE;
}

// Basically LRUCache is like a bookkeeper? 
// It keeps track of the capacity, the current size, the head and tail of the doubly linked list, and the hash map for O(1) access to the nodes in the list.



// Third, let's implement the functions to create a new node, add a node to the head of the list, remove a node from the list, and move a node to the head of the list.

// Create a new node.
Node* createNode(int key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->prev = NULL; // This is only the initial state of the node when it is created. When we add the node to the head of the list, we will update these pointers accordingly.
    newNode->next = NULL; // This is only the initial state of the node when it is created. When we add the node to the head of the list, we will update these pointers accordingly.
    return newNode;
};


// Add a node to the head of the list. (This is used when we access an item in the cache or add a new item to the cache, as both of these actions make the item the most recently used one.)
// So what if it is a node already in the list? We will handle that case separately when we implement the get and put functions for the cache. 
// For now, we will just implement the function to add a new node to the head of the list, assuming that the node is not already in the list.
// So, this function is just assuming that we are adding a new node to the head of the list, and we will update the pointers accordingly to maintain the structure of the list and the hash map.
// If it is an existing node, we will handle that case separately when we implement the get and put functions for the cache, as we will need to move the existing node to the head of the list instead of creating a new node and adding it to the head of the list.
// Basically, we need to update that existing node's next and prev pointers by basically prev_node = node->prev; prev_node->next = node->next; 
// next_node = node->next; next_node->prev = node->prev; 
// and then we can add the existing node to the head of the list by basically calling this function again with the existing node as the argument.
void addToHead(LRUCache* cache, Node* node) {
    node->next = cache->head; // The new node's next pointer will point to the current head of the list.
                              // This is because we are adding the new node to the head of the list, so it will become the new head and the current head will become the second node in the list.
    
    node->prev = NULL; // The new node's previous pointer will be NULL because it will be the new head of the list, and there will be no nodes before it.
    if (cache->head != NULL) { // If the current head is not NULL, we need to update its previous pointer to point to the new node.
        cache->head->prev = node; // The current head's previous pointer will now point to the new node, because the new node is being added to the head of the list.
    }                   

    cache->head = node; // Finally, we update the cache's head pointer to point to the new node, making it the new head of the list.
    if (cache->tail == NULL) { // If the tail is NULL, it means this is the first node being added to the list, so we also need to update the tail pointer to point to the new node.
        cache->tail = node; // The tail pointer will now point to the new node, because it is the only node in the list and therefore both the head and tail.
    }
    // After adding the node to the head of the list, we also need to update the hash map to point to this new node for O(1) access.
    cache->hashMap[hash(node->key)] = node; // We update the hash map to point to the new node using its key. 
                                      // This allows us to quickly access this node in O(1) time when we need to retrieve or update its value.
                                      //
                                      //
                                      //
     
    // Do we need to update the size of the cache here? No, we will update the size of the cache when we add a new item to the cache, not when we add a node to the head of the list.


    // That's it for adding a node to the head of the list. We have updated the pointers in the linked list and the hash map accordingly to maintain the structure of the LRU cache.
    //
    //
}

// Remove a node from the list (without freeing it).
// We would obviously need to remove a node from the list when we need to evict the least recently used item from the cache,
// or when we need to move a node to the head of the list after accessing it.

void removeNode(LRUCache* cache, Node* node) {
    // Check if the node has a previous node before dereferencing
    if (node->prev != NULL) {
        node->prev->next = node->next; // We update the previous node's next pointer to skip over the node being removed and point to the next node.
    } else {
        // If there's no previous node, this node is the head
        cache->head = node->next; // Update head to the next node
    }
    
    // Check if the node has a next node before dereferencing  
    if (node->next != NULL) {
        node->next->prev = node->prev; // We update the next node's previous pointer to skip over the node being removed and point to the previous node.
    } else {
        // If there's no next node, this node is the tail
        cache->tail = node->prev; // Update tail to the previous node
    }
    
    // After removing the node from the list, we also need to update the hash map to remove the reference to this node for O(1) access.
    cache->hashMap[hash(node->key)] = NULL; // We update the hash map to remove the reference to this node using its key.
    
    // Note: We do NOT free the node here or decrement size, as this function is used both for moving nodes (in moveToHead)
    // and for eviction. The caller is responsible for freeing the node if needed.
}

// Evict the tail node (least recently used) from the cache
void evictTail(LRUCache* cache) {
    if (cache->tail == NULL) {
        return; // Nothing to evict
    }
    
    Node* tailNode = cache->tail;
    removeNode(cache, tailNode); // Remove from list and hash map
    free(tailNode); // Free the memory
    cache->size--; // Decrement the size
}

// Next, we will implement the function to move a node to the head of the list after accessing it, which is a common operation in an LRU cache to update the order of usage of the items in the cache.
void moveToHead(LRUCache* cache, Node* node) {
    // If the node is already at the head, no need to move it
    if (cache->head == node) {
        return;
    }
    
    // First, we need to remove the node from its current position in the list, since we will be moving it to the head of the list.
    removeNode(cache, node); // We call the removeNode function to remove the node from its current position in the list (but not free it)

    // Next, we need to add the node to the head of the list, since it is now the most recently used item in the cache.
    addToHead(cache, node); // We call the addToHead function to add the node to the head of the list, which will also update the hash map accordingly.

    // That's it for moving a node to the head of the list. We have updated the pointers in the linked list and the hash map accordingly to maintain the structure of the LRU cache.
}

// Next, we will implement the functions to get and put items in the cache, which are the main operations that we will be performing on the cache.
// The get function will retrieve the value associated with a given key in the cache, 
int get_value(LRUCache* cache, int key) {
    Node* node = cache->hashMap[hash(key)]; // We access the hash map to get the node associated with the given key in the cache.
    
    // Verify the node exists and has the correct key (handle hash collisions)
    if (node == NULL || node->key != key) { // If the node is NULL or key doesn't match, it means that the key is not present in the cache
        return -1; // We return -1 to indicate that the key is not found in the cache.
    } else { // If the node is not NULL, it means that the key is present in the cache, so we need to move this node to the head of the list to update its usage order and then return its value.
        moveToHead(cache, node); // We call the moveToHead function to move this node to the head of the list
        return node->value; // Finally, we return the value associated with this key in the cache, which is stored in the value field of the node.
    }
}


// Next, we will implement the put function to add a new key-value pair to the cache or update the value of an existing key in the cache.
void put_value(LRUCache* cache, int key, int value) {
    Node* node = cache->hashMap[hash(key)]; // We access the hash map to get the node associated with the given key in the cache.
    
    // Check if node exists and has the correct key (handle hash collisions)
    if (node == NULL || node->key != key) { // If the node is NULL or key doesn't match, it means that the key is not present in the cache, so we need to add a new key-value pair to the cache.
        Node* newNode = createNode(key, value); // We create a new node with the given key and value using the createNode function.
        addToHead(cache, newNode); // We call the addToHead function to add this new node to the head of the list, which will also update the hash map accordingly.
        cache->size++; // We increment the size of the cache by 1, since we have added a new item to the cache.
        if (cache->size > cache->capacity) { // If the size of the cache exceeds its capacity, we need to evict the least recently used item from the cache.
            evictTail(cache); // We call the evictTail function to remove and free the tail node, which is the least recently used item in the cache
        }
    } else { // If the node is not NULL and key matches, it means that the key is already present in the cache, so we need to update its value and move it to the head of the list to update its usage order.
        node->value = value; // We update the value associated with this key in the cache by setting it to the new value provided as an argument to this function.
        moveToHead(cache, node); // We call the moveToHead function to move this node to the head of the list, which will also update the hash map accordingly.
    }
    // This function does not need to return any value, as it is simply updating the cache with the new key-value pair or updating the value of an existing key in the cache.
    return ; // We can simply return here, as there is no need to return any value from this function.

}

// Next, we will implement a function to create a new LRU cache with a given capacity, which will initialize the cache's properties and allocate memory for the hash map.
LRUCache* createCache(int capacity) {
    LRUCache* cache = (LRUCache*)malloc(sizeof(LRUCache)); // We allocate memory for the LRUCache structure using malloc.
    cache->capacity = capacity; // We set the capacity of the cache to the given capacity provided as an argument to this function.
    cache->size = 0; // We initialize the size of the cache to 0, since there are no items in the cache when it is first created.
    cache->head = NULL; // We initialize the head pointer of the list to NULL, since there are no nodes in the list when the cache is first created.
    cache->tail = NULL; // We initialize the tail pointer of the list to NULL, since there are no nodes in the list when the cache is first created.
    cache->hashMap = (Node**)malloc(sizeof(Node*) * HASH_SIZE); // We allocate memory for the hash map, which is an array of pointers to nodes, with a size of HASH_SIZE. 
                                                                // This allows us to store key-node pairs for O(1) access based on the keys in the cache.
    for (int i = 0; i < HASH_SIZE; i++) { // We initialize all entries in the hash map to NULL, since there are no items in the cache when it is first created.
        cache->hashMap[i] = NULL; // We set each entry in the hash map to NULL, indicating that there are no key-node pairs stored in the hash map when the cache is first created.
    }
    // So, basically at the start of the cache, each node's key will be the index in the hash map, 
    // and the value will be the pointer to the corresponding node in the linked list.

    return cache; // Finally, we return a pointer to the newly created LRUCache structure, which is now initialized and ready to be used for storing key-value pairs in the cache.
}


// Next, we will implement a function to free the memory allocated for the LRU cache and its components when we are done using it, to prevent memory leaks in our program.
void free_cache(LRUCache* cache) {
    // First, we need to free the memory allocated for the nodes in the linked list, since we have dynamically allocated memory for each node in the list.
    Node* current = cache->head; // We start from the head of the list to traverse through all the nodes in the list.
    while (current != NULL) { // We continue traversing until we reach the end of the list, which is indicated by a NULL pointer.
        Node* temp = current; // We store a temporary pointer to the current node, so that we can free its memory after we move to the next node in the list.
        current = current->next; // We move to the next node in the list by updating the current pointer to point to the next node.
        free(temp); // We free the memory allocated for the current node using the temporary pointer, since we have already moved to the next node in the list and we no longer need this node.
    }
    // After freeing all the nodes in the linked list, we also need to free the memory allocated for the hash map, since we have dynamically allocated memory for it as well.
    free(cache->hashMap); // We free the memory allocated for the hash map using free, since we no longer need it after we have freed all the nodes in the linked list.

    // Finally, we need to free the memory allocated for the LRUCache structure itself, since we have dynamically allocated memory for it as well.
    free(cache); // We free the memory allocated for the LRUCache structure using free, since we no longer need it after we have freed all its components.

    // That's it for freeing the memory allocated for the LRU cache and its components. We have successfully prevented memory leaks in our program by freeing all dynamically allocated memory when we are done using it.
    // Return value of this function is void, since we are simply freeing memory and there is no need to return any value from this function.
}


// Next, we will implement a main function to demonstrate how to use the LRU cache that we have implemented, 
// by creating a cache, 
// adding some key-value pairs to it, 
// retrieving values from it, 
// and then freeing the memory allocated for the cache when we are done using it.

int main() {

    // Create a new LRU cache with a capacity of 2.
    LRUCache* cache = createCache(2); 
    // We call the createCache function to create a new LRU cache with a capacity of 2, which will initialize the cache's properties and allocate memory for the hash map.

    // Add some key-value pairs to the cache using the put_value function.
    put_value(cache, 1, 1); // We add a key-value pair (1, 1) to the cache using the put_value function.
    put_value(cache, 2, 2); // We add another key-value pair (2, 2) to the cache using the put_value function.
    // What if I put_value(cache, 6, 6) here? This will cause the least recently used item (key 1) to be evicted from the cache since the capacity is exceeded. 
    // So, the 'key' = 6 , does not matter since it is just a new key-value pair being added to the cache, and 
    // it will cause the least recently used item (key 1) to be evicted from the cache since the capacity is exceeded.

    // Retrieve values from the cache using the get_value function.
    printf("%d\n", get_value(cache, 1)); // We retrieve the value associated with key 1 from the cache using the get_value function and print it. This should return 1.

    // Add another key-value pair to the cache, which will cause the least recently used item (key 2) to be evicted from the cache since the capacity is exceeded.
    put_value(cache, 3, 3); // We add another key-value pair (3, 3) to the cache using the put_value function. This will cause key 2 to be evicted from the cache since it is the least recently used item.

    // Try to retrieve values from the cache again after eviction.
    printf("%d\n", get_value(cache, 2)); // We try to retrieve the value associated with key 2 from the cache using the get_value function and print it. This should return -1 since key 2 has been evicted from the cache.

    // Free the memory allocated for the cache when we are done using it.
    free_cache(cache); // We call the free_cache function to free all memory allocated for the LRU cache and its components, preventing memory leaks in our program.

    return 0; // Finally, we return 0 from the main function to indicate that our program has executed successfully.

}
