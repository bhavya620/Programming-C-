#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int id;
    string phone;
public:
    Person(string n, int i, string p)
        : name(n), id(i), phone(p) {
        cout << "Person ";
    }
    virtual ~Person() = default;
};

class Student : virtual public Person {
protected:
    string programme;
    double cgpa;
public:
    Student(string n, int i, string p, string prog, double c)
        : Person(n, i, p), programme(prog), cgpa(c) {
        cout << "Student ";
    }
};

class Staff : virtual public Person {
protected:
    string department;
    double salary;
public:
    Staff(string n, int i, string p, string dept, double sal)
        : Person(n, i, p), department(dept), salary(sal) {
        cout << "Staff ";
    }
};

class TeachingAssistant : public Student, public Staff {
public:
    TeachingAssistant(string n, int i, string p, string prog, double c,
                      string dept, double sal)
        : Person(n, i, p),
          Student(n, i, p, prog, c),
          Staff(n, i, p, dept, sal) {
        cout << "TA ";
    }
    void display() const {
        cout << "\nName: " << name << ", ID: " << id
             << ", Programme: " << programme
             << ", Department: " << department << '\n';
    }
};

class ResearchScholar : public Student {
    double fellowship;
public:
    ResearchScholar(string n, int i, string p, string prog,
                    double c, double f)
        : Person(n, i, p), Student(n, i, p, prog, c),
          fellowship(f) {}
    void display() const {
        cout << name << " fellowship: Rs " << fellowship << '\n';
    }
};

int main() {
    TeachingAssistant ta("Kavya", 201, "9876543210",
                         "CSE", 8.7, "Computer Science", 25000);
    ta.display();

    ResearchScholar scholar("Arun", 202, "9876501234",
                            "AI", 9.1, 18000);
    scholar.display();
    return 0;
}
