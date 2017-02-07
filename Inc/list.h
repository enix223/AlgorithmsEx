#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdbool.h>

/**
 * +---- ListHead
 * |
 * v
 * +---------+    +--> +---------+    +--> +---------+
 * | Element |    |    | Element |    |    | Element |
 * +---------+    |    +---------+    |    +---------+
 * |   Next  | ---+    |   Next  | ---+    |   Next  | ---\
 * +---------+         +---------+         +---------+    |
 *                                                       ---
 *                                                        -
 */

#ifdef __cplusplus
extern "C" {
#endif 

typedef int Element;
typedef struct Node {
    Element element;
    struct Node *next;
} Node, *LinkedList;


LinkedList CreateLinkedList(void);

bool DestroyLinkedList(LinkedList list);

void InsertElementToLinkedList(Element element, LinkedList *list);

bool DeleteElementFromLinkedList(Element element, LinkedList *list);

Node *findElementForLinkedList(Element element, LinkedList list);

#ifdef __cplusplus
}
#endif 

#endif  /* LIST_H_INCLUDED */