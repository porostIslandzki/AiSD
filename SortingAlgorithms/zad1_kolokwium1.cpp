#include<iostream>
using namespace std;

struct Pair {
    int nr1;
    int nr2;
};

void InsertionSort(Pair pairs[], int n) {
   for(int k=1; k<n; k++){
    for(int i= k-1; i>=0; i--){
        if(pairs[i+1].nr1 < pairs[i].nr1){
            swap(pairs[i], pairs[i+1]);
        } else {
            break;
        }
    }
   }
}

int main(){
    int n; //liczba par liczb
    cin >> n;
    Pair* pairs = new Pair[n];

    for(int i=0; i<n; i++){
        cin >> pairs[i].nr1;
        cin >> pairs[i].nr2;
    }

    Pair* even = new Pair[n];
    Pair* odd = new Pair[n];
    int evenCount = 0;
    int oddCount = 0;

    for (int i = 0; i < n; i++) {
        if (pairs[i].nr1 % 2 == 0) {
            even[evenCount++] = pairs[i];
        } else {
            odd[oddCount++] = pairs[i];
        }
    }

    InsertionSort(even, evenCount);
    InsertionSort(odd, oddCount);

    for(int i = 0; i < evenCount; i++) cout << even[i].nr2 << " ";
    for(int i = 0; i < oddCount; i++) cout << odd[i].nr2 << " ";

    cout << endl;
    delete[] pairs;
    delete[] even;
    delete[] odd;

    return 0;

}
