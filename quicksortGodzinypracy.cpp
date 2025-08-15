#include <iostream>
using namespace std;

struct Pracownik {
    int id;
    double dni_pracy[5];
    double srednia;
};

double srednia(double tablica[5]) {
    double suma = 0;
    for (int i = 0; i<5; i++) {
        suma += tablica[i];
    }
    double wynik;
    wynik = suma/5;
    return wynik;
}

void wczytaj(Pracownik *pracownik, int n) {
    for (int i =0;i<n;i++) {
        cout << "podaj id pracownika: " << endl;
        cin >> pracownik[i].id;
        cout << "podaj godziny pracy: " << endl;
        for (int j=0; j<5; j++) {
            cin >> pracownik[i].dni_pracy[j];
        }
        pracownik[i].srednia = srednia(pracownik[i].dni_pracy);
    }
}

void wyswietl(Pracownik *pracownik, int n) {
    for (int i =0; i<n; i++) {
        cout << "Id pracownika " << i+1 << " to: " << pracownik[i].id << endl;
        cout << "Liczba przepracowanych godzin to: " << endl;
        for (int j=0; j<5; j++) {
            cout << pracownik[i].dni_pracy[j] << " ";
        }
        cout << endl;
        cout << "Srednia pracownika to "<< pracownik[i].srednia << endl;
        cout << endl;
    }
}

void quickSort(Pracownik *x, int lewy, int prawy) {
    int srodek = (int)(lewy+prawy)/2;
    Pracownik piwot = x[srodek];
    x[srodek] = x[prawy];
    int granica = lewy;
    int i = lewy;
    while (i<prawy) {
        if (x[i].srednia<piwot.srednia) {
            swap(x[granica],x[i]);
            granica++;
        }
        i++;
    }
    x[prawy] = x[granica];
    x[granica] = piwot;
    if (lewy<granica-1) {
        quickSort(x,lewy,granica-1);
    }
    if (granica+1 <prawy) {
        quickSort(x,granica+1,prawy);
    }
}


int main() {
    int liczbaPracownikow;
    cout << "podaj liczbe pracownikow" << endl;
    cin >> liczbaPracownikow;
    Pracownik *pracownik = new Pracownik [liczbaPracownikow];
    wczytaj(pracownik,liczbaPracownikow);
    wyswietl(pracownik, liczbaPracownikow);
    cout << "pracownicy posortowani wzgledem sredniej godzin: " << endl;
    quickSort(pracownik,0,liczbaPracownikow-1);
    wyswietl(pracownik, liczbaPracownikow);

    return 0;
}