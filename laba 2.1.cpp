#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;

    Node(const string& newData, Node* newNext = nullptr)
        : data(newData), next(newNext) {
    }
};

// Функция для добавления элемента в стек
Node* push(Node* top, const string& value) {
    return new Node(value, top);
}

// Функция для удаления верхнего элемента из стека
Node* pop(Node* top) {
    if (top) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    return top;
}

// Функция для печати всех элементов стека
void print(const Node* top) {
    const Node* current = top;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Функция для печати элементов стека, начинающихся с буквы 't'
void printStartingWithLowerCaseT(const Node* top) {
    const Node* current = top;
    while (current) {
        if (!current->data.empty() && islower(current->data[0])) {
            cout << current->data << " ";
        }
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* top = nullptr; // Инициализация вершины стека

    // Добавление элементов в стек
    top = push(top, "TE");
    top = push(top, "group");
    top = push(top, "the");
    top = push(top, "of");
    top = push(top, "Students");

    cout << "Содержимое стека после добавления элементов:" << endl;
    print(top);

    // Удаление верхнего элемента из стека
    top = pop(top);
    cout << "Содержимое стека после удаления одного элемента:" << endl;
    print(top);

    cout << "Строки в стеке, начинающиеся со строчной буквы 't':" << endl;
    printStartingWithLowerCaseT(top);

    // Освобождение памяти, выделенной под стек
    while (top) {
        top = pop(top);
    }

    return 0;
}
