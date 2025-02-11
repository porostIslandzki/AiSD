#include<iostream>
using namespace std;

class Solution {
  public:
    void immediateSmaller(int* arr, int n) {
        for(int i=0; i<n- 1; i++){ //-1 zeby nie sprawdzac poza tablica
            if(arr[i+1] < arr[i]){
                arr[i] = arr[i+1];
            } else{
                arr[i] = -1;
            }
        }
        arr[n-1] = -1;
    }
};

int main() {
    int n;
    cin >> n;  // Wczytujemy rozmiar tablicy

    int* arr = new int[n];  // Tworzymy dynamiczną tablicę
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // Wczytujemy wartości
    }

    Solution obj;
    obj.immediateSmaller(arr, n);  // Wywołujemy funkcję

    // Wypisujemy zmodyfikowaną tablicę
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;  // Zwalniamy pamięć dynamiczną
    return 0;
}


/*Dla każdego elementu arr[i], sprawdź arr[i+1]:
Jeśli arr[i+1] < arr[i] → zamień arr[i] = arr[i+1]
W przeciwnym razie zamień arr[i] = -1
Ostatni element arr[n-1] zawsze ustaw na -1.
Modyfikujesz tablicę arr bez tworzenia nowej.*/
