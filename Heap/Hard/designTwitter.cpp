class Twitter {
public:
    unordered_map<int, vector<int>> userTweets; //userid, tweetid
    unordered_map<int, unordered_set<int>> userFollowings; // who follows whom
    unordered_map<int, int> tweetTime; // tweet, time
    int time;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back(tweetId); // user -> tweet
        tweetTime[tweetId] = ++time; // tweet->time
    }
    
    vector<int> getNewsFeed(int userId) {
        unordered_set<int> followList; // user follow whoms
        if(userFollowings.find(userId) != userFollowings.end()){
            followList = userFollowings[userId];
        }
        followList.insert(userId); // include user
        priority_queue<pair<int, int>> tweetQueue;
        for(int currUser: followList){  // for each user
            if(userTweets.find(currUser) != userTweets.end()){ // if user tweeted
                vector<int>& currUserTweet = userTweets[currUser]; // tweetId of user
                if(!currUserTweet.empty()){
                    int tweetToAdd = min(10, static_cast<int>(currUserTweet.size()));  // add upto 10 tweets
                    for(int i=currUserTweet.size()-1; i>= static_cast<int>(currUserTweet.size()) - tweetToAdd; i--){
                        int tweetId = currUserTweet[i];
                        tweetQueue.push({tweetTime[tweetId], tweetId});
                    }
                }
            }
        }

        vector<int> newsFeed;
        while(!tweetQueue.empty() and newsFeed.size()<10){
            newsFeed.push_back(tweetQueue.top().second);
            tweetQueue.pop();
        }
        return newsFeed;


    }
    
    void follow(int followerId, int followeeId) {
        userFollowings[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(userFollowings.find(followerId) != userFollowings.end()){
            userFollowings[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */