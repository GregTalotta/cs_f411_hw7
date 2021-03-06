cs_f411_hw7

# Closest Pair

## What is it?

C++ divide and conquer implementation of closest pair, that also tracks how many
operations it did. It is based on the algorithm outlined in Levitin Anany.
Introduction to the Design and Analysis of Algorithms (p. 195). Pearson
Education. Kindle Edition.

## How to Use

First add the .cpp and .h to your project folder. Then include the header in
your file. Call one of the five functions with a vector of points. Point is a
struct that has an int for x, and an int for y. It does not modify the original
data.

```c++
struct point
{
    int x;
    int y;
};
```

1. closestPair()
    1. Returns a double that is the distance between the closest pair.
1. printClosestPair()
    1. Returns nothing, but prints the number of operations done.
1. closestPairOperations()
    1. Returns an int that is the number of operations done.
1. printRetClosestPair()
    1. Prints the number of operations and returns the distance.
1. brute_force_cp()
    1. Prints the number of operations and returns the distance by brute force.

# Use my Testing File

For a quick way to run the code, modify or run my test.cpp.
