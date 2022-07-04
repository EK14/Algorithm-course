#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    long long N;
    std::cin >> N;
    std::vector<long long> vc(N);
    for(long long &element: vc){
        std::cin >> element;
    }
    std::sort(vc.begin(), vc.end());
    for(long long i = 0, j = N - 1; i < j; ++i, --j){
        std::cout << vc[i] << " " << vc[j] << " ";
    }
    if(N % 2 != 0){
        std::cout << vc[N/2];
    }
    return 0;
}
