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

#ifndef EXHAUSTIVE_SEARCH_H_INCLUDED
#define EXHAUSTIVE_SEARCH_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 * Find the sub array with maximum sum in `arr` with range from `low` and `high`.
 * This funciton is using exhaustive search
 * @param arr        The array pointer which would be used for search
 * @param low        The lower boundary for the search range
 * @param high       The higher boundary for the search range
 * @param resultLow  The lower boundary for the subarray with maximum sum
 * @param resultHigh The higher boundary for the subarray with maximum sum
 * @param sum        The sum of the subarray with maximum sum
 * @return           None
 */
void esFindMaxSubarray(int *arr, int low, int high,
                       int *resultLow, int *resultHigh, int *sum);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // EXHAUSTIVE_SEARCH_H_INCLUDED
