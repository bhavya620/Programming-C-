
#include <iostream>
using namespace std;

class Parcel
{
public:
    double weight;

    Parcel(double w)
    {
        weight = w;
    }
};

void charge(int grams)
{
    cout << "Integer weight: " << grams << " grams" << endl;
}

void charge(double kg, bool express = false,
             bool insured = false)
{
    double amount = kg * 50;

    if (express)
        amount += 30;

    if (insured)
        amount += 20;

    cout << "Courier charge: Rs. " << amount << endl;
}

void charge(Parcel p)
{
    cout << "Parcel weight: " << p.weight << " kg" << endl;
}

int main()
{
    charge(500);
    charge(2);
    charge(2.0);
    charge(2.0f);
    charge(3.0, true);
    charge(Parcel(4.5));

    return 0;
}
