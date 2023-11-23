/*
U učionici se nalazi nekoliko prenosivih računala. Riječ je tablet i laptop računalima različitih proizvođača na kojima se nalaze različiti operacijski sustavi.
Slijedeći programski kod u nastavku napišite sve potrebne klase, metode i funkcije koje su potrebne da bi funkcija main radila kao što je to i predviđeno.

int main(){
    int brTableta, brLaptopa;
    int brAndroida, brWindowsa, brLinuxa;

    Tablet Acer("Android"), Prestigio("Windows");
    Laptop Dell("Linux"), IBM("Windows"), Toshiba("Windows");

    vector<Racunalo*> Ucionica1 = { &Acer, &Prestigio, &Dell, &IBM, &Toshiba };
    AnalizaUcionice(Ucionica1, &brTableta, &brLaptopa, &brAndroida, &brWindowsa, &brLinuxa);


    // u nastavku ispisite dobivenu analizu ucionice u sljedecem obliku:

    U ucionici se nalazi 5 racunala
    Broj tablet racunala : 2
    Broj laptop racunala : 3
    Android OS : 1
    Windows OS : 3
    Linux OS : 1
    //
    return 0;    
}

Napomena: Klasa Racunalo  je apstraktna - demonstrirati polimorfizam unutar funkcije AnalizaUcionice prilikom provjere tipa računala (tablet ili laptop).
*/
