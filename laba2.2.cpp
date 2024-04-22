#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int newData, Node* newNext = nullptr)
        : data(newData), next(newNext) {
    }
};

// Функция для добавления элемента в стек
Node* push(Node* top, int value) {
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

int main() {
    Node* top = nullptr; // Инициализация вершины стека

    // Добавление элементов в стек
    top = push(top, 5);
    top = push(top, 3);
    top = push(top, 44);
    top = push(top, 555);

    cout << "Содержимое стека после добавления элементов:" << endl;
    print(top);

    // Удаление двух элементов из стека
    top = pop(top);
    top = pop(top);

    // Добавление чисел 20 и 30 в стек
    top = push(top, 20);
    top = push(top, 30);

    cout << "Содержимое стека после удаления двух элементов и добавления 20 и 30:" << endl;
    print(top);

    // Подсчет количества положительных двузначных чисел
    int count = 0;
    const Node* current = top;
    while (current) {
        if (current->data > 9 && current->data < 100) {
            count++;
        }
        current = current->next;
    }

    cout << "Количество положительных двузначных чисел в стеке: " << count << endl;

    // Освобождение памяти, выделенной под стек
    while (top) {
        top = pop(top);
    }

    return 0;
}
