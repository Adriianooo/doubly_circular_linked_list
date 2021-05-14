#include "linkedlist.h"


linkedlist* Create()
{
	linkedlist* list = new linkedlist;
	list->count = 0;
	list->head = nullptr;
	list->Tail = nullptr;

	return list;
}


void Insert(linkedlist* list, int numero, string nome)
{
	if (IsEmpty(list)) {
		Node* n1 = new Node;
		n1->name = nome;
		n1->next = n1->previous = n1;
		list->head = list->Tail = n1;
		n1->id = numero;
	}
	else {
		Node* node = new Node;
		node->name = nome;
		list->head->previous = node;
		node->next = list->head;
		node->previous = list->Tail;
		node->id = numero;
		list->head = node;
	}
	++list->count;
}

void Append(linkedlist* list, int numero, string nome)
{
	if (IsEmpty(list)) {
		Node* n1 = new Node;
		n1->name = nome;
		n1->next = n1->previous = n1;
		list->head = list->Tail = n1;
		n1->id = numero;
	}
	else {
		Node* node = new Node;
		node->name = nome;
		list->Tail->next = node;
		node->previous = list->Tail;
		node->next = list->head;
		node->id = numero;
		list->Tail = node;
	}

	++list->count;
}

void Destroy(linkedlist* list)
{
	Clear(list);
	delete list;
}

void Clear(linkedlist* list)
{
	while (list->count != 0) {
		RemoveHead(list);
	}
}

bool IsEmpty(const linkedlist* list)
{
	if (list->count == 0) {
		return true;
	}
	else {
		return false;
	}
}


Node* RemoveNode(linkedlist* list, int numero)
{
	Node* Remove = list->head;
	Node* Remove2 = nullptr;

	while (Remove != nullptr && Remove->id != numero) {
		Remove2 = Remove;
		Remove = Remove->next;
	}
	if (Remove == nullptr) {
		return nullptr;
	}
	else if (Remove == list->head) {
		return RemoveHead(list);
	}
	else if (Remove == list->Tail) {
		return RemoveTail(list);
	}
	else {
		Remove2->next = Remove->next;
		Remove->next->previous = Remove2;
		--list->count;
		return Remove;
	}
}

Node* RemoveTail(linkedlist* list)
{
	Node* Remove = list->Tail;
	
	if (list->head == list->Tail) {
		list->head = list->Tail = nullptr;
	}
	else {
		list->Tail->previous->next = list->head;
		list->head->previous = list->Tail->previous;
		list->Tail = list->Tail->previous;
	}

	--list->count;
	return Remove;
}

Node* RemoveHead(linkedlist* list)
{
	Node* Remove = list->head;

	if (list->head == list->Tail) {
		list->head = list->Tail = nullptr;
	}

	else {
		list->head->next->previous = list->Tail;
		list->Tail->next = list->head->next;
		list->head = list->head->next;

	}

	--list->count;
	return Remove;
}

int Count(const linkedlist* list)
{
	return list->count;
}

Node* GetHead(const linkedlist* list)
{
	return list->head;
}

Node* GetTail(const linkedlist* list)
{
	return list->Tail;
}

Node* GetNode(const linkedlist* list, string nome)
{
	Node* n = list->head;
	while (n != nullptr) {
		if (n->name == nome) {
			return n;
		}
		n = n->next;
	}
	
	return nullptr;
}

void DestroyNode(Node* node)
{
	delete node;
	node = nullptr;
}


