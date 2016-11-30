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
#include <stdio.h>

#include "bm_compare.h"
#include "timeit.h"
#include "exhaustive_search.h"
#include "divide_and_conquer.h"

#define MAX_TEST_ARRAY_SIZE     100
#define TEST_INCR_SIZE          1

void findMaxSubarrayPerformanceCompare(const char *resultFilePath)
{
    int numOfElem = 1;
    int *arr;
    int maxLeft, maxRight, MaxSum;
    int cycle = 0;
    double result1[MAX_TEST_ARRAY_SIZE/TEST_INCR_SIZE], result2[MAX_TEST_ARRAY_SIZE/TEST_INCR_SIZE];
    FILE *f;
    char line[30] = {'0'};

    if ((f = fopen(resultFilePath, "w")) == NULL)
    {
        printf("Can't open file %s", resultFilePath);
        return;
    }

    arr = malloc(numOfElem * sizeof(int));
    do
    {
        /* Find with divide and conquer */
        TIMEIT(DIVIDE_AND_CONQUER, findMaxSubarray(arr, 0, numOfElem - 1, &maxLeft, &maxRight, &MaxSum), &result1[cycle]);

        /* Find with exhaustive search */
        TIMEIT(EXHAUSTIVE_SEARCH, esFindMaxSubarray(arr, 0, numOfElem - 1, &maxLeft, &maxRight, &MaxSum), &result2[cycle]);

#if (BENCHMARK_VERBOSE)
        printf("[Cycle %d] Arr size: %d, Elapse: %.10f, %.10f\n", cycle, numOfElem, result1[cycle], result2[cycle]);
#endif // BENCHMARK_VERBOSE

        sprintf(line, "%.10f %.10f\n", result1[cycle], result2[cycle]);
        fwrite(line, strlen(line), 1, f);

        /* Increase the array size */
        numOfElem += TEST_INCR_SIZE;

        arr = realloc(arr, numOfElem * sizeof(int));

        cycle ++;
    }
    while(numOfElem < MAX_TEST_ARRAY_SIZE);

    fclose(f);
}
