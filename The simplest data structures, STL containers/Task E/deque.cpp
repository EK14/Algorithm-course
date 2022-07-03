#include <iostream>
#include <deque>
#include <string>

int main() {
    std::deque <std::string> dq;
    std::string message;
    while(1){
        std::cin >> message;
        if(message == "exit"){
            std::cout << "bye"<<std::endl;
            break;
        }
        else if(message == "push_front"){
            std::cin >> message;
            dq.push_front(message);
            std::cout << "ok"<<std::endl;
        }
        else if(message == "push_back"){
            std::cin >> message;
            dq.push_back(message);
            std::cout << "ok"<<std::endl;
        }
        else if(message == "size"){
            std::cout << dq.size()<<std::endl;
        }
        else if(message == "clear") {
            while (!dq.empty())
                dq.pop_back();
            std::cout << "ok"<<std::endl;
        }
        else if(!dq.empty()){
            if(message == "pop_front"){
                std::cout << dq.front()<<std::endl;
                dq.pop_front();
            }
            else if(message == "pop_back"){
                std::cout << dq.back()<<std::endl;
                dq.pop_back();
            }
            else if(message == "front")
                std::cout << dq.front()<<std::endl;
            else if(message == "back")
                std::cout << dq.back()<<std::endl;
            else
                std::cout << "error" << std::endl;
        }
        else
            std::cout << "error" << std::endl;
    }
}
