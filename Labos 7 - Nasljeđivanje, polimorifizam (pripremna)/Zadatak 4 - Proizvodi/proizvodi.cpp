/*
Potrebno je napisati sve klase kako bi donji programski odsječak radio, uz ispravno modeliranje nasljeđivanja i polimorfizma.
Dodatno, potrebno je u klasi proizvod napraviti čistu virtualnu funkciju getKoefKvalitete() i pomoću nje pronaći koji proizvod iz vektora ima
najveći koeficijent kvalitete.

Za automobil, koeficijent se računa kao: 1.0 / (2015 - GOD_PROIZVODNJE) * maxBrzina / 100.0 * cijena / 100000.0;
Za lego igračku, računa se kao: brKomada / cijena.

int main()
{
vector<Proizvod*> vp = {
new LegoIgracka("Star Wars - Millenium Falcon", 2250.99, 756), //1. parametar = naziv, 2. parametar = cijena, 3. parametar = br. komada
new Automobil("BMW", 51230, 2013, 207.34), //1. parametar = naziv, 2. parametar = cijena, 3. parametar = god. proizvodnje, 4. parametar = max brzina
new LegoIgracka("Vlakic na upravljanje", 1750.99, 877),
new Automobil("Yugo 45", 14500, 1988, 127.88),
};

for (int i = 0; i < 4; i++){
vp[i]->print();
}


//Dodati kod za pronalazak proizvoda s najvećim koeficijentom i ispis tog proizvoda i odgovarajućeg koeficijenta.


return 0;
}


*/

#include<iostream>
#include<vector>
using namespace std;

class Proizvod {
protected:
	string naziv;
	double cijena;
public:
	Proizvod(string naziv, double cijena) {
		this->naziv = naziv;
		this->cijena = cijena;
	}
	virtual double getKoefKvalitete() = 0;
	virtual void print() = 0;
};

class Automobil : public Proizvod {
public:
	int godina;
	double brzina;
	Automobil(string naziv, double cijena, int godina, double brzina) :Proizvod(naziv, cijena) {
		this->godina = godina;
		this->brzina = brzina;
	}
	
	double getKoefKvalitete() {
		double koef = 1.0 / (2015 - godina) * brzina / 100.0 * cijena / 100000.0;
		return koef;
	}
	void print() {
		cout << "Naziv proizvoda - " << naziv << " , cijena proizvoda - " << cijena << " , godina proizvodnje automobila - " << godina << " , maksimalna brzina automobila - " << brzina << endl;
	}
};

class LegoIgracka : public Proizvod {
public:
	int brKomada;
	LegoIgracka(string naziv, double cijena, int brKomada) : Proizvod(naziv, cijena) {
		this->brKomada = brKomada;
	}
	
	double getKoefKvalitete() {
		double koef = brKomada / cijena;
		return koef;
	}
	void print() {
		cout << "Naziv proizvoda - " << naziv << " , cijena proizvoda - " << cijena << " , broj komada lego igracke - " << brKomada << endl;
	}
};

int main()
{
	vector<Proizvod*> vp = {
	new LegoIgracka("Star Wars - Millenium Falcon", 2250.99, 756), //1. parametar = naziv, 2. parametar = cijena, 3. parametar = br. komada
	new Automobil("BMW", 51230, 2013, 207.34), //1. parametar = naziv, 2. parametar = cijena, 3. parametar = god. proizvodnje, 4. parametar = max brzina
	new LegoIgracka("Vlakic na upravljanje", 1750.99, 877),
	new Automobil("Yugo 45", 14500, 1988, 127.88),
	};

	for (int i = 0; i < 4; i++) {
		vp[i]->print();
	}

	/*
	Dodati kod za pronalazak proizvoda s najvećim koeficijentom i ispis tog proizvoda i odgovarajućeg koeficijenta.
	*/
	Proizvod* najveci = NULL;
	double naj = 0.0;
	for (int i = 0; i < vp.size(); i++) {
		if (vp[i]->getKoefKvalitete() > naj) {
			naj = vp[i]->getKoefKvalitete();
			najveci = vp[i];
		}
	}

	cout << "Proizvod s najvecim koeficijentom kvalitete i njegov koeficijent je > " << endl;
	najveci->print();
	cout << najveci->getKoefKvalitete() << endl;
	return 0;
}
