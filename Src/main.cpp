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

#include <iostream>
#include <string.h>
#include "test.h"
#include "bm_compare.h"

#ifdef WINDOWS
    #include <direct.h>
    #define GetCurrentDir _getcwd
#else
    #include <unistd.h>
    #define GetCurrentDir getcwd
#endif

using namespace std;

static void printUsage()
{
    cout << "Usage: \n\tAlg [unittest|benchmark]\n." << endl;
}

int main(int argc, const char *argv[])
{
    cout << "Welcome to world of: \"Introduction to Algorithms\"..." << endl;

    if (argc >= 2)
    {
        if (strcmp(argv[1], "unittest") == 0)
        {
            cout << "Running unit test..." << endl;

            testRun();
        }
        else if (strcmp(argv[1], "benchmark") == 0)
        {
            if (argc == 3)
            {
                cout << "Running benchmark test..." << endl;

                findMaxSubarrayPerformanceCompare(argv[2]);
            }
            else
            {
                printUsage();
            }
        }
    }
    else
    {
        printUsage();
    }

    return 0;
}
