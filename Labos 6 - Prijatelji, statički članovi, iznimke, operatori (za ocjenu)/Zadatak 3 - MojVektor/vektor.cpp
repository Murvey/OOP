/*
Deklarirajte klasu 'MojVektor' koja predstavlja vektor realnih brojeva ciji su elementi smjesteni u privatnom dijelu klase. Zatim, realizirajte slijedece:
a)    u funkciji mani ispisite koliko postoji 'živih' instanci tipa MojVektor pozivom metode 'brojac' na slijedeci nacin:
cout << MojVektor::brojac() << endl
brojac se povecava za vrijednost 1 svaku put kada se kreira novi objekt tipa MojVektor, te se smanjuje za vrijednost 1 svaki put kada se objekt tog tipa uništi
b)    u klasi MojVektor implementirajte metodu getElement koja kao parametar ima indeks tj. cijeli broj. Ukoliko je indeks negativan broj metoda mora baciti iznimku tipa (fali tekst)
c)    implementirajte operaciju zbrajanja dva objekta tipa MojVektor kao neclansku operatorsku funkciju koja kao rezultat vraća novi vektor sa svim elementima prvog i drugog vektora
d)    implementirajte prefiks i postfiks operatora unutar klase MojVektor. oba operatora trebaju uvecati sve elemente vektora za 1
e)    preopteretite operator '<<' za ispis svih elemenata objekta tipa MojVektor, te operator '>>' te operator kojim se nova (ucitana) vrijednost dodaje tom vektoru
*/

#include <iostream>
#include <vector>

using namespace std;

class MojVektorException
{
public:
    int index;

    MojVektorException(int _index)
    {
        index = _index;
    }

    void ispis()
    {
        cout << "index ne moze biti negativan broj!" << endl;
    }
};
class MojVektor
{
private:
    vector<int> vektorBrojeva;
public:
    static int brVektora;

    friend vector<int> operator +(MojVektor vec1, MojVektor vec2);
    friend ostream& operator << (ostream& izlaz, MojVektor tmp);
    friend istream& operator >>(istream& ulaz, MojVektor& tmp);

    MojVektor() 
    {
        brVektora++;
    }
    MojVektor(vector<int>pom)
    {
        for (int i = 0; i < pom.size(); i++)
        {
            vektorBrojeva.push_back(pom[i]);
        }
        brVektora++;
    }

    static int brojac()
    {
        return brVektora;
    }

    int getElement(int index);

    MojVektor& operator++()
    {
        for (int i = 0; i < vektorBrojeva.size(); i++)
        {
            ++vektorBrojeva[i];
        }
        return *this;
    }
    MojVektor operator++(int)
    {
        MojVektor pom = *this;
        for (int i = 0; i < vektorBrojeva.size(); i++)
        {
            pom.vektorBrojeva.push_back(vektorBrojeva[i]++);
        }
        return pom;
    }
    ~MojVektor()
    {
        brVektora--;
    }
};
int MojVektor::brVektora = 0;

int MojVektor::getElement(int index)
{
    try
    {
        if (index < 0)
        {
            throw MojVektorException(index);
        }
        else
        {
            return vektorBrojeva[index];
        }
    }
    catch (MojVektorException tmp)
    {
        tmp.ispis();
    }
}

vector<int> operator +(MojVektor vec1, MojVektor vec2)
{
    vector<int>pom;

    for (int i = 0; i < vec1.vektorBrojeva.size(); i++)
    {
        pom.push_back(vec1.vektorBrojeva[i]);
    }
    for (int i = 0; i < vec2.vektorBrojeva.size(); i++)
    {
        pom.push_back(vec2.vektorBrojeva[i]);
    }

    return pom;
}

ostream& operator << (ostream& izlaz, MojVektor tmp)
{
    for (int i = 0; i < tmp.vektorBrojeva.size(); i++)
    {
        izlaz << tmp.vektorBrojeva[i] << " ";
    }
    izlaz << endl;
    return izlaz;
}

istream& operator >>(istream& ulaz, MojVektor& tmp)
{
    int n;
    ulaz >> n;
    tmp.vektorBrojeva.push_back(n);
    return ulaz;
}
int main()
{
    vector<int>vektor1 = { 1,3,5,7,9 };
    vector<int>vektor2 = { 2,4,6,8,10 };
    MojVektor mojVektor1(vektor1);
    MojVektor mojVektor2(vektor2);

    cout << MojVektor::brojac() << endl;

    int broj1 = mojVektor1.getElement(-2);
    broj1 = mojVektor1.getElement(0);

    cout << broj1 << endl;

    vector<int> vektor3 = mojVektor1 + mojVektor2;

    for (int i = 0; i < vektor3.size(); i++)
    {
        cout << vektor3[i] << " ";
    }
    cout << endl;
    
    mojVektor1++;
    cout << mojVektor1;
    cin >> mojVektor1;
    cout << "novi vektor:" << mojVektor1;
    return 0;
}
