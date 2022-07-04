#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

int main() {
    long long N, sum = 0;
    std::cin >> N;
    std::vector<std::pair<long long, long long>> B(N);
    std::vector<std::pair<std::pair<long long, long long>, long long>> array(N);
    std::vector<long long> A(N);
    for (long long &elem: A)
        std::cin >> elem;
    std::sort(A.begin(), A.end(), [](const long long &l, const long long &r){
        return l > r;
    });
    for(long long i = 0; i < N; ++i) {
        std::cin >> B[i].first;
        B[i].second = i;
    }
    std::sort(B.begin(), B.end(), [](const std::pair<long long, long long> &l, const std::pair<long long, long long> &r){
        return l.first > r.first;
    });
    for(long long i = 0; i < N; ++i){
        array[i].first.first = A[i];
        array[i].first.second = B[i].first;
        array[i].second = B[i].second;
        sum += abs(A[i] - B[i].first);
    }
    std::sort(array.begin(), array.end(), [](const std::pair<std::pair<long long, long long>, long long> &l, const std::pair<std::pair<long long, long long>, long long> &r){
        return l.second < r.second;
    });
    std::cout << sum <<std::endl;
    for(std::pair<std::pair<long long, long long>, long long>&elem: array){
        std::cout << elem.first.first << " ";
    }
}
