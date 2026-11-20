#include <iostream>
#include <string>
using namespace std;

class Address {
    string city;
    int pin;
public:
    Address(const string& c, int p) : city(c), pin(p) {
        cout << "Address+ ";
    }
    ~Address() { cout << "~Address "; }
    string str() const { return city + "-" + to_string(pin); }
};

class Person {
protected:
    string name;
    int age;
    Address home;
public:
    Person(const string& n, int a, const string& city, int pin)
        : name(n), age(a), home(city, pin) {
        cout << "Person+ ";
    }
    virtual ~Person() { cout << "~Person "; }
};

class Course {
    string title;
public:
    explicit Course(const string& t) : title(t) {
        cout << "Course+ ";
    }
    ~Course() { cout << "~Course "; }
    string getTitle() const { return title; }
};

class Student : virtual public Person {
    long long regNo;
    Course course;
public:
    Student(const string& n, int a, long long r,
            const string& city, int pin, const string& c)
        : Person(n, a, city, pin), regNo(r), course(c) {
        cout << "Student+ ";
    }
    ~Student() override { cout << "~Student "; }
    void print() const {
        cout << "\n" << regNo << " " << name << " (" << age
             << ") " << home.str() << " Course: " << course.getTitle() << '\n';
    }
};

class Staff : virtual public Person {
    string department;
public:
    Staff(const string& n, int a, const string& city,
          int pin, const string& d)
        : Person(n, a, city, pin), department(d) {
        cout << "Staff+ ";
    }
    ~Staff() override { cout << "~Staff "; }
};

class TeachingAssistant : public Student, public Staff {
public:
    TeachingAssistant()
        : Person("Mira", 22, "Chennai", 600001),
          Student("Mira", 22, 3001, "Chennai", 600001, "C++"),
          Staff("Mira", 22, "Chennai", 600001, "CSE") {
        cout << "TA+ ";
    }
    ~TeachingAssistant() override { cout << "~TA "; }
};

int main() {
    cout << "Complete-code output:\n";
    {
        class SimplePerson {
        protected:
            string name;
            int age;
        public:
            SimplePerson(const string& n, int a) : name(n), age(a) {}
        };
        class SimpleAddress {
            string city;
            int pin;
        public:
            SimpleAddress(const string& c, int p) : city(c), pin(p) {}
            string str() const { return city + "-" + to_string(pin); }
        };
        class SimpleStudent : public SimplePerson {
            long long regNo;
            SimpleAddress home;
        public:
            SimpleStudent(const string& n, int a, long long r,
                          const string& c, int p)
                : SimplePerson(n, a), regNo(r), home(c, p) {}
            void print() const {
                cout << regNo << " " << name << " (" << age
                     << ") " << home.str() << '\n';
            }
        };
        SimpleStudent s("Kavya", 19, 192311001, "Salem", 636001);
        s.print();
    }

    cout << "Construction/destruction trace:\n";
    {
        Student s("Ravi", 20, 1001, "Madurai", 625001, "OOP");
        s.print();
    }
    cout << '\n';
    {
        Staff st("Nila", 35, "Chennai", 600001, "IT");
    }
    cout << '\n';
    {
        TeachingAssistant ta;
    }
    cout << '\n';
    return 0;
}
