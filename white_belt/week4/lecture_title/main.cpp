#include <iostream>

struct Specialization {
    std::string value;
    explicit Specialization(const std::string& v) {
        value = v;
    }
};

struct Course {
    std::string value;
    explicit Course(const std::string& v) {
        value = v;
    }
};

struct Week {
    std::string value;
    explicit Week(const std::string& v) {
        value = v;
    }
};


struct LectureTitle {
    std::string specialization;
    std::string course;
    std::string week;
    LectureTitle(const Specialization& s, const Course& c, const Week& w) {
        specialization = s.value;
        course = c.value;
        week = w.value;
    }
};

int main() {
    LectureTitle title(
        Specialization("C++"),
        Course("White belt"),
        Week("4th")
    );
    return 0;
}