#include <iostream>
using namespace std;

class Razlomak {
    int brojnik, nazivnik;
    static int counter;
public:
    Razlomak(int _brojnik, int _nazivnik) :brojnik(_brojnik), nazivnik(_nazivnik) {
        if (brojnik / nazivnik == 0) {
            counter++;
        }
    };

    static int brojac() {
        return counter;
    }

    void SetNazivnik(int br);

};

int Razlomak::counter = 0;

void Razlomak :: SetNazivnik(int br) {
    try {
        if (br == 0) {
            throw "RazlomakException";
        }
        nazivnik = br;
    }
    catch (const char* Iznimka) {
        cout << "Iznimka:" << Iznimka;
    }
}

int main() {
    Razlomak A(2, 3);
    A.SetNazivnik(0);

    return 0;
}
