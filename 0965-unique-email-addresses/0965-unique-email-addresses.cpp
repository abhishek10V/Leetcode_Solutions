class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
          map<string , int> mp;
        
        for(int i=0 ; i<emails.size(); i++){
            string sb = "";
            int j=0;
            while(j<emails[i].length() && emails[i][j] != '@'){
                if(emails[i][j] == '.') j++;
                else if(emails[i][j] == '+'){
                    while(emails[i][j] != '@') j++;
                }else sb.push_back(emails[i][j++]);
            }
           
            while(j < emails[i].size()) sb.push_back(emails[i][j++]);
            
            mp[sb]++;
        }
       
        return mp.size();
    }
};