#include<bits/stdc++.h>
using namespace std;

class Solution {

private:
//for converting string to integer
    int converter(string t)
    {
        bool neg=false;
        int val=0;
        if(t[0]=='-')
        {
            neg=true;
            int i=1;
            while(i<t.size()){
                val=val*10+(t[i]-48);
                i++;
            }
        }else{
            int i=0;
            while(i<t.size())
            {
                val=val*10+(t[i]-48);
                i++;
            }
        }
        return neg?(-val):val;
    }
//Checking is string is just operator
    bool isOperator(string t)
    {
        if(t=="+"||t=="-"||t=="*"||t=="/")
        return true;
        else
        return false;

    }
//Calculation
    int cal(int a,int b,string op)
    {
        //swap(a,b);
        if(op=="*")
        return a*b;
        else if(op=="-")
        return a-b;
        else if(op=="+")
        return b+a;
        else
        return a/b;
    }
public:

    int evalRPN(vector<string>& tokens) {
        stack<int> integ;
        for(int i =0;i<tokens.size();i++)
        {
            if(!isOperator(tokens[i])){
                integ.push(converter(tokens[i]));
            }else{
                int b=integ.top();integ.pop();
                int a=integ.top();integ.pop();
                integ.push(cal(a,b,tokens[i]));
            }
        }
        return integ.top();
    }
};