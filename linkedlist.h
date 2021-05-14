#ifndef __DOUBLY_CIRCULAR_LINKED_LIST_H__
#define __DOUBLY_CIRCULAR_LINKED_LIST_H__
#include <string>
using namespace std;

struct Node {
	int id;
	string name;
	Node* next;
	Node* previous;
};

struct linkedlist {
	int count;
	Node* head;
	Node* Tail;
};

linkedlist* Create();

void Insert(linkedlist* list, int id, string name);

void Append(linkedlist* list, int id, string name);

void Destroy(linkedlist* list);

void Clear(linkedlist* list);

bool IsEmpty(const linkedlist* list);

Node* RemoveNode(linkedlist* list, int numero);

Node* RemoveTail(linkedlist* list);

Node* RemoveHead(linkedlist* list);

int Count(const linkedlist* list);

Node* GetHead(const linkedlist* list);

Node* GetTail(const linkedlist* list);

Node* GetNode(const linkedlist* list, string name);

void DestroyNode(Node* node);







#endif
