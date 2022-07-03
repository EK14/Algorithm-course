#include <iostream>
#include <vector>
#include <algorithm>

bool Predicate(std::vector <int> &array, int K, int mid){
    int segmnumb = 0;
    int current_ind = array[0] + mid;
    segmnumb++;
    for(int i = 0; i < array.size(); ++i){
        if(current_ind < array[i]){
            segmnumb++;
            current_ind = array[i] + mid;
        }
    }
    return segmnumb <= K;
}
int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector <int> array(n, 0);
    for(int&elem : array){
        std::cin >> elem;
    }
    sort(array.begin(), array.end());
    long long left = 0;
    long long right = abs(array[n-1]) + abs(array[0]);
    long long mid;
    while(right != left){
        mid = (right + left) / 2;
        if(Predicate(array, k, mid))
            right = mid;
        else
            left = mid + 1;
    }
    std::cout << right;
}
