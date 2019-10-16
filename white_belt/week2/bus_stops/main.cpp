#include <iostream>
#include <map>
#include <vector>

void print_vector(const std::vector<std::string>& v) {
    for (const auto& s : v){
        std::cout << s;
        if (s != v.back()) {
            std::cout << ' ';
        }
    }
    std::cout << std::endl;
}


int main() {
    int count = 0;
    std::cin >> count;
    std::map<std::string, std::vector<std::string>> buses_for_stop;
    std::map<std::string, std::vector<std::string>> stops_for_bus;

    std::map<int, std::string> m = {{1, "odd"}, {2, "even"}, {1, "one"}};
    for (int i = 0; i < count; i++) {
        std::string operation_code;
        std::cin >> operation_code;

        if (operation_code == "NEW_BUS") {
            std::string bus;
            int stop_count;
            std::cin >> bus >> stop_count;
            for (int j = 0; j < stop_count; j++) {
                std::string stop;
                std::cin >> stop;
                buses_for_stop[stop].push_back(bus);
                stops_for_bus[bus].push_back(stop);
            }
        } else if (operation_code == "BUSES_FOR_STOP") {
            std::string stop_to_find;
            std::cin >> stop_to_find;
            if (buses_for_stop[stop_to_find].empty()) {
                std::cout << "No stop" << std::endl;
                continue;
            }
            print_vector(buses_for_stop[stop_to_find]);
        } else if (operation_code == "STOPS_FOR_BUS") {
            std::string bus_to_find;
            std::cin >> bus_to_find;
            if (stops_for_bus[bus_to_find].empty()) {
                std::cout << "No bus" << std::endl;
                continue;
            }
            for (const auto& stop: stops_for_bus[bus_to_find]) {
                std::cout << "Stop " << stop << ":";
                if (buses_for_stop[stop].size() == 1 && buses_for_stop[stop][0] == bus_to_find) {
                    std::cout << " no interchange" << std::endl;
                    continue;
                }
                for (const auto& bus : buses_for_stop[stop]) {
                    if (bus != bus_to_find) {
                        std::cout << ' ' << bus;
                    }
                }
                std::cout << std::endl;
            }
        } else if (operation_code == "ALL_BUSES") {
            bool empty = true;
            for (const auto& item : stops_for_bus) {
                if (!item.second.empty()) {
                    empty = false;
                    std::cout << "Bus " << item.first << ": ";
                    print_vector(item.second);
                }
            }
            if (empty) {
                std::cout << "No buses" << std::endl;
            }
        }
    }
    return 0;
}