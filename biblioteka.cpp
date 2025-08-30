#include <iostream>
using namespace std;

struct Book {
    string tytul;
    string autor;
    int rok_wydania;
    double cena;
};

void sredniaCena(Book *book, int n) {
    double suma = 0;
    for (int i = 0; i < n; i++) {
        suma += book[i].cena;
    }
    double wynik = suma / n;
    cout << "średnia cena wszystkich ksiazek to: " << wynik;
}

void wyswietl(Book *book, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Tytul: " << book[i].tytul << endl;
        cout << "Autor: " << book[i].autor << endl;
        cout << "Rok wydania: " << book[i].rok_wydania << endl;
        cout << "Cena ksiazki to: " << book[i].cena << endl;
    }
}

void pobierz(Book *book, int n) {
    for (int i =0; i<n;i++) {
        cout << "Podaj tytul ksiazki: ";
        cin >> book[i].tytul;
        cout << "Podaj autora: ";
        cin >> book[i].autor;
        cout << "Podaj rok wydania: ";
        cin >> book[i].rok_wydania;
        cout << "Podaj cene: ";
        cin >> book[i].cena;
    }
}

void quickSort(Book *x, int lewy, int prawy) {
    int srodek = (int) (lewy + prawy) / 2;
    Book piwot =x[srodek];
    x[srodek] = x[prawy];
    int granica = lewy;
    int i = lewy;
    while (i<prawy) {
        if (x[i].rok_wydania < piwot.rok_wydania) {
            swap(x[granica],x[i]);
            granica++;
        }
        i++;
    }
    x[prawy] =x[granica];
    x[granica] = piwot;
    if (lewy<granica-1) {
        quickSort(x,lewy,granica-1);
    }
    if (granica+1<prawy) {
        quickSort(x,granica+1,prawy);
    }
}

void bubbleSort(Book *x, int n) {
    int i = n - 1;
    while (i > 0) {
        int j = 0;
        while (j < i) {
            if (x[j].cena > x[j + 1].cena) {
                swap(x[j], x[j + 1]);
            }
            j++;
        }
        i--;
    }
}

void najdrozszaKsiazka(Book *book, int n) {
    double najdrozsza = 0;
    int indeks =0;
    for (int i=0; i<n;i++) {
        if (book[i].cena > najdrozsza) {
            najdrozsza = book[i].cena;
            indeks = i;
        }

    }
    cout << "najdrozsza ksiazka to: " << book[indeks].tytul;
}

int liczbaKsiazekOdAutora (Book *book, int n, string autor) {
    int ksiazkaAutora = 0;
    for (int i =0; i<n;i++) {
        if (book[i].autor == autor) {
            ksiazkaAutora++;
        }
    }
    return ksiazkaAutora;
}

void obnizCene(Book *book, int n, double procent) {
    for (int i =0; i<n; i++) {
        book[i].cena = book[i].cena*procent;
    }
}

int main() {
    int n;
    cout << "podaj ile ksiazek chcesz wczytac: " << endl;
    cin >> n;
    Book *ksiazka = new Book[n];

    cout << "quickSort wedlug roku wydania: " << endl;
    wyswietl(ksiazka,n);


    return 0;
}
