#include <iostream>
using namespace std;

class Event
{
    int rows;
    int seats;
    int** seatMap;

public:

    // Dynamic constructor
    Event(int r, int s)
    {
        rows = r;
        seats = s;

        if (rows == 0 || seats == 0)
        {
            seatMap = nullptr;
            return;
        }

        seatMap = new int*[rows];

        for (int i = 0; i < rows; i++)
        {
            seatMap[i] = new int[seats];

            for (int j = 0; j < seats; j++)
            {
                seatMap[i][j] = 0;
            }
        }

        cout << "Event created" << endl;
    }

    void book(int r, int s)
    {
        if (r >= 0 && r < rows && s >= 0 && s < seats)
        {
            seatMap[r][s] = 1;
            cout << "Seat booked" << endl;
        }
    }

    void cancel(int r, int s)
    {
        if (r >= 0 && r < rows && s >= 0 && s < seats)
        {
            seatMap[r][s] = 0;
            cout << "Seat cancelled" << endl;
        }
    }

    void display()
    {
        cout << "\nSeat Map:" << endl;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < seats; j++)
            {
                cout << seatMap[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Destructor
    ~Event()
    {
        if (seatMap != nullptr)
        {
            for (int i = 0; i < rows; i++)
            {
                delete[] seatMap[i];
            }

            delete[] seatMap;
        }

        cout << "Event destroyed" << endl;
    }
};

int main()
{
    // Stack object
    Event e1(2, 3);
    e1.book(0, 1);
    e1.book(1, 2);
    e1.display();

    // Heap object
    Event* e2 = new Event(2, 2);
    e2->book(0, 0);
    e2->display();

    delete e2;

    // Block scope
    {
        Event e3(1, 3);
        e3.book(0, 2);
        e3.display();
    }

    return 0;
}