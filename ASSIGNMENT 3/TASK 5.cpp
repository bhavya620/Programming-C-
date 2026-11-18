#include <iostream>
#include <string>
using namespace std;

class Time
{
    int seconds;

public:

    Time(int s = 0)
    {
        seconds = s;
    }

    // Prefix ++
    Time& operator++()
    {
        seconds++;
        return *this;
    }

    // Postfix ++
    Time operator++(int)
    {
        Time old = *this;
        seconds++;
        return old;
    }

    bool operator==(const Time& t)
    {
        return seconds == t.seconds;
    }

    bool operator<(const Time& t)
    {
        return seconds < t.seconds;
    }

    void display()
    {
        cout << seconds << " seconds" << endl;
    }
};

class Playlist
{
    string songs[5];
    int size;

public:

    Playlist()
    {
        size = 5;

        songs[0] = "Song A";
        songs[1] = "Song B";
        songs[2] = "Song C";
        songs[3] = "Song D";
        songs[4] = "Song E";
    }

    string& operator[](int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Invalid index" << endl;
            return songs[0];
        }

        return songs[index];
    }

    const string& operator[](int index) const
    {
        if (index < 0 || index >= size)
        {
            return songs[0];
        }

        return songs[index];
    }
};

int main()
{
    Time t(10);

    Time a = t++;
    Time b = ++t;

    cout << "a = ";
    a.display();

    cout << "b = ";
    b.display();

    cout << "t = ";
    t.display();

    Playlist p;

    cout << "\nPlaylist:" << endl;
    cout << p[0] << endl;
    cout << p[1] << endl;

    cout << "\nInvalid access:" << endl;
    cout << p[10] << endl;

    return 0;
}