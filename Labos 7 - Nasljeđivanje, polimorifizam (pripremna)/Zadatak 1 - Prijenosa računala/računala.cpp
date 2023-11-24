/*
U učionici se nalazi nekoliko prenosivih računala. Riječ je tablet i laptop računalima različitih proizvođača na kojima se nalaze različiti operacijski sustavi.
Slijedeći programski kod u nastavku napišite sve potrebne klase, metode i funkcije koje su potrebne da bi funkcija main radila kao što je to i predviđeno.

int main(){
    int brTableta, brLaptopa;
    int brAndroida, brWindowsa, brLinuxa;

    Tablet Acer("Android"), Prestigio("Windows");
    Laptop Dell("Linux"), IBM("Windows"), Toshiba("Windows");

    vector<Racunalo*> Ucionica1 = { &Acer, &Prestigio, &Dell, &IBM, &Toshiba };
    AnalizaUcionice(Ucionica1, &brTableta, &brLaptopa, &brAndroida, &brWindowsa, &brLinuxa);


    // u nastavku ispisite dobivenu analizu ucionice u sljedecem obliku:

    U ucionici se nalazi 5 racunala
    Broj tablet racunala : 2
    Broj laptop racunala : 3
    Android OS : 1
    Windows OS : 3
    Linux OS : 1
    //
    return 0;    
}

Napomena: Klasa Racunalo  je apstraktna - demonstrirati polimorfizam unutar funkcije AnalizaUcionice prilikom provjere tipa računala (tablet ili laptop).
*/

#include<iostream>
#include<vector>
using namespace std;

class Racunalo {
protected:
    //Članu sustav možemo pristupiti samo u klasni Racunalo i u izvedenim klasama
    //Razlog tome je postavljena vidljivost portected 
    string sustav;
public:
    Racunalo(string sustav) { this->sustav = sustav; }
    virtual string getSustav() = 0;
    virtual string getRacunalo() = 0;
    virtual void ispis() = 0;//Za provjeru polomorfizma u metodi AnalizaUcionice
};

class Tablet : public Racunalo{
public:
    //Konstruktor nasljeđuje člansku varijablu klase Racunalo
    //Pošto bazna klasa ima konstruktor mora imati i izvedena klasa konstruktor s istim parametrima
    //U slucaju ovog zadatka moguce je ne imati konstruktor u baznoj klasi
    Tablet(string sustav) : Racunalo(sustav){}
    string getRacunalo() {
        return "Tablet";
    }
    string getSustav() {
        return sustav;
    }
    //Za provjeru polomorfizma u metodi AnalizaUcionice
    void ispis() override{
        cout << "Tablet sa sustavom " << sustav << endl;
    }
};

class Laptop : public Racunalo {
public:
    //Konstruktor nasljeđuje člansku varijablu klase Racunalo
    //Pošto bazna klasa ima konstruktor mora imati i izvedena klasa konstruktor s istim parametrima
    //U slucaju ovog zadatka moguce je ne imati konstruktor u baznoj klasi
    Laptop(string sustav) : Racunalo(sustav) {}
    string getRacunalo() {
        return "Lapotop";
    }
    string getSustav() {
        return sustav;
    }
    //Za provjeru polomorfizma u metodi AnalizaUcionice
    void ispis() override{
        cout << "Lapotop sa sustavom " << sustav << endl;
    }
};
static void AnalizaUcionice(vector<Racunalo*> ucionica, int* brtableta, int* brlaptopa, int* brandroida, int* brwindowsa, int* brlinuxa) {
    int _brtableta = 0, _brlaptopa = 0, _brandroida = 0, _brwindowsa = 0, _brlinuxa = 0;
    for (int i = 0; i < ucionica.size(); i++) {
        if (ucionica[i]->getRacunalo() == "Tablet") { _brtableta++; ucionica[i]->ispis(); }
        else { _brlaptopa++; ucionica[i]->ispis();}

        if (ucionica[i]->getSustav() == "Windows") { _brwindowsa++; }
        else if (ucionica[i]->getSustav() == "Android") { _brandroida++; }
        else { _brlinuxa++; }
    }
    *brtableta = _brtableta, *brlaptopa = _brlaptopa, *brandroida = _brandroida, *brwindowsa = _brwindowsa, *brlinuxa = _brlinuxa;
}
int main() {
    int brTableta = 0, brLaptopa;
    int brAndroida, brWindowsa, brLinuxa;

    Tablet Acer("Android"), Prestigio("Windows");
    Laptop Dell("Linux"), IBM("Windows"), Toshiba("Windows");


    //Dolazi do polimorfizma - moramo paziti da zadovoljavamo uvjete
    //Moramo imati nasljeđivanje (klase Laptop i Tablet nasljeduju klasu racunalo)
    //Mora biti pretvorba na viši tip podatka
    //Mora postojati virtualna metoda u baznoj klasi
    
    vector<Racunalo*> Ucionica1 = { &Acer, &Prestigio, &Dell, &IBM, &Toshiba };
    AnalizaUcionice(Ucionica1, &brTableta, &brLaptopa, &brAndroida, &brWindowsa, &brLinuxa);

    
    /* u nastavku ispisite dobivenu analizu ucionice u sljedecem obliku:

    U ucionici se nalazi 5 racunala
    Broj tablet racunala : 2
    Broj laptop racunala : 3
    Android OS : 1
    Windows OS : 3
    Linux OS : 1
    */
    cout << endl << "U ucionici se nalazi " << Ucionica1.size() << " racunala" << endl;
    cout << "Broj tablet racunala : " << brTableta << endl;
    cout << "Broj laptop racunala : " << brLaptopa << endl;
    cout << "Android OS : " << brAndroida << endl;
    cout << "Windows OS : " << brWindowsa << endl;
    cout << "Linux OS : " << brLinuxa << endl;
    return 0;
}
