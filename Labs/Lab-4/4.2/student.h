#ifndef STUDENT_H
#define STUDENT_H

#include <vector>
#include "course.h"

class Student {
    public:
        Student(int, std::string, std::vector<Course>);
        int getID() const;
        double getGPA() const;
        std::string getName() const;
        std::vector<Course> courses;
        void print(std::ostream &os) const;

    private:
        int id;
        std::string name;
};

inline std::ostream &operator << (std::ostream &os, const Student &student) {
    student.print(os);

    return os;
}

#endif