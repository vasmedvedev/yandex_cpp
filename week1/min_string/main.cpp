#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::string a, b, c;
    std::cin >> a >> b >> c;
    std::vector<std::string> v = {a, b, c};
    std::sort(v.begin(), v.end());
    std::cout << v.front() << std::endl;
    return 0;
}