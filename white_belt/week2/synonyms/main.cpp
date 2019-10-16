#include <iostream>
#include <set>
#include <map>

int main() {
    int count = 0;
    std::cin >> count;
    std::map<std::string, std::set<std::string>> synonyms;

    for (int i = 0; i < count; ++i) {
        std::string operation;
        std::cin >> operation;

        if (operation == "ADD") {
            std::string word;
            std::string synonim;
            std::cin >> word >> synonim;
            synonyms[word].insert(synonim);
            synonyms[synonim].insert(word);
        } else if (operation == "COUNT") {
            std::string word_to_find;
            std::cin >> word_to_find;
            std::cout << synonyms[word_to_find].size() << std::endl;
        } else if (operation == "CHECK") {
            std::string a;
            std::string b;
            std::cin >> a >> b;

            if (synonyms[a].count(b)) {
                std::cout << "YES";
            } else {
                std::cout << "NO";
            }
            std::cout << std::endl;
        }
    }
    return 0;
}