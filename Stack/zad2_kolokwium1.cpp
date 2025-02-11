#include <iostream>
using namespace std;

class Stack {
private:
    char* arr;
    int topIndex;
    int capacity;
public:
    Stack(int size = 1000) {
        capacity = size;
        arr = new char[capacity];
        topIndex = -1;
    }
    ~Stack() {
        delete[] arr;
    }

    void push(char value) {
        if (topIndex >= capacity - 1) return;
        arr[++topIndex] = value;
    }
    void pop() {
        if (topIndex >= 0) --topIndex;
    }
    bool isEmpty() {
        return topIndex < 0;
    }
    char top() {
        if (topIndex < 0) return '\0';
        return arr[topIndex];
    }
};
//jesli nawias otwierajacy, wrzucamy go na stos
//jesli nawias zamykajacy, sprawdzamy stos
int main() {
    int n;
    cin >> n;

    while (n--) {
        Stack s; // Tworzymy nowy stos dla każdego testu
        string expr;
        cin >> expr; // Wczytujemy całe wyrażenie

        bool isValid = true;
        for (char c : expr) {
            if (c == '.') break; // Kropka kończy wyrażenie

            if (c == '(' || c == '{' || c == '[') {
                s.push(c);
            } else if (c == ')' || c == '}' || c == ']') {
                if (s.isEmpty()) {
                    isValid = false; // Zamykający nawias bez otwierającego → NIE
                    break;
                }

                char top = s.top();
                if ((c == ')' && top == '(') ||
                    (c == '}' && top == '{') ||
                    (c == ']' && top == '[')) {
                    s.pop(); // Usuwamy pasującą parę
                } else {
                    isValid = false; // Niepoprawne dopasowanie nawiasów
                    break;
                }
            }
        }

        if (!s.isEmpty()) isValid = false; // Jeśli stos nie jest pusty, to błąd

        cout << (isValid ? "TAK" : "NIE") << endl;
    }

    return 0;
}
