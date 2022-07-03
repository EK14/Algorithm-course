#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n, k, l, r;
    long double sum = 0, x;
    std::cin >> n;
    std::vector <long double> pref(n, 0);
    for(int i = 0; i < n; ++i){
        std::cin >> x;
        sum += log(x);
        pref[i] = sum;
    }
    std::cin >> k;
    for(int i = 0; i < k; ++i){
        std::cin >> l >> r;
        (l == 0) ? (x = exp((double)1/(r+1) * pref[r])) : (x = exp((double)1/(r-l+1) * (pref[r] - pref[l-1])));
        x = trunc(x * 100000000) / 100000000;
        printf("%.7Lf\n", x);
    }
}
