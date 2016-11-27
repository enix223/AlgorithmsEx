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

#include <stdlib.h>
#include <time.h>
#include "bm_compare.h"
#include "exhaustive_search.h"
#include "divide_and_conquer.h"


#define MAX_TEST_ARRAY_SIZE     1000000
#define TEST_INCR_SIZE          10
#define TIMEIT(tag, func)       do{                                                         \
                                    clock_t start = clock();                                \
                                    (func);                                                 \
                                    clock_t end = clock();                                  \
                                    double elapse = (double)(end - start)/CLOCKS_PER_SEC;   \
                                    printf("[%s] Execution times: %.10f", tag, elapse);     \
                                }while(0)

void findMaxSubarrayPerformanceCompare()
{
    int numOfElem = 10;
    int *arr;
    int maxLeft, maxRight, MaxSum;

    arr = malloc(numOfElem * sizeof(int));
    do
    {

        /* Find with divide and conquer */
        TIMEIT("divide and conquer", findMaxSubarray(arr, 0, numOfElem - 1, &maxLeft, &maxRight, &MaxSum));

        /* Find with exhaustive search */
        TIMEIT("exhaustive search", esFindMaxSubarray(arr, 0, numOfElem - 1, &maxLeft, &maxRight, &MaxSum));

        /* Increase the array size */
        numOfElem += TEST_INCR_SIZE;

        arr = realloc(arr, numOfElem * sizeof(int));
    }
    while(numOfElem < MAX_TEST_ARRAY_SIZE);
}
