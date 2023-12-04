/*
tvrtki se koristi nekoliko različitih tipova računala, a ovo su njihove karakteristike:

Osobna računala - prosječni trošak po računalu: 5.000 kn
Prijenosna računala - prosječni trošak po računalu: 4.000 kn, od čega najviše ima laptopa sa prosječnom cijenom od 5.500 kn.

a)    Sukladno navedenoj specifikaciji deklarirajte sve potrebne klase i prikažite ispravan model nasljeđivanja.

b)    Svako računalo koristi samo jedan operacijski sustav čije ime (Windows, Linux ili nešto treće) treba inicijalizirati konstruktorom glavne bazne klase koja u konačnici mora biti realizirana kao apstraktna klasa. U funkciji main kreirajte novi objekt tipa PrijenosnoRacunalo na kojemu se koristi Linux operacijski sustav.

c)    Svako od računala podrazumijevano ima podatak o lokaciji na kojoj se nalazi, a on se vraća pozivom metode 'GetLokacija'. Za sva računala ova metoda podrazumijevano treba vratiti "Prostorija tvrtke". U klasama OsobnoRacunalo i PrijenosnoRacunalo implementirajte nadređenje (eng. override) te metode tako da vraćaju "U uredu zaposlenika" za klasu OsobnoRacunalo te "Na terenu" za klasu PrijenosnoRacunalo. Demonstrirajte pozive nadređenih metoda u funkciji main.

d)    Napišite globalnu funkciju
        double ProsjecniTrosak(vector<Racunalo(pointer)> tvrtka);

        koja treba vratiti ukupni prosječni trošak svih računala u predanom vektoru. U funkciji main testirajte i demonstrirajte poziv ove funkcije tako da u vektor smjestite adrese barem 3 objekta (računala) različitog tipa. Napomena: u funkciji ProsjecniTrosak potrebno je demonstrirati polimorfizam prilikom dohvata prosječnog troška pojedinog tipa računala.

e)    U funkciji main dodajte sljedeću pretvorbu na više:
        Racunalo (pointer) r = new Laptop("Windows");

        Prilikom dealokacije pokazivača 'r' potrebno je da se prvo izvrši destruktor klase Laptop, a zatim i destruktor klase Racunalo. Demonstrirajte u funkciji main. 

*/

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Racunalo {
protected:
    double prosijecniTrosak;
    string os;
    string lokacija = "Prostorija tvrtke";
public:
    Racunalo(string os) {
        this->os = os;
    }
    virtual string getLokacija() {
        return lokacija;
    }
    virtual double getProsjecniTrosak() = 0;
    virtual ~Racunalo(){
        cout << "Destruktor Racunala\n";
    }
};

class OsobnoRacunalo : public Racunalo {
public:
    OsobnoRacunalo(string os) : Racunalo(os) {
        prosijecniTrosak = 5000;
    }
    string getLokacija() override {
        this->lokacija = "U uredu zaposlenika";
        return lokacija;
    }
    double getProsjecniTrosak() override { return prosijecniTrosak; }
};

class PrijenosnoRacunalo : public Racunalo {
public:
    PrijenosnoRacunalo(string os) : Racunalo(os) {
        prosijecniTrosak = 4000;
    }
    string getLokacija() override final {
        this->lokacija = "Na terenu";
        return lokacija;
    }
    double getProsjecniTrosak() override { return prosijecniTrosak; }
};

class Laptop : public PrijenosnoRacunalo {
public:
    Laptop(string os) : PrijenosnoRacunalo(os) {
        prosijecniTrosak = 5500;
    }
    double getProsjecniTrosak() override final { return prosijecniTrosak; }
    ~Laptop() {
        cout << "Destruktor Laptopa\n";
    }
};

double ProsjecniTrosak(vector<Racunalo*> tvrtka) {
    double prosjecniTrosak = 0.0;
    for (auto r : tvrtka) 
        prosjecniTrosak += r->getProsjecniTrosak();
    prosjecniTrosak /= tvrtka.size();
    return prosjecniTrosak;
}


int main(){
    PrijenosnoRacunalo obj1("Linux");
    Laptop obj2("Windows");
    OsobnoRacunalo obj3("Red Star OS");

    vector<Racunalo*>racunala{ &obj1 , &obj2 ,&obj3 };

    for (auto r : racunala) {
        std::cout << r->getLokacija() << endl;
    }
    cout << ProsjecniTrosak(racunala) << endl;
    
    Racunalo* r = new Laptop("Windows");
    delete r;
}
