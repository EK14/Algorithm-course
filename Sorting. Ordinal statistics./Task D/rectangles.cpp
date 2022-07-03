#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    long long N, count = 0, k1 = 0, k2 = 0;
    std::cin >> N;
    std::vector<long long> vc(N);
    for(long long i = 0; i < N; ++i)
        std::cin >> vc[i];
    std::sort(vc.begin(), vc.end());
    long long *pt1 = &vc[0], *pt2 = &vc[0];
    for(;pt2 < &vc[0]+N-1; pt2++){
        if(*pt1 == *pt2){
            k1 += 1;
        }
        else{
            count += k1 / 4;
            k2 += (k1 - 4*(k1/4))/2;
            pt1 = pt2;
            k1 = 0;
            pt2--;
        }
    }
    if(*pt1 == *pt2)
        k1 += 1;
    count += k1 / 4;
    k2 += (k1 - 4*(k1/4))/2;
    count += k2 / 2;
    std::cout << count;
}
