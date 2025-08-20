#include <iostream>
using namespace std;

struct Student {
    string imie;
    string nazwisko;
    double oceny[5];
    double srednia;
};

void selectionSort(Student *x, int n) {
    int i = n-1;
    while (i>0) {
        int ind = 0;
        int j=1;
        while (j<=i) {
            if (x[j].nazwisko>x[ind].nazwisko) {
                ind =j;
            }
            j++;
        }
        swap(x[i],x[ind]);
        i--;
    }
}

void pobierz(Student *student, int n) {
    for (int i =0; i<n;i++) {
        cout << "podaj imie: " << endl;
        cin >> student[i].imie;
        cout << "podaj nazwisko: " << endl;
        cin >> student[i].nazwisko;
        cout << "podaj 5 ocen: " << endl;
        for (int j=0;j<5;j++) {
            cin >> student[i].oceny[j];
        }
    }
}

void srednia (Student *student,int n) {
    for (int i =0;i<n;i++) {
        double suma = 0;
        for (int j=0;j<5;j++) {
            suma += student[i].oceny[j];
        }
        double wynik = suma/5;
        student[i].srednia = wynik;
    }
}

void wyswietl(Student *student, int n) {
    for (int i=0; i<n;i++) {
        cout << "Student " <<i+1<< endl<< "imie: " << student[i].imie <<endl<< "nazwisko: " << student[i].nazwisko << endl;
        cout << "Oceny: " ;
        for (int j=0; j<5;j++) {
            cout << student[i].oceny[j] << " ";
        }
        cout << endl;
        cout << "Srednia: ";
        cout << student[i].srednia;
        cout << endl;
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


int main() {
    int liczbaStudentow;
    cout << "podaj ilosc studentow: " << endl;
    cin >> liczbaStudentow;
    Student *student = new Student[liczbaStudentow];
    pobierz(student,liczbaStudentow);
    srednia(student,liczbaStudentow);
    wyswietl(student,liczbaStudentow);
    cout << endl;
    cout << "Po sortowaniu przez wybieranie wedlug nazwiska: " << endl;
    selectionSort(student,liczbaStudentow);
    wyswietl(student,liczbaStudentow);
    cout << "Po fladze polskiej wedlug sredniej: " << endl;
    cout << "Ponizej 4.0" << endl;
    int granica = flagaPolska(student,liczbaStudentow,4.0);
    wyswietl(student,granica);
    cout << "Powyzej 4.0" << endl;
    wyswietl(student+granica,liczbaStudentow-granica);



    return 0;
}