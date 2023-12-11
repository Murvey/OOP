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
