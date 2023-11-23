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
