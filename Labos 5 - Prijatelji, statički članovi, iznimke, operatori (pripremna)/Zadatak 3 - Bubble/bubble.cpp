/*
Potrebno je napisati klasu Bubble sa svojstvima boja i radijus.
Implementacijom operatora zbrajanja (+) potrebno je omogućiti "spajanje" dva bubble-a u jedan.
Novi bubble ima obujam jednak zbroju obujama bubble-a od kojih je nastao, a preuzima boju većeg bubble-a.
Pri izdvajanju novog bubble-a iz postojećeg (operator -) nastaje novi sa smanjenim obujmom. Boja ostaje od originalnog bubble-a.

Obujam se računa prema obujmu kugle - V = 4/3 * r * r * r * PI. Također, treći korjen se računa kao pow(x, 1.0/3) (potrebno pri izračunavanju radijusa iz obujma).

Potrebno je dodati i operator == koji uspoređuje dva Bubble objekta. Dva bubble-a su isti ako imaju istu boju, i ako im se radijus razlikuje za ne više od 0.0001.

Main.cpp:

int main()
{
Bubble a("blue", 10.4);
Bubble b("red", 7.2);
Bubble c("green", 18.8);

Bubble x = a + b; //nastat će novi bubble obujma 6275.27
cout << x; //blue: 11.44
Bubble y = x + c;
cout << y; //green: 20.12

Bubble z = y - x;
cout << z; //green: 18.8

if(z == c)
cout << "OK" << endl; //OK


return 0;
}
*/

#include <iostream>
#include <math.h>
#include <iomanip>

#define PI 3.14159265358979323846
using namespace std;

class Bubble
{
public:
    string boja;
    double radijus;
    double obujam;

    Bubble() {}
    Bubble(string _boja, double _radijus)
    {
        boja = _boja;
        radijus = _radijus;
        obujam = (4.0 / 3.0) * pow(_radijus, 3) * PI;
    }
    
    Bubble operator +(const Bubble& tmp)
    {
        Bubble pom;
        pom.obujam = obujam + tmp.obujam;
        if (obujam > tmp.obujam)
        {
            pom.boja = boja;
        }
        else
        {
            pom.boja = tmp.boja;
        }

        pom.radijus = pow((3 * pom.obujam) / (4 * PI), 1.0 / 3.0);

        return pom;
    }

    Bubble operator -(const Bubble& tmp)
    {
        Bubble pom;
        pom.obujam = obujam - tmp.obujam;
        pom.boja = boja;

        pom.radijus = pow((3 * pom.obujam) / (4 * PI), 1.0 / 3.0);

        return pom;
    }

    bool operator ==(const Bubble& tmp)
    {
        if (boja == tmp.boja && abs(radijus - tmp.radijus) < 0.0001)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

ostream& operator<<(ostream& izlaz, Bubble tmp)
{
    izlaz << fixed << setprecision(2) << tmp.boja << ": " << tmp.radijus << endl;
    return izlaz;
}

int main()
{
    Bubble a("blue", 10.4);
    Bubble b("red", 7.2);
    Bubble c("green", 18.8);

    Bubble x = a + b; //nastat će novi bubble obujma 6275.27
    cout << x; //blue: 11.44
    Bubble y = x + c;
    cout << y; //green: 20.12

    Bubble z = y - x;
    cout << z; //green: 18.8

    if (z == c)
        cout << "OK" << endl; //OK

    return 0;
}
