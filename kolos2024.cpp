#include <iostream>
using namespace std;

struct Student {
    int indeks;
    double srednia;
    double oceny[4];
};

void pobierz(Student *student,int n) {
    for (int i=0;i<n;i++) {
        double suma = 0;
        cout << "podaj nr indeksu: " << endl;
        cin >> student[i].indeks;
        cout << "podaj oceny: " << endl;
        for (int j=0;j<4;j++) {
            cin >> student[i].oceny[j];
            suma += student[i].oceny[j];
        }
        double wynik = suma/4;
        student[i].srednia = wynik;
    }
}

bool czyZdal(Student student) {
    for (int i =0;i<4;i++){
            if (student.oceny[i]<3) {
                return false;
            }
        }
    return true;
    }


int flagaPolska(Student *x, int n, double granica) {
    int i = 0;
    int j = n - 1;
    while (i < j) {
        while (czyZdal(x[i])  && i < j) {
            i++;
        }
        while (!czyZdal(x[j]) && i < j) {
        }
        if (i < j) {
            swap(x[i], x[j]);
            i++;
            j--;
        }
    }
    if (czyZdal(x[i])) {
        return i + 1;
    } else {
        return i;
    }
}
//
void wypisz(Student *tab, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Indeks: " << tab[i].indeks << " Oceny: ";
        for (int j = 0; j < 4; j++) {
            cout << tab[i].oceny[j] << " ";
        }
        cout << endl;
    }
}

int main () {
    int liczbaStudentow;
    cout << "podaj liczbe studentow" << endl;
    cin >> liczbaStudentow;
    Student *student = new Student [liczbaStudentow];
    pobierz(student,liczbaStudentow);
    int zdani = flagaPolska(student,liczbaStudentow,4);
    cout << "studenci ktorzy ZDALI wszystko" << endl;
    wypisz(student,liczbaStudentow);
    cout << "studenci ktorzy NIE ZDALI chociaz jednego" << endl;
    wypisz(student+zdani,liczbaStudentow-zdani);
    return 0;
}