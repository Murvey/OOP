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
