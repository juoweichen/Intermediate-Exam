# 42 C Intermediate-Exam
Intermediate exam subjects and solution<br>
**Note:** Not complete means not passed on examshell yet<br>
**Note:** Subjects might change

## Quick Start
Subject description => Subject.en.txt<br>
execution:
```
sh exec.sh
./a.out
```

## Level 0:
**count_of_2**<br>
Implement a function which counts, for a given integer n, the number of 2s that appear in all the numbers between 0 and n (inclusive).<br>
<br>
**equation**<br>
The goal of this exercise is to find all possible answers to the following<br>
	AB + CA = n
<br>
where A, B, and C are individual digits [0-9] and n is an integer.<br>
<br>
**find_pivot**<br>
Given an array of integers and its size passed as parameters, create a function able to return the pivot index of this array. <br>
The pivot index is the index where the sum of the numbers on the left
is equal to the sum of the numbers on the right.<br>
<br>
**is_anagram**<br>
An anagram is a sequence of characters formed by rearranging the letters of
another sequence, such as 'cinema', formed from 'iceman'.<br>
Given two strings as parameters, create a function able to tell whether or
not the first string is an anagram of the second.<br>
<br>
**print_doublon**<br>
Given two sorted arrays passed as parameters, create a function able to print all the number that are present in one array and in the other, separated by a space. <br>

## Level 1:
**stack**<br>
Implement a stack data structure in C<br>
<br>
**count_alpha**<br>
Write a program called count_alpha that takes a string and displays the number of occurences of its alphabetical characters. Other characters are not counted.<br>
The order is the order of occurence in the string. The display must be ended by a newline.<br>
<br>
**flood_fill**<br>
Write a function that takes a char ** as a 2-dimensional array of char, a t_point as the dimensions of this array and a t_point as the starting point.<br>

Starting from the given 'begin' t_point, this function fills an entire zone by replacing characters inside with the character 'F'. A zone is an group of the same character delimitated horizontally and vertically by other characters
or the array boundry.<br>
<br>
**height_tree**<br>
Implement a function to calculate the height of an n-ary tree.<br>
<br>
**queue**<br>
Implement a queue data structure in C.<br>

## Level 2:
**reverse_tree**<br>
Implement a function to reverse a binary tree (i.e., flip it from right to left).<br>
<br>
**is_looping**<br>
Given the first node of a linked list as parameter, create a function which returns 1 if the linked list is looping, otherwise 0.<br>
<br>
**ord_alphlong**<br>
Write a program that takes a string as a parameter and prints its words sorted in order of their length first and then in alphabetical order on each line: <br>
when we say alphabetical order we ignore the case of letters.<br>
<br>
**str_maxlenoc**<br>
Write a program that takes one or more strings and displays, followed by a newline, the longest string that appears in every parameter. If more that one string qualifies, it will display the one that appears first in the first parameter. Note that the empty string technically appears in any string.<br>

## Not complete:
**longest_sequence**<br>
Given the root node of a binary tree, create a function that return the length of the longest path which comprises of nodes with consecutive values in increasing order.<br>
Every node is considered as a path of length 1.<br>

# Level 3:

## Not complete:
**convert_bst**<br>
A binary search tree (BST) is a binary tree in which every node fits a specific ordering property :<br>
all left descendants <= n < all right descendants<br>
This must be true for each node n.<br>
<br>

**perimeter**<br>
Implement a function which prints the perimeter of a binary tree.<br>
<br>
The perimeter is defined as follows :<br>
- leftmost nodes from top to bottom
- leaf nodes from left to right
- rightmost nodes from bottom to top
<br>

**width_tree**<br>
Given the root node of a binary tree, create a function that returns the 'width' of the tree, which is the number of node present on the longest path between two leaves in the tree.<br>
<br>
