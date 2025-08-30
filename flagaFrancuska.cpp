#include <iostream>
using namespace std;

struct Student {
    int nr_indeksu;
    double oceny[4];
    double srednia;
};

void wczytaj(Student *student, int n) {
    for (int i = 0; i < n; i++) {
        cout << "podaj nr. indeksu: " << endl;
        cin >> student[i].nr_indeksu;
        double suma = 0;
        for (int j = 0; j < 4; j++) {
            cout << "podaj 4 oceny: " << endl;
            cin >> student[i].oceny[j];
            if (student[i].oceny[j]<2 || student[i].oceny[j]>5) {
                cout << "podales zla ocene " << endl;
                j--;
            }else {
                suma += student[i].oceny[j];
            }
        }
        double wynik = suma / 4;
        student[i].srednia = wynik;
    }
}


int flagaFracuska(Student *x, int n, double
    granica1, double granica2) {
    int i = -1;
    int j = 0;
    int k = n;
    while (j < k) {
        if (x[j].srednia <= granica1) {
            i++;
            swap(x[i], x[j]);
            j++;
        } else {
            if (x[j].srednia > granica2) {
                k--;
                swap(x[k], x[j]);
            } else {
                j++;
            }
        }
    }
    return i, k;
}


void wyswietl(Student *student, int n, double granica1,double granica2) {
    for (int i =0; i<n; i++) {
        cout << "nr. indeksu: " << student[i].nr_indeksu << " " <<endl;
        for (int j =0; j<4; j++){
            cout << student[i].oceny[j] << " ";
        }
        cout << endl;
        cout << "srednia: " << student[i].srednia;


        if (student[i].srednia >granica2) {
            cout << " -> grupa osob WYSOKA " << endl;
        }else if (granica1< student[i].srednia && student[i].srednia <granica2) {
            cout << " -> grupa osob SREDNIA " << endl;
        }else {
            cout << " -> grupa osob NISKA " << endl;
        }
        cout << endl;
    }
}


int main () {
    int liczba_studentow;
    double granica1,granica2;
    granica1 =3.0;
    granica2 = 4.5;
    cout << "podaj liczbe studentow" << endl;
    cin >> liczba_studentow;
    Student *student = new Student[liczba_studentow];
    wczytaj(student,liczba_studentow);
    cout << "Przed sortowaniem flagaFRANCUSKA" << endl;
    cout << endl;
    wyswietl(student,liczba_studentow,granica1,granica2);
    cout << endl;
    cout << "Po sortowaniu flagaFRANCUSKA" << endl;
    cout << endl;
    flagaFracuska(student,liczba_studentow,granica1,granica2);
    wyswietl(student,liczba_studentow,granica1,granica2);

    return 0;
}