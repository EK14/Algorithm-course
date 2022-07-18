#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

int main() {
    std::priority_queue<long> q;
    std::string operation;
    long x;
    while(std::cin >> operation){
        if(operation == "CLEAR")
            while(!q.empty())
                q.pop();
        if(operation == "ADD"){
            std::cin >> x;
            q.push(x);
        }
        if(operation == "EXTRACT"){
            if(!q.empty()) {
                std::cout << q.top() << std::endl;
                q.pop();
            }
            else
                std::cout << "CANNOT" << std::endl;
        }
    }
}
