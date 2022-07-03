#include <iostream>
#include <vector>
#include <cmath>

int64_t MaxSubsegmentSum(int64_t begin, int64_t end, std::vector<int64_t>&array){
    int64_t currSum = 0, maxSum = array[begin];
    for(int64_t i = begin; i < end ; ++i){
        currSum += array[i];
        maxSum = fmax(maxSum, currSum);
        if(currSum < 0) currSum = 0;
    }
    return maxSum;
}

int main() {
    int N, Q;
    int64_t l, r;
    std::cin >> N;
    std::vector<int64_t> array(N, 0);
    for(int i = 0; i < N; ++i){
        std::cin >> array[i];
    }
    std::cin >> Q;
    for(int i = 0; i < Q; ++i){
        std::cin >> l >> r;
        std::cout << MaxSubsegmentSum(l, r, array)<<std::endl;
    }
}
