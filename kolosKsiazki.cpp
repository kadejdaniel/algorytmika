#include <iostream>
using namespace std;

const int n = 5;

struct ksiazka {
    string tytul;
    int rok;
};

void insertionSort(ksiazka tab[]) {
    int i = n - 2;
    while (i >= 0) {
        int j = i;
        ksiazka temp = tab[j];
        while (temp.rok > tab[j + 1].rok && j < n - 1) {
            tab[j].rok = tab[j + 1].rok;
            j = j + 1;
        }
        tab[j].rok = temp.rok;
        i = i - 1;
    }
}

void wyswietl(ksiazka tab[]) {
    for (int i = 0; i < n; i++) {
        cout << "Tytul to: " << tab[i].tytul << " " << "Rok wydania: " << tab[i].rok << endl;
    }
}

int main() {
    ksiazka tab[n] = {
        {"mis", 2007}, {"amis", 2010}, {"bmis", 2006}, {"cmis", 1999},
    };
    wyswietl(tab);
    insertionSort(tab);
    cout << "po sortowaniu: " << endl;
    wyswietl(tab);
    return 0;
}
