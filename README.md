# push_swap
Sorting data on a stack with a limited set of instructions

## Overview

This project from [School 42](https://42london.com) curriculum focuses on algorithm design and optimization. The goal is to sort a random set of numbers in ascending order using two stacks and a limited set of operations, including swapping, pushing, popping and rotating elements. The challenge lies in minimizing the number of moves required.

## Specifications
At the beginning there are two stacks: A and B. Stack A contains a random amount of negative and/or positive numbers which cannot be duplicated, and the stack B is empty. The goal is to sort in ascending order numbers into stack A, using only the following operations:

- sa (swap a) – swap the first 2 elements at the top of stack A;
- sb (swap b) – swap the first 2 elements at the top of stack B;
- ss – sa and sb at the same time;
- pa (push a) – take the first element at the top of B and put it at the top of A;
- pb (push b) – take the first element at the top of A and put it at the top of B.
- ra (rotate a) – shift up all elements of stack A by 1, so that the first element becomes the last one;
- rb (rotate b) – shift up all elements of stack B by 1, so that the first element becomes the last one;
- rr – ra and rb at the same time;
- rra (reverse rotate a) – shift down all elements of stack A by 1, the last element becomes the first one;
- rrb (reverse rotate b) – shift down all elements of stack B by 1, the last element becomes the first one;
- rrr – rra and rrb at the same time.

In School 42, all the code written in C must comply with the [42 Norm](https://cdn.intra.42.fr/pdf/pdf/960/norme.en.pdf). External functions allowed for this project: `read`, `write`, `malloc`, `free`, `exit`. The use of any other function not written by me is strictly forbidden.

## The algorithm
After dedicating almost a month to studying various sorting algorithms, including Bubble Sort, Quick Sort, Radix Sort, and others, as well as attempting to come up with my own solutions, I ultimately found that none proved as efficient as the so-called "Turk algorithm", described in this [Medium article](https://medium.com/@ayogun/push-swap-c1f5d2d41e97).

In summary, the process involves moving all elements from stack A to stack B, excluding the last three elements. At each step the "cheapest" number to move is selected, where "cheapest" refers to the number requiring the least operations. Then, the last three elements in stack A are sorted in place. Finally, all elements are pushed back to stack A, resulting in a fully sorted stack.

For a set of 100 random numbers, the algorithm required fewer than 700 operations, as defined by the instructions specified above. Similarly, for a larger set of 500 random numbers, the algorithm performed admirably, completing the sorting process in less than 5500 operations.

## Usage
To try out this project, `git clone` this repository to your local machine and run `make`. Once the compilation is complete, you will have an executable named `push_swap`. Run this executable with your set of numbers as arguments, for example: `./push_swap 5 2 8 1 3`. The program will output a series of instructions to sort the numbers.