#include <iostream>
using namespace std;

// Strukturę Student z numerem indeksu, czterema ocenami, oraz średnią.
// Wczytanie danych dla studentów.
// Obliczenie średniej z ocen.
// Posortowanie studentów wg średniej quicksortem (według schematu, który przesłałeś).
// Wyświetlenie wyników.


struct Student {
    int nr_indeks;
    double oceny[4];
    double srednia;
};

double obliczsrednia(double oceny[4]) {
    double suma = 0;
    for (int i =0; i<4; i++) {
        suma += oceny[i];
    }
    double wynik = suma/4;
    return wynik;
}

void pobierz(Student *studenci, int n) {

    for (int i =0; i<n; i++) {
        cout << "Wypelnij dane dla studenta nr: " << i+1 << endl;
        cout << "podaj nr. indeksu: " << endl;
        cin >> studenci[i].nr_indeks;
        cout << "podaj 4 oceny : " << endl;
        for (int j=0; j<4; j++) {
            cin >> studenci[i].oceny[j];
        }
        studenci[i].srednia = obliczsrednia(studenci[i].oceny);
    }
}

void wyswietl(Student *student, int n) {

    for (int i =0; i<n;i++) {
        cout << "Informacje dla studenta nr: " << i+1 << endl;
        cout << "indeks to: " << student[i].nr_indeks << endl;
        cout << "oceny to: " << endl;
        for (int j=0; j<4; j++) {
            cout << student[i].oceny[j] << " ";
        }
        cout << endl;
        cout << "srednia to: " << student[i].srednia << endl;
    }
}

void quicksort(Student x[], int lewy, int prawy) {
    int srodek = (lewy + prawy) / 2;
    Student piwot = x[srodek];

    x[srodek] = x[prawy];

    int granica = lewy;
    int i = lewy;

    while (i < prawy) {
        if (x[i].srednia < piwot.srednia) {
            swap(x[granica], x[i]);
            granica++;
        }
        i++;
    }

    x[prawy] = x[granica];
    x[granica] = piwot;

    if (lewy < granica - 1)
        quicksort(x, lewy, granica - 1);
    if (granica + 1 < prawy)
        quicksort(x, granica + 1, prawy);
}


int main() {

    int liczba_studentow;
    cout << "podaj liczbe studentow to wczytania" << endl;
    cin >> liczba_studentow;
    Student *studenci = new Student[liczba_studentow];
    pobierz(studenci,liczba_studentow);
    cout << "Studenci PRZED sortowaniem: " << endl;
    wyswietl(studenci,liczba_studentow);
    cout << "Studenci PO sortowaniu: " << endl;
    quicksort(studenci,0,liczba_studentow-1);
    wyswietl(studenci,liczba_studentow);

    return 0;
}
