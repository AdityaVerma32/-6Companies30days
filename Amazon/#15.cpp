#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double r;
    double x;
    double y;
    Solution(double radius, double x_center, double y_center) {
        r=radius;
        x=x_center;
        y=y_center;
    }
    
    vector<double> randPoint() {
        double angle=((double) rand()/RAND_MAX) * 2 * 3.147;
        double hyp= sqrt((double) rand()/RAND_MAX) * r;

        double per=sin(angle) * hyp;
        double base=cos(angle) * hyp;

        return {x+base,y+per};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */