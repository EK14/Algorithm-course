#include <iostream>
#include <vector>

int main() {
    long N, M;
    std::cin >> N;
    std::vector<long> first(N);
    for(long &elem: first)
        std::cin >> elem;
    std::cin >> M;
    std::vector<long> second(M);
    for(long &elem: second)
        std::cin >> elem;
    std::vector<long> merged;
    long* pt1 = &first[0];
    long* pt2 = &second[0];
    while(pt1 <= &first[N-1] || pt2 <= &second[M-1]){
        if(*pt1 < *pt2 && pt1 <= &first[N-1]) {
            merged.push_back(*pt1);
            pt1++;
        }
        else if(pt2 <= &second[M-1]){
            merged.push_back(*pt2);
            pt2++;
        }
    }
    for(long &elem: merged)
        std::cout << elem << " ";
}
