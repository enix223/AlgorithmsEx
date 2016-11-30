/**
  *  -
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


#ifndef TIMEIT_H_INCLUDED
#define TIMEIT_H_INCLUDED

#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

typedef void *timeFunc(void);

double timeit(char *tag, timeFunc func);


#define TIMEIT(tag, func, elapse)       do{                                                         \
                                            clock_t start = clock();                                \
                                            (func);                                                 \
                                            clock_t end = clock();                                  \
                                            *elapse = (double)(end - start)/CLOCKS_PER_SEC;         \
                                        }while(0)


#define TIMEIT_PRINT(tag, func)         do{                                                         \
                                            clock_t start = clock();                                \
                                            (func);                                                 \
                                            clock_t end = clock();                                  \
                                            double elapse = (double)(end - start)/CLOCKS_PER_SEC;   \
                                            printf("[%s] Execution times: %.10f\n", tag, elapse);   \
                                        }while(0)

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // TIMEIT_H_INCLUDED
