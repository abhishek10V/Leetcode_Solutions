class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> vec;
        bool flag = true;
        for(auto & n : nums){
            vec.push_back(to_string(n));
            if(n != 0) flag = false;
        }
        if(flag == true) return "0";

        sort(vec.begin() , vec.end() , [](string & a, string & b){
               return (a+b) > (b+a);
        });

        string ans = "";
        for(auto & v : vec){
            ans += v;
        }
        return ans;
    }
};