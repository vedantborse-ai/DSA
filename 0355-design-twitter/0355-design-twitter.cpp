#include <bits/stdc++.h>
using namespace std;

class Twitter {
private:
    int timeStamp; // to track recency of tweets
    unordered_map<int, unordered_set<int>> follows; // user -> followees
    unordered_map<int, vector<pair<int,int>>> tweets; // user -> {time, tweetId}

public:
    Twitter() {
        timeStamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // max heap to get most recent tweets
        priority_queue<pair<int,int>> maxHeap;
        
        // include user’s own tweets
        for (auto &tw : tweets[userId]) {
            maxHeap.push(tw);
        }
        
        // include tweets of followees
        for (auto followee : follows[userId]) {
            for (auto &tw : tweets[followee]) {
                maxHeap.push(tw);
            }
        }
        
        // extract up to 10 most recent
        vector<int> feed;
        int count = 0;
        while (!maxHeap.empty() && count < 10) {
            feed.push_back(maxHeap.top().second);
            maxHeap.pop();
            count++;
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return; // cannot follow self
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (follows[followerId].count(followeeId)) {
            follows[followerId].erase(followeeId);
        }
    }
};

/**
 * Example usage:
 * Twitter* obj = new Twitter();
 * obj->postTweet(1,5);
 * vector<int> feed = obj->getNewsFeed(1); // [5]
 * obj->follow(1,2);
 * obj->postTweet(2,6);
 * feed = obj->getNewsFeed(1); // [6,5]
 * obj->unfollow(1,2);
 * feed = obj->getNewsFeed(1); // [5]
 */
