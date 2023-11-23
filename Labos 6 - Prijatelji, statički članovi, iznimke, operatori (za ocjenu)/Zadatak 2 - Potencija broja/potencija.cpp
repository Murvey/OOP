/*
Deklarirajte klasu 'PotencijaBroja' tako da su baza(broj) i njegova potencija u privatnom dijelu klase te se inicijalu konstruktorom koji ima dva parametra. Zatim, realizirajte slijedece:

a)    Ispisite koliko postoji potencija (objekata tipa PotencijaBroja) koji su prilikom kreiranja tih objekata mogli predstaviti prirodnim brojevima (pozitivnim cijelim brojem bez ostatka). npr. potencija 16e1/4(4. korijen od 16) mogla se predstaviti prirodnim brojem 2. U funkciji main ispisati trazenu kolicinu pozivom metode 'brojac' na slijedeci nacin
cout << PotencijaBroja::brojac() << endl;
b)    u klasi potencija broja deklarirajte metodu SetPotencija koja kao parametar ima realni broj. Ukoliko je potencija negativan broj izbaciti iznimku tipa 'PotencijaBrojaException', a u protivnom potrebno je postaviti potenciju baze (broja) na zadanu vrijednost. Metodu SetPotencija implementirajte van klase, a u funkciji main demonstrirajte njen poziv gdje se prilikom hvatanja iznimke treba izvrsiti metoda 'ispis'  klase 'PotencijaBrojaException' koja će ispisati odgovarajuću poruku korisniku
c)    implementirajte operaciju zbrajanja dva objekta tipa PotencijaBroja kao neclansku operatorsku funkciju koja kao rezultat vraca realan broj, te demonstrirajte njen poziv u funkciji main. Baza i potencija broja moraju ostati privatni u klasi PotencijaBroja
d)    implementirajte prefiks i postfiks operatore unutar klase PotencijaBroja. Oba operatora trebaju trebaju uvecati potenciju broja za vrijednost 1;
e)    preopteretite operatore '<<' i '>>' za ispis i unos objekta tipa PotencijaBroja

*/

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class PotencijaBrojaException
{
public:
    double potencija;

    PotencijaBrojaException(double _potencija)
    {
        potencija = _potencija;
    }

    void ispis()
    {
        cout << "Potencija mora biti pozitivan broj" << endl;
    }
};

class PotencijaBroja
{
private:
    int baza;
    double potencija;

public:
    static int brPrirodnihBrojeva;
    friend double operator +(PotencijaBroja br1, PotencijaBroja br2);
    friend ostream& operator <<(ostream& izlaz, PotencijaBroja tmp);
    friend istream& operator >>(istream& ulaz, PotencijaBroja& tmp);

    PotencijaBroja() {}
    PotencijaBroja(int _baza, double _potencija)
    {
        baza = _baza;
        potencija = _potencija;
        int tmp = pow(baza, potencija);
        float razlika = pow(baza, potencija) - tmp;
        if (razlika == 0.0)
        {
            brPrirodnihBrojeva++;
        }
        
    }
    void SetPotencija(double _potencija);

    static int brojac()
    {
        return brPrirodnihBrojeva;
    }

    PotencijaBroja& operator++()
    {
        potencija++;
        return *this;
    }
    PotencijaBroja& operator ++(int)
    {
        PotencijaBroja pom = *this;
        potencija++;
        return pom;
    }
    ~PotencijaBroja()
    {
        int tmp = pow(baza, potencija);
        float razlika = pow(baza, potencija) - tmp;
        if (razlika == 0.0)
        {
            brPrirodnihBrojeva--;
        }

    }
};
int PotencijaBroja::brPrirodnihBrojeva = 0;

void PotencijaBroja::SetPotencija(double _potencija)
{
    try
    {
        if (_potencija <= 0)
        {
            throw PotencijaBrojaException(_potencija);
        }
        else
        {
            int tmpBr = pow(baza, potencija);
            float razlika = pow(baza, potencija) - tmpBr;
            if (razlika == 0.0)
            {
                brPrirodnihBrojeva--;
            }
            tmpBr = pow(baza, _potencija);
            razlika = pow(baza, _potencija) - tmpBr;
            if (razlika == 0.0)
            {
                brPrirodnihBrojeva++;
            }

            potencija = _potencija;
        }
    }
    catch (PotencijaBrojaException tmp)
    {
        tmp.ispis();
    }
}

double operator + (PotencijaBroja br1, PotencijaBroja br2)
{
    return pow(br1.baza, br1.potencija) + pow(br2.baza, br2.potencija);
}

ostream& operator<<(ostream& izlaz, PotencijaBroja tmp)
{
    izlaz << pow(tmp.baza, tmp.potencija);
    return izlaz;
}

istream& operator >>(istream& ulaz, PotencijaBroja& tmp)
{
    ulaz >> tmp.baza >> tmp.potencija;
    return ulaz;
}
int main()
{
    PotencijaBroja broj1(16, 1.0 / 4);
    PotencijaBroja broj2(27, 1.0 / 3);
    PotencijaBroja broj3(15, 1.0 / 2);

    cout << PotencijaBroja::brojac() << endl;

    broj1.SetPotencija(-2.0);
    broj1.SetPotencija(1.0 / 5.0);

    cout << PotencijaBroja::brojac() << endl;

    cout << broj1 + broj2 << endl;

    broj1++;

    cout << broj1 << endl;

    ++broj1;
    cout << broj1 << endl;

    PotencijaBroja broj4;

    cin >> broj4;
    cout << broj4;

    return 0;
}
