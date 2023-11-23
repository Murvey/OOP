/*
Podaci o putničkoj agenciji sadrže naziv, adresu te popis putnika koji putuju u zadanom trenutku. Podatak o putniku sadrži ime, prezime, destinaciju i cijenu putovanja.

a)    Deklarirajte klase 'Agencija' i 'Putnik' te njihove članove tako da se pomoću njih može opisati gore navedena specifikacija. Popis putnika u putničkoj agenciji realizirajte pomoću vektora pokazivača na putnike.

b)    Unutar klase Putnik demonstrirajte enkapsulaciju tj. implementirajte metode za postavljanje i dohvat cijene putovanja tako da nova vrijednost može biti samo u intervalu [0, 25000]. Ukoliko to pravilo nije zadovoljeno novu vrijednost treba ignorirati.

c)    U klasi Agencija implementirajte kopirni konstruktor te demonstrirajte njegov poziv u funkciji main.

d)    U klasi Agencija implementirajte prijenosni konstruktor te demonstrirajte njegov poziv u funkciji main.

e)    U klasi Agencija implementirajte operator pridruživanja sa semantikom prijenosa te demonstrirajte njegov poziv u funkciji main.

NAPOMENE:
-Klasa Agencija mora imati odgovarajući destruktor. U protivnom gubi se 0,5 bodova.
-Za rješavanje zadatka studenti mogu koristiti Visual Studio
-Studenti mogu pisati sav programski kod u istoj (jednoj) datoteci
-Konačno rješenje potrebno je predati kao tekst (copy/paste programskog koda)
*/

#include <iostream>
#include <vector>

using namespace std;

class Putnik
{
private:
    float cijena;

public:
    string ime, prezime, destinacija;

    Putnik() {}
    Putnik(string _ime, string _prezime, string _destinacija)
    {
        ime = _ime;
        prezime = _prezime;
        destinacija = _destinacija;
    }

    void setCijena(float _cijena)
    {
        if (cijena >= 0 && cijena <= 25000)
        {
            cijena = _cijena;
        }
        else
        {
            cout << "Cijena mora biti u intervalu [0 , 25 000]\n";
        }
    }

    float getCijena()const
    {
        return cijena;
    }
};
class Agencija
{
public:
    string naziv, adresa;
    vector<Putnik*> putnici;

    Agencija() {}
    Agencija(string _naziv, string _adresa)
    {
        naziv = _naziv;
        adresa = _adresa;
    }

    //kopirni konstruktor
    Agencija(const Agencija& tmp)
    {
        for (int i = 0; i < tmp.putnici.size(); i++)
        {
            putnici.push_back(new Putnik);
            *putnici[i] = *tmp.putnici[i];
        }
        naziv = tmp.naziv;
        adresa = tmp.adresa;
    }

    //operator = (copy)
    Agencija& operator =(const Agencija& tmp)
    {
        if (this != &tmp)
        {
            for (int i = 0; i < putnici.size(); i++)
            {
                delete putnici[i];
            }
            putnici.clear();

            for (int i = 0; i < tmp.putnici.size(); i++)
            {
                putnici.push_back(new Putnik);
                *putnici[i] = *tmp.putnici[i];
            }
            naziv = tmp.naziv;
            adresa = tmp.adresa;
        }
        return *this;
    }

    //prijenosni konstruktor
    Agencija(Agencija&& tmp)
    {
        for (int i = 0; i < tmp.putnici.size(); i++)
        {
            putnici.push_back(tmp.putnici[i]);
            tmp.putnici[i] = NULL;
        }
        naziv = tmp.naziv;
        adresa = tmp.adresa;
    }
 
    //operator = (move)

    Agencija& operator =(Agencija&& tmp)
    {
        if (this != &tmp)
        {
            for (int i = 0; i < putnici.size(); i++)
            {
                delete putnici[i];
            }
            putnici.clear();

            for (int i = 0; i < tmp.putnici.size(); i++)
            {
                putnici.push_back(tmp.putnici[i]);
                tmp.putnici[i] = NULL;
            }
            naziv = tmp.naziv;
            adresa = tmp.adresa;
        }
        return *this;

    }
    ~Agencija()
    {
        for (int i = 0; i < putnici.size(); i++)
        {
            delete putnici[i];
        }
        putnici.clear();
    }
};

int main()
{
    Agencija agencija1("Agencija 1", "Agencijska 1");

    //kopirni konstruktor
    Agencija agencija2 = agencija1;

    //operator = (copy)
    Agencija agencija3("Agencija3", "Agencijska 3"), agencija4("Agencija 4", "Agencijska 4");
    agencija3 = agencija4;

    //prijenosni konstruktor
    Agencija agencija5 = move(Agencija("Agencija 5", "Agencijska 5"));

    //operator = (move)
    Agencija agencija6;
    agencija6 = Agencija("Agencija6", "Agencijska 6");

    return 0;
}
