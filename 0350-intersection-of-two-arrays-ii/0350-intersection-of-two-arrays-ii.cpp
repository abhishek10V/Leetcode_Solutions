class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp1;
        map<int, int> mp2;
        vector<int> result;
        for(int i=0; i<nums1.size(); i++){
            mp1[nums1[i]]++;
        }
        for(int i=0; i<nums2.size(); i++){
            mp2[nums2[i]]++;
        }
        for(auto & itr : mp1){
            if(mp2.find(itr.first) != mp2.end()){
               for(int i=0; i<min(mp1[itr.first] , mp2[itr.first]); i++){
                  result.push_back(itr.first);
               }
            }
        }
        return result;
    }
};