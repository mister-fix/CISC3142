#ifndef COURSE_H
#define COURSE_H

#include <iostream>

class Course {
    public:
        Course(int, int, std::string);
        int getCourseCode() const {return courseCode;}
        int getCredits() const {return courseCredits;}
        std::string getGrade() const {return grade;}
        void print(std::ostream &os) const;

    private:
        int courseCode;
        int courseCredits;
        std::string grade;
};

// Print operator
inline std::ostream &operator <<(std::ostream &os, const Course &course) {
    course.print(os); 
    
    return os;
}

// Constructor
inline Course::Course(int courseCode, int courseCredits, std::string grade) {
    this->courseCode = courseCode;
    this->courseCredits = courseCredits;
    this->grade = grade;
}

// Print method
inline void Course::print(std::ostream &os) const {
    os << this->courseCode << " " << "(" << this->courseCredits << " credits): " << this->grade << std::endl;
}

#endif