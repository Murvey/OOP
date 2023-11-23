/*
Svaka slika ima svoju cijenu izraženu u eurima. Slijedeći programski kod u nastavku napišite klasu Slika i sve potrebne podatkovne članove i metode kojima se dobije očekivano ponašanje programskog koda.

 

Slika Slika1(2000); // 2000 eura

Slika Slika2(3000); // 3000 eura

Slika Slika3(1800); // 1800 eura

cout << Slika::ProsjecnaCijena() << " eura"; // 2266.67 eura
*/

#include <iostream>
using namespace std;

class Slika
{
public:
    int cijena;
    static int ukCijena;
    static int brSlika;

    Slika() {}

    Slika(int _cijena)
    {
        cijena = _cijena;
        ukCijena += cijena;
        brSlika++;
    }

    static double ProsjecnaCijena()
    {
        return (double)ukCijena / brSlika;
    }
};

int Slika::ukCijena = 0;
int Slika::brSlika = 0;
int main()
{
    Slika Slika1(2000); // 2000 eura

    Slika Slika2(3000); // 3000 eura

    Slika Slika3(1800); // 1800 eura

    cout << Slika::ProsjecnaCijena() << " eura"; // 2266.67 eura


    return 0;
}
