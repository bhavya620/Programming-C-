
#include <iostream>
using namespace std;

int& highestMark(int marks[], int n)
{
    int maxIndex = 0;

    for (int i = 1; i < n; i++)
    {
        if (marks[i] > marks[maxIndex])
        {
            maxIndex = i;
        }
    }

    return marks[maxIndex];
}

int main()
{
    int marks[5] = {75, 89, 92, 68, 85};

    cout << "Highest mark: " << highestMark(marks, 5) << endl;

    highestMark(marks, 5) += 2;

    cout << "After moderation: "
         << highestMark(marks, 5) << endl;

    cout << "All marks: ";

    for (int i = 0; i < 5; i++)
    {
        cout << marks[i] << " ";
    }

    cout << endl;

    return 0;
}
