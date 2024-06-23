# OS-Multithreading-Assignment

## Description
This repository contains solutions to three multithreading problems in C, involving counting characters in a file, enhanced merge sort using multithreading, and parallel matrix multiplication. Each solution utilizes threads to improve computational efficiency.

## Repository Contents
- `Assignment.pdf`: The assignment document detailing the questions and requirements.
- `q1.c`: C program for counting characters in a file using 26 threads.
- `q2.c`: C program for sorting an array using multithreaded merge sort.
- `q3.c`: C program for performing matrix multiplication using 9 threads.
- `temp.txt`: A sample text file used for testing the character counting program.

## Assignment Questions

### Question 1: Character Counting
Write a program that takes a filename as input. The task is to count the number of alphabets in the mentioned file using 26 threads, each responsible for counting a specific letter. All threads will print their character count and also return the count to the main thread, which will print the sum of all characters in the file.

### Question 2: Multithreaded Merge Sort
Enhance the performance of merge sort using multithreading. Check the number of processor cores in your system, create an equivalent number of threads, and divide the array among these threads for sorting. The program should print the number of cores and the MAC address of your system at the start.

### Question 3: Parallel Matrix Multiplication
Improve the performance of matrix multiplication using multithreading. Create 9 threads to calculate each element of the resultant 3x3 matrix by multiplying two 3x3 matrices provided by the user.

## Compilation and Execution
### Question 1: Character Counting
1. Compile the program:
   ```bash
   gcc -o q1 q1.c -pthread
2. Run the program
   ```bash
   ./q1 temp.txt

### Question 2: Multithreaded Merge Sort
1. Compile the program:
   ```bash
   gcc -o q2 q2.c -pthread
2. Run the program
   ```bash
   ./q2

### Question 3: Parallel Matrix Multiplication
1. Compile the program:
   ```bash
   gcc -o q3 q3.c -pthread
2. Run the program
   ```bash
   ./q3

## Note
Ensure you have a Linux environment set up for compiling and running the programs.
Each program should be run in a Unix-based environment.
   
