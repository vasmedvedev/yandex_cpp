#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

class Person {
public:
    Person(const std::string& first_name, const std::string& last_name, int year) {
        first_names[year] = first_name;
        last_names[year] = last_name;
        year_of_birth = year;
    }
    void ChangeFirstName(int year, const std::string& first_name) {
        if (year >= year_of_birth) {
            first_names[year] = first_name;
        }
    }
    void ChangeLastName(int year, const std::string& last_name) {
        if (year >= year_of_birth) {
            last_names[year] = last_name;
        }
    }
    std::string GetFullName(int year) const {
        if (year < year_of_birth) {
            return "No person";
        }
        auto f = first_names.upper_bound(year);
        auto l = last_names.upper_bound(year);

        f = (f == first_names.begin()) ? first_names.end() : --f;
        l = (l == last_names.begin()) ? last_names.end() : --l;

        if (f == first_names.end() && l == last_names.end()) {
            return "Incognito";
        } else if (f == first_names.end()) {
            return l->second + unknown_first;
        } else if (l == last_names.end()) {
            return f->second + unknown_last;
        } else {
            return f->second + ' ' + l->second;
        }
    }
    std::string GetFullNameWithHistory(int year) const {
        if (year < year_of_birth) {
            return "No person";
        }
        auto f = first_names.upper_bound(year);
        auto l = last_names.upper_bound(year);

        f = (f == first_names.begin()) ? first_names.end() : --f;
        l = (l == last_names.begin()) ? last_names.end() : --l;

        if (f == first_names.end() && l == last_names.end()) {
            return "Incognito";
        } else if (f == first_names.end()) {
            return get_names(year, last_names) + unknown_first;
        } else if (l == last_names.end()) {
            return get_names(year, first_names) + unknown_last;
        } else {
            return get_names(year, first_names) + ' ' + get_names(year, last_names);
        }

    }
private:
    std::map<int, std::string> first_names;
    std::map<int, std::string> last_names;
    int year_of_birth;
    const std::string unknown_first = " with unknown first name";
    const std::string unknown_last = " with unknown last name";

    std::string get_names(const int year, const std::map<int, std::string>& names) const {
        auto name = names.upper_bound(year);
        name = (name == names.begin()) ? names.end() : --name;
        std::string current_name;
        std::vector<std::string> old_names_vector;
        std::string old_names;
        std::string last_record;

        if (name != names.end()) {
            current_name = name->second;
            last_record = current_name;
        }

        name = (name == names.begin()) ? name : --name;

        while (true) {
            if(name->second != last_record) {
                old_names_vector.push_back(name->second);
                last_record = name->second;
            }
            if (name != names.begin()) {
                --name;
            } else {
                break;
            }
        }
        for (auto it = old_names_vector.begin(); it != old_names_vector.end(); ++it) {
            old_names += *it;
            if (it != old_names_vector.end() - 1) {
                old_names += ", ";
            }
        }
        return current_name + (old_names.empty() ? "": (" (" + old_names + ')'));
    }

};


int main() {
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }

    return 0;
}