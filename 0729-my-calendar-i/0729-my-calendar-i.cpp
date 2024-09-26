class MyCalendar {
public:
    vector<pair<int , int>> dates;
    MyCalendar() {
        dates;
    }
    
    bool book(int start, int end) {
        if(dates.empty()){
             dates.push_back({start , end});
             return true;
        }
        
        for(auto& d : dates){
           if(start < d.second && end > d.first) return false;
        }
       
           dates.push_back({start , end});
       
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */