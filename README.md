# Patterns-possible-on-a-smartphone
Given the restriction that a dot must be used the first time it is passed over, it is not as simple as counting the number of permutations of dots:
submission from k=4 to k=9:
9!/(9-k)!=985824
The Android imposes these conditions on patterns:
Each pattern must connect at least four dots.
The dots in the pattern must all be distinct.
If the line segment connecting any two consecutive dots in the pattern passes through any other dots, the other dots must have previously been in the pattern.


A pattern can be pretty much anything you want with the following constraints:
It needs to contain at least four dots (and obviously, no more than nine).
Once a dot is lit, it can't be used again.
You can use one or several "knight moves", such as in [0 5 4 2]:


In this example, the knight move is between 0 and 5.
You cannot go over an unlit dot without lighting it. For example, the pattern [0 2 1 4] is illegal, because moving your finger between 0 and 2 will light 1.
Once a dot is lit, you can use it to reach another unlit dot. For example, both [0 4 3 5] and [0 4 5 3] are legal.

I tried hard to enlist all possible solutions using basic principles of discrete maths, but its meant to be done by brute force.

Using basic symmetries, Mathematica and basic coding algorithms we can arrive at the requisite answer.

First let us enlist all possible permutations  of length greater than 4 from integers 1-9.

Then the algorithm just iterates through this listing, splitting each listing into an array of integers,and then, for each number, asks if the next number is a valid step given the history of this path (which is just the array up to that point). Obviously, we could reverse the process and just generate the right opts, but it would mean that we would have to iterate through every single step in every path, which would be unnecessary in most cases.

The magic number is 389112

4 dots: 1624 solutions
5 dots: 7152 solutions
6 dots: 26016 solutions 
7 dots: 72912 solutions
8 dots: 140704 solutions
9 dots: 140704 solutions 
Total:  389112
