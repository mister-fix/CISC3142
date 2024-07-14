/**
 * Assuming the existence of the following classes
 * 
 * class Person {
 *      Person(Name name, int age) {...}
 *      public String toString() {return name + " (" + age + ")";}
 * 
 *      private Name name;
 *      private int age;
 * }
 * 
 * class Name {
 *      Name(String first, String last) {...}
 *      public String toString() {return first + " " + last;}
 * 
 *      private String first, last;
 * }
 * 
 * class Date {
 *      Date(int year, int month, int dom) {...}
 *      public String toString() {return month + "/" + dom + "/" + year;]
 * 
 *      private int year, month, dom;
 * }
 */

// Task below 

/**
 * Implement a subclass of Person named Employee with the following state/behavior
 * 
 * class Employee extends Person {
 *      Employee(Name name, int age, int id, Date hireDate) {* for you to implement *}
 *      Employee(String first, String last, int age, int id, int year, int month, int dom) {* for you to implement *}
 *      public String toString() {* for you to implement *}
 * 
 *      int id;
 *      Date hireDate;
 * }
 */


public class Employee extends Person {
    Employee(Name name, int age, int id, Date hireDate) {
        super(name, age);
        this.id = id;
        this.hireDate = hireDate;
    }

    Employee(String first, String last, int age, int id, int year, int month, int dom) {
        super(new Name(first, last), age);
        this.id = id;
        hireDate = new Date(year, month, dom);
    }

    public String toString() {
        return super.toString() + " #" + id + " " + hireDate.toString();
    }

    private int id;
    private Date hireDate;
}