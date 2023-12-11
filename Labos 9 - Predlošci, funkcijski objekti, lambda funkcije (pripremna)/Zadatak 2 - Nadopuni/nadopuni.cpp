/*
Potrebno je nadopuniti donji programski odsječak na način da napišete funkciju "izdvoji", za koju vrijedi sljedeće:

vraća vector<int> (novi vektor)
prvi argument: vector<int>&
drugi argument: funkcija
Funkcija izdvoji mora iz vektora "brojevi" izdvojiti samo one koji su djeljivi s 3. Drugi argument funkcije potrebno je poslati kao lambda izraz (nadopuniti).

int main()
{
vector<int> brojevi = {1, 4, 5, 7, 3, 6, 12, 65, 32, 8, 87, 55, 23, 22, 1, 1, 433, 66, 7, 433, 3, 32, 76, 8, 72, 256, 42};

vector<int> rez = izdvoji(brojevi, /*lambda izraz*//*);

for (int i = 0; i < rez.size(); i++)
cout << rez[i] << " ";
//ispis: 3 6 12 87 66 3 72 42

}


*/


#include<iostream>
#include<vector>
#include<functional>
using namespace std;

vector<int> izdvoji(vector<int>& tmp, function<bool(int)>kriterij) { //& brzi prijenos jer nema kopiranja , moze i bez &
	vector<int> pom;
	for (int i = 0; i < tmp.size(); i++) {
		if (kriterij(tmp[i])) {
			pom.push_back(tmp[i]);
		}
	}
	return pom;
}
bool djeljivS3(int a) {
	return a % 3 == 0;
}

int main()
{
	vector<int> brojevi = { 1, 4, 5, 7, 3, 6, 12, 65, 32, 8, 87, 55, 23, 22, 1, 1, 433, 66, 7, 433, 3, 32, 76, 8, 72, 256, 42 };

	vector<int> rez = izdvoji(brojevi, djeljivS3);//[](int n) {return (n % 3 == 0);} moze ovo umjesto definiranja globalne funkcije djejivS3

	for (int i = 0; i < rez.size(); i++)
		cout << rez[i] << " ";
	//ispis: 3 6 12 87 66 3 72 42

}
