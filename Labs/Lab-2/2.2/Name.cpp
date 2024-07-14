#include <iostream>
#include <string>

using namespace std;

class Name {
    Name(String first, String last) {
        this.first = first;
        this.last = last;
    }

    private string first, last;
};

class Person {
    Person(Name name, int age) {
        this.name = name;
        this.age = age;
    }

    private Name name;
    private int age;

    class Employee : Person {
        Employee(Name name, int age, int id, Date hireDate);
        Employee(string first, string last, int age, int id, int year, int month, int dom);

        public String toString() {
            return name + " (" + age + ") #" + id + hireDate; 
        }

        private int id;
        private Date hireDate;
    };
};

class Date {
    Date(int year, int month, int dom) {
        this.year = year;
        this.month = month;
        this.dom = dom;
    }

    public String toString() {
        return month + "/" + dom + "/" + year;
    }

    private int month, dom, year;
};