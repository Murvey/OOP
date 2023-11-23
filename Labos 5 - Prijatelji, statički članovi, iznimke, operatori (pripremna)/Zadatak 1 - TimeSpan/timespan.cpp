
#include<iostream>
using namespace std;

class TimeSpan {
public:
    int h, m, s;
    TimeSpan(int _h, int _m, int _s) : h(_h), m(_m), s(_s) {}

    TimeSpan operator +(const TimeSpan& a) {
        int sat, minuta, sekunda;
        sat = h + a.h;
        minuta = m + a.m;
        sekunda = s + a.s;
        while (sekunda >= 60) {
            if (sekunda >= 60) {
                sekunda = sekunda - 60;
                minuta++;
            }
        }
        while (minuta >= 60) {
            if (minuta >= 60) {
                minuta = minuta - 60;
                sat++;
            }
        }
        return TimeSpan(sat, minuta, sekunda);
    }

    bool operator<(const TimeSpan& a) {
        if (a.h < h)  return false;
        else if (a.h > h)  return true;
        else {
            if (a.m < m)  return false;
            else if (a.m > m) return true;
            else {
                if (a.s < s) return false;
                else if (a.s > s) return true;
                else return false;
            }
        }
    }

    bool operator ==(const TimeSpan& a) {
        if (h == a.h && m == a.m && s == a.s) return true;
        else return false;
    }
    operator int() {
        return 60 * 60 * h + 60 * m + s;
    }

    friend ostream& operator <<(ostream& izlaz, TimeSpan a);
};
ostream& operator<<(ostream& izlaz, TimeSpan a)
{
    izlaz << a.h << ":" << a.m << ":" << a.s << "\n";
    return izlaz;
}

int main()
{
    TimeSpan a(1, 0, 0);
    TimeSpan x(24, 0, 0);

    while (a < x)
    {
        if (a == TimeSpan(1, 0, 0))
            a = a + TimeSpan(10, 6, 7);
        else if (a < TimeSpan(12, 0, 0))
            a = a + TimeSpan(0, 37, 14);
        else
            a = a + TimeSpan(9, 11, 57);

        cout << a ;

    }

    cout << "Ukupno sekundi: " << (int)a << endl;

    return 0;
}
