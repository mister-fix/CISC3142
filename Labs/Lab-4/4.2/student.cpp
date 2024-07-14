#include "student.h"

using namespace std;

// Constructor
Student::Student(int id, std::string name, std::vector<Course> courses) {
    this->id = id;
    this->name = name;
    this->courses = courses;
}

// Get student ID
int Student::getID() const {
    return this->id;
}

// Get student name
string Student::getName() const {
    return this->name;
}

// Get student GPA
double Student::getGPA() const {
    double total;
    double creds;
    double cgrade;
    double gpa;

    // Calculating total grade and credits
    for(int i = 0; i < courses.size(); i++) {
        if(courses[i].getGrade() == "A") cgrade = 4.0;
        else if(courses[i].getGrade() == "B") cgrade = 3.0;
        else if(courses[i].getGrade() == "C") cgrade = 2.0;
        else if(courses[i].getGrade() == "D")cgrade = 1.0;

        total += cgrade * courses[i].getCredits();
        creds += courses[i].getCredits();
    }

    // Evaluating GPA
    gpa = total / creds;

    // Returning gpa
    return gpa;
}

// Print student object
void Student::print(std::ostream &os) const {
	os << id << " " << name << ": " << this->getGPA() << endl;
    
    // Printing courses
    for(int i = 0; i < courses.size(); i++) {
        os << "--- " << courses[i];
    }
}