#include <iostream>
using namespace std;

    struct Pracownik {
        double wyniki[3];
        double norma;
        int nr_stanowiska;
        double premia;
    };

void najlepsi(Pracownik *pracownik,int n) {
    double max_premia = pracownik[n-1].premia;
    for (int i =n;i>=0;i--) {
        if (pracownik[i].premia == max_premia) {
            cout << "Stanowisko: " << pracownik[i].nr_stanowiska
                << " | Premia: " << pracownik[i].premia << endl;
        }
    }
}

void selectionSort(Pracownik *x, int n) {
    int i = n-1;
    while (i>0) {
        int ind =0;
        int j = 1;
        while (j<=i) {
            if (x[j].premia< x[ind].premia) {
                ind = j;

            }
            j++;

        }
        swap(x[i],x[ind]);
        i--;
    }
}


void wyswietl(Pracownik *pracownik,int n) {

    for (int i=0 ;i <n;i++) {
        cout << "Numer stanowiska: " << pracownik[i].nr_stanowiska << " " << "Wyniki z 3 msc: ";
        for (int j=0;j<3;j++) {
            cout << pracownik[i].wyniki[j] << " ";
        }
        cout << endl;
        cout <<"Norma wynosi: " << pracownik[i].norma << " "<<"a Premia wynosi: " << pracownik[i].premia;
        cout << endl;
    }
}

void wczytaj(Pracownik *pracownik, int n) {
    for (int i =0;i <n;i++) {
        cout << "Podaj nr. stanowiska: " << endl;
        cin >> pracownik[i].nr_stanowiska;
        cout << "Podaj wyniki z 3 msc: " << endl;
        for (int j =0;j<3;j++) {
            cin >> pracownik[i].wyniki[j];
        }
        cout << "Podaj norme: " << endl;
        cin >> pracownik[i].norma;
        double wynik_kwartalny = 0;
        for (int i =0;i<n;i++) {
            wynik_kwartalny = (pracownik[i].wyniki[0]*0.25 +pracownik[i].wyniki[1]*0.5 +pracownik[i].wyniki[2]*0.25);
            pracownik[i].premia= wynik_kwartalny-pracownik[i].norma;
        }
    }
}

int main() {
    cout << "Podaj ilosc pracownikow";
    int k;
    cin >> k;
    Pracownik *pracownik = new Pracownik[k];
    wczytaj(pracownik,k);
    selectionSort(pracownik,k);
    wyswietl(pracownik,k);
    cout << endl;
    najlepsi(pracownik,k);
    return 0;
}