#include<iostream>
using namespace std;

void BubbleSort(int tab[], unsigned int n){
    for(unsigned int i=n-1; i>0; i--){
        for(unsigned int j=0; j < i; j++){
            if(tab[j] > tab[j+1]){
                swap(tab[j], tab[j+1]);
            }
        }
    }
}
//mało wydajne, ilość operacji wiodących
//jest niezalezna
//od ukladu danych na wejsciu - porownuje,
//nawet jesli nie musi
//złożoność - suma ciągu arytmetycznego
// n-1 + n -2 + n-3 + .. + 3 + 2 + 1 =
//= (n-1)*(1+n-1)/2 = (n^2 - n)/2

int main(){
    int n;
    cin >> n;
    int tab[n];
    for(int i=0; i<n; i++){
        cin >> tab[i];
    }
    BubbleSort(tab, n);
    for(int j=0; j<n; j++){
        cout << tab[j] << " ";
    }
}
