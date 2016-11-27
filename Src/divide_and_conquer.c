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
#include "divide_and_conquer.h"


static void findMaxCrossingSubArray(int *arr, int low, int mid, int high,
                                    int *maxLow, int *maxHigh, int *subArrsum);

void findMaxSubarray(int *arr, int low, int high,
                     int *resultLow, int *resultHigh, int *sum)
{
    int ll, lh, lsum;
    int rl, rh, rsum;
    int ml, mh, msum;
    int mid;

    if (low == high)
    {
        *resultLow = low;
        *resultHigh = high;
        *sum = arr[low];
        return;
    }
    else
    {
        mid = (low + high) / 2;

        /* Find left half max sub array */
        findMaxSubarray(arr, low, mid, &ll, &lh, &lsum);

        /* Find right half max sub array */
        findMaxSubarray(arr, mid + 1, high, &rl, &rh, &rsum);

        /* Find cross mid max sub array */
        findMaxCrossingSubArray(arr, low, mid, high, &ml, &mh, &msum);

        if (lsum > msum && lsum > rsum)
        {
            *resultLow = ll;
            *resultHigh = lh;
            *sum = lsum;
        }
        else if (rsum > lsum && rsum > msum)
        {
            *resultLow = rl;
            *resultHigh = rh;
            *sum = rsum;
        }
        else
        {
            *resultLow = ml;
            *resultHigh = mh;
            *sum = msum;
        }
    }
}


/**
 * @brief Private methods
 */
static void findMaxCrossingSubArray(int *arr, int low, int mid, int high,
                                    int *maxLow, int *maxHigh, int *subArrsum)
{
    int leftSum = INT_MIN, rightSum = INT_MIN;
    int sum = 0;
    int maxLeft = 0, maxRight = 0;
    int i ;
    for (i = mid; i >= low; i --)
    {
        sum += arr[i];
        if ( sum > leftSum )
        {
            leftSum = sum;
            maxLeft = i;
        }
    }

    sum = 0;
    for (i = mid + 1; i <= high; i ++)
    {
        sum += arr[i];
        if ( sum > rightSum )
        {
            rightSum = sum;
            maxRight = i;
        }
    }

    *maxLow = maxLeft;
    *maxHigh = maxRight;
    *subArrsum = leftSum + rightSum;
}
