#include <iostream>
using namespace std;

//Polega na sprawdzeniu, ile jest wystąpień każdej
//wartości
//Liczniki aktualizuje się w tablicy
//Musimy wiedzieć ile może pojawić się różnych wartości
//na wejściu - aby zapewnić odpowiednią ilość liczników

void CountingSort(int tab[], int n, int k) {
    int T[k + 1] = {0};

    for (int i = 0; i < n; i++) {
        T[tab[i]]++;  // Inkrementacja licznika dla danej liczby
    }

    // Odtworzenie posortowanej tablicy
    int index = 0;
    for (int i = 0; i <= k; i++) { // Przechodzimy przez tablicę zliczającą
        while (T[i] > 0) {  // Jeśli liczba i wystąpiła, wypisujemy ją tyle razy, ile trzeba
            tab[index++] = i;
            T[i]--;
        }
    }
}

//zalety: szybki! prosty
//wady: mało uniwersalny, trzeba znać rozpiętość zbioru
// n+n = 2*n

int main(){
    int n, k;
    cin >> n;
    cin >> k;
    int tab[n];
    for(int i=0; i<n; i++){
        cin >> tab[i];
    }
    CountingSort(tab, n, k);
    for(int j=0; j<n; j++){
        cout << tab[j] << " ";
    }
}
