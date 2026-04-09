#include <iostream>
#include <vector>
#include <thread>

long factorial(int n) {
    long fact = 1;
    for (int i = 2; i <= n; i++)
        fact *= i;
    return fact;
}

int main() {
    std::vector<int>    arr     = {1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<long>   results(arr.size());
    std::vector<std::thread> threads;

    for (int i = 0; i < arr.size(); i++)
        threads.emplace_back([&, i]() {
            results[i] = factorial(arr[i]);
        });

    for (auto &t : threads)
        t.join();

    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << "! = " << results[i] << "\n";

    return 0;
}
