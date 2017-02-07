/**
  * AlgorithmEx - Exercise codes for 'Introdution of algorithms (Third edition)'
  *
  * MIT License
  *
  * Copyright (c) 2016 Enix Yu
  *
  * Permission is hereby granted, free of charge, to any person obtaining a copy
  * of this software and associated documentation files (the "Software"), to deal
  * in the Software without restriction, including without limitation the rights
  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  * copies of the Software, and to permit persons to whom the Software is
  * furnished to do so, subject to the following conditions:
  *
  * The above copyright notice and this permission notice shall be included in all
  * copies or substantial portions of the Software.
  *
  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  * SOFTWARE.
  *******************************************************************************
  */

#include <stdio.h>
#include <string.h>
#include "Basic.h"
#include "list.h"
#include "test_list.h"


int initTestSuiteForList(void)
{
    return 0;
}

int cleanTestSuiteForList(void)
{
    return 0;
}

void testLinkedListCreate(void)
{
    LinkedList list = CreateLinkedList();
    CU_ASSERT(list != NULL);
    CU_ASSERT(list->element == 0);
    CU_ASSERT(list->next == NULL);
}

void testLinkedListDestroy(void)
{
    LinkedList list = CreateLinkedList();
    
    Element newElem = 1;
    InsertElementToLinkedList(newElem, &list);
    newElem = 2;
    InsertElementToLinkedList(newElem, &list);
    newElem = 3;
    InsertElementToLinkedList(newElem, &list);

    DestroyLinkedList(list);
}

void testLinkedListInsertElement(void)
{
    LinkedList list = CreateLinkedList();
    LinkedList prevNode;
    prevNode = list;
    Element newElem;

    for (int i = 0; i < 100; i ++)
    {
      newElem = i;
      InsertElementToLinkedList(newElem, &list);
      CU_ASSERT(list->element == newElem);
      CU_ASSERT(list->next == prevNode);
      prevNode = list;  
    }

    DestroyLinkedList(list);
}

void testLinkedListDeleteElement(void)
{
    LinkedList list = CreateLinkedList();
    LinkedList prevNode;
    prevNode = list;

    for (int i = 0; i < 100; i ++)
    {
      InsertElementToLinkedList(i, &list);
      CU_ASSERT(list->element == i);
      CU_ASSERT(list->next == prevNode);
      prevNode = list;  
    }

    for (int i = 200; i > 0; i --)
    {
        bool flag = DeleteElementFromLinkedList(i, &list);
        if (i < 100) 
        {
            CU_ASSERT_TRUE(flag);
        } 
        else 
        {
            // Element not found case
            CU_ASSERT_FALSE(flag);
        }

        if (i >= 100)
        {
            CU_ASSERT(list->element == 99);
        }
        else
        {
            CU_ASSERT(list->element == i - 1);
        }
    }

    DestroyLinkedList(list);
}

void testLinkedListFindElement(void)
{
    LinkedList list = CreateLinkedList();
    Node *targetNode;
    for (int i = 0; i < 100; i ++)
    {
      InsertElementToLinkedList(i, &list);
      if (i == 88) 
      {
          targetNode = list;
      }
    }

    Node *found = findElementForLinkedList(88, list);
    CU_ASSERT(found != NULL);
    CU_ASSERT(targetNode == found);

    Node *notFound = findElementForLinkedList(188, list);
    CU_ASSERT(notFound == NULL);
}

CU_pSuite createListTestSuite(void)
{
    CU_pSuite pSUITE = NULL;

    pSUITE = CU_add_suite("test list data structure",
                          initTestSuiteForList,
                          cleanTestSuiteForList);
    if (NULL == pSUITE)
    {
        return NULL;
    }

    if (NULL == CU_add_test(pSUITE,
                            "test list create function",
                            testLinkedListCreate) ||
        NULL == CU_add_test(pSUITE,
                            "test list destroy function",
                            testLinkedListDestroy) ||
        NULL == CU_add_test(pSUITE,
                            "test list element insert",
                            testLinkedListInsertElement) ||
        NULL == CU_add_test(pSUITE,
                            "test list element delete",
                            testLinkedListDeleteElement) ||
        NULL == CU_add_test(pSUITE,
                            "test list element lookup function",
                            testLinkedListFindElement)
        )
    {
        return NULL;
    }

    return pSUITE;
}
