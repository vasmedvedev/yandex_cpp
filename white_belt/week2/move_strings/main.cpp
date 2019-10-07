#include <iostream>
#include <vector>

void MoveStrings(std::vector<std::string>& source, std::vector<std::string>& destination) {
    for(const auto& s : source) {
        destination.push_back(s);
    }
    source.clear();
}


int main() {
    std::vector<std::string> source = {"a", "b", "c"};
    std::vector<std::string> destination = {"z"};
    MoveStrings(source, destination);

    for(const auto& s : destination) {
        std::cout << s << ' ' << std::endl;
    }

    std::cout << source.size();
    return 0;
}