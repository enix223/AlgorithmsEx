#include <stdlib.h>
#include <stdio.h>
#include "list.h"

LinkedList CreateLinkedList(void)
{
    LinkedList list = malloc(sizeof(Node));
    if (list == NULL) {
        exit(-1);
    }
    list->element = 0;
    list->next = NULL;
    return list;
}

bool DestroyLinkedList(LinkedList list)
{
    if (list == NULL) {
        return false;
    }

    Node *currentNode = list, *nextNode = NULL;
    while(currentNode)
    {
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    } 
    return true;
}

void InsertElementToLinkedList(Element element, LinkedList *list)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->element = element;
    newNode->next = *list;
    *list = newNode;
}

bool DeleteElementFromLinkedList(Element element, LinkedList *list)
{
    Node *pNode = *list, *prevNode = *list;
    while(pNode && pNode->element != element) {
        prevNode = pNode;
        pNode = pNode->next;
    }

    if (pNode == NULL) {
        // Element not found
        return false;
    }

    prevNode->next = pNode->next;
    if (pNode == *list) {
        *list = pNode->next;
    }

    free(pNode);
    return true;
}

Node *findElementForLinkedList(Element element, LinkedList list)
{
    Node *pNode = list;
    while (pNode && pNode->element != element) {
        pNode = pNode->next;
    }

    return pNode;
}
