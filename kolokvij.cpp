#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

namespace Sastanak {
    class Odgovor {
    public:
        string tekst;
        Odgovor(string _tekst) :tekst(_tekst) {};
        Odgovor(){};
    };

    class Tocka {
    public:
        int broj;
        string red;
        string opis;
        Odgovor *nadodaj;
        //friend ostream& operator <<(ostream& os, Tocka t);

        Tocka(int _broj, string _red, string _opis) :broj(_broj), red(_red), opis(_opis) {};
        Tocka(int broj, string red, string _opis, Odgovor* odgovor){
            this->broj = broj;
            this->red = red;
            this->opis = opis;
            this->nadodaj = odgovor;
        };

        Tocka() {
            this->broj = 0;
            this->red = "Točka nula";
            this->opis = "Razno";
        };

        operator string() {
            return red + " - " + opis + "\n";
        }

        Tocka operator =(const Tocka& t) {
            this->broj = t.broj;
            this->opis = t.opis;
            this->red = t.red;
            return *this;
        }

        void odgovor() {
            this->opis = this->opis + this->nadodaj->tekst;
        }
    };

    void ispisi(vector<Tocka> vec) {
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i].broj << "\t";
        }
    }

    ostream& operator <<(ostream& os, Tocka t) {
        os << "Ad" << t.broj << ";" << t.red << ";" << t.opis;
        return os;
    }

    class NeispravnaTocka {
        string tekst;
    public:
        NeispravnaTocka(string _tekst) :tekst(_tekst) {};

        string what() {
            return tekst;
        }
    };

    bool operator<(Tocka a, Tocka b) {
        return a.broj < b.broj;
    }

    class ElementDnevnogReda : public Tocka {
    public:
        ElementDnevnogReda(int broj, string red, string opis) : Tocka(broj, red, opis) {};
        virtual string tekstualno() const = 0;
    };

}


    int main() {
        //1. zadatak
        using namespace Sastanak;

        //2. zadatak
        Tocka t1(1, "Tocka prva", "Citanje zapisnika");
        Tocka t2; // postavlja točku na: 0, "Točka 0", "Razno"
        Tocka t3(2, "Tocka druga", "Izvjesce povjerenika");
        Tocka t4(3, "Tocka treca", "Plan rada");
        vector<Tocka> tocke{ t1, t2, t3, t4 };

        // * ispisuje se "neispravna točka" 
        // (razred Tocka treba provjeravati jesu li svi podaci navedeni: redni broj, naziv i opis)
        // * razred NeispravnaTocka mora imati samo konstruktor koji prima tekst
        // poruke (nema drugih funkcija) i nasljeđivati od razreda "exception"

        NeispravnaTocka e("neispravna tocka");

        try {
            Tocka t(4, "Tocka cetvrta", "");// prazan opis - baca se iznimka
            if (t.opis == "" || t.red == "" || t.broj == NULL) {
                throw e;
            }
        }
        catch (NeispravnaTocka& e) {
            cout << e.what() << endl;
        };

        //zadatak 3.
        cout << (string)t1 << endl;  // ispisuje "Tocka prva - Citanje zapisnika"
        cout << t1 << endl;  // ispisuje "Ad1;Tocka prva;Citanje zapisnika"


        //4. zadatak
         // * ovdje upotrijebiti funkciju "sort" zaglavlja "algorithm"
        // * za razred Tocka treba definirati i kopirni operator pridruživanja

        sort(tocke.begin(), tocke.end());
        ispisi(tocke);  // ispisuje točke sortirane po rednom broju

        //5. zadatak
        // * ovdje upotrijebiti funkciju "sort" zaglavlja "algorithm"
        // * varijabla slaganje_tocaka mora sadrzavati lambda-izraz
        function<bool(Tocka, Tocka)> slaganje_tocaka = [](Tocka a, Tocka b) {return a < b; };
        sort(tocke.begin(), tocke.end(), slaganje_tocaka);
        ispisi(tocke);  // ispisuje točke sortirane po rednom broju obratnim redoslijedom

        /*/6. zadatak
        vector<ElementDnevnogReda*> red{ &t1, &t2, &t3, &t4 };
        sort(red.begin(), red.end(), usporedba_tocaka);

        // Funkcijom "tekstualno" demonstrirati polimorfizam; razred ElementDnevnogReda
        // mora biti apstraktan s jednom funkcijom "tekstualno"!

        // ispisuje točke sortirane po rednom broju
        for (vector<ElementDnevnogReda*>::const_iterator itr = red.begin();
            itr != red.end(); ++itr) { 
            cout << (*itr)->tekstualno() << endl;
        }*/

        //7. zadatak
        Tocka s(5, "Peta tocka", "Glasanje", new Odgovor("kolega A - za"));
        Tocka z = s;

        // nadovezuje tekst zadan s "nadodaj" s tekstom zadanim s konstruktoru
        s.odgovor()->nadodaj("kolega B - protiv");

        // ispisuje "kolega A - za; kolega B - protiv"
        cout << s.odgovor()->tekst() << endl;

        // ispisuje "kolega A - za"
        cout << z.odgovor()->tekst() << endl;

        return 0;
    }
