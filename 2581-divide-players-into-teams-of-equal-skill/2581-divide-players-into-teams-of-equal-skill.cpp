class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        if(skill.size() == 2) return skill[0] * skill[1];

        sort(skill.begin() , skill.end());
        int left = 0, right = skill.size() - 1;
        long long sum = skill[left] + skill[right];
        long long chem = skill[left] * skill[right];
        left++ , right--;
        while(left < right){
            if(skill[left] + skill[right] == sum){
                 chem += (skill[left] * skill[right]);
                 left++ , right--;
            }else return -1;
        }
        return chem;
    }
};