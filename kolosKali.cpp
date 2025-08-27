#include <iostream>
using namespace std;

struct Samochod {
    string model;
    int liczba_drzwi;
    double pojemnosc;
};

const int N = 6;
void selectionSort(Samochod *x, int n) {
    int i = n - 1;
    while (i > 0) {
        int ind = 0;
        int j = 1;
        while (j <= i) {
            if (x[j].model > x[ind].model) {
                ind = j;
            }
            j++;
        }
        swap(x[i], x[ind]);
        i--;
    }
}
int rozne(Samochod *samochod) {
    int rozne = 0;
    for (int i =0; i<N;i++) {
        if (samochod[i].model != samochod[i+1].model) {
            rozne++;
        }
    }
    return rozne;
}


void wyswietl(Samochod *tab) {
    for (int i = 0; i < N; i++) {
        cout << "model: " << tab[i].model << " " << "liczba drzwi: " << tab[i].liczba_drzwi << endl;
    }
}

int main() {
    Samochod samochod[N] = {
        {"panda", 3, 2.5},
       {"panda", 3, 2.5},
        {"fiat", 2, 2.5},
        {"audi", 4, 2.5},
        {"bmw", 5, 2.5},
        {"zetoro", 2, 2.5},

    };
    cout << "przed sortowaniem" << endl;
    wyswietl(samochod);
    cout << endl;
    cout << "po sortowaniu" << endl;
    selectionSort(samochod,N);
    wyswietl(samochod);
    cout << endl;
    cout << "roznych modeli jest: " << rozne(samochod);
    return 0;
}
