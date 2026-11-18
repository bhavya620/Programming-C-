#include <iostream>
#include <cstring>
using namespace std;

class Text
{
    char* data;

public:

    // Constructor
    Text(const char* str = "")
    {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    // Copy constructor
    Text(const Text& t)
    {
        data = new char[strlen(t.data) + 1];
        strcpy(data, t.data);
    }

    // Assignment operator
    Text& operator=(const Text& t)
    {
        if (this != &t)
        {
            delete[] data;

            data = new char[strlen(t.data) + 1];
            strcpy(data, t.data);
        }

        return *this;
    }

    // + operator
    Text operator+(const Text& t)
    {
        int length = strlen(data) + strlen(t.data);

        char* temp = new char[length + 1];

        strcpy(temp, data);
        strcat(temp, t.data);

        Text result(temp);

        delete[] temp;

        return result;
    }

    // == operator
    bool operator==(const Text& t)
    {
        return strcmp(data, t.data) == 0;
    }

    // != operator
    bool operator!=(const Text& t)
    {
        return !(*this == t);
    }

    // Output operator
    friend ostream& operator<<(ostream& out, const Text& t)
    {
        out << t.data;
        return out;
    }

    // Destructor
    ~Text()
    {
        delete[] data;
    }
};

int main()
{
    Text a("Hello ");
    Text b("World");

    Text c = a + b;

    cout << "Text: " << c << endl;

    Text d("Hello World");

    cout << "Equal: " << boolalpha << (c == d) << endl;

    Text e;
    e = c;

    cout << "Copied text: " << e << endl;

    e = e;

    cout << "After self assignment: " << e << endl;

    return 0;
}