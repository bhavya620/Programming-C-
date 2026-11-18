#include <iostream>
#include <iomanip>
using namespace std;

class Money
{
    long long paise;

public:

    Money(long long rupees = 0, int p = 0)
    {
        paise = rupees * 100 + p;
    }

    // + operator
    Money operator+(const Money& m)
    {
        Money result;
        result.paise = paise + m.paise;
        return result;
    }

    // - operator
    Money operator-(const Money& m)
    {
        Money result;
        result.paise = paise - m.paise;
        return result;
    }

    // += operator
    Money& operator+=(const Money& m)
    {
        paise += m.paise;
        return *this;
    }

    // == operator
    bool operator==(const Money& m)
    {
        return paise == m.paise;
    }

    // < operator
    bool operator<(const Money& m)
    {
        return paise < m.paise;
    }

    // Output operator
    friend ostream& operator<<(ostream& out, const Money& m)
    {
        long long rupees = m.paise / 100;
        long long p = m.paise % 100;

        if (p < 0)
            p = -p;

        out << "Rs " << rupees << "."
            << setw(2) << setfill('0') << p;

        return out;
    }

    // Input operator
    friend istream& operator>>(istream& in, Money& m)
    {
        long long rupees;
        int p;

        cin >> rupees >> p;
        m.paise = rupees * 100 + p;

        return in;
    }
};

int main()
{
    Money a(120, 75);
    Money b(79, 25);

    Money c = a + b;

    cout << c << endl;
    cout << boolalpha << (c == Money(200)) << endl;

    Money d(0, 75);
    Money e(0, 50);

    cout << "Rs 0.75 + Rs 0.50 = "
         << d + e << endl;

    return 0;
}