#include <iostream>
#include <string>
using namespace std;

class Book
{
    string title;
    int copies;

public:

    // Default constructor
    Book() : Book("", 0)
    {
    }

    // Parameterized constructor
    Book(string t, int c) : title(t), copies(c)
    {
        if (copies < 0)
            copies = 0;
    }

    // Constructor with title only
    Book(string t) : Book(t, 0)
    {
    }

    // Display book details
    void display()
    {
        cout << "Title: " << title << endl;
        cout << "Copies: " << copies << endl;
        cout << endl;
    }
};

int main()
{
    Book b1;                    // Default constructor
    Book b2("C++ Programming"); // Title only
    Book b3("Data Structures", 5); // Title and copies
    Book b4("Computer Networks", -2); // Invalid copies

    cout << "Book 1:" << endl;
    b1.display();

    cout << "Book 2:" << endl;
    b2.display();

    cout << "Book 3:" << endl;
    b3.display();

    cout << "Book 4:" << endl;
    b4.display();

    return 0;
}