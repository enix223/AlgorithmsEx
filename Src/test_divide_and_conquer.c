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
#include "test_divide_and_conquer.h"
#include "divide_and_conquer.h"

int initTestSuiteForDivideAndConquer(void)
{
    return 0;
}

int cleanTestSuiteForDivideAndConquer(void)
{
    return 0;
}

void testFindMaxSubArrayEvenLongOnLeft(void)
{
    int arr[] = {10, 1, 2, -9999, 1, 2};

    int resultLow, resultHigh, sum;
    findMaxSubarray(arr, 0, sizeof(arr)/sizeof(int) - 1, &resultLow, &resultHigh, &sum);
    CU_ASSERT(resultLow == 0);
    CU_ASSERT(resultHigh == 2);
    CU_ASSERT(sum == 13);
}

void testFindMaxSubArrayEvenLongOnRight(void)
{
    int arr[] = {10, 1, -9999, 123, 2, 1};

    int resultLow, resultHigh, sum;
    findMaxSubarray(arr, 0, sizeof(arr)/sizeof(int) - 1, &resultLow, &resultHigh, &sum);
    CU_ASSERT(resultLow == 3);
    CU_ASSERT(resultHigh == 5);
    CU_ASSERT(sum == 126);
}

void testFindMaxSubArrayEvenLongOnMid(void)
{
    int arr[] = {-10, 18, 3, 9, 1, -2};

    int resultLow, resultHigh, sum;
    findMaxSubarray(arr, 0, sizeof(arr)/sizeof(int) - 1, &resultLow, &resultHigh, &sum);
    CU_ASSERT(resultLow == 1);
    CU_ASSERT(resultHigh == 4);
    CU_ASSERT(sum == 31);
}

void testFindMaxSubArrayOddLongOnLeft(void)
{
    int arr[] = {10, 1, -9999, 1, 2};

    int resultLow, resultHigh, sum;
    findMaxSubarray(arr, 0, sizeof(arr)/sizeof(int) - 1, &resultLow, &resultHigh, &sum);
    CU_ASSERT(resultLow == 0);
    CU_ASSERT(resultHigh == 1);
    CU_ASSERT(sum == 11);
}

void testFindMaxSubArrayOddLongOnRight(void)
{
    int arr[] = {10, 1, -9999, 123, 2};

    int resultLow, resultHigh, sum;
    findMaxSubarray(arr, 0, sizeof(arr)/sizeof(int) - 1, &resultLow, &resultHigh, &sum);
    CU_ASSERT(resultLow == 3);
    CU_ASSERT(resultHigh == 4);
    CU_ASSERT(sum == 125);
}

void testFindMaxSubArrayOddLongOnMid(void)
{
    int arr[] = {-10, 18, 9, 1, -2};

    int resultLow, resultHigh, sum;
    findMaxSubarray(arr, 0, sizeof(arr)/sizeof(int) - 1, &resultLow, &resultHigh, &sum);
    CU_ASSERT(resultLow == 1);
    CU_ASSERT(resultHigh == 3);
    CU_ASSERT(sum == 28);
}

void testFindMaxSubArrayWithOneElemArr(void)
{
    int arr[] = {1};

    int resultLow, resultHigh, sum;
    findMaxSubarray(arr, 0, sizeof(arr)/sizeof(int) - 1, &resultLow, &resultHigh, &sum);
    CU_ASSERT(resultLow == 0);
    CU_ASSERT(resultHigh == 0);
    CU_ASSERT(sum == 1);
}

void testFindMaxSubArrayWithAllPositiveArr(void)
{
    int arr[] = {1, 2, 3, 4, 5, 6};

    int resultLow, resultHigh, sum;
    findMaxSubarray(arr, 0, sizeof(arr)/sizeof(int) - 1, &resultLow, &resultHigh, &sum);
    CU_ASSERT(resultLow == 0);
    CU_ASSERT(resultHigh == 5);
    CU_ASSERT(sum == 21);
}

void testFindMaxSubArrayWithAllNegativeAscArr(void)
{
    int arr[] = {-1, -2, -3, -4, -5, -6};

    int resultLow, resultHigh, sum;
    findMaxSubarray(arr, 0, sizeof(arr)/sizeof(int) - 1, &resultLow, &resultHigh, &sum);
    CU_ASSERT(resultLow == 0);
    CU_ASSERT(resultHigh == 0);
    CU_ASSERT(sum == -1);
}

void testFindMaxSubArrayWithAllNegativeDescArr(void)
{
    int arr[] = {-6, -5, -4, -3, -2, -1};

    int resultLow, resultHigh, sum;
    findMaxSubarray(arr, 0, sizeof(arr)/sizeof(int) - 1, &resultLow, &resultHigh, &sum);
    CU_ASSERT(resultLow == 5);
    CU_ASSERT(resultHigh == 5);
    CU_ASSERT(sum == -1);
}

CU_pSuite createDivideAndConquerTestSuite(void)
{
    CU_pSuite pSUITE = NULL;

    pSUITE = CU_add_suite("test divide and conquer",
                          initTestSuiteForDivideAndConquer,
                          cleanTestSuiteForDivideAndConquer);
    if (NULL == pSUITE)
    {
        return NULL;
    }

    if (NULL == CU_add_test(pSUITE,
                            "test odd length array with result on left for findMaxSubarray",
                            testFindMaxSubArrayOddLongOnLeft) ||
        NULL == CU_add_test(pSUITE,
                            "test odd length array with result on right for findMaxSubarray",
                            testFindMaxSubArrayOddLongOnRight) ||
        NULL == CU_add_test(pSUITE,
                            "test odd length array with result on mid for findMaxSubarray",
                            testFindMaxSubArrayOddLongOnMid) ||
        NULL == CU_add_test(pSUITE,
                            "test even length array with result on left for findMaxSubarray",
                            testFindMaxSubArrayEvenLongOnLeft) ||
        NULL == CU_add_test(pSUITE,
                            "test even length array with result on right for findMaxSubarray",
                            testFindMaxSubArrayEvenLongOnRight) ||
        NULL == CU_add_test(pSUITE,
                            "test even length array with result on mid for findMaxSubarray",
                            testFindMaxSubArrayEvenLongOnMid) ||
        NULL == CU_add_test(pSUITE,
                            "test one elem array for findMaxSubarray",
                            testFindMaxSubArrayWithOneElemArr) ||
        NULL == CU_add_test(pSUITE,
                            "test array with all positive for findMaxSubarray",
                            testFindMaxSubArrayWithAllPositiveArr) ||
        NULL == CU_add_test(pSUITE,
                            "test array with all negative in asc order for findMaxSubarray",
                            testFindMaxSubArrayWithAllNegativeAscArr) ||
        NULL == CU_add_test(pSUITE,
                            "test array with all negative in desc order for findMaxSubarray",
                            testFindMaxSubArrayWithAllNegativeDescArr)
    )
    {
        return NULL;
    }

    return pSUITE;
}
