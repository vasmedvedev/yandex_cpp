#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

class Person {
public:
    void ChangeFirstName(int year, const std::string& first_name) {
        first_names[year] = first_name;
    }
    void ChangeLastName(int year, const std::string& last_name) {
        last_names[year] = last_name;
    }
    std::string GetFullName(const int year) {
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
    std::string GetFullNameWithHistory(const int year) {
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
    const std::string unknown_first = " with unknown first name";
    const std::string unknown_last = " with unknown last name";

    static std::string get_names(const int year, const std::map<int, std::string>& names) {
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
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }

    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    std::cout << person.GetFullNameWithHistory(1990) << std::endl;

    person.ChangeFirstName(1966, "Pauline");
    std::cout << person.GetFullNameWithHistory(1966) << std::endl;

    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }

    person.ChangeLastName(1961, "Ivanova");
    std::cout << person.GetFullNameWithHistory(1967) << std::endl;
    return 0;
}