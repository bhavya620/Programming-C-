#include <iostream>
#include <string>
using namespace std;

class Prescription
{
    int n;
    string* medicines;

public:

    // Constructor
    Prescription(int count)
    {
        n = count;
        medicines = new string[n];
    }

    // Copy constructor - Deep Copy
    Prescription(const Prescription& p)
    {
        n = p.n;
        medicines = new string[n];

        for (int i = 0; i < n; i++)
        {
            medicines[i] = p.medicines[i];
        }
    }

    // Copy assignment operator
    Prescription& operator=(const Prescription& p)
    {
        if (this != &p)
        {
            delete[] medicines;

            n = p.n;
            medicines = new string[n];

            for (int i = 0; i < n; i++)
            {
                medicines[i] = p.medicines[i];
            }
        }

        return *this;
    }

    // Destructor
    ~Prescription()
    {
        delete[] medicines;
    }

    void set(int i, string medicine)
    {
        medicines[i] = medicine;
    }

    string get(int i)
    {
        return medicines[i];
    }
};

int main()
{
    Prescription p(2);

    p.set(0, "Paracetamol");
    p.set(1, "ORS");

    // Copy constructor
    Prescription q = p;

    q.set(1, "Cetirizine");

    // Copy assignment
    Prescription r(1);
    r = p;

    p.set(0, "Ibuprofen");

    cout << p.get(0) << " " << p.get(1) << " | ";
    cout << q.get(0) << " " << q.get(1) << " | ";
    cout << r.get(0) << " " << r.get(1) << endl;

    return 0;
}