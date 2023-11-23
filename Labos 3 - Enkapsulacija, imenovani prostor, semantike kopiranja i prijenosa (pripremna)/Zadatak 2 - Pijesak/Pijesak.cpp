/*
Za klasu Pijesak napišite konstruktore i operatore pridruživanja s semantikom kopiranja i semantikom prijenosa. U funkciji main demonstrirajte njihove pozive.

 

#include <iostream>

#include <string>

using namespace std;

 

class Zrno{

public:

       string boja;

       float promjer;

};

class Pijesak{

public:

       int kolicina;

       Zrno* zrno;

       Pijesak(int _kolicina) : kolicina(_kolicina){

             // dinamički alocirajte polje 'zrno'

       }

       ~Pijesak(){

             // ?

       }

};

int main(){

       Pijesak igraliste(1000000);

       cout << "Na igralistu ima " << igraliste.kolicina << " zrna pijeska!\n";

 

       // Demonstrirajte pozive oba konstruktora i oba operatora pridruživanja

       return 0;

}
*/

#include <iostream>
#include <string>
using namespace std;
/*Za klasu Pijesak napišite konstruktore i operatore pridruživanja s 
semantikom kopiranja i semantikom prijenosa. U funkciji main demonstrirajte
njihove pozive.*/
class Zrno {
public:
    string boja;
    float promjer;
    Zrno() {}
};
class Pijesak {
public:
    int kolicina;
    Zrno* zrno;
    Pijesak(int _kolicina) : kolicina(_kolicina) {
        // dinamički alocirajte polje 'zrno'
        zrno = new Zrno[kolicina];
    }
    Pijesak(const Pijesak& z) {
        zrno = new Zrno[z.kolicina];
        for (int i = 0; i < z.kolicina;i++) {
            zrno[i] = z.zrno[i];
        }
        kolicina = z.kolicina;

        cout << "kopirni konstruktor\n";
    }

    Pijesak& operator =(const Pijesak& z) {
        if (this != &z) {
            delete[] zrno;
            zrno = new Zrno[z.kolicina];
            for (int i = 0; i < z.kolicina; i++) {
                zrno[i] = z.zrno[i];
            }
            kolicina = z.kolicina;

            cout << "operator = (kopirni) \n";
        }

        return *this;
    }

    Pijesak(Pijesak&& z) {
        zrno = z.zrno;
        z.zrno = NULL;
        kolicina = z.kolicina;
        cout << "Konstruktor prijenosa \n";
    }

    Pijesak& operator =(Pijesak&& z) {
        if (this != &z) {
            delete[] zrno;
            zrno = z.zrno;
            z.zrno = NULL;
            kolicina = z.kolicina;
            cout << "operator = (prijenosni) \n";
        }
        return *this;
    }

    ~Pijesak() {
        // ?
        delete[] zrno;
    }
};
int main() {
    Pijesak igraliste(1000000);
    cout << "Na igralistu ima " << igraliste.kolicina << " zrna pijeska!\n";

    // Demonstrirajte pozive oba konstruktora i oba operatora pridruživanja
    Pijesak plaza = igraliste;

    Pijesak cement(100);
    cement = plaza;
    cout << plaza.zrno << endl;

    Pijesak plaza2 = move(Pijesak(500));

    Pijesak otok(10);
    otok = Pijesak(600);
    cout << "|||| " << plaza.zrno << "|||| ";
    return 0;
}
