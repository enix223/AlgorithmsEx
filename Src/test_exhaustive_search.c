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
#include "exhaustive_search.h"
#include "test_exhaustive_search.h"

int initTestSuiteForExhaustiveSearch(void)
{
    return 0;
}

int cleanTestSuiteForExhaustiveSearch(void)
{
    return 0;
}

void testesFindMaxSubarrayEvenLongOnLeft(void)
{
    int arr[] = {10, 1, 2, -9999, 1, 2};

    int resultLow, resultHigh, sum;
    esFindMaxSubarray(arr, 0, sizeof(arr)/sizeof(int) - 1, &resultLow, &resultHigh, &sum);
    CU_ASSERT(resultLow == 0);
    CU_ASSERT(resultHigh == 2);
    CU_ASSERT(sum == 13);
}

void testesFindMaxSubarrayEvenLongOnRight(void)
{
    int arr[] = {10, 1, -9999, 123, 2, 1};

    int resultLow, resultHigh, sum;
    esFindMaxSubarray(arr, 0, sizeof(arr)/sizeof(int) - 1, &resultLow, &resultHigh, &sum);
    CU_ASSERT(resultLow == 3);
    CU_ASSERT(resultHigh == 5);
    CU_ASSERT(sum == 126);
}

void testesFindMaxSubarrayEvenLongOnMid(void)
{
    int arr[] = {-10, 18, 3, 9, 1, -2};

    int resultLow, resultHigh, sum;
    esFindMaxSubarray(arr, 0, sizeof(arr)/sizeof(int) - 1, &resultLow, &resultHigh, &sum);
    CU_ASSERT(resultLow == 1);
    CU_ASSERT(resultHigh == 4);
    CU_ASSERT(sum == 31);
}

void testesFindMaxSubarrayOddLongOnLeft(void)
{
    int arr[] = {10, 1, -9999, 1, 2};

    int resultLow, resultHigh, sum;
    esFindMaxSubarray(arr, 0, sizeof(arr)/sizeof(int) - 1, &resultLow, &resultHigh, &sum);
    CU_ASSERT(resultLow == 0);
    CU_ASSERT(resultHigh == 1);
    CU_ASSERT(sum == 11);
}

void testesFindMaxSubarrayOddLongOnRight(void)
{
    int arr[] = {10, 1, -9999, 123, 2};

    int resultLow, resultHigh, sum;
    esFindMaxSubarray(arr, 0, sizeof(arr)/sizeof(int) - 1, &resultLow, &resultHigh, &sum);
    CU_ASSERT(resultLow == 3);
    CU_ASSERT(resultHigh == 4);
    CU_ASSERT(sum == 125);
}

void testesFindMaxSubarrayOddLongOnMid(void)
{
    int arr[] = {-10, 18, 9, 1, -2};

    int resultLow, resultHigh, sum;
    esFindMaxSubarray(arr, 0, sizeof(arr)/sizeof(int) - 1, &resultLow, &resultHigh, &sum);
    CU_ASSERT(resultLow == 1);
    CU_ASSERT(resultHigh == 3);
    CU_ASSERT(sum == 28);
}

void testesFindMaxSubarrayWithOneElemArr(void)
{
    int arr[] = {1};

    int resultLow, resultHigh, sum;
    esFindMaxSubarray(arr, 0, sizeof(arr)/sizeof(int) - 1, &resultLow, &resultHigh, &sum);
    CU_ASSERT(resultLow == 0);
    CU_ASSERT(resultHigh == 0);
    CU_ASSERT(sum == 1);
}

void testesFindMaxSubarrayWithAllPositiveArr(void)
{
    int arr[] = {1, 2, 3, 4, 5, 6};

    int resultLow, resultHigh, sum;
    esFindMaxSubarray(arr, 0, sizeof(arr)/sizeof(int) - 1, &resultLow, &resultHigh, &sum);
    CU_ASSERT(resultLow == 0);
    CU_ASSERT(resultHigh == 5);
    CU_ASSERT(sum == 21);
}

void testesFindMaxSubarrayWithAllNegativeAscArr(void)
{
    int arr[] = {-1, -2, -3, -4, -5, -6};

    int resultLow, resultHigh, sum;
    esFindMaxSubarray(arr, 0, sizeof(arr)/sizeof(int) - 1, &resultLow, &resultHigh, &sum);
    CU_ASSERT(resultLow == 0);
    CU_ASSERT(resultHigh == 0);
    CU_ASSERT(sum == -1);
}

void testesFindMaxSubarrayWithAllNegativeDescArr(void)
{
    int arr[] = {-6, -5, -4, -3, -2, -1};

    int resultLow, resultHigh, sum;
    esFindMaxSubarray(arr, 0, sizeof(arr)/sizeof(int) - 1, &resultLow, &resultHigh, &sum);
    CU_ASSERT(resultLow == 5);
    CU_ASSERT(resultHigh == 5);
    CU_ASSERT(sum == -1);
}

CU_pSuite createExhaustiveSearchTestSuite(void)
{
    CU_pSuite pSUITE = NULL;

    pSUITE = CU_add_suite("test divide and conquer",
                          initTestSuiteForExhaustiveSearch,
                          cleanTestSuiteForExhaustiveSearch);
    if (NULL == pSUITE)
    {
        return NULL;
    }

    if (NULL == CU_add_test(pSUITE,
                            "test odd length array with result on left for esFindMaxSubarray",
                            testesFindMaxSubarrayOddLongOnLeft) ||
        NULL == CU_add_test(pSUITE,
                            "test odd length array with result on right for esFindMaxSubarray",
                            testesFindMaxSubarrayOddLongOnRight) ||
        NULL == CU_add_test(pSUITE,
                            "test odd length array with result on mid for esFindMaxSubarray",
                            testesFindMaxSubarrayOddLongOnMid) ||
        NULL == CU_add_test(pSUITE,
                            "test even length array with result on left for esFindMaxSubarray",
                            testesFindMaxSubarrayEvenLongOnLeft) ||
        NULL == CU_add_test(pSUITE,
                            "test even length array with result on right for esFindMaxSubarray",
                            testesFindMaxSubarrayEvenLongOnRight) ||
        NULL == CU_add_test(pSUITE,
                            "test even length array with result on mid for esFindMaxSubarray",
                            testesFindMaxSubarrayEvenLongOnMid) ||
        NULL == CU_add_test(pSUITE,
                            "test one elem array for esFindMaxSubarray",
                            testesFindMaxSubarrayWithOneElemArr) ||
        NULL == CU_add_test(pSUITE,
                            "test array with all positive for esFindMaxSubarray",
                            testesFindMaxSubarrayWithAllPositiveArr) ||
        NULL == CU_add_test(pSUITE,
                            "test array with all negative in asc order for esFindMaxSubarray",
                            testesFindMaxSubarrayWithAllNegativeAscArr) ||
        NULL == CU_add_test(pSUITE,
                            "test array with all negative in desc order for esFindMaxSubarray",
                            testesFindMaxSubarrayWithAllNegativeDescArr)
    )
    {
        return NULL;
    }

    return pSUITE;
}
