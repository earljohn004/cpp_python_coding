# Python Coding Problem
Refactor the code and fix problems.
Create a python script to update the BuildNum of `SConstruct` file and `VERSION` file

## Pre-requisites
```bash

export BuildNum=12345

# assign any value to BuildNum variable
```
- Use `python3` command to run the program

```bash
python3 original_updater.py
python3 updater_newsolution.py 
```

## Solution 1 : Refactor the Old Code
filename is [original_updater.py](https://github.com/earljohn004/cpp_python_coding/blob/master/python_problem/original_updater.py). Fixed the wrong parameter of chmod command from 755 to 775

## Solution 2 : New Solution
filename is [updater_newsolution.py](https://github.com/earljohn004/cpp_python_coding/blob/master/python_problem/updater_newsolution.py)
Solution 2 is tested on a macOS machine. The main solution uses python subprocess command to run `sed` command to perform string manipulation same as solution 1

note: Solution 2 is not tested on a linux machine. `sed -i` command in macOS has an extra parameter compared to linux
