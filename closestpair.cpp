#include "closestpair.h"
#include <cmath>
#include <algorithm>
#include <iostream>
#include <limits>
using std::abs;
using std::cout;
using std::endl;
using std::min;
using std::pow;
using std::sort;
using std::sqrt;
using std::vector;

// *******************internal use functions***************
struct result_type
{
    double distance;
    int operations;
};

struct info
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
result_type ClosestPairLong(const vector<point> &p, const vector<point> &q, info increment_data)
{
    int size = increment_data.end_pos - increment_data.start_pos;
    if (size <= 3)
    {
        double d = std::numeric_limits<double>::max();
        for (int i = increment_data.start_pos; i < increment_data.end_pos - 1; ++i)
        {
            for (int j = i + 1; j < increment_data.end_pos; ++j)
            {
                increment_data.curr_operations++;
                d = min(d, sqrt(pow(((double)p[i].x - (double)p[j].x), 2) + pow(((double)p[i].y - (double)p[j].y), 2)));
            }
        }
        return {d, increment_data.curr_operations};
    }
    int midpoint = increment_data.end_pos - size / 2;
    //new y vector 1
    vector<point> q_1;
    for (int i = increment_data.start_pos; i < midpoint; ++i)
    {
        q_1.push_back(p[i]);
    }
    sort(q_1.begin(), q_1.end(), compare_y);
    //new y vector 2
    vector<point> q_2;
    for (int i = midpoint; i < increment_data.end_pos; ++i)
    {
        q_2.push_back(p[i]);
    }
    sort(q_2.begin(), q_2.end(), compare_y);
    //recursive calls
    info new_1 = {increment_data.start_pos, midpoint, increment_data.curr_operations};
    info new_2 = {midpoint, increment_data.end_pos, increment_data.curr_operations};
    result_type d_1 = ClosestPairLong(p, q_1, new_1);
    result_type d_2 = ClosestPairLong(p, q_2, new_2);
    //the rest
    double d = min(d_1.distance, d_2.distance);
    double dd = pow(d, 2);
    int x_of_mid = p[midpoint].x;
    vector<point> s;
    int num = 1;
    for (int i = increment_data.start_pos; i < increment_data.end_pos; ++i)
    {
        if (abs(q[i].x - x_of_mid) < d)
        {
            s.push_back(q[i]);
            ++num;
        }
    }
    int k = 0;
    for (int i = 0; i <= num - 2; ++i)
    {
       for(k = i +1; ((k <= num - 1) && (pow((double)s[k].y - (double)s[i].y, 2) < dd)); ++ k) //I changed this from the book
        {
            increment_data.curr_operations++;
            double distance = pow(((double)s[k].x - (double)s[i].x),2) + pow(((double)s[k].y - (double)s[i].y),2);
            dd = min(distance, dd);
        }
    }
    return {sqrt(dd), d_1.operations + d_2.operations + increment_data.curr_operations};
}

// jumper function
result_type ClosestPairRet(vector<point> &data)
{
    vector<point> q = data;
    sort(data.begin(), data.end(), compare_x);
    sort(q.begin(), q.end(), compare_y);
    result_type answer = ClosestPairLong(data, q, {0, (int)data.size(), 0});
    return answer;
}

//************************* end internal functions ***************************

// normal
double ClosestPair(std::vector<point> data)
{
    return ClosestPairRet(data).distance;
}

// prints the number of operations.
void PrintClosestPair(std::vector<point> data)
{
    result_type info = ClosestPairRet(data);
    cout << "It did " << info.operations << " operations." << endl;
}

// prints and return a value... so side effects
double PrintRetClosestPair(std::vector<point> data)
{
    result_type info = ClosestPairRet(data);
    cout << "It did " << info.operations << " operations." << endl;
    return info.distance;
}

// returns the number of operations.
int ClosestPairOperations(std::vector<point> data)
{
    return ClosestPairRet(data).operations;
}