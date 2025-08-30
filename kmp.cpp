// Tablica dopasowań (tab_dopasowan): mówi nam, ile znaków możemy „przeskoczyć” w wzorcu przy niezgodności.
// Funkcja kmp: używa tej tablicy, aby znaleźć wszystkie
// miejsca wystąpień wzorca w tekście bez powtarzania niepotrzebnych porównań.
// Dzięki temu KMP działa w czasie O(n + m), gdzie n = długość tekstu, m = długość wzorca.


#include <iostream>
using namespace std;

void tablica_dopasowan(string wzorzec, int dlw, int *tab_dopasowan) {
    tab_dopasowan[0] = 0;
    tab_dopasowan[1] = 0;
    int t = 0;
    int i = 1;
    while (i < dlw) {
        while (t > 0 && wzorzec[t] != wzorzec[i]) {
            t = tab_dopasowan[t];
        }
        if (wzorzec[t] == wzorzec[i]) {
            t++;
        }
        tab_dopasowan[i + 1] = t;
        i++;
    }
}

void kmp(string wzorzec,string tekst,int dlw, int dlt,int *tab_dopasowan) {
    int i =0;
    int j =0;
    while (i<dlt-dlw+1) {
        while (wzorzec[j] == tekst[i+j] && j<dlw) {
            j++;
        }
        if (j==dlw) {
            cout << "znaleziono w wzorzec na pozycji:" << i;
        }
        i = i+max(1,j-tab_dopasowan[j]);
        j=tab_dopasowan[j];
    }

}

int main () {

    string wzorzec, tekst;
    cout << "podaj wzorzec" << endl;
    getline(cin,wzorzec); // getline uwzglednia spacje tab itp
    cout << "podaj tekst" << endl;
    getline(cin,tekst);
    int *tab = new int[wzorzec.length()];

    tablica_dopasowan(wzorzec,wzorzec.length(),tab);
    kmp(wzorzec,tekst,wzorzec.length(),tekst.length(),tab);

    return 0;
}