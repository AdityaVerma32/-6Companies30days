#include<bits/stdc++.h>
using namespace std;

class StockPrice {
public:
    map<int,int> mp,freq;
    int maxTime=INT_MIN;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(mp.find(timestamp)!=mp.end()){
            int k=mp[timestamp];
            freq[k]--;
            if(freq[k]==0)
            freq.erase(k);
        }
        mp[timestamp]=price;
        freq[price]++;
        if(maxTime<timestamp)
        maxTime=timestamp;
    }
    
    int current() {
        return mp[maxTime];
    }
    
    int maximum() {
        return freq.rbegin()->first;
    }
    
    int minimum() {
        return freq.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */