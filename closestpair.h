#ifndef FILE_CLOSESTPAIR_H_INCLUDED
#define FILE_CLOSESTPAIR_H_INCLUDED


#include <vector>

struct point
{
    int x;
    int y;
};

double closestPair(std::vector<point> data);
void printClosestPair(std::vector<point> data);
int closestPairOperations(std::vector<point> data);
double printRetClosestPair(std::vector<point> data);

double brute_force_cp(std::vector<point> data);

#endif //#ifndef FILE_CLOSESTPAIR_H_INCLUDED