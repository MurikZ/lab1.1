#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int newData, Node* newNext = nullptr)
        : data(newData), next(newNext) {
    }
};

// Функция для добавления элемента в конец списка
Node* append(Node* head, int value) {
    if (head == nullptr) {
        return new Node(value);
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new Node(value);
        return head;
    }
}

// Функция для удаления последних двух элементов из списка
Node* removeLastTwo(Node* head) {
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
        // Если список пустой или содержит менее двух элементов, возвращаем nullptr
        return nullptr;
    }
    else {
        Node* current = head;
        while (current->next->next->next != nullptr) {
            current = current->next;
        }
        delete current->next->next;
        delete current->next;
        current->next = nullptr;
        return head;
    }
}

// Функция для печати списка
void printList(const Node* head) {
    const Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Функция для освобождения памяти, выделенной под список
void deleteList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

int main() {
    Node* head = nullptr; // Инициализация головы списка

    // Добавление элементов в список
    head = append(head, 1);
    head = append(head, 2);
    head = append(head, 3);
    head = append(head, 4);
    head = append(head, 5);

    cout << "Исходный список:" << endl;
    printList(head);

    // Удаление последних двух элементов
    head = removeLastTwo(head);

    cout << "Список после удаления двух последних элементов:" << endl;
    printList(head);

    // Освобождение памяти, выделенной под список
    deleteList(head);

    return 0;
}
