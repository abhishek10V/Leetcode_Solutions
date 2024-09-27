class MyCalendarTwo {
public:
    vector<pair<int , int>> singleB;
    vector<pair<int , int>> doubleB;
    MyCalendarTwo() {
        singleB;
        doubleB;
    }
    
    bool book(int start, int end) {
        
        for(auto & d : doubleB){
            if(start < d.second && end > d.first) return false;
        }

        for(auto & b : singleB){
            if(start < b.second && end > b.first){
                doubleB.push_back({max(start , b.first) , min(end , b.second)});
            }
        }
        singleB.push_back({start , end});
       
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */