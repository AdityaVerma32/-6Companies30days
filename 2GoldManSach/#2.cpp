#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    double findDis(vector<int> p1,vector<int> p2){
        double a=pow(((double)p2[1]-(double)p1[1]),2.0);
        double b=pow(((double)p2[0]-(double)p1[0]),2.0);

        return sqrt(a+b);

    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        set<vector<int>> temp;
        temp.insert(p1);
        temp.insert(p2);
        temp.insert(p3);
        temp.insert(p4);
        if(temp.size()!=4) return false;
        double a=findDis(p1,p2);
        double b=findDis(p2,p3);
        double c=findDis(p3,p4);
        double d=findDis(p4,p1);
        double e=findDis(p1,p3);
        double f=findDis(p2,p4);
        set<double> st;
        st.insert(a);
        st.insert(b);
        st.insert(c);
        st.insert(d);
        st.insert(e);
        st.insert(f);
        return st.size()==2;
    }
};