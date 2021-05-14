// main.cpp
// Adriano Pinheiro Fernandes TIA: 32055161
#include <iostream>
#include <clocale>
#include "linkedlist.h"
using namespace std;

void Print(const linkedlist* list)
{
	Node* n = list->head;
	int i;
	for (i = 0; i < list->count; i++) {
		cout << "[" << n->id << "]: " << n->name << "\n";
		n = n->next;
	}
}

void PrintReverse(const linkedlist* list)
{
	Node* n = list->Tail;
	int i;
	for (i = 0; i < list->count; i++) {
		cout <<"[" << n->id << "]" << n->name << "\n";
		n = n->previous;
	}

}


void PrintDoubleListInfo(const linkedlist* list)
{
	if (IsEmpty(list))
	{
		cout << "Lista vazia!\n";
	}
	else
	{
		cout << "Lista:\n";
		Print(list);
		cout << "Lista invertida:\n";
		PrintReverse(list);
	}
}
int main()
{
	setlocale(LC_ALL, "pt_BR");
	cout << "*** Lista Circular Duplamente Ligada/Encadeada (Doubly Circular Linked List)*** \n";
	linkedlist* list = Create();
	PrintDoubleListInfo(list);
	Insert(list, 1, "Carol");
	Insert(list, 2, "Eric");
	Insert(list, 3, "John");
	Append(list, 4, "Leo");
	Append(list, 5, "Julia");
	Append(list, 6, "Lisa");

	PrintDoubleListInfo(list);
	Clear(list);
	PrintDoubleListInfo(list);

	Insert(list, 11, "Paulo");
	Append(list, 22, "Thomas");
	Insert(list, 33, "Olga");
	Append(list, 44, "Bia");
	Insert(list, 55, "Angela");
	Append(list, 66, "Karen");
	Insert(list, 77, "Adauto");
	PrintDoubleListInfo(list);

	Node* temp = RemoveNode(list, 44);
	cout << "Nó removido -> id: " << temp->id << ", name: " << temp->name << '\n';
	DestroyNode(temp);
	PrintDoubleListInfo(list);
	temp = RemoveHead(list);
	cout << "Nó removido -> id: " << temp->id << ", name: " << temp->name << '\n';
	DestroyNode(temp);
	PrintDoubleListInfo(list);
	temp = RemoveTail(list);
	cout << "Nó removido -> id: " << temp->id << ", name: " << temp->name << '\n';
	DestroyNode(temp);
	PrintDoubleListInfo(list);
	Destroy(list);
	cout << "Fim.\n";
}