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

#ifndef DIVIDE_AND_CONQUER_H_INCLUDED
#define DIVIDE_AND_CONQUER_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 * @brief Find a sub array in the given `arr`array with the max sum value
 * @param arr: The pointer to the origin array
 * @param low: The lower bound of the finding range
 * @param high: The higer bound of the finding range
 * @param resultLow: The pointer to the lower bound for the maximum subarray
 * @param resultHigh: The pointer to the higher bound for the maximum subarray
 * @param sum: The pointer to keep the sum of the maximum subarray
 * @return None
 */
void findMaxSubarray(int *arr, int low, int high,
                     int *resultLow, int *resultHigh, int *sum);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // DIVIDE_AND_CONQUER_H_INCLUDED
