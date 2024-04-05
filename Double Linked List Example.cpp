// Double Linked List Example.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct CustNode
{
	int custId;
	struct CustNode* nextCustId;
	struct CustNode* prevCustId;
};

void AddCustNodeFrontOfList(CustNode** head, int newCustId)
{
	struct CustNode* new_CustomerNode = new CustNode;

	new_CustomerNode->custId = newCustId;

	new_CustomerNode->nextCustId = (*head);
	new_CustomerNode->prevCustId = NULL;

	if ((*head) != NULL)
		(*head)->prevCustId = new_CustomerNode;

	(*head) = new_CustomerNode;
}

void AddCustNodeAfterSelected(struct CustNode* prev_node, int newCustId)
{
	if (prev_node == NULL) {
		cout << "previous node cannot be null";
		return;
	}

	struct CustNode* new_CustomerNode = new CustNode;

	new_CustomerNode->custId = newCustId;
	new_CustomerNode->nextCustId = prev_node->nextCustId;

	prev_node->nextCustId = new_CustomerNode;

	new_CustomerNode->prevCustId = prev_node;

	if (new_CustomerNode->nextCustId != NULL)
		new_CustomerNode->nextCustId->prevCustId = new_CustomerNode;
}

void AddCustNodeEndOfList(struct CustNode** head, int newCustId)
{
	struct CustNode* new_CustomerNode = new CustNode;
	struct CustNode* lastCustNode = *head;

	new_CustomerNode->custId = newCustId;
	new_CustomerNode->nextCustId = NULL;

	if (*head == NULL)
	{
		new_CustomerNode->prevCustId = NULL;
		*head = new_CustomerNode;
		return;
	}

	while (lastCustNode->nextCustId != NULL)
		lastCustNode = lastCustNode->nextCustId;

	lastCustNode->nextCustId = new_CustomerNode;
}

void DeleteCustNode(struct CustNode** head, struct CustNode* del_node)
{
	if (*head == NULL || del_node == NULL)
		return;

	if (*head == del_node)
		*head = del_node->nextCustId;

	if (del_node->nextCustId != NULL)
		del_node->nextCustId->prevCustId = del_node->prevCustId;

	if (del_node->prevCustId != NULL)
		del_node->prevCustId->nextCustId = del_node->nextCustId;

	free(del_node);
}

void displayList(struct CustNode* custNodeList)
{
	while (custNodeList) 
	{
		if (custNodeList->nextCustId == NULL)
			cout << "[" << custNodeList->custId << "] "	 << "->"	<< "DONE" ;
		else
			cout << "[" << custNodeList->custId << "] "	 << "->" ;
		custNodeList = custNodeList->nextCustId;
	}
	cout << "\n";
}
int main()
{
	struct CustNode* head = NULL;
	AddCustNodeFrontOfList(&head, 25);
	displayList(head);
	AddCustNodeEndOfList(&head, 12);
	displayList(head);
	AddCustNodeAfterSelected(head, 33);
	displayList(head);
	AddCustNodeFrontOfList(&head, 125);
	displayList(head);
	AddCustNodeEndOfList(&head, 66);
	displayList(head);
	AddCustNodeAfterSelected(head->nextCustId->nextCustId, 330);
	displayList(head);
	DeleteCustNode(&head, head->nextCustId->nextCustId);
	displayList(head);
	AddCustNodeFrontOfList(&head, 680);
	displayList(head);
}