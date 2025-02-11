#include <iostream>
using namespace std;

template<typename T>
class Queue {
    T *arr;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

public:
    Queue(int cap = 1000) {
        capacity = cap;
        arr = new T[capacity];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void push(T ele) {
        if (size == capacity) {
            cout << "Queue full" << endl;
            return;
        }
        arr[nextIndex] = ele;
        nextIndex = (nextIndex + 1) % capacity;
        if (firstIndex == -1) {
            firstIndex = 0;
        }
        size++;
    }

    T front() {
        if (isEmpty()) {
            cout << "Queue empty" << endl;
            return T();
        }
        return arr[firstIndex];
    }

    void pop() {
        if (isEmpty()) {
            cout << "Queue empty" << endl;
            return;
        }
        firstIndex = (firstIndex + 1) % capacity;
        size--;
        if (size == 0) {
            nextIndex = 0;
            firstIndex = -1;
        }
    }
};

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

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

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

    int* findSpiral(Node* root, int& resultSize) {
        if (root == NULL) {
            resultSize = 0;
            return NULL;
        }

        Stack<Node*> s1, s2;
        s1.push(root);

        while (!s1.isEmpty() || !s2.isEmpty()) {
            while (!s1.isEmpty()) {
                Node* current = s1.top();
                s1.pop();
                addToResult(current->data);
                if (current->right) s2.push(current->right);
                if (current->left)  s2.push(current->left);
            }

            while (!s2.isEmpty()) {
                Node* current = s2.top();
                s2.pop();
                addToResult(current->data);
                if (current->left)  s1.push(current->left);
                if (current->right) s1.push(current->right);
            }
        }

        resultSize = size;
        return result;
    }
};

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);

    Solution sol;
    int resultSize;
    int* result = sol.findSpiral(root, resultSize);

    for (int i = 0; i < resultSize; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    delete[] result;

    return 0;
}
