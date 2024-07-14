#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#include "student.h"

using namespace std;

// Load students vector
void loadStudents(string fileName, vector<Student> &students);
// Course comparison
bool compareGrade(const Course &c1, const Course &c2);
// Student comparison
bool compareGPA(const Student &s1, const Student &s2);
// Print results
void printResults(vector<Student> &students);

int main() {
    try {
        vector<Student> students;

        loadStudents("students.data", students);
        
        sort(students.begin(), students.end(), compareGPA);

        // Printing results;
        printResults(students);

        cout << "\n" << students.size() << " records processed" << endl;

        return 0;
    }
    catch(string message) {
        cout << "Error: " << message << endl;
        exit(1);
    }
};

// Loading students into the students vector
void loadStudents(string fileName, vector<Student> &students) {
    ifstream studentsFile(fileName.c_str());
    if(!studentsFile.good()) {
        throw string("Input file: " + fileName + ", not found!");
    }

    int studentID, courseCode, courseCredits;
    std::string studentName, courseGrade;

    studentsFile >> studentID;

    while(studentsFile) {
        studentsFile >> studentName >> courseCode;

        std::vector<Course> courses;

        while(courseCode != -1) {
            studentsFile >> courseCredits >> courseGrade;
            courses.push_back(Course(courseCode, courseCredits, courseGrade));

            studentsFile >> courseCode;
        }

        students.push_back(Student(studentID, studentName, courses));

        studentsFile >> studentID;
    }

    studentsFile.close();
}

// Grade comparison method
bool compareGrade(const Course &c1, const Course &c2) {
    return c1.getGrade() < c2.getGrade();
}

// Student comparison method
bool compareGPA(const Student &s1, const Student &s2) {
    return s1.getGPA() > s2.getGPA();
}

// Printing results
void printResults(vector<Student> &students) {
    for(auto student : students) {
        cout << student;
    }
}