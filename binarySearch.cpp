#include <iostream>
#include <vector>

void BinarySearch(const std::vector<int>& array, int target) {
    int left = 0;
    int right = array.size() - 1;
    int mid;
    while(left <= right){
        mid = left + (right - left) / 2;
        if(target == array[mid]) {
            std::cout << "YES\n";
            return;
        }
        else if (array[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    std::cout << "NO\n";
}

int main() {
    int N, K;
    std::cin >> N >> K;
    std::vector<int> array1(N,0);
    std::vector<int> array2(K,0);
    for(int&elem : array1){
        std::cin >> elem;
    }
    for(int& elem : array2){
        std::cin >> elem;
    }
    for(int pos=0; pos < K; ++pos){
        BinarySearch(array1, array2[pos]);
    }
}
