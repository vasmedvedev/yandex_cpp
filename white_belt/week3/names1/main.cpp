#include <iostream>
#include <map>


class Person {
public:
    void ChangeFirstName(int year, const std::string& first_name) {
        first_names[year] = first_name;
    }
    void ChangeLastName(int year, const std::string& last_name) {
        last_names[year] = last_name;
    }
    std::string GetFullName(int year) {
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
    };
private:
    std::map<int, std::string> first_names;
    std::map<int, std::string> last_names;
    const std::string unknown_first = " with unknown first name";
    const std::string unknown_last = " with unknown last name";
};


int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        std::cout << person.GetFullName(year) << std::endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        std::cout << person.GetFullName(year) << std::endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        std::cout << person.GetFullName(year) << std::endl;
    }
    return 0;
}