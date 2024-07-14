public class Person {
    private Name name;
    private int age;

    Person() {
        name = new Name("", "");
        age = 0;
    }

    Person(Name name, int age) {
        this.name = name;
        this.age = age;
    }

    public String toString() {
        return name + " (" + age + ")";
    }
}
