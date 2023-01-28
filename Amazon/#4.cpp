#include<bits/stdc++.h>
using namespace std;

class TweetCounts {
public:
    map<string,vector<int>> mp;
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        mp[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int interval=60;
        if(freq=="hour") interval*=60;
        if(freq=="day") interval*=(60*24);

        int n=(endTime - startTime)/interval;



        vector<int> ans(n+1,0);
        for(auto &it:mp[tweetName]){
            if(it>=startTime && it<=endTime){
                int ind=(it-startTime)/interval;
                ans[ind]++;
            }
        }

        return ans;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */