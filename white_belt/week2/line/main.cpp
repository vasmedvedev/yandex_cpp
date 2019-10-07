#include <iostream>
#include <vector>

//void handle_command(const std::string command, const int arg) {
//
//}

struct Person {
    bool worried;
};

struct Command {

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


int main() {
    int i = 0;
    int operations_number;
    int count;
    std::string command;
    std::vector<Person> line;


    while(i < operations_number) {
        std::getline(std::cin, command);
        if (command == "COME") {
            if (count > 0) {
                add_to_line(line, count);
            } else {
                remove_from_line(line, count);
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