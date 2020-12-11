#include "closestpair.h"
#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::endl;

int main()
{
    vector<point> my_data = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}}; //got this from the geeksforgeels example
    double thing = PrintRetClosestPair(my_data);
    cout << thing << endl;
    return 0;
}