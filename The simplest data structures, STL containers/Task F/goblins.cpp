#include <iostream>
#include <deque>
#include <string>

int main() {
    long N;
    std::deque<std::string> firsthalf;
    std::deque<std::string> secndhalf;
    std::cin >> N;
    std::string message;
    for(int i=0; i<N; ++i) {
        std::cin >> message;
        if (message == "+") {
            std::cin >> message;
            secndhalf.push_back(message);
        } else if (message == "*") {
            std::cin >> message;
            secndhalf.push_front(message);
        } else if (message == "-") {
            std::cout << firsthalf.front() << std::endl;
            firsthalf.pop_front();
        }
        if (secndhalf.size() != firsthalf.size()) {
            firsthalf.push_back(secndhalf.front());
            secndhalf.pop_front();
        }
    }
}
