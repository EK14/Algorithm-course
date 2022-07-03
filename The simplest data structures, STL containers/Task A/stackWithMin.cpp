#include <iostream>
#include <stack>
#include <stdlib.h>
#include <string>

int main() {
    int M, size;
    long long n;
    std::stack <std::pair<long long, long long>> st;
    std::string message;
    std::cin >> M;
    std::pair<long long, long long> pr;
    for(int i = 0; i < M; ++i) {
        std::cin >> message;
        if (message == "push") {
            std::cin >> message;
            n = atoi(message.c_str());
            if (st.empty() || n < st.top().second) {
                pr.first = n;
                pr.second = n;
                st.push(pr);
            } else {
                pr.first = n;
                pr.second = st.top().second;
                st.push(pr);
            }
            std::cout << "ok\n";
        } else if (message == "clear") {
            size = st.size();
            for (int j = 0; j < size; ++j) {
                st.pop();
            }
            std::cout << "ok\n";
        } else if (message == "size") {
            std::cout << st.size()<<std::endl;
        } else if(!st.empty()) {
            if (message == "pop") {
                std::cout << st.top().first << std::endl;
                st.pop();
            }
            else if (message == "back") {
                std::cout << st.top().first << std::endl;
            }
            else if(message == "min") {
                std::cout << st.top().second << std::endl;
            }
        }
        else{
            std::cout << "error\n";
        }
    }
}
