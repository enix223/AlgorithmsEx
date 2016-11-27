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

#include <limits.h>
#include "exhaustive_search.h"

void esFindMaxSubarray(int *arr, int low, int high,
                       int *resultLow, int *resultHigh, int *sum)
{
    int i, j, k, tempSum = INT_MIN;
    int candidateSum = INT_MIN, tempLow, tempHigh;

    if (low == high)
    {
        *resultLow = low;
        *resultHigh = low;
        *sum = arr[low];
        return;
    }


    for (i = low; i <= high; i ++)
    {
        for (j = low; j <= i; j ++)
        {
            tempSum = 0;
            for (k = j; k <= i; k ++)
            {
                tempSum += arr[k];
            }

            if (tempSum > candidateSum)
            {
                candidateSum = tempSum;
                tempLow = j;
                tempHigh = i;
            }
        }
    }

    *resultLow = tempLow;
    *resultHigh = tempHigh;
    *sum = candidateSum;
}
