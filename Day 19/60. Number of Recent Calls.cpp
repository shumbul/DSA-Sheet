class RecentCounter {
    queue<int> time;
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        time.push(t); //return the number of pings that have happened in the time range [t-3000, t]
        while (time.front()<t-3000)
        {
            time.pop(); //removes old pings that are outside the 3000ms window
        }
        return time.size();
    }
};
