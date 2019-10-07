#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Reverse(vector<int>& v) {
    vector<int> tmp;
    for(auto it = v.rbegin(); it != v.rend(); ++it) {
        tmp.push_back(*it);
    }
    v = tmp;
}

int main() {
    vector<int> source = {5, 4, 3, 2, 1};
    Reverse(source);
    for(auto c : source) {
        cout << c << ' ';
    }
    return 0;
}