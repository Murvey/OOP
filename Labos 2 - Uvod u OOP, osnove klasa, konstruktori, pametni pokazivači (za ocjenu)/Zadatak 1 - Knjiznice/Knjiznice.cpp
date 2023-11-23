/*
Svaka knjižnica ima podatak o nazivu i adresi, te popis knjiga koje su dostupne u toj knjižnici. Svaka knjiga ima naslov i autora, te broj posuđenih i dostupnih primjeraka.
a)    deklarirajte klase 'Knjiznica' i 'Knjiga'te njihove članove, tako da se pomoću njih može opisati gore navedena specifikacija.
b)    u funkciji main dodajte slijedeći programski odsječak te implementirajte sve potrebne metode da bi se mogao uspješno izvesti
Knjiga knjiga("Knjiga 1", "Autor 1", 20, 15);
Knjiznica knjiznica("Knjiznica 1", "Adresa 1", knjiga)//knjiga automatski dodana knjiznici
c)    u klasi Knjiznica deklarirajte metodu 'PriKrajuZaliha' koja vraća popis svih knjiga čiji je broj dostupnih primjeraka manji od 10. Implementaciju metode napišite van klase
d)    implementirajte metodu 'Sortiraj' unutar klase Knjiznica koja će sortirati sve knjige počevši kod onih koje su najviše puta posuđene prema manje
e)    napišite globalnu funkciju 'NajvisePrimjeraka' koja prima popis knjižnica, a vraća knjižnicu koja ima najveći broj dostupnih primjeraka knjiga
*/
#include <iostream>
#include <vector>

using namespace std;

class Knjiga
{
public:
    string naslov, autor;
    int posudene, dostupne;

    Knjiga() {}
    Knjiga(string _naslov, string _autor, int _posudene, int _dostupne)
    {
        naslov = _naslov;
        autor = _autor;
        posudene = _posudene;
        dostupne = _dostupne;
    }
};

class Knjiznica
{
public:
    string naziv, adresa;
    vector<Knjiga> knjige;

    Knjiznica() {}
    Knjiznica(string _naziv, string _adresa, Knjiga _knjiga)
    {
        naziv = _naziv;
        adresa = _adresa;
        knjige.push_back(_knjiga);
    }

    void dodajKnjigu(Knjiga _knjiga)
    {
        knjige.push_back(_knjiga);
    }

    vector<Knjiga> PriKrajuZaliha()
    {
        vector<Knjiga>pom;
        for (int i = 0; knjige.size();i++)
        {
            if (knjige[i].dostupne < 10)
            {
                pom.push_back(knjige[i]);
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

            for (int i = 0;i < knjige.size() - 1;i++)
            {
                if (knjige[i].posudene < knjige[i + 1].posudene)
                {
                    Knjiga pom;
                    pom = knjige[i];
                    knjige[i] = knjige[i + 1];
                    knjige[i + 1] = pom;
                }
            }
        }
    }
};

Knjiznica NajvisePrimjeraka(vector<Knjiznica>);

int main()
{
    Knjiga knjiga("Knjiga 1", "Autor 1", 20, 15);
    Knjiznica knjiznica("Knjiznica 1", "Adresa 1", knjiga);//knjiga automatski dodana knjiznici
    
    vector<Knjiga>knjigePriKrajuZaliha = knjiznica.PriKrajuZaliha();
    return 0;
}

Knjiznica NajvisePrimjeraka(vector<Knjiznica>knjiznice)
{
    Knjiznica pom;
    int najviseDostupnih = 0;
    int dostupneTrenutnaKnjiznica;

    for (int i = 0;i < knjiznice.size();i++)
    {
        dostupneTrenutnaKnjiznica = 0;
        for (int j = 0;j < knjiznice[i].knjige.size();j++)
        {
            dostupneTrenutnaKnjiznica += knjiznice[i].knjige[j].dostupne;
        }
        if (dostupneTrenutnaKnjiznica > najviseDostupnih)
        {
            pom = knjiznice[i];
            najviseDostupnih = dostupneTrenutnaKnjiznica;
        }

    }

    return pom;
}
