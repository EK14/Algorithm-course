#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    long N, score, inf, math, rus;
    std::string name, surname;
    std::cin >> N;
    std::vector<std::pair<std::string, int>> enrollee(N);
    for(int i = 0; i < N; ++i) {
        std::cin >> name >> surname >> inf >> math >> rus;
        enrollee[i].first = name + " " + surname;
        enrollee[i].second = inf + math + rus;
    }
    std::stable_sort(enrollee.begin(), enrollee.end(), [](const std::pair<std::string, int>& l, const std::pair<std::string, int>& r){
        return l.second > r.second;
    });
    for(int i = 0; i < N; ++i)
        std::cout << enrollee[i].first << std::endl;
}
