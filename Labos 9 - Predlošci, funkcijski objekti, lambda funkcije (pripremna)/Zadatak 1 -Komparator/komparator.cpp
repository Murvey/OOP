/*
a) Napišite klasu "Komparator" koja ima jedan generički parametar T i metodu 

"vece_ili_jednako" koja ima dva parametra tipa T i koja vraća rezultat 

usporedbe tih dvaju parametara operacijom >=.



b) Napišite zaglavlje funkcije "usporedi" koja ima jedan generički parametar 

P koji označava tip elemenata u vektoru. Isto tako, funkcija treba imati dva 

parametra: prvi je vektor s elementima tipa P koje uspoređujemo (vector<P>), a 

drugi objekt klase "Komparator" koja radi s elementima tipa P (Komparator<P>). 



c) Upotrebom objekta tipa Komparator i njegove metode "vece_ili_jednako" 

funkcija "usporedi" treba vratiti 0 ako elementi u vektoru nisu poslagani 

u opadajućem redoslijedu, odnosno 1 ako jesu.



d) Upotreba funkcije "usporedi" treba izgledati ovako:



vector<int> v = {12, 2, 1};

bool r = usporedi<int>(v, Komparator<int>());

cout << "rezultat: " << r << endl;  // treba ispisati 1



e) Implementirajte metodu "usporedi" tako da radi s bilo kojom klasom koja ima

metodu "vece_ili_jednako" povratnog tipa bool, s dva parametra (to jest, ne 

radi samo s klasom Komparator).
*/

#include<iostream>
#include<vector>
using namespace std;

template<class T> class Komparator {
public:
	bool vece_ili_jednako(T tmp1,T tmp2) {
		
		if (tmp1 >= tmp2) {
			return true;
		}
		else {
			return false;
		}
	}

};
template<class P, class K> bool usporedi(vector<P> tmp1, K tmp2) {
	int counter = 0;
	for (int i = 1; i < tmp1.size(); i++) {
		if (tmp2.vece_ili_jednako(tmp1[i - 1], tmp1[i])) {
			counter++;
		}
	}
	if (counter == tmp1.size() - 1) {
		return 1;

	}
	else {
		return 0;
	}
}
int main() {
	vector<int> v = { 12, 2, 1 };

	bool r = usporedi<int>(v, Komparator<int>());

	cout << "rezultat: " << r << endl;  // treba ispisati 1
	return 0;
}
