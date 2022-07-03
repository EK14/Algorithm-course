#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    long long n, k, A0, A1;
    std::cin >> n >> k >> A0 >>A1;
    std::vector<long long> A(n);
    A[0] = A0;
    A[1] = A1;
    for(long long i = 2; i < n; ++i){
        A[i] =(A[i-1]*123 + A[i-2]*45) % (10000000 + 4321);
    }
    std::nth_element(A.begin(), A.begin()+k-1, A.end());
    std::cout<<A[k-1];
    return 0;
}
