class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char , int> mp1;
        for(auto & c : s1) mp1[c]++;
      
        int i=0 , j = s1.length() - 1;
        unordered_map<char , int> mp2;
        while(j < s2.length()){
           create(mp2 , i , j , s2);
           
           if(mp1 == mp2) return true;
           else{
              i++;
              j++;
              mp2.clear();
           }
        }
        return false;
    }
    void create(unordered_map<char , int> & mp , int i , int j, string & s2){
        for(int in = i; in<=j; in++){
            mp[s2[in]]++;
        }
    }
};