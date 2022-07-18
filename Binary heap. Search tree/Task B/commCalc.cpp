#include <iostream>
#include <algorithm>
#include <queue>

int main() {
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    std::string operation;
    int N, x, first, second;
    double sum = 0.0;
    std::cin >> N;
    for(int i = 0; i < N; ++i){
        std::cin >> x;
        q.push(x);
    }
    while(q.size() != 1){
        first = q.top();
        q.pop();
        second = q.top();
        q.pop();
        sum += (first + second) * 0.05;
        q.push(first + second);
    }
    printf("%.2f", sum);
}
