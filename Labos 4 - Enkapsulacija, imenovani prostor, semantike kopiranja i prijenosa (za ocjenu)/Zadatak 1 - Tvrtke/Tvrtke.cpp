/*
Podaci o tvrtci sadrže OIB, naziv, adresu te popis svih zaposlenika. podaci o zaposlenicima sadrže ime i prezime te godine radnog staža.
a)    deklarirajte klase 'Tvrtka' i 'Zaposlenik' te njihove članove, tako da se pomoću njih može opisati gore navedena specifikacija.  Popis zaposlenika u tvrtci realizirajte pomoću vektora pokazivača na zaposlenike
b)    unutar klase Zaposlenik demonstrirajte enkapsulaciju tj. implementirajte metode za postavljanje i dohvat godina radnog staža tako da nova vrijednost može biti samo u intervalu [0, 35]. Ukoliko to pravilo nije zadovoljeno novu vrijednost samo treba ignorirati
c)    u klasi Tvrtka implementirajte kopirni konstruktor te demonstrirajte njegov poziv u funkciji main
d)    u klasi Tvrtka implementirajte operator pridruživanja sa dubokim kopiranjem te demonstrirajte njegov poziv u funkciju main
e)    u klasi Tvrtka implementirajte operator pridruživanja sa semantikom prijenosa te demonstrirajte njegov poziv u funkciji main
NAPOMENA: klasa tvrtka mora imati odgovarajući destruktor
*/

#include <iostream>
#include <vector>

using namespace std;

class Zaposlenik
{
private:
    int staz;

public:
    string ime, prezime;

    void setStaz(int _staz)
    {
        if (_staz >= 0 && staz <= 35)
        {
            staz = _staz;
        }
        else
        {
            cout << "Nesipravan staz\n";
        }
    }

    int getStaz()const
    {
        return staz;
    }
};
class Tvrtka
{
public:
    string oib, naziv, adresa;
    vector<Zaposlenik*> zaposlenici;

    Tvrtka() {}
    Tvrtka(string _naziv, string _adresa, string _oib)
    {
        naziv = _naziv;
        adresa = _adresa;
        oib = _oib;
    }

    void dodajZaposlenik(vector<Zaposlenik*>tmp)
    {
        for (int i = 0; i < tmp.size(); i++)
        {
            zaposlenici.push_back(new Zaposlenik);
            *zaposlenici[i] = *tmp[i];
        }
    }

    //kopirni konstruktor
    Tvrtka(const Tvrtka& tmp)
    {
        for (int i = 0; i < tmp.zaposlenici.size(); i++)
        {
            zaposlenici.push_back(new Zaposlenik);
            *zaposlenici[i] = *tmp.zaposlenici[i];
        }
        oib = tmp.oib;
        naziv = tmp.naziv;
        adresa = tmp.adresa;
    }

    //operator = (copy)
    Tvrtka& operator =(const Tvrtka& tmp)
    {
        if (this != &tmp)
        {
            for (int i = 0; i < zaposlenici.size(); i++)
            {
                delete zaposlenici[i];
            }
            zaposlenici.clear();

            for (int i = 0; i < tmp.zaposlenici.size(); i++)
            {
                zaposlenici.push_back(new Zaposlenik);
                *zaposlenici[i] = *tmp.zaposlenici[i];
            }
            oib = tmp.oib;
            naziv = tmp.naziv;
            adresa = tmp.adresa;
        }
        return *this;
    }

    //prijenosni konstruktor
    Tvrtka(Tvrtka&& tmp)
    {
        for (int i = 0; i < tmp.zaposlenici.size(); i++)
        {
            zaposlenici.push_back(tmp.zaposlenici[i]);
            tmp.zaposlenici[i] = NULL;
        }
        oib = tmp.oib;
        naziv = tmp.naziv;
        adresa = tmp.adresa;
    }
 
    //operator = (move)
    Tvrtka& operator =(Tvrtka&& tmp)
    {
        if (this != &tmp)
        {
            for (int i = 0; i < zaposlenici.size(); i++)
            {
                delete zaposlenici[i];
            }
            zaposlenici.clear();

            for (int i = 0; i < tmp.zaposlenici.size(); i++)
            {
                zaposlenici.push_back(tmp.zaposlenici[i]);
                tmp.zaposlenici[i] = NULL;
            }
            oib = tmp.oib;
            naziv = tmp.naziv;
            adresa = tmp.adresa;
        }
        return *this;
    }

    void ispisTvrtka()
    {
        cout << "Naziv: " << naziv << endl;
        cout << "Adresa: " << adresa << endl;
        cout << "OIB: " << oib << endl;

        for (int i = 0; i < zaposlenici.size(); i++)
        {
            cout << "\tIme: " << zaposlenici[i]->ime << " Prezime: " << zaposlenici[i]->prezime << " Staz: " << zaposlenici[i]->getStaz() << endl;
        }
    }

    ~Tvrtka()
    {
        for (int i = 0; i < zaposlenici.size(); i++)
        {
            delete zaposlenici[i];
        }
        zaposlenici.clear();
    }
};
int main()
{
    Zaposlenik zaposlenik1, zaposlenik2, zaposlenik3;
    vector <Zaposlenik*> zaposlenici1;

    zaposlenik1.ime = "Marko";
    zaposlenik1.prezime = "Markic";
    zaposlenik1.setStaz(15);

    zaposlenici1.push_back(new Zaposlenik);
    *zaposlenici1[0] = zaposlenik1;

    zaposlenik2.ime = "Ivan";
    zaposlenik2.prezime = "Ivic";
    zaposlenik2.setStaz(10);
    
    zaposlenici1.push_back(new Zaposlenik);
    *zaposlenici1[1] = zaposlenik2;

    zaposlenik3.ime = "Luka";
    zaposlenik3.prezime = "Lukic";
    zaposlenik3.setStaz(20);

    zaposlenici1.push_back(new Zaposlenik);
    *zaposlenici1[2] = zaposlenik3;

    Tvrtka tvrtka1("Tvrtka1 d.o.o.", "Zagrebacka 1", "1111111111111");
    tvrtka1.dodajZaposlenik(zaposlenici1);

    tvrtka1.ispisTvrtka();

    //kopirni konstruktor
    Tvrtka tvrtka2 = tvrtka1;
    tvrtka2.ispisTvrtka();

    //operator = (copy)
    Tvrtka tvrtka3("Tvrtka 3 d.o.o.", "Zagrebacka 3", "3333333333333"), tvrtka4("Tvrtka 4 d.o.o.", "Zagrebacka 4", "4444444444444");
    tvrtka3 = tvrtka4;
    
    tvrtka3.ispisTvrtka();

    //prijenosni konstruktor
    Tvrtka tvrtka5 = move(Tvrtka("Tvrtka 5 d.o.o.", "Zagrebacka 5", "5555555555555"));
    
    tvrtka5.ispisTvrtka();

    //operator = (move)
    Tvrtka tvrtka6;
    tvrtka6 = Tvrtka("Tvrtka 6 d.o.o.", "Zagrebacka 6", "666666666666");
    
    tvrtka6.ispisTvrtka();

    return 0;
}
