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

