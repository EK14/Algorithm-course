#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

int main() {
    std::stack <std::pair<long long, long long>> in;
    std::stack <std::pair<long long, long long>> out;
    std::string message;
    std::pair<long long, long long> pr;
    long long M;
    long long x;
    std::cin >> M;
    for(int i = 0; i < M; ++i){
        std::cin >> message;
        if(message == "enqueue"){
            std::cin >> message;
            x = stoi(message);
            pr.first = x;
            pr.second = in.empty() ? x: std::min(x, in.top().second);
            in.push(pr);
            std::cout << "ok"<<std::endl;
        }
        else if(message == "size"){
            std::cout << in.size()+out.size()<<std::endl;
        }
        else if(message == "clear"){
            while(!in.empty()){
                in.pop();
            }
            while(!out.empty()){
                out.pop();
            }
            std::cout << "ok"<<std::endl;
        }
        else if(!in.empty() || !out.empty()){
            if (message == "dequeue") {
                if (out.empty()) {
                    while(!in.empty()){
                        in.top().second = out.empty() ? in.top().first: std::min(in.top().first, out.top().second);
                        out.push(in.top());
                        in.pop();
                    }
                }
                std::cout << out.top().first<<std::endl;
                out.pop();
            }
            else if(message == "front"){
                if (out.empty()) {
                    while(!in.empty()){
                        in.top().second = out.empty() ? in.top().first: std::min(in.top().first, out.top().second);
                        out.push(in.top());
                        in.pop();
                    }
                }
                std::cout << out.top().first<<std::endl;
            }
            else if(message == "min"){
                std::cout <<( in.empty() ? out.top().second: out.empty() ? in.top().second: (std::min(in.top().second, out.top().second)))<<std::endl;
            }
            else
                std::cout << "error" <<std::endl;
        }
        else
            std::cout << "error" <<std::endl;
    }
    return 0;
}
