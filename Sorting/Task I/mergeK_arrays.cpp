#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

// Complexity - O(S*logN)
int main() {
    long K, N, x;
    std::queue<std::vector<long>> queue;
    std::vector<long> first;
    std::vector<long> second;
    std::vector<long> merged;
    std::cin >> K;
    for(int i = 0; i < K; ++i){
        std::cin >> N;
        for(int j = 0; j < N; ++j){
            std::cin >> x;
            first.push_back(x);
        }
        queue.push(first);
        first.clear();
    }
    while(queue.size() != 1){
        first = queue.front();
        queue.pop();
        second = queue.front();
        queue.pop();
        std::merge(first.begin(), first.end(), second.begin(), second.end(), std::back_inserter(merged));
        queue.push(merged);
        merged.clear();
    }
    for(int i = 0; i < queue.front().size(); ++i)
        std::cout << queue.front()[i] << " ";
} 
