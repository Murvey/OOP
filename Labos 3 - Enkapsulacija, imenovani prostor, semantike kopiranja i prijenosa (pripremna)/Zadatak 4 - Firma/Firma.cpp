#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Zaposlenik {
private:
	string ime, prezime, IDnumber;
	
public:
	Zaposlenik() {
		cout << "Zaposlenik constructor called" << endl;
	}
	~Zaposlenik() {
		cout << "Zaposlenik " << ime << " " << prezime << " " << IDnumber << " " << "destructor called" << endl;
	}

	void setIme(string _ime) {
		ime = _ime;
	}

	void setPrezime(string _prezime) {
		prezime = _prezime;
	}

	void setID(string _IDnumber) {
		IDnumber = _IDnumber;
	}

	string getIme() const {
		return ime;
	}
	string getPrezime() const {
		return prezime;
	}
	string getIDnumber() const {
		return IDnumber;
	}
};

class Firma {
private:
	string naziv;
	string OIB;
	string adresa;
	vector<Zaposlenik> zaposlenici;
public:

	/*Set Funkcija za atribut(Clanski podatak) NAZIV tipa string*/
	void setNaziv(string _naziv) {
		if (_naziv.size() < 5) {
			while (_naziv.size() < 5) {
				/*INACE u zadatku pise odustati od ponovnog unosa sto znaci bez while petlje,
				ali ovako je lakse testiranje funkcionalnosti koda */
				cout << "Neispravan naziv firme. Naziv firme mora imati minimalno 5 znakova!" << endl;
				cout << "Ponovno unesite naziv firme > ";
				cin >> _naziv;
			};
		}
		else {
			naziv = _naziv;
		}
	}

	/* ----------------------- PREGLEDNOST ------------------ */
	/*Set Funkcija za atribut(Clanski podatak) OIB tipa string*/
	void setOIB(string _OIB) {
		if (_OIB.size() == 11*sizeof(char)) {
			OIB = _OIB;
		}
		else {
			while (_OIB.size() != 11 ) {
				/*INACE u zadatku pise odustati od ponovnog unosa sto znaci bez while petlje,
				ali ovako je lakse testiranje funkcionalnosti koda */
				cout << "Neispravan OIB firme. OIB firme mora sadrzavati tocno 11 znamenki!" << endl;
				cout << "Ponovno unesite OIB firme > ";
				cin >> _OIB;
			};
		}
	}

	/* ----------------------- PREGLEDNOST ------------------ */
	/*Set Funkcija za atribut(Clanski podatak) ADRESA tipa string*/
	void setAdresa(string _adresa) {
		adresa = _adresa;
	}

	/*Get funkcija za atribut Naziv tipa string */
	/*Deklaracijom const prije tijela metode getNaziv naglašavamo da konstantni objekti tipa
	Firma mogu pozvati metodu getNaziv jer ona neće mijenjati stanje tog objekta*/
	string getNaziv() const {
		return naziv;
	}

	/*Get funkcija za atribut OIB tipa string */
	string getOIB() const {
		return OIB;
	}

	/*Get funkcija za atribut Adresa tipa string */
	string getAdresa() const {
		return adresa;
	}

	void dodajZaposlenika1(Zaposlenik z) {
		zaposlenici.push_back(z);
	}

	void dodajZaposlenika2(Zaposlenik &z) {
		zaposlenici.push_back(z);
	}

	void dodajZaposlenika3(Zaposlenik* z) {
		zaposlenici.push_back(*z);
	}

	void ispisSvihZaposlenika() {
		for (int i = 0; i < zaposlenici.size(); i++) {
			cout << "Zaposlenik broj " << i + 1 << " > " << endl << "\t" << "Ime:  " << zaposlenici[i].getIme()
				<< endl << "\t" << "Prezime:  " << zaposlenici[i].getPrezime()
				<< endl << "\t" << "ID:  " << zaposlenici[i].getIDnumber() << endl;
		}
	}

	Zaposlenik nadjiZaposlenika1(string ime, string prezime) {
		for (int i = 0; i < zaposlenici.size(); i++) {
			if (zaposlenici[i].getIme() == ime && zaposlenici[i].getPrezime() == prezime) {
				return zaposlenici[i];
			}
		}
	}

	Zaposlenik* nadjiZaposlenika2(string ime, string prezime) {
		Zaposlenik* zap = NULL;
		for (int i = 0; i < zaposlenici.size(); i++) {
			if (zaposlenici[i].getIme() == ime && zaposlenici[i].getPrezime() == prezime) {
				return &zaposlenici[i];
			}
		}
	}

	Zaposlenik& nadjiZaposlenika3(string ime, string prezime) {
		for (int i = 0; i < zaposlenici.size(); i++) {
			if (zaposlenici[i].getIme() == ime && zaposlenici[i].getPrezime() == prezime) {
				return zaposlenici[i];
			}
		}
	}

};
int main() {
	Firma firma;
	string imeFirme, OIBFirme, adresaFirme;

	cout << "Unesite naziv firme > ";
	cin >> imeFirme;
	firma.setNaziv(imeFirme);
	
	cout << "Unesite OIB firme > ";
	cin >> OIBFirme;
	firma.setOIB(OIBFirme);

	cout << "Unesite adresu firme > ";
	cin >> adresaFirme;
	firma.setAdresa(adresaFirme);
	cin.clear();

	int br;
	cout << "Upisite broj zaposlenika > ";
	cin >> br;
	
	for (int i = 0; i < br; i++) {
		string ime, prezime, id;
		cout << "Upisite ime, prezime i ID broj za " << i + 1 << ". zaposlenika > ";
		cin >> ime >> prezime >> id;
		Zaposlenik zap;
		zap.setIme(ime);
		zap.setPrezime(prezime);
		zap.setID(id);
		if (i == 0) {
			firma.dodajZaposlenika1(zap);
		}
		else if (i == 1) {
			firma.dodajZaposlenika2(zap);
		}
		else {
			firma.dodajZaposlenika3(&zap);
		}
	}

	firma.ispisSvihZaposlenika();
	Zaposlenik prvi,drugi,treci;
	prvi.setIme("Pero");
	prvi.setPrezime("Preic");
	prvi.setID("0004");

	drugi.setIme("Ivo");
	drugi.setPrezime("Ivic");
	drugi.setID("0005");

	treci.setIme("Ana");
	treci.setPrezime("Anic");
	treci.setID("0006");

	firma.dodajZaposlenika3(&prvi);
	firma.dodajZaposlenika3(&drugi);
	firma.dodajZaposlenika3(&treci);

	Zaposlenik izmjena1 = firma.nadjiZaposlenika1(prvi.getIme(), prvi.getPrezime());
	izmjena1.setID("0021");
	Zaposlenik* izmjena2 = firma.nadjiZaposlenika2(drugi.getIme(), drugi.getPrezime());
	izmjena2->setID("0022");
	Zaposlenik& izmjena3 = firma.nadjiZaposlenika3(treci.getIme(), treci.getPrezime());
	izmjena3.setID("0023");
	firma.ispisSvihZaposlenika();
	return 0;
};
