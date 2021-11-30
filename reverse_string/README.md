# Solution to String Reversal Problem
Makefile sets `TEST_MODE`  by default, comment `TEST_MODE` in line 42 of MakeFile to run program in non-test mode.

## Problem
Reverse each word in the input string. The order of the words will be unchanged.
A word is made up of letters and/or numbers. Other characters (spaces, punctuation) will not be reversed.

## Summary of Solution
- The solution is found in [src/solution.cpp](https://github.com/earljohn004/cpp_python_coding/blob/master/reverse_string/src/solution.cpp)
- The test cases are found in [src/main.cpp](https://github.com/earljohn004/cpp_python_coding/blob/master/reverse_string/src/main.cpp) , a lightweight unit_test_framework is used. 

### How to run
1. compile the code using `make`
2. run the program using `make run`

#### Sample output in Test Mode
```bash
Running test: test_alternate_characters
PASS
Running test: test_basic_numbers_only
PASS
Running test: test_basic_reversal
PASS
Running test: test_combination_multiple_words
PASS
Running test: test_no_alphanumeric
PASS
Running test: test_required
PASS
Running test: test_solo_characters
PASS

*** Results ***
** Test case "test_alternate_characters": PASS
** Test case "test_basic_numbers_only": PASS
** Test case "test_basic_reversal": PASS
** Test case "test_combination_multiple_words": PASS
** Test case "test_no_alphanumeric": PASS
** Test case "test_required": PASS
** Test case "test_solo_characters": PASS
*** Summary ***
Out of 7 tests run:
0 failure(s), 0 error(s)

```

#### Sample output in Non-Test Mode
> Comment line 42 in Makefile,  clean project using `make clean` then compile`make` and run `make run`

```bash
Build Success
func:main (L:32) [LOG_MES] origin = Stri_ng;-%   2b$#e reversed
func:main (L:33) [LOG_VAR] result = irtS_gn;-%   b2$#e desrever
```

notes:
https://github.com/earljohn004/cppgenericmakefile my folder structure and Makefile template
https://github.com/eecs280staff/unit_test_framework for the unit_test_framework 
