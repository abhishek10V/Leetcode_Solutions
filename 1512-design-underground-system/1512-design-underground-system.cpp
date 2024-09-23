class UndergroundSystem {
public:
    unordered_map<int , pair<string , int>> checkIN;
    unordered_map<string , pair<int , int>> dest;

    UndergroundSystem() {
       checkIN;
       dest;
    }
    
    void checkIn(int id, string stationName, int t) {
        checkIN[id] = {stationName , t};
    }
    
    void checkOut(int id, string stationName, int t) {
        if(checkIN.find(id) != checkIN.end()){
            dest[checkIN[id].first + " "+ stationName] = {(t - checkIN[id].second) + dest[checkIN[id].first +" "+ stationName].first , dest[checkIN[id].first +" "+ stationName].second + 1};
        }
    }
    
    double getAverageTime(string start, string end) {
        return (double) dest[start +" "+ end].first / dest[start +" "+ end].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */