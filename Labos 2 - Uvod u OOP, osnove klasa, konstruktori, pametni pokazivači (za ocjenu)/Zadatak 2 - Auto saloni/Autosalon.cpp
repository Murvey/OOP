#include <iostream>
#include <vector>

using namespace std;

class Automobil
{
public:
    string proizvodjac, vrstaGoriva;
    int snaga;
    long int cijena;

    Automobil() {}
    Automobil(string _proizvodjac, string _vrstaGoriva, int _snaga, long int _cijena)
    {
        proizvodjac = _proizvodjac;
        vrstaGoriva = _vrstaGoriva;
        snaga = _snaga;
        cijena = _cijena;
    }
};

class AutoSalon
{
public:
    string naziv, adresa;
    vector<Automobil> automobili;

    AutoSalon() {}
    AutoSalon(string _naziv, string _adresa, vector<Automobil> _automobili)
    {
        naziv = _naziv;
        adresa = _adresa;

        for (int i = 0;i < _automobili.size();i++)
        {
            automobili.push_back(_automobili[i]);
        }
    }

    void ispis()
    {
        cout << "Automobili u autosalonu " << naziv << " :\n";
        for (int i = 0;i < automobili.size();i++)
        {
            cout << "Automobil: " << automobili[i].proizvodjac << ", vrsta goriva:" << automobili[i].vrstaGoriva << ", snaga:" << automobili[i].snaga << ", cijena:" << automobili[i].cijena << endl;
        }
    }

    vector <Automobil> NajsnaznijiMotori()
    {
        vector<Automobil> pom;
        for (int i = 0;i < automobili.size();i++)
        {
            if (automobili[i].snaga > 100)
            {
                pom.push_back(automobili[i]);
            }
        }

        return pom;
    }

    void Sortiraj()
    {
        int bilaZamjena = 1;
        while (bilaZamjena)
        {
            bilaZamjena = 0;

            for (int i = 0;i < automobili.size() - 1;i++)
            {
                if (automobili[i].snaga > automobili[i + 1].snaga)
                {
                    Automobil pom;
                    pom = automobili[i];
                    automobili[i] = automobili[i + 1];
                    automobili[i + 1] = pom;
                    bilaZamjena = 1;
                }
            }
        }
    }

};
 
void ispisVektora(vector<Automobil>);
AutoSalon najskupljiAutosalon(vector<AutoSalon>);

int main()
{
    vector<Automobil> auti = { Automobil("BMW 118i", "benzin", 150,2250),
        Automobil("Dacia Duster", "plin",  91, 114200),
        Automobil("Citroen C3", "diesel", 110, 127000) 
    };
    
    AutoSalon autosalon("Auto Salon", "Rijecka cesta 200, Rijeka", auti);// svi automobili u popisu automatski pripadaju tom autosalonu

    autosalon.ispis();

    vector<Automobil>snagaVecaOdSto = autosalon.NajsnaznijiMotori();

    ispisVektora(snagaVecaOdSto);

    autosalon.Sortiraj();
    cout << "Sortirani auto saloni:\n";
    autosalon.ispis();

    return 0;
}

void ispisVektora(vector<Automobil>automobili)
{
    cout << "Automobili jaci od 100 KS:\n";
    for (int i = 0;i < automobili.size();i++)
    {
        cout << "Automobil: " << automobili[i].proizvodjac << ", vrsta goriva:" << automobili[i].vrstaGoriva << ", snaga:" << automobili[i].snaga << ", broj kilometara:" << automobili[i].cijena << endl;
    }
}

AutoSalon najskupljiAutosalon(vector<AutoSalon> autosaloni)
{
    AutoSalon najskuplji;
    int ukCijena;
    float prosjecnaCijena;
    for (int i = 0;i < autosaloni.size();i++)
    {
        ukCijena = 0;
        prosjecnaCijena = 0;

        for (int j = 0;j < autosaloni[i].automobili.size();j++)
        {
            ukCijena += autosaloni[i].automobili[j].cijena;
        }

        if (prosjecnaCijena < ukCijena / autosaloni[i].automobili.size())
        {
            prosjecnaCijena = ukCijena / autosaloni[i].automobili.size();
            najskuplji = autosaloni[i];
        }
    }

    return najskuplji;
}
