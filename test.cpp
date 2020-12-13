#include "closestpair.h"
#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::endl;
#include <time.h>

int main()
{
    
    cout << "The geeks for geeks dataset." << endl;
    vector<point> my_data = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    double thing = printRetClosestPair(my_data);
    double answer = brute_force_cp(my_data);
    cout << "The correct answer is: 1.414214   You got: " << thing << "    brute force got: " << answer << endl;
    // I need more testing data, and I am not calculating it by hand...
    // I guess I can write a brute force and compare the answers.
    cout << endl << "random time" << endl;
    cout << "the data set is...:" << endl;
    srand(time(NULL));
    vector<point> random;
    for(int i =0; i < 10; ++i){
        random.push_back({rand()%10000000,rand()%10000000});
        //cout << i << "(" << random[i].x <<"," << random[i].y << ")" << endl;
    }
    thing = printRetClosestPair(random);
    answer = brute_force_cp(random);
    cout << "you got: " << thing << "    brute force got: " << answer <<endl;
    return 0;
}