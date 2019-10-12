#include <iostream>
#include <vector>


const std::vector<unsigned short int> number_of_days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void print_vector(const std::vector<std::string>& v) {
    for (auto s : v) {
        std::cout << s << std::endl;
    }
}

void next_month(std::vector<std::vector<std::string>>& month, const int next_month) {
    const int days_in_next_month = number_of_days[next_month];
    if (month.size() > days_in_next_month) {
        auto diff = month.size() - days_in_next_month;
        std::vector<std::string> leap_elements;
        for (auto it = month.end() - diff; it != month.end(); ++it) {
            leap_elements.insert(std::end(leap_elements), std::begin(*it), std::end(*it));
        }
        month[days_in_next_month - 1].insert(std::end(month[days_in_next_month - 1]), std::begin(leap_elements), std::end(leap_elements));
    }
    month.resize(days_in_next_month);
}

void print_day(const std::vector<std::vector<std::string>>& month, const int day) {
    std::cout << month[day - 1].size();
    for (const auto& s : month[day - 1]) {
        std::cout << ' ' << s;
    }
    std::cout << std::endl;
}

int main() {
    int count = 0;
    int month_number = 0;
    std::cin >> count;
    std::vector<std::vector<std::string>> month(number_of_days[month_number]);

    for (int i = 0; i < count; ++i) {
        std::string operation_code;
        std::cin >> operation_code;
        int day;

        if (operation_code == "ADD") {
            std::string activity;
            std::cin >> day >> activity;
            month[day - 1].push_back(activity);
        } else if (operation_code == "NEXT") {
            month_number = (month_number < 11) ? month_number + 1 : 0;
            next_month(month, month_number);
        } else if (operation_code == "DUMP") {
            std::cin >> day;
            print_day(month, day);
        }
    }

    return 0;
}