#include <iostream>
#include <vector>
#include <string>


struct Person {
    bool worried;
};


void remove_from_line(std::vector<Person>& line, int count) {
    for(int i = 0; i < count; ++i) {
        line.pop_back();
    }
}


void add_to_line(std::vector<Person>& line, int count) {
    for(int i = 0; i < count; ++i) {
        Person p {false};
        line.push_back(p);
    }
}


int get_worry_count(const std::vector<Person>& line) {
    int count = 0;
    for(auto p : line) {
        count += (p.worried) ? 1 : 0;
    }
    return count;
}


void print_line(const std::vector<Person>& line) {
    for (auto p : line) {
        std::cout << p.worried << ' ';
    }
    std::cout << std::endl;
}

int main() {
    int i = 0;
    int operations_number;
    int count = 0;

    std::string input;
    std::string command;
    std::vector<Person> line;

    std::cin >> operations_number;

    while(i <= operations_number) {
        std::getline(std::cin, input);
        size_t space_pos = input.find(' ');

        if (space_pos != std::string::npos) {
            count = std::stoi(input.substr(space_pos));
            command = input.substr(0, space_pos);
        } else {
            command = input;
        }

        if (command == "COME") {
            if (count > 0) {
                add_to_line(line, count);
            } else {
                remove_from_line(line, count * -1);
            }
        } else if (command == "WORRY" || command == "QUIET") {
            line[count].worried = command == "WORRY";
        } else if (command == "WORRY_COUNT") {
            std::cout << get_worry_count(line) << std::endl;
        }
        ++i;

    }
    return 0;
}