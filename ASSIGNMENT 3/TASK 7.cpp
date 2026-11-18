#include <iostream>
#include <cmath>
using namespace std;

class Complex
{
    double real;
    double imag;

public:

    // Default constructor
    Complex()
    {
        real = 0;
        imag = 0;
    }

    // Real constructor
    Complex(double r)
    {
        real = r;
        imag = 0;
    }

    // Real and imaginary constructor
    Complex(double r, double i)
    {
        real = r;
        imag = i;
    }

    // Addition
    Complex operator+(const Complex& c)
    {
        return Complex(real + c.real, imag + c.imag);
    }

    // Subtraction
    Complex operator-(const Complex& c)
    {
        return Complex(real - c.real, imag - c.imag);
    }

    // Multiplication
    Complex operator*(const Complex& c)
    {
        double r = real * c.real - imag * c.imag;
        double i = real * c.imag + imag * c.real;

        return Complex(r, i);
    }

    // Division
    Complex operator/(const Complex& c)
    {
        double denominator =
            c.real * c.real + c.imag * c.imag;

        if (denominator == 0)
        {
            cout << "Error: Division by zero" << endl;
            return Complex();
        }

        double r =
            (real * c.real + imag * c.imag) / denominator;

        double i =
            (imag * c.real - real * c.imag) / denominator;

        return Complex(r, i);
    }

    // Equality
    bool operator==(const Complex& c)
    {
        return real == c.real && imag == c.imag;
    }

    // Magnitude
    double magnitude()
    {
        return sqrt(real * real + imag * imag);
    }

    // Output
    friend ostream& operator<<(ostream& out, const Complex& c)
    {
        out << c.real;

        if (c.imag >= 0)
            out << " + " << c.imag << "j";
        else
            out << " - " << -c.imag << "j";

        return out;
    }
};

int main()
{
    Complex r1(10, 0);
    Complex r2(5, 0);

    // Series impedance
    Complex series = r1 + r2;

    cout << "Series impedance = " << series << endl;
    cout << "Magnitude = " << series.magnitude() << endl;

    // Parallel impedance
    Complex parallel =
        (r1 * r2) / (r1 + r2);

    cout << "Parallel impedance = "
         << parallel << endl;

    cout << "Magnitude = "
         << parallel.magnitude() << endl;

    // Division by zero test
    Complex zero(0, 0);

    cout << "\nDivision by zero test:" << endl;

    Complex result = r1 / zero;

    cout << "Result = " << result << endl;

    return 0;
}