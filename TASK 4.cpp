#include <iostream>
using namespace std;

int main() {
    int a = 7, b = 2;
    float c = a / b;
    float d = (float)a / b;

    cout << c << " " << d << endl;

    char ch = 'A' + 2;
    cout << ch << " " << ch + 1 << endl;

    bool flag = 5;
    cout << flag << " " << boolalpha << flag << endl;

    unsigned int u = 1;
    int s = -1;

    cout << (s < u ? "s < u" : "s >= u") << endl;

    return 0;
}