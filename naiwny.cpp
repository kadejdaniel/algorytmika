#include <iostream>
using namespace std;

int naiwny (string tekst, string wzorzec, int dlt, int dlw) {
    int i =0;
    while (i<=dlt-dlw) {
        int j =0;
        while (j<dlw && wzorzec[j]==tekst[i+j]) {
            j++;
        }
        if (j==dlw) {
            return i;
        }
        i++;
    }
    return -1;
}


int main () {
    string tekst, wzorzec;
    cout << "podaj tekst" << endl;
    getline(cin,tekst);
    cout << "podaj wzorzec" << endl;
    getline(cin,wzorzec);
int wynik = naiwny(tekst,wzorzec,tekst.length(),wzorzec.length());
    if (wynik !=-1) {
        cout << "znaleziono wzorzec";
    }else {
        cout << "NIE";
    }
    return 0;
}