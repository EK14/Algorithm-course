#include <iostream>
#include <vector>

bool Predicate(int mid, int K, int N, std::vector <int> &array){
    int cownumb = 1;
    int current_pos = array[0];
    for(int i = 0; i < N; ++i){
        if(array[i] - current_pos >= mid){
            cownumb++;
            current_pos = array[i];
        }
    }
    return cownumb >= K;
}
int main() {
    int N, K;
    std::cin >> N >> K;
    std::vector <int> array(N, 0);
    for(int&elem : array){
        std::cin >> elem;
    }
    int left = 1;
    int right = array[N-1];
    int mid;
    while(right - left > 1){
        mid = (left + right) / 2;
        if(Predicate(mid, K, N, array)){
            left = mid;
        }
        else
            right = mid;
    }
    std::cout << left;
}
