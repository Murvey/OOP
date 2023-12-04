/*
U Zoološkom vrtu živi nekoliko tipova životinja, a ovo su njihove karakteristike:

Pas - prosječna težina: 10kg
Riba - prosječna težina: 3.5kg. U Zoološkom vrtu najviše je zastupljena pod-vrsta ribe šaran prosječne težine 3kg

a) sukladno navedenoj specifikaciji deklarirajte sve potrebne klase i prikažite ispravan model nasljeđivanja.

b) Svaka životinja ima svoje ime a njega se treba inicijalizirati konstruktorom glavne bazne klase koja u konačnici mora biti realizirana kao apstraktna klasa. U funkciji main kreirajte novi objekt tipa Pas sa proizvoljnim imenom.

c) Svaka od životinja proizvoljno ima podatak o lokaciji, a on se vraća pozivom metode ‘GetLokacija’; Za sve životinje ova metoda podrazumno treba vratiti “ZOO”. U klasama Pas i Riba implementirajte nadređenje (eng. override) te metode tako da vraćaju “ZOO-dvorište” za klasu Pas, te “ZOO-bazen” za klasu Riba. Demonstrirajte pozive nadređenih metoda u funkciji main.

d) Napišite globalnu funkciju 
double ProsjecnaTezina(vector<Zivotinja(pointer)> zoo);
koja treba vratiti ukupno prosječnu težinu svih životinja u predanom vektoru. U funkciji main testirajte i demonstrirajte poziv ove funkcije tako da u vektor smjestite adrese barem 3 objekta (životinje) različitog tipa. Napomena: u funkciji ProsjecnaTezina potrebno je demonstrirati polimorfizam prilikom dohvata prosječne težine pojedinog tipa životinje.

e) U funkciji main dodajte sljedeću pretvorbu na više:
Zivotinja(pointer) z = new Pas(”Rex”);
Prilikom dealokacije pokazivača ‘z’ potrebno je da se prvo izvrši destruktor klase Pas, a zatim i destruktor klase Zivotinja. Demonstrirajte u funkciji main. 
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Zivotinja {
protected:
    double prosjecnaTezina;
    string ime;
public:
    Zivotinja(string ime) {
        this->ime = ime;
    }
    virtual string getLokacija() { return "ZOO"; }
    virtual double getProsjecnaTezina() = 0;
    virtual ~Zivotinja(){
        cout << "Zivotinja destruktor" << endl;
    }
};

class Pas : public Zivotinja {
public:
    Pas(string ime) : Zivotinja(ime) {
        prosjecnaTezina = 10.0;
    }
    string getLokacija() override { return "ZOO-dvoriste"; }
    double getProsjecnaTezina() override { return prosjecnaTezina; }
    virtual ~Pas() {
        cout << "Pas destruktor" << endl;
    }
};

class Riba : public Zivotinja {
public:
    Riba(string ime) : Zivotinja(ime) {
        prosjecnaTezina = 3.5;
    }
    string getLokacija() override { return "ZOO-bazen"; }
    double getProsjecnaTezina() override { return prosjecnaTezina; }
};

class Saran : public Riba {
public:
    Saran(string ime) : Riba(ime) {
        prosjecnaTezina = 3.0;
    }
    double getProsjecnaTezina() override { return prosjecnaTezina; }
};

double prosjecnaTezina(vector<Zivotinja*> zoo) {
    double prosjecnaTezina = 0.0;
    for (auto z : zoo) prosjecnaTezina += z->getProsjecnaTezina();
    return prosjecnaTezina / zoo.size();
}

int main(){
    Pas bubi("Bubi");
    Saran orgi("Orgi");
    Riba kmica("Kmica");

    cout<< orgi.getLokacija() << endl;
    cout<< bubi.getLokacija() << endl;

    vector<Zivotinja*> zoo = { &bubi,&kmica,&orgi };
    cout << prosjecnaTezina(zoo) << endl;

    Zivotinja* z = new Pas("Rex");
    delete z;
}
