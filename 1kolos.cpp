#include <iostream>
using namespace std;

struct Pracownik {
    double wyniki[3];
    int nr_stanowiska;
    double pensja;
    double premia;
};


void selectionSort(Pracownik *x, int n) {
    int i = n-1;
    while (i>0) {
        int ind = 0;
        int j=1;
        while (j<=i) {
            if (x[j].premia>x[ind].premia) {
                ind =j;
            }
            j++;
        }
        swap(x[i],x[ind]);
        i--;
    }
}
void obliczpremie(Pracownik *pracownik, int n) {
    bool kwalifikuje;

    for (int i =0;i <n;i++) {
        double suma = 0;
        kwalifikuje = true;
        for (int j=0;j<3;j++) {
            suma += pracownik[i].wyniki[j];
            if (pracownik[i].wyniki[j] < 95) {
                kwalifikuje = false;
            }

        }

        if (kwalifikuje) {
            double srednia = suma/3;
            double wynik = srednia - 95;
            pracownik[i].premia = pracownik[i].pensja * wynik * 0.01;
        }else {
            pracownik[i].premia = 0;
        }
    }
}

void wyswietl(Pracownik *pracownik, int n) {
    for (int i = 0; i < n; i++) {
        cout << "numer stanowiska pracownika: " << pracownik[i].nr_stanowiska
                << " " << "pensja: " << pracownik[i].pensja << " " << "premia wynosi: " << pracownik[i].premia << endl;
    }

}

void pobierzDane(Pracownik *pracownik, int n) {
    for (int i = 0; i < n; i++) {
        cout << "podaj numer stanowiska pracownika: " << endl;
        cin >> pracownik[i].nr_stanowiska;
        cout << "podaj pensje pracownika: " << endl;
        cin >> pracownik[i].pensja;
        cout << "podaj wyniki pracownika z 3 miesiecy (w procentach): " << endl;
        for (int j = 0; j < 3; j++) {
            cin >> pracownik[i].wyniki[j];
        }
    }
}

int main() {
    int liczbaPracownikow;
    cout << "podaj liczbe pracownikow" << endl;
    cin >> liczbaPracownikow;
    Pracownik *pracownik = new Pracownik[liczbaPracownikow];
    pobierzDane(pracownik,liczbaPracownikow);
    obliczpremie(pracownik,liczbaPracownikow);
    wyswietl(pracownik,liczbaPracownikow);
    selectionSort(pracownik,liczbaPracownikow);
    cout << endl;
    cout << "Po selectionSort: " << endl;
    wyswietl(pracownik,liczbaPracownikow);

    return 0;
}
