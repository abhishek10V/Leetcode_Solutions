class Solution {
public:
    int minimumPushes(string word) {

        int i;
        int freq[26];

        vector<int> num;

        for(i=0;i<26;i++){
            freq[i]=0;
        }

        for(i=0;i<word.size();i++) {
            freq[word[i]-'a']++;
        }

        for(i=0;i<26;i++) {
            if(freq[i]!=0) {
                num.push_back(freq[i]);
            }
        }

        sort(num.begin(),num.end());

        int cnt=0,sum=0,offset=1,ans=0;


        for(i=num.size()-1;i>=0;i--) {
            cnt++;
            sum+=num[i];
            if(cnt==8) {

                ans+=sum*offset;
                cnt=0;
                sum=0;
                offset++;
            }
        }

        ans+=sum*offset;

        return ans;


        
    }
};