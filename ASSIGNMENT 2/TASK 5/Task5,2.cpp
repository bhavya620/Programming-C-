
#include <iostream>
#include <string>
using namespace std;

class BusTicket
{
    static int issued;
    static const int CAPACITY = 3;

    int seat;
    string name;

public:
    explicit BusTicket(const string& n)
        : seat(0), name(n)
    {
        if (issued < CAPACITY)
        {
            issued++;
            seat = issued;
        }
    }

    static int count()
    {
        return issued;
    }

    void print() const
    {
        cout << name << ": ";

        if (seat)
            cout << "Seat " << seat;
        else
            cout << "Waiting";

        cout << endl;
    }
};

int BusTicket::issued = 0;

int main()
{
    BusTicket trip[4] = {
        BusTicket("Asha"),
        BusTicket("Bala"),
        BusTicket("Chitra"),
        BusTicket("Dev")
    };

    for (const BusTicket& t : trip)
    {
        t.print();
    }

    cout << "Issued: " << BusTicket::count() << endl;

    return 0;
}
