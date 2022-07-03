#include <iostream>
#define EPS 1e-10

double function(int a, int b, int c, int d, double x){
    return a*x*x*x+b*x*x+c*x+d;
}

double BinarySearch(int a, int b, int c, int d, float target) {
    double left = -10000;
    double right = 10000;
    double mid;
    while(right - left > EPS){
        mid = (right + left) / 2;
        if (function(a, b, c, d, mid) * function(a, b, c, d, right) > 0)
            right = mid;
        else
            left = mid;
    }
    return left;
}

int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    printf("%8f", BinarySearch(a, b, c, d, 0));
}
