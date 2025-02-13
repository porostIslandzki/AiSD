#include <iostream>
#include <sstream>
#include <cctype>
using namespace std;

const int MAX_STACK_SIZE = 100;

class NumberStack {
public:
    int data[MAX_STACK_SIZE];
    int top;

    NumberStack() { top = -1; }

    bool isEmpty() { return top == -1; }

    void push(int value) {
        if (top < MAX_STACK_SIZE - 1) {
            data[++top] = value;
        }
    }

    int pop() {
        if (isEmpty()) return 0;
        return data[top--];
    }

    int peek() {
        if (isEmpty()) return 0;
        return data[top];
    }
};


int evaluateONP(string exp) {
    NumberStack s;
    stringstream ss(exp);
    string token;

    while (ss >> token) {
        if (isdigit(token[0]) || (token.size() > 1 && isdigit(token[1]))) {
            s.push(stoi(token)); // Konwersja liczby na int i dodanie do stosu
        } else {
            int op1 = s.pop();
            int op2 = s.pop();
            if (token == "+") s.push(op2 + op1);
            else if (token == "-") s.push(op2 - op1);
            else if (token == "*") s.push(op2 * op1);
            else if (token == "/") s.push(op2 / op1);
        }
    }

    return s.peek();
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        string ONP;
        getline(cin, ONP);

        cout << evaluateONP(ONP) << endl;  // Obliczamy wartość wyrażenia
    }

    return 0;
}
