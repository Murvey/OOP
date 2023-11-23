#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Knjiga {
public:
    string autor, naslov, tipKnjige , tezinaCitanja, recenzijaNaInternetu , jezik, id;
    Knjiga() {}
    Knjiga(string _autor, string _naslov, string _tipKnijge, string _tezinaCitanja,
        string _recenzijaNaInternetu, string _jezik, string _id) : autor(_autor), naslov(_naslov),
        tipKnjige(_tipKnijge), tezinaCitanja(_tezinaCitanja), recenzijaNaInternetu(_recenzijaNaInternetu)
        ,jezik(_jezik) , id(_id){
        cout << "Knjiga constructor called " << naslov << endl;
    }
    ~Knjiga() {
        cout << "Knjiga destructor called "<< naslov << endl;
    }
};

class Knjiznica {
private:
    string naziv, kategorija, adresa;
    vector<Knjiga> Knjige;
public:
    string getNaziv() const { return this->naziv; }
    string getKategorija() const { return this->kategorija; }
    string getAdresa() const { return this->adresa; }

    void dodajKnjigu1(Knjiga z) { Knjige.push_back(z); } // tri puta pozvan destruktor
    void dodajKnjigu2(Knjiga& z) { Knjige.push_back(z); } // jednom pozvan destruktor
    void dodajKnjigu3(Knjiga* z) { Knjige.push_back(*z); }// dva puta pozvan destruktor

    Knjiga nadjiKnjigu1(string _id) {
        Knjiga pom;
        for (int i = 0; i < Knjige.size(); i++) {
            if (Knjige[i].id == _id) {
                return Knjige[i];
            }
        }
        
    }
    Knjiga* nadjiKnjigu2(string _id) {
        Knjiga* pom = NULL;
        for (int i = 0; i < Knjige.size(); i++) {
            if (Knjige[i].id == _id) {
                return &Knjige[i];
            }
        }
        
    }
    Knjiga& nadjiKnjigu3(string _id) {
        Knjiga pom;
        for (int i = 0; i < Knjige.size(); i++) {
            if (Knjige[i].id == _id) {
                return Knjige[i];
            }
        }
    }

    void setNaziv(string naziv) {
        
        naziv[0] = toupper(naziv[0]);
        for (int i = 1; i < naziv.size(); i++) { 
            /*UKOMPONIRAJ MOGUCNOST NAZIVA S VISE RIJECI GDJE 
            SVAKA RIJEC POCINJE S VELIKIM SLOVOM ()*/
            naziv[i] = tolower(naziv[i]); 
        }
        this->naziv = naziv;
    };

    void setKategorija(string kategorija) {
        /* OVAJ DIO MOZES NAPRAVITI EFIKASNIJE ()
        -> Globani Vector stringova koji je konstantan
        -> Usporedujes string kategorija sa svakim elementom u globalnom vektoru
        -> Globalna funkcija Check koja provjerava jednakost
        -> U slucaju da string kategorija nije jedank ni jednom elementu funkcija
           check vraca false, inace vraca true
        */

        kategorija[0] = toupper(kategorija[0]);
        for (int i = 1; i < kategorija.size(); i++) { kategorija[i] = tolower(kategorija[i]); }
        /*OSIGURAVAMO DA KORISNIK BEZ OBZIRA NA VELIKO ILI MALO SLOVO UPISE KATEGORIJU*/

        if (kategorija == "Djecja" || kategorija == "Znanstvena"
            || kategorija == "Citaonica" || kategorija == "Opcenito") {
            this->kategorija = kategorija;
        }
    };
    void setAdresa(string adresa) { this->adresa = adresa; };

    void ispisSvihKnjiga() {
        for (int i = 0; i < Knjige.size(); i++) {
            cout <<"   " << i + 1 << ". Knjiga >\n" << "\t-Autor: " << Knjige[i].autor << endl << "\t-Naslov: " << Knjige[i].naslov << endl
                << "\t-Vrsta Knjige: " << Knjige[i].tipKnjige << endl << "\t-Zahtjevnost: " << Knjige[i].tezinaCitanja << endl << "\t-Ocjena recenzija: "
                << Knjige[i].recenzijaNaInternetu << endl << "\t-Jezik: " << Knjige[i].jezik << endl << "\t-Identifikacijski broj: " <<Knjige[i].id<<endl<< "\n";
        }
    }
};


int main(){
    Knjiga z1(string("Honore de balzac"), string("Otac Goriot"), string("Roman"), string("8 od 10"), string("10 od 10"), string("francuski"), string("0001"));
    Knjiga z2(string("Giovannija Boccaccia"), string("Dekameron"), string("Zbirka novela"), string("3 od 10"), string("9 od 10"), string("talijanski"), string("0002"));
    Knjiga z3(string("Miguel de Cervantes"), string("Don Kihot"), string("Roman"), string("7 od 10"), string("8,5 od 10"), string("spanjolski"), string("0003"));
    

    Knjiznica k;
    k.setAdresa("Trg Dragutina Domjanica 6, 10360, Sesvete");
    k.setNaziv("Knjznica sESVETE");
    k.setKategorija("oPCENITO");

    cout << "Adresa: " << k.getAdresa()<< endl;
    cout << "Naziv: " << k.getNaziv() << endl;
    cout << "Kategorija: " << k.getKategorija() << endl;
    
    k.dodajKnjigu1(z1);
    k.dodajKnjigu2(z2);
    k.dodajKnjigu3(&z3);
    //cout << 1000 << " || ";
    //for (int i = 0; i < k.Knjige.size(); i++) { cout << k.Knjige[i].naslov << " "; }
    cout << "\n";
    k.ispisSvihKnjiga();

    Knjiga izmjena1 = k.nadjiKnjigu1("0001");
    Knjiga* izmjena2 = k.nadjiKnjigu2("0002");
    Knjiga& izmjena3 = k.nadjiKnjigu3("0003");

    k.ispisSvihKnjiga();
    
    return 0;
}


