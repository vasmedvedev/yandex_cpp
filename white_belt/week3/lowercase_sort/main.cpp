#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>

int main() {
    std::vector<std::string> v;
    int count;
    std::cin >> count;

    for (int i = 0; i < count; ++i) {
        std::string s;
        std::cin >> s;
        v.push_back(s);
    }
    std::sort(v.begin(), v.end(), [](const std::string& a, const std::string& b) {
        std::string x;
        std::string y;
        for (unsigned char c : a) {
            x += std::tolower(c);
        }
        for (unsigned char c : b) {
            y += std::tolower(c);
        }
        return x < y;
    });
    for (const auto& s : v) {
        std::cout << s << ' ';
    }
    std::cout << std::endl;
    return 0;
}