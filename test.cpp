#include "closestpair.h"
#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::endl;

int main()
{
    cout << "The geeks for geeks dataset." << endl;
    vector<point> my_data = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    double thing = PrintRetClosestPair(my_data);
    cout << "The correct answer is: 1.414214   You got: " << thing << endl;
    // I need more testing data, and I am not calculating it by hand...
    // I guess I can write a brute force and compare the answers.
    return 0;
}