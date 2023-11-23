/*
Vlasnik ste koncerna za iznajmljivanje pedalina diljem Jadrana. Imate niz lokacija na kojima iznamljujete, te vam je već pomalo nespretno voditi evidenciju o tome gdje su koje pedaline te ste se odlučili baciti na posao i napraviti C++ program koji će vam u tome pomoći.

Odlučili ste definirati niz lokacija gdje iznamljujete, i za svaku lokaciju bilježiti koje pedaline iznamljujete (kako vam ne bi nestale).

Klasa Lokacija ima sljedeća svojstva:

ime i prezime odgovorne osobe
GPS koordinate (double X i double Y)
niz predmeta koji su dostupni
Klasa Pedalina ima sljedeća svojstva:

boja
kapacitet
U main programu potrebno je od korisnika tražiti unos broja N, nakon kojeg se unose podaci o N lokacija. Nakon što se unesu sva polja, potrebno je tražiti unos broja M, koji označava broj pedalina, te je potrebno unijeti tih M pedalina (neka lokacija može nuditi više pedalina).

Primjer izvođenja:

Unesite broj lokacija (N):2
 Unesite odgovornu osobu i GPS koordinate za 1. lokaciju:
 Pero Jankovic
 43.346216 16.734324
 Unesite odgovornu osobu i GPS koordinate za 2. lokaciju:
 Danko Stankovic
 43.246216 16.834324
 Unesite broj pedalina (M): 1
 Unesite redni broj lokacije kojoj pripada 1. pedalina: 2
 Unesite boju i kapacitet pedaline: Crvena 7
 
 Ispis lokacija i pedalina:
 
43.346216 16.734324 Pero Jankovic – pedaline:
43.246216 16.834324 Danko Stankovic – pedaline: Crvena (7)
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Pedalina
{
public:
    string boja;
    int kapacitet;
};
class Lokacija
{
public:
    string ime, prezime;
    double x, y;
    vector<Pedalina>pedaline;
};

int main()
{
    int brojLokacija;

    cout << "Unesite broj lokacija (N):";
    cin >> brojLokacija;

    Lokacija* lokacije;

    if ((lokacije = new Lokacija[brojLokacija]) == NULL)
    {
        cout << "Greska kod alokacije" << endl;
        return -1;
    }

    for (int i = 0;i < brojLokacija;i++)
    {
        cout << "Unesite odgovornu osobu i GPS koordinate za " << i + 1 << ". lokaciju:" << endl;
        cin >> lokacije[i].ime >> lokacije[i].prezime;
        cin >> lokacije[i].x >> lokacije[i].y;
    }

    int brojPedalina;
    cout << "Unesite broj pedalina (M): ";
    cin >> brojPedalina;

    for (int i = 0;i < brojPedalina;i++)
    {
        int brojLokacije;
        cout << "Unesite redni broj lokacije kojoj pripada " << i + 1 << ". pedalina: ";
        cin >> brojLokacije;
        brojLokacije;

        Pedalina pom;
        cout << "Unesite boju i kapacitet pedaline: ";
        cin >> pom.boja >> pom.kapacitet;

        lokacije[brojLokacije-1].pedaline.push_back(pom);
    }

    cout << "Ispis lokacija i pedalina:"<<endl;

    for (int i = 0;i < brojLokacija;i++)
    {
        cout << i + 1 << ". " << lokacije[i].x << " " << lokacije[i].y << " " << lokacije[i].ime << " " << lokacije[i].prezime << " -pedaline:" << endl;

        for (int j = 0;j < lokacije[i].pedaline.size();j++)
        {
            cout << "\t" << lokacije[i].pedaline[j].boja << " " << lokacije[i].pedaline[j].kapacitet << endl;
        }
    }

    delete[] lokacije;
    return 0;
}
