#include <iostream>
using namespace std;

int main() {
    const int INNER = 10;
    const int MIDDLE = 20;
    const int OUTER = 30;

    int zone = 3;
    int fare;

    if (zone == 1)
        fare = INNER;
    else if (zone == 2)
        fare = MIDDLE;
    else
        fare = OUTER;

    cout << "Fare: Rs " << fare << endl;

    return 0;
}