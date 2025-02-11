#include <iostream>
using namespace std;

void SelectionSort(int tab[], int n) {
    int minx;
    for (int i = 0; i < n - 1; i++) {
        minx = i;
        for (int j = i + 1; j < n; j++) {
            if (tab[j] < tab[minx]) {
                minx = j;
            }
        }
        swap(tab[i], tab[minx]);     }
}

//działa, wystraczy wyszukac min w przedziale
//mało wydajne, ilosc operacji wiodących
//jest niezależna od układu danych na wejsciu
//porównuje nawet jesli nie musi

//złożoność: ciągłe poszukiwanie najmniejszej wartości
// n-1 + n-2 + n-3 + .. + 3 + 2 + 1 =
//= (n-1)*(1+n-1)/2 = (n^2 - n)/2
//nie jest to szybkie sortowanie

int main(){
    int n;
    cin >> n;
    int tab[n];
    for(int i=0; i<n; i++){
        cin >> tab[i];
    }
    SelectionSort(tab, n);
    for(int j=0; j<n; j++){
        cout << tab[j] << " ";
    }
}
