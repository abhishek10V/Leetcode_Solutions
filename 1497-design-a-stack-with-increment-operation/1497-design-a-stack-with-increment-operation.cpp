class CustomStack {
public:
    vector<int> st;
    int sz;
    CustomStack(int maxSize) {
        sz = maxSize;
    }
    
    void push(int x) {
        if(st.size() == sz) return;
        st.push_back(x);
    }
    
    int pop() {
        if(st.size() == 0) return -1;
        
        else{
            int ans;
            ans = st[st.size() - 1];
            st.pop_back();
            return ans;
        }
    }
    
    void increment(int k, int val) {
        if(st.size() <= k)
        for(int i=0 ; i<st.size()  ; i++) st[i] += val;
        else
        for(int i=0 ; i<k  ; i++) st[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */