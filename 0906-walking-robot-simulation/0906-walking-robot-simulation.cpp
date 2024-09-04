class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> set;
        for(auto & o : obstacles){
            string key = to_string(o[0]) + "_" + to_string(o[1]);
            set.insert(key);
        }

        int x = 0 , y = 0;
        int maxD = 0;
        pair<int , int> dir = {0 , 1};

        for(int i=0 ; i<commands.size(); i++){
            if(commands[i] == -2){
                dir = {-dir.second , dir.first};
            }else if(commands[i] == -1){
                dir = {dir.second , -dir.first};
            }else{
                for(int s = 0 ; s<commands[i]; s++){
                    int newX = x + dir.first;
                    int newY = y + dir.second;

                    string nextKey = to_string(newX) + "_" + to_string(newY);

                    if(set.find(nextKey) != set.end()) break;

                    x = newX;
                    y = newY;
                }
            }

            maxD = max(maxD , x*x + y*y);
        }
        return maxD;
    }
};