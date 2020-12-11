#ifndef FILE_CLOSESTPAIR_H_INCLUDED
#define FILE_CLOSESTPAIR_H_INCLUDED


#include <vector>

struct point
{
    int x;
    int y;
};

double ClosestPair(std::vector<point> data);
void PrintClosestPair(std::vector<point> data);
int ClosestPairOperations(std::vector<point> data);
double PrintRetClosestPair(std::vector<point> data);

#endif //#ifndef FILE_CLOSESTPAIR_H_INCLUDED