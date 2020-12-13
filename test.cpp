#include "closestpair.h"
#include <vector>
#include <algorithm>
using std::vector;
#include <iostream>
using std::cout;
using std::endl;
#include <time.h>

bool compare(const point &ob1, const point &ob2)
{
    return ((ob1.x == ob2.x) && (ob1.y == ob2.y));
}

int main()
{

    cout << "The geeks for geeks dataset." << endl;
    vector<point> my_data = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    double thing = printRetClosestPair(my_data);
    double answer = brute_force_cp(my_data);
    cout << "The correct answer is: 1.414214   You got: " << thing << "    brute force got: " << answer << endl;
    cout << endl
         << "random time" << endl;
    cout << "the data set is...:" << endl;
    srand(time(NULL));
    vector<point> random;
    for (int i = 0; i < 10000; ++i)
    {
        random.push_back({rand() % 100000, rand() % 100000});
    }
    vector<point>::iterator it = std::unique(random.begin(), random.end(), compare);
    thing = printRetClosestPair(random);
    answer = brute_force_cp(random);
    cout << "you got: " << thing << "    brute force got: " << answer << endl;
    return 0;
}