/*Preorder Traversal to jeden ze sposobów
przechodzenia drzewa binarnego. W tej metodzie
odwiedzamy węzły w następującej kolejności:

Odwiedzamy bieżący węzeł (root)
Przechodzimy do lewego poddrzewa (left)
Przechodzimy do prawego poddrzewa (right)*/

#include <iostream>
using namespace std;

template<typename T>
class Stack {
    T* arr;
    int topIndex;
    int capacity;

public:
    Stack(int cap = 1000) {
        capacity = cap;
        arr = new T[capacity];
        topIndex = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(T ele) {
        if (topIndex >= capacity - 1) {
            cout << "Stack full" << endl;
            return;
        }
        arr[++topIndex] = ele;
    }

    void pop() {
        if (topIndex < 0) {
            cout << "Stack empty" << endl;
            return;
        }
        topIndex--;
    }

    T top() {
        if (topIndex < 0) {
            cout << "Stack empty" << endl;
            return T();
        }
        return arr[topIndex];
    }

    bool isEmpty() {
        return topIndex < 0;
    }
};

// Struktura drzewa binarnego
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Tworzenie nowego węzła drzewa
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Klasa rozwiązania dla preorder traversal
class Solution {
private:
    int* result;
    int size;
    int capacity;

public:
    Solution() {
        capacity = 1000;
        size = 0;
        result = new int[capacity];
    }

    ~Solution() {
        delete[] result;
    }

    void addToResult(int value) {
        if (size >= capacity) return;
        result[size++] = value;
    }

    // Preorder traversal iteracyjny
    int* preorderTraversal(Node* root, int& resultSize) {
        if (root == NULL) {
            resultSize = 0;
            return NULL;
        }

        Stack<Node*> s1;
        s1.push(root);

        while (!s1.isEmpty()) {
            Node* current = s1.top();
            s1.pop();
            addToResult(current->data); // Dodajemy wartość węzła do wyniku

            // Najpierw dodajemy prawe dziecko, potem lewe (aby pierwsze przetwarzane było lewe)
            if (current->right) s1.push(current->right);
            if (current->left) s1.push(current->left);
        }

        resultSize = size;
        return result;
    }
};

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    Solution sol;
    int resultSize;
    int* result = sol.preorderTraversal(root, resultSize);

    // Wypisujemy wynik preorder traversal
    for (int i = 0; i < resultSize; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    delete[] result; // Zwolnienie pamięci

    return 0;
}
