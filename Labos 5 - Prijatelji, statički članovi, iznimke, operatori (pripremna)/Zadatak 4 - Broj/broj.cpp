#include<iostream>
using namespace std;

class PrevelikBroj {
public:
    int broj;
    PrevelikBroj(int _broj) : broj(_broj) {}
    string poruka() const{
        return "prevelik broj";
    }
};
class PremaliBroj {
public:
    int broj;
    PremaliBroj(int _broj) : broj(_broj) {}
    string poruka() const{
        return "premali broj";
    }
};

int test(int broj) {
    if (broj > 0){
        return 1;
    }
    else if (broj == 0) {
        return 0;
    }
    else {
        return -1;
    }
}
int main() {
    
    try {
        cout << "pocetak testa\n";
        int t = test(2);
        cout << "pocetak primjera\n";
        if (t == 1) {
            throw PrevelikBroj(t);
        }
        else if (t == -1) {
            throw PremaliBroj(t);
        }
    }
    catch (const PrevelikBroj& e) {
        cout << e.poruka() << endl;
    }
    catch (const PremaliBroj& e) {
        cout << e.poruka() << endl;
    }
    catch (...) {
        cout << "... neka druga greska!";
    }

    cout << "nastavak main funkcije\n";
    return 0;
}

