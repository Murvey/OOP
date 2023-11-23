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
