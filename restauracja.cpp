#include <iostream>
using namespace std;

struct Danie {
    string nazwa;
    string kategoria;
    double cena;
    double czas_przygotowania;
    double oceny[4];
    double srednia;
};

void najlepsze_danie(Danie *danie, int n) {
    int max_ocena = 0;
    for (int i =0; i<n; i++) {
        if (danie[i].srednia > max_ocena) {
            max_ocena = danie[i].srednia;
            string najlepsze_danie = danie[i].nazwa;
        }

    }

}

double srednia(Danie *danie, int n) {
    for (int i = 0; i < n; i++) {
        double suma = 0;
        for (int j = 0; j < 5; j++) {
            suma += danie[i].oceny[j];
        }
        double wynik = suma / 5;
        danie[i].srednia = wynik;
    }
}

void wczytaj_dane(Danie *danie, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Danie nr. "<<i+1 << endl;
        cout << "Podaj nazwe: " << endl;
        cin >> danie[i].nazwa;
        cout << "Podaj kategorie: " << endl;
        cin >> danie[i].kategoria;
        cout << "Podaj cene: " << endl;
        cin >> danie[i].cena;
        cout << "Podaj czas przygotowania: " << endl;
        cin >> danie[i].czas_przygotowania;
        cout << "Podaj oceny dania" << endl;
        for (int j=0; j<4; j++) {
            cin >>danie[i].oceny[j];
        }
        danie[i].srednia = srednia(danie,n);
    }
}

void wyswietl(Danie *danie, int n) {
    for (int i =0; i<n; i++) {
        cout << "Nazwa: " << danie[i].nazwa << " " << "Kategoria: " << danie[i].kategoria
        << " " << "Cena: " << danie[i].cena << " "
        << "Czas przygotowania: " << danie[i].czas_przygotowania << endl;
        for (int j =0; j<4; j++){
            cout << danie[i].oceny[j] << " ";
        }
        cout << endl;
        cout << "srednia: " << danie[i].srednia;
    }
}


void insertionSort(Danie *x, int n) {
    int i = n - 2;
    while (i >= 0) {
        int j = i;
        Danie temp = x[j];
        while (temp.nazwa > x[j + 1].nazwa && j < n - 1) {
            x[j].nazwa = x[j + 1].nazwa;
            j++;
        }
        x[j].nazwa = temp.nazwa;
        i--;
    }
}


int flagaFrancuska(Danie *x, int n, int granica1, int granica2) {
    int i = -1;
    int j = 0;
    int k = n;
    while (j < k) {
        if (x[j].czas_przygotowania <= granica1) {
            i++;
            swap(x[i], x[j]);
            j++;
        } else {
            if (x[j].czas_przygotowania > granica2) {
                k--;
                swap(x[k], x[j]);
            } else {
                j++;
            }
        }
    }
    return i, k;
}

int main() {
    cout << "podaj liczbe dan" << endl;
    int liczba_dan;
    cin >> liczba_dan;
    Danie *danie = new Danie[liczba_dan];

    return 0;
}
