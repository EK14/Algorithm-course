#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

double triangleArea(std::pair<long, long> p1, std::pair<long, long> p2, std::pair<long, long> p3){
    double len1 = sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
    double len2 = sqrt(pow(p1.first - p3.first, 2) + pow(p1.second - p3.second, 2));
    double len3 = sqrt(pow(p3.first - p2.first, 2) + pow(p3.second - p2.second, 2));
    double semiPerimeter = (len1 + len2 + len3)/2;
    return sqrt(semiPerimeter*(semiPerimeter - len1)*(semiPerimeter - len2)*(semiPerimeter - len3));
}

int main() {
    std::pair<long, long> p;
    int N;
    std::cin >> p.first >> p.second >> N;
    std::vector<std::pair<std::pair<long, long>, std::pair<long, long>>> segment(N);
    for(int i = 0; i < N; ++i){
        std::cin >> segment[i].first.first >> segment[i].first.second >> segment[i].second.first >> segment[i].second.second;
    }
    std::sort(segment.begin(), segment.end(), [&p](const std::pair<std::pair<long, long>, const std::pair<long, long>> &l, std::pair<std::pair<long, long>, std::pair<long, long>> &r){
        return triangleArea(p, l.first, l.second) < triangleArea(p, r.first, r.second);
    });
    for(int i = 0; i < N; ++i){
        std::cout << segment[i].first.first << " " << segment[i].first.second << " " << segment[i].second.first << " " << segment[i].second.second << std::endl;
    }
}
