#include <vector>
using std::vector;
#include <algorithm>
using std::min;
#include <cmath>
using std::abs;
using std::pow;
using std::sqrt;

struct point
{
    int x;
    int y;
};

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

ret ClosestPair(const vector<point> &data_x, const vector<point> &data_y, input input);

int main()
{
    // ClosestPair();
    return 0;
}

ret ClosestPair(const vector<point> &data_x, const vector<point> &data_y, input stuff)
{
    int size = stuff.end_pos - stuff.start_pos;
    if (size <= 3)
    {
        // return brute force
    }
    int midpoint = stuff.end_pos - size / 2;
    input new_1 = {stuff.start_pos, midpoint, stuff.curr_operations + 1};
    input new_2 = {midpoint + 1, stuff.end_pos, stuff.curr_operations + 1};
    ret d_1 = ClosestPair(data_x, data_y, new_1);
    ret d_2 = ClosestPair(data_x, data_y, new_2);
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
    for (int i = 0; i < s.size() - 2; ++i)
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