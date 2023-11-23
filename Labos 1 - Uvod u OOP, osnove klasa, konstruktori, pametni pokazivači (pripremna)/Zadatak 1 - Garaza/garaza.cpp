/*
Vlasnik ste niza garaža u velegradu Zagrebu i iznajmljujete ih za razumnu cijenu, i već vam je pomalo nespretno voditi evidenciju o tome koje sve garaže postoje i tko ima koje ključeve, pa ste se odlučili baciti na posao i napraviti C++ program koji će vam u tome pomoći.

Odlučili ste definirati niz garaža, i u svakoj garaži bilježiti niz ključeva koji su vaši (kako vam ne bi nestali).

Klasa Garaza ima sljedeća svojstva:

veličinu (širina x duljina)
cijenu iznajmljivanja
lokaciju
niz ključeva koji su vaši
Klasa Kljuc ima sljedeća svojstva:

ime i prezime osobe kod koje je ključ
U main programu potrebno je od korisnika tražiti unos broja N, nakon kojeg se unose podaci o N garaža. Nakon što se unesu sva polja, potrebno je tražiti unos broja M, koji označava broj ključeva, te je potrebno unijeti tih M ključeva (neka garaža može imati više ključeva).

Primjer izvođenja:

Unesite broj garaža (N):2
 Unesite velicinu, lokaciju i cijenu za 1. garazu:
 10 20
 Konavoska 3
 500
 Unesite velicinu, lokaciju i cijenu 2. garazu:
 15 25
 Konavoska 3b
 440
 Unesite broj kljuceva (M): 1
 Unesite redni broj garaze kojoj pripada 1. kljuc: 2
 Unesite ime vlasnika kljuca: Ana Anic
 
 Ispis garaza i kljuceva:
 
Konavoska 3 10x20 - kljucevi:
Konavoska 3b 15x25 - kljucevi: Ana Anic
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class kljuc {
public:
	string ime, prezime;
};
class velicina {
public:
	int sirina, duljina;
};
class lokacija {
public:
	string adresa;
	string adresniBroj;
};
class Garaza {
public:
	velicina velicina;
	int cijena;
	lokacija lokacija;
	vector<kljuc> kljucevi;
};

int main() {
	int N;
	cout << "Unesite broj garaža (N):";
	cin >> N;

	vector<Garaza> garaze;

	for (int i = 0; i < N; i++) {
		Garaza garaza;

		cout << "Unseite velicinu, lokaciju i cijenu za " << (i + 1) << ". garazu:" << " \n";
		cin >> garaza.velicina.sirina >> garaza.velicina.duljina;
		cin >> garaza.lokacija.adresa >> garaza.lokacija.adresniBroj;
		cin >> garaza.cijena;

		garaze.push_back(garaza);
	}

	int M;
	cout << "Unesite broj kljuceva (M): ";
	cin >> M;

	int redniBr;
	for (int i = 0; i < M; i++) {
		kljuc kljuc;
		cout << "Unesite redni broj garaze kojoj pripada " << (i + 1) << ". kljuc: ";
		cin >> redniBr;

		cout << "Unesite ime vlasnika kljuca: ";
		cin >> kljuc.ime;
		cin >> kljuc.prezime;

		garaze[redniBr - 1].kljucevi.push_back(kljuc);
	}

	cout << "\n" << "Ispis garaza i kljuceva:" << "\n";

	for (int i = 0; i < N; i++) {
		cout << (i + 1) << ". " << garaze[i].lokacija.adresa << " " << garaze[i].lokacija.adresniBroj << " " << garaze[i].velicina.sirina
			<< "x" << garaze[i].velicina.duljina << " - kljucevi: ";
		for (int j = 0; j < garaze[i].kljucevi.size(); j++) {
			cout << garaze[i].kljucevi[j].ime << " " << garaze[i].kljucevi[j].prezime;
		}
		cout << "\n";
	}

	return 0;
}
