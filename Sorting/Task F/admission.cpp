#include <iostream>
#include <vector>
#include <algorithm>

long long GCD(long long a, long long b){
    if(b==0)
        return a;
    return GCD(b, a%b);
}

int main() {
    long long N, T;
    std::pair<long, long> S;
    std::cin >> N >> S.first >> T;
    S.second = GCD(T, S.first);
    std::vector<std::pair<long, long>> points(N);
    for(int i = 0; i < N; ++i) {
        std::cin >> points[i].first;
        points[i].second = GCD(T, points[i].first);
    }
    points.push_back(S);
    std::sort(points.begin(), points.end(), [](const std::pair<long, long>& l, const std::pair<long, long>& r){
        if(l.second == r.second)
            return l.first > r.first;
        return l.second > r.second;
    });
    for(int i = 0; i < N; ++i) {
        if(S.first == points[i].first && S.second == points[i].second) {
            std::cout << i + 1;
            break;
        }
    }
}
