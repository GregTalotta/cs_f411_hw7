#include "closestpair.h"
#include <cmath>
#include <algorithm>
#include <iostream>
using std::abs;
using std::cout;
using std::endl;
using std::min;
using std::pow;
using std::sort;
using std::sqrt;
using std::vector;

// internal use functions
struct ret
{
    double distance;
    int operations;
};

struct input
{
    int start_pos = 0;
    int end_pos = -1;
    int curr_operations = 0;
};

bool compare_x(const point &n1, const point &n2)
{
    return n1.x < n2.x;
}

bool compare_y(const point &n1, const point &n2)
{
    return n1.y < n2.y;
}

// more or less the function from the book
ret ClosestPairLong(const vector<point> &data_x, const vector<point> &data_y, input stuff)
{
    int size = stuff.end_pos - stuff.start_pos;
    if (size <= 3)
    {
        double d = 1000000000000000000.0; //ok not the best way to do it.
        for (int i = stuff.start_pos; i < stuff.end_pos - 1; ++i)
        {
            for (int j = i + 1; j < stuff.end_pos; ++j)
            {
                d = min(d, sqrt(pow((data_x[i].x - data_x[j].x), 2) + pow((data_x[i].y - data_x[j].y), 2)));
            }
        }
        return {d, stuff.curr_operations};
    }
    int midpoint = stuff.end_pos - size / 2;
    //new y vector 1
    vector<point> q_1;
    for (int i = stuff.start_pos; i < midpoint; ++i)
    {
        q_1.push_back(data_x[i]);
    }
    sort(q_1.begin(), q_1.end(), compare_y);
    //new y vector 2
    vector<point> q_2;
    for (int i = midpoint; i < stuff.end_pos; ++i)
    {
        q_2.push_back(data_x[i]);
    }
    sort(q_2.begin(), q_2.end(), compare_y);
    //recursive calls
    stuff.curr_operations++;
    input new_1 = {stuff.start_pos, midpoint, stuff.curr_operations};
    stuff.curr_operations++;
    input new_2 = {midpoint, stuff.end_pos, stuff.curr_operations};
    ret d_1 = ClosestPairLong(data_x, q_1, new_1);
    ret d_2 = ClosestPairLong(data_x, q_2, new_2);
    //the rest
    double d = min(d_1.distance, d_2.distance);
    double dd = pow(d, 2);
    int x_of_mid = data_x[midpoint].x;
    vector<point> s;
    for (int i = stuff.start_pos; i < stuff.end_pos; ++i)
    {
        if (abs(data_y[i].x - x_of_mid) < d)
        {
            s.push_back(data_y[i]);
        }
    }
    int k = 0;
    for (int i = 0; i <= s.size() - 2; ++i)
    {
        k = i + 1;
        while ((k <= s.size() - 1) && (pow(s[k].y - s[i].y, 2) < dd))
        {
            dd = min(((double)s[k].x - (double)s[i].x) + ((double)s[k].y - (double)s[i].y), dd);
            ++k;
        }
    }
    return {sqrt(dd), d_1.operations + d_2.operations};
}

// jumper function
ret ClosestPairRet(vector<point> &data)
{
    vector<point> data_y = data;
    sort(data.begin(), data.end(), compare_x);
    sort(data_y.begin(), data_y.end(), compare_y);
    return ClosestPairLong(data, data_y, {0, data.size(), 0});
}

//************************* end internal functions ***************************

// normal
double ClosestPair(std::vector<point> data)
{
    return ClosestPairRet(data).distance;
}

//prints the number operation 
void PrintClosestPair(std::vector<point> data)
{
    ret info = ClosestPairRet(data);
    cout << "It did " << info.operations << " operations." << endl;
}

// prints and return a value... so side effects
double PrintRetClosestPair(std::vector<point> data)
{
    ret info = ClosestPairRet(data);
    cout << "It did " << info.operations << " operations." << endl;
    return info.distance;
}

// returns the number of operations.
int ClosestPairOperations(std::vector<point> data)
{
    return ClosestPairRet(data).operations;
}