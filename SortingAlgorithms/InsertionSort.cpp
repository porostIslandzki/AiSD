#include <iostream>
using namespace std;

//tworzymy zbiór wartości posortowanych (na
//początku umieszczamy tam jeden element
//pobieramy z części nieposortowanej kolejny
//element i wstawiamy go w dobre miejsce do
//tych posortowanych

void InsertionSort(int tab[], int n) {
   for(int k=1; k<n; k++){
    for(int i= k-1; i>=0; i--){
        if(tab[i+1] < tab[i]){
            swap(tab[i], tab[i+1]);
        } else {
            break;
        }
    }
   }
}

//Potrafi uwzględnić kolejność danych na wejściu
//dla danych wstępnie posortowanych wykonuje mniej
//porównan i przestawień

//pesymistyczna złożoność (n^2 - n)/2



int main(){
    int n;
    cin >> n;
    int tab[n];
    for(int i=0; i<n; i++){
        cin >> tab[i];
    }
    InsertionSort(tab, n);
    for(int j=0; j<n; j++){
        cout << tab[j] << " ";
    }
}
