/*
Napraviti klasu Vrt sa sljedećim (privatnim) poljima:

adresa
vlasnik
sirina
duljina
Omogućiti korisniku kreiranje novog vrta i postavljanje članova. Treba pripaziti na sljedeća pravila:

Povrsina mora biti barem 10m2.
Naziv vlasnika mora pocinjati velikim slovom
Sve provjere pravila je potrebno napraviti unutar klase Vrt. (Gdje?)

Dodati klasu Cvijet s nekoliko proizvoljnih polja (vrsta, boja, kolicina, ...). Neka klasa Cvijet ima samo jedan konstruktor, unutar kojeg je potrebno ispisati „Cvijet constructor called“ korisniku, te jedan destruktor u kojem treba ispisati "Cvijet destructor called" korisniku. Proširiti klasu Vrt s poljem vector<Cvijet> i dodati u klasu Vrt metode:

dodajCvijet1(Cvijet z)
dodajCvijet2(Cvijet& z)
dodajCvijet3(Cvijet* z) 
Što se ispisuje prilikom poziva metoda 1,2 i 3? U kojim slučajevima se stvara novi objekt? Zašto se ispisuje više puta destruktor nego konstruktor?

Dodati u klasu Vrt metodu „ispisSvihCvijetova“.

Dodati u klasu Vrt metode:

Cvijet nadjiCvijet1(string vrsta)
Cvijet* nadjiCvijet2(string vrsta)
Cvijet& nadjiCvijet3(string vrsta)
Koristeći nadjiCvijet1 naći i zatim izmjeniti podatke o jednom cvijetu, a zatim koristeći metodu nadjiCvijet2 naći i zatim izmjeniti podatke o drugom svijetu, te koristeći metodu nadjiCvijet3 naći i zatim izmjeniti podatke o trećem cvijetu. Pozvati „ispisSvihCvijetova“ za vrt. Što zapažate?

Koje su prednosti a koji nedostaci u načinima pozivanja metoda s objektima kao parametrima i vraćanja objekata kao vrijednosti iz funkcije? Kada koristiti jedan način a kada drugi?
*/
#include <iostream>
#include <vector>

using namespace std;

class Cvijet
{
private:
    string vrsta, boja;
    int kolicina;

public:
    Cvijet()
    {
        cout << "Cvijet constructor called\n";
    }
    ~Cvijet()
    {
        cout << "Cvijet destructor called\n";
    }

    void setCvijet(string _vrsta, string _boja, int _kolicina)
    {
        vrsta = _vrsta;
        boja = _boja;
        kolicina = _kolicina;
    }

    string getVrsta()const
    {
        return vrsta;
    }

    string getBoja()const
    {
        return boja;
    }

    int getKolicina()const
    {
        return kolicina;
    }
};
class Vrt
{
private:
    string adresa, vlasnik;
    int sirina, duljina;

    vector<Cvijet> cvjece;

public:

    void SetVlasnik(string _vlasnik)
    {
        if (_vlasnik[0] < 'A' || _vlasnik[0] > 'Z')
        {
            while (_vlasnik[0] < 'A' || _vlasnik[0] > 'Z')
            {
                cout << "Naziv vlasnika mora pocinjati velikim slovom\nUnesite naziv vlasnika: ";
                cin >> _vlasnik;
            }

        }
        else
        {
            vlasnik = _vlasnik;
        }
    }

    void setPovrsina(int _duljina, int _sirina)
    {
        if (_duljina * _sirina < 10)
        {
            while (_duljina * _sirina < 10)
            {
                cout << "Povrsina mora biti barem 10m2.\nUnesite duljinu i sirinu: ";
                cin >> _duljina >> _sirina;
            }

        }
        else
        {
            duljina = _duljina;
            sirina = _sirina;
        }

    }

    void setAdresa(string _adresa)
    {
        adresa = _adresa;
    }

    string getAdresa()const
    {
        return adresa;
    }

    string getVlasnik() const
    {
        return vlasnik;
    }

    int getSirina()const
    {
        return sirina;
    }

    int getDuljina() const
    {
        return duljina;
    }


    void dodajCvijet1(Cvijet z)
    {
        cvjece.push_back(z);
    }

    void dodajCvijet2(Cvijet& z)
    {
        cvjece.push_back(z);
    }

    void dodajCvijet3(Cvijet* z)
    {
        cvjece.push_back(*z);
    }
    Cvijet nadjiCvijet1(string vrsta)
    {
        for (int i = 0; i < cvjece.size(); i++)
        {
            if (cvjece[i].getVrsta() == vrsta)
            {
                return cvjece[i];
            }
        }
    }

    Cvijet* nadjiCvijet2(string vrsta)
    {
        for (int i = 0; i < cvjece.size(); i++)
        {
            if (cvjece[i].getVrsta() == vrsta)
            {
                return &cvjece[i];
            }
        }
    }

    Cvijet& nadjiCvijet3(string vrsta)
    {
        for (int i = 0; i < cvjece.size(); i++)
        {
            if (cvjece[i].getVrsta() == vrsta)
            {
                return cvjece[i];
            }
        }
    }

    void ispisSvihCvijetova()
    {
        for (int i = 0; i < cvjece.size(); i++)
        {
            cout << "Vrsta: " << cvjece[i].getVrsta() << ", Kolicina:" << cvjece[i].getKolicina() << ", Boja: " << cvjece[i].getBoja() << endl;
        }
    }

};
int main()
{
    Vrt vrt1;
    
    vrt1.SetVlasnik("Ante");
    vrt1.setPovrsina(5, 8);
    vrt1.setAdresa("Vrbik 8a");

    Cvijet cvijet1, cvijet2, cvijet3;

    cvijet1.setCvijet("suncokret", "zuta", 5);
    cvijet2.setCvijet("ruza", "crvena", 12);
    cvijet3.setCvijet("ljiljan", "bijela", 2);

    vrt1.dodajCvijet1(cvijet1);
    vrt1.dodajCvijet2(cvijet2);
    vrt1.dodajCvijet3(&cvijet3);

    vrt1.ispisSvihCvijetova();

    Cvijet izmjena1 = vrt1.nadjiCvijet1("suncokret");
    izmjena1.setCvijet("suncokret", "zuta", 0);

    Cvijet* izmjena2 = vrt1.nadjiCvijet2("ruza");
    izmjena2->setCvijet("ruza", "crvena", 0);

    Cvijet& izmjena3 = vrt1.nadjiCvijet3("ljiljan");
    izmjena3.setCvijet("ljiljan", "bijela", 0);

    cout << "ispis svih cvjetova nakon izmjene\n";

    vrt1.ispisSvihCvijetova();

    return 0;
}
