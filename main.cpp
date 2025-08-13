#include <iostream>
using namespace std;

const int n = 4;

struct s {
    string model;
    int liczba_drzwi;
    float pojemnosc;
};


void selection_sort(s tab[]) {
    int i = n - 1;
    while (i > 0) {
        int ind = 0;
        int j = 1;
        while (j <= i) {
            if (tab[j].model > tab[ind].model) {
                ind = j;
            }
            j = j + 1;
        }
        swap(tab[i], tab[ind]);
        i = i - 1;
    }
}

void wyswietl(s tab[]) {
    for (int i = 0; i < n; i++) {
        cout << tab[i].model << " " << tab[i].liczba_drzwi << " " << tab[i].pojemnosc << endl;
    }
}
int ileroznych(s tab[]) {
    int count = 1;
    for (int i = 1; i<n; i++) {
        if (tab[i].model != tab[i-1].model) {
            count++;
        }
    }
    return count;
}

void pobierz(s tab[]) {
    for (int i = 0; i < n; i++) {
        cout << "podaj model auta nr " << i+1 << endl;
        cin >> tab[i].model;
        cout << "podaj liczbe drzwi auta nr " << i+1 << endl;
        cin >> tab[i].liczba_drzwi;
        cout << "podaj pojemnosc auta nr " << i+1 << endl;
        cin >> tab[i].pojemnosc;
    }
}

int main() {
    s tablica_aut[n];
    pobierz(tablica_aut);
    wyswietl(tablica_aut);
    selection_sort(tablica_aut);
    cout << "tablica po sortowaniu: " << endl;
    wyswietl(tablica_aut);
    cout << "licznik roznych modeli wynosi: " << ileroznych(tablica_aut);
    return 0;
}
