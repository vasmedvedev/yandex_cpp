#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <set>
#include <sstream>

class Date {
public:
    Date(int _year, int _month, int _day) {
        if (_month < 1 || _month > 12) {
            throw std::invalid_argument("Month value is invalid: " + std::to_string(_month));
        }
        if (_day < 1 || _day > 31) {
            throw std::invalid_argument("Day value is invalid: " + std::to_string(_day));
        }
        year = _year;
        month = _month;
        day = _day;
    }
    int GetYear() const {
        return year;
    };
    int GetMonth() const {
        return month;
    };
    int GetDay() const {
        return day;
    };

private:
    int year;
    int month;
    int day;
};

void PrintSet(const std::set<std::string>& set) {
    for (const auto& event : set) {
        std::cout << event << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << std::setw(4) << std::setfill('0') << date.GetYear() << '-';
    os << std::setw(2) << std::setfill('0') << date.GetMonth() << '-';
    os << std::setw(2) << std::setfill('0') << date.GetDay();
    return os;
}

Date DateFromString(const std::string& date) {
    std::istringstream iss(date);
    int year, month, day;
    iss >> year;
    iss.ignore(1);
    iss >> month;
    iss.ignore(1);
    iss >> day;

    if (!iss || (iss.peek() != EOF)) {
        throw std::invalid_argument("Wrong date format: " + date);
    }

    return Date(year, month, day);
}

bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() != rhs.GetYear()) {
        return lhs.GetYear() < rhs.GetYear();
    } else if (lhs.GetMonth() != rhs.GetMonth()) {
        return lhs.GetMonth() < rhs.GetMonth();
    } else {
        return lhs.GetDay() < rhs.GetDay();
    }
}


class Database {
public:
    void AddEvent(const Date& date, const std::string& event) {
        events[date].insert(event);
    };
    bool DeleteEvent(const Date& date, const std::string& event) {
        if (events[date].find(event) != events[date].end()) {
            events[date].erase(event);
            return true;
        } else {
            return false;
        }
    };

    int DeleteDate(const Date& date) {
        if (events.find(date) == events.end()) {
            return 0;
        }
        size_t count = events.at(date).size();
        events.erase(date);
        return count;
    };

    void Find(const Date& date) const {
        if (events.find(date) == events.end()) {
            return;
        }
        PrintSet(events.at(date));
    };

    void Print() const {
        for (auto const& pair : events) {
            for (auto const& event : pair.second) {
                std::cout << pair.first << ' ' << event << std::endl;
            }
        }
    };

private:
    std::map<Date, std::set<std::string>> events;
};

int main() {
    Database db;

    std::string command;
    while (std::getline(std::cin, command)) {
        std::istringstream iss(command);
        std::string action;
        std::string date;
        std::string event;

        iss >> action;
        iss.ignore(1);
        try {
            if (action == "Print") {
                db.Print();
            } else if (action == "Add") {
                iss >> date;
                auto parsed_date = DateFromString(date);
                iss >> event;
                db.AddEvent(parsed_date, event);
            } else if (action == "Del") {
                iss >> date;
                auto parsed_date = DateFromString(date);
                if (iss.peek() == EOF) {
                    int deleted = db.DeleteDate(parsed_date);
                    std::cout << "Deleted " << deleted << " events" << std::endl;
                } else {
                    iss >> event;
                    std::cout << (db.DeleteEvent(parsed_date, event) ? "Deleted successfully" : "Event not found") << std::endl;
                }
            } else if (action == "Find") {
                iss >> date;
                db.Find(DateFromString(date));
            } else if (!action.empty()) {
                std::cout << "Unknown command: " << action << std::endl;
            }
        } catch (std::invalid_argument &exc) {
            std::cout << exc.what() << std::endl;
        }
    }

    return 0;
}
