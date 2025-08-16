#include <iostream>
using namespace std;

struct Student {
    double oceny[5];
    int nr_id;
    double srednia;
};

void obliczSrednia(Student *student, int n) {

    for (int i = 0; i < n; i++) {
        double suma = 0;
        for (int j = 0; j < 5; j++) {
            suma += student[i].oceny[j];
        }
        double srednia = suma / 5;
        student[i].srednia = srednia;
    }
}

void pobierz(Student *student, int n) {
    for (int i = 0; i < n; i++) {
        cout << "podaj nr. id studenta: " << endl;
        cin >> student[i].nr_id;
        cout << "podaj 5 ocen w skali od 2-5" << endl;
        for (int j = 0; j < 5; j++) {
            cin >> student[i].oceny[j];
        }
    }
}

int flagaPolska(Student *x, int n, double granica) {
    int i = 0;
    int j = n - 1;
    while (i < j) {
        while (x[i].srednia <= granica && i < j) {
            i++;
        }
        while (x[j].srednia > granica && i < j) {
        }
        if (i < j) {
            swap(x[i], x[j]);
            i++;
            j--;
        }
    }
    if (x[i].srednia <= granica) {
        return i + 1;
    } else {
        return i;
    }
}

void wyswietl(Student *student, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Numer id to: " << student[i].nr_id << endl;
        cout << "Oceny to: " << endl;
        for (int j = 0; j < 5; j++) {
            cout << student[i].oceny[j] << " ";
        }
        cout << "srednia to: " << student[i].srednia << endl;;
    }

}

int main() {
    int liczbaStudentow;
    cout << "podaj ilosc studentow: " << endl;
    cin >> liczbaStudentow;
    Student *student = new Student[liczbaStudentow];
    pobierz(student,liczbaStudentow);
    obliczSrednia(student,liczbaStudentow);
    wyswietl(student,liczbaStudentow);
    flagaPolska(student,liczbaStudentow,4.0);
    int granica = flagaPolska(student,liczbaStudentow,4.0); // zakladamy granica = 3, czyli 3 osoby ze srednia nizsza od 4.0
    cout << endl;
    cout << "studenci ze srednia ponizej 4.0" << endl;
    wyswietl(student,granica);
    cout << "studenci ze srednia powyzej 4.0" << endl;
    wyswietl(student+granica,liczbaStudentow-granica); //wskaznik przesuniety o 3 czyli zaczynamy od student[3]
    return 0;
}
