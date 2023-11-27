/*
Potrebno je napraviti ispravne klase kako bi donji programski odsječak funkcionirao ispravno. Potrebno je modelirati nasljeđivanje,te osigurati da postoji apstraktna klasa u modelu (ispravno odabrati metodu koja je čista virtualna).

Dodatno, plaća za se računa na način da se osnovici plaće pribroje bonusi:

za igrača, svaki 10. gol donosi 10% osnovice kao bonus; dok svaka 5. asistencija donosi isto 10% osnovice kao bonus
za trenera, svaka 5. pobjeda donosi bonus od 10% osnovice, svaki 10. remi (nerijeseno) donosi isto 10% osnovice, dok se za svaki 8. poraz skida 10% osnovice
za detalje, pogledati primjere ispisa koda
int main()
{
Igrac i("Luka", "Modric", 100000); //Ime, prezime, osnovica plaće
i.dodajGolove(7);
i.dodajAsistencije(12);
i.ispis(); //Luka Modric - golova: 7, asistencija: 12
cout << "Placa: " << i.izracunPlace() << endl; //Placa: 120000

Igrac i2("C", "Ronaldo", 234505);
i2.dodajGolove(57);
i2.dodajAsistencije(32);
i2.ispis(); //C Ronaldo - Golova : 57, Asistencije : 32.
cout << "Placa: " << i2.izracunPlace() << endl; //Placa : 492461

Trener t1("Hose", "Murinjo", 143009); //Ime, prezime, osnovica plaće
t1.dodajPobjede(88); //Dodati broj pobjeda (W)
t1.dodajRemi(12); //Dodati broj neriješenih utakmica (D)
t1.dodajIzgubljene(0); //Dodati broj izgubljenih (L)
t1.ispis(); //Hose Murinjo - Omjer (W/D/L): 88 / 12 / 0
cout << "Placa: " << t1.izracunPlace() << endl; //Placa: 400425

t1.dodajPobjede(11);
t1.dodajIzgubljene(47);
t1.ispis(); //Hose Murinjo - Omjer (W/D/L): 99 / 12 / 47
cout << "Placa: " << t1.izracunPlace() << endl; //Placa: 357523

}



Demonstrirajte polimorfizam u funkciji main.
*/

#include<iostream>
using namespace std;

class Osoba {
protected:
	string ime, prezime;
	int osnovica;
public:
	Osoba(string ime, string prezime, int osnovica) { 
		this->ime = ime;
		this->prezime = prezime;
		this->osnovica = osnovica;
	}
	virtual int izracunPlace() = 0;
	virtual void ispis() = 0;
};


class Igrac : public Osoba{
private:
	int golovi = 0, asistencije = 0;
public:
	Igrac(string ime, string prezime, int osnovica) :Osoba(ime, prezime, osnovica) {}
	
	

	void dodajGolove(int a) {
		this->golovi += a;
	}

	void dodajAsistencije(int a) {
		this->asistencije += a;
	}

	void ispis() {
		cout << ime << " " << prezime << " - Golova : " << golovi << ", Asistencija : " << asistencije << endl;
	}

	int izracunPlace() {
		int placa = round(((double(golovi / 10) / 10 + double(asistencije / 5) / 10) + 1) * osnovica);

		return placa;
	}
};

class Trener : public Osoba {
	int pobjede = 0, remi = 0, izgubljene = 0;
public:
	Trener(string ime, string prezime, int osnovica) :Osoba(ime, prezime, osnovica) {}
	
	void dodajPobjede(int a) {
		this->pobjede += a;
	}

	void dodajRemi(int a) {
		this->remi += a;
	}

	void dodajIzgubljene(int a) {
		this->izgubljene += a;
	}

	void ispis() {
		cout << ime << " " << prezime << " - Omjer (W/D/L) : " << pobjede << " / " << remi << " / " << izgubljene << " " << (double(pobjede / 5) / 10 + double(remi / 10) / 10 - double(izgubljene / 8) / 10) << endl;
	}

	int izracunPlace() {
		int placa = round(((double(pobjede / 5) / 10 + double(remi / 10) / 10 - double(izgubljene / 8) / 10) + 1) * osnovica);
		return placa;
	}
};


int main()
{
	Igrac i("Luka", "Modric", 100000); //Ime, prezime, osnovica plaće
	i.dodajGolove(7);
	i.dodajAsistencije(12);
	i.ispis(); //Luka Modric - golova: 7, asistencija: 12
	cout << "Placa: " << i.izracunPlace()  << endl; //Placa: 120000

	Igrac i2("C", "Ronaldo", 234505);
	i2.dodajGolove(57);
	i2.dodajAsistencije(32);
	i2.ispis(); //C Ronaldo - Golova : 57, Asistencije : 32.
	cout << "Placa: " << i2.izracunPlace() << endl ; //Placa : 492461

	Trener t1("Hose", "Murinjo", 143009); //Ime, prezime, osnovica plaće
	t1.dodajPobjede(88); //Dodati broj pobjeda (W)
	t1.dodajRemi(12); //Dodati broj neriješenih utakmica (D)
	t1.dodajIzgubljene(0); //Dodati broj izgubljenih (L)
	t1.ispis(); //Hose Murinjo - Omjer (W/D/L): 88 / 12 / 0
	cout << "Placa: " << t1.izracunPlace() << endl; //Placa: 400425

	t1.dodajPobjede(11);
	t1.dodajIzgubljene(47);
	t1.ispis(); //Hose Murinjo - Omjer (W/D/L): 99 / 12 / 47
	cout << "Placa: " << t1.izracunPlace() << endl; //Placa: 357523

}

