#include <iostream>
#include <string>

using namespace std;

struct Node
{
	int data;
	Node* next;

	Node(int newData) : data(newData), next(nullptr) {}
};
void delfirst10(Node* head) {
	if (head->data == 10) { // Если первый элемент равен 10, удаляем его
		Node* temp = head;
		head = head->next;
		delete temp;
		return;
	}

	Node* current = head;
	while (current->next != nullptr && current->next->data != 10) {
		current = current->next;
	}

	if (current->next != nullptr) { // Если найден элемент со значением 10
		Node* temp = current->next;
		current->next = temp->next;
		delete temp;
	}
}


void print(Node* head) {
	Node* current = head;
	while (current != nullptr) {
		cout << current->data;
		current = current->next;
	}
}
int main() {
	Node* node = new Node(5);
	node->next = new Node(10);
	node->next->next = new Node(15);

	print(node);
	cout << "\n";
	delfirst10(node);
	print(node);

}

