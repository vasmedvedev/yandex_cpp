#include <iostream>
#include <vector>
#include <map>

int main() {
    int count = 0;
    std::cin >> count;
    std::map<std::vector<std::string>, int> line;
    int next_number = 1;

    for (int i = 0; i < count; ++i) {
        int stops;
        std::cin >> stops;
        std::vector<std::string> temp;

        for(int j = 0; j < stops; ++j) {
            std::string name;
            std::cin >> name;
            temp.push_back(name);
        }
        if (line.count(temp)) {
            std::cout << "Already exists for " << line[temp] << std::endl;
            continue;
        }
        line[temp] = next_number;
        std::cout << "New bus " << next_number << std::endl;
        ++next_number;
    };
    return 0;
}