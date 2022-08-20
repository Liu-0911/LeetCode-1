#include <iostream>
#include <vector>
#include <array>

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::vector<int>{1,2,3,4,5};
    auto arr = std::to_array({1,2,3,45});
    for(auto n:arr){
        std::cout<<n;
    }
    return 0;
}
