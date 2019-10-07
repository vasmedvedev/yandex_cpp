#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

bool IsPalindrom(const std::string& s) {
    bool even = s.length() % 2 == 0;
    const std::string head = s.substr(0, s.length() / 2);
    std::string tail = s.substr(even ? s.length() / 2 : (s.length() / 2) + 1, s.length());
    std::reverse(tail.begin(), tail.end());
    return head == tail;
}

std::vector<std::string> PalindromFilter(const std::vector<std::string>& words, int min_length){
    std::vector<std::string> result;

    for(const auto& word : words) {
        if(IsPalindrom(word) && word.length() >= min_length) {
            result.push_back(word);
        }
    }
    return result;
}

int main() {
    int min_length = 4;
    const std::vector<std::string> words = {"weew", "bro", "code"};
    for(const auto& word : PalindromFilter(words, min_length)) {
        std::cout << word << std::endl;
    }
    return 0;
}