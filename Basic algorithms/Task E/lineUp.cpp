#include <iostream>
#include <vector>

int main() {
    int n, k, l, r;
    long long sum = 0, x;
    std::cin >> n;
    std::vector <long long> pref(n, 0);
    for(int i = 0; i < n; ++i){
        std::cin >> x;
        sum += x;
        pref[i] = sum;
    }
    std::cin >> k;
    for(int i = 0; i < k; ++i){
        std::cin >> l >> r;
        std::cout << ((l == 1) ? pref[r-1]: pref[r-1] - pref[l-2]) << " ";
    }
}
