#include <iostream>
#include <queue>

int main() {
    std::queue<char> first;
    std::queue<char> second;
    char x;
    long long count = 0;
    for(int i = 0; i < 5; ++i){
        std::cin >> x;
        first.push(x);
    }
    for(int i = 0; i < 5; ++i){
        std::cin >> x;
        second.push(x);
    }
    while(1){
        if(count == 1000000) {
            std::cout << "botva" << std::endl;
            break;
        }
        if(first.empty()) {
            std::cout << "second " << count << std::endl;
            break;
        }
        if(second.empty()) {
            std::cout << "first " << count << std::endl;
            break;
        }
        if((first.front() == '0' && second.front() == '9') || ((first.front() > second.front()) && !(first.front() == '9' && second.front() == '0'))){
            first.push(first.front());
            first.push(second.front());
        }
        else if((second.front() == '0' && first.front() == '9') || ((second.front() > first.front()) && !(second.front()== '9' && first.front() == '0'))){
            second.push(first.front());
            second.push(second.front());
        }
        count++;
        first.pop();
        second.pop();
    }
    return 0;
}
