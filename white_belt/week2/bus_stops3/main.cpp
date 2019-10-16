#include <iostream>
#include <set>
#include <map>

int main() {
    int count = 0;
    std::cin >> count;
    std::map<std::set<std::string>, int> line;
    int next_number = 1;

    for (int i = 0; i < count; ++i) {
        int stops;
        std::cin >> stops;
        std::set<std::string> temp;

        for(int j = 0; j < stops; ++j) {
            std::string name;
            std::cin >> name;
            temp.insert(name);
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