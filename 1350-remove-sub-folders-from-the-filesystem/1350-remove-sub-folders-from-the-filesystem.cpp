class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin() , folder.end());
        vector<string> res;

        res.push_back(folder[0]);

        for(int i=1; i<folder.size(); i++){
            string currFolder = folder[i];
            string lastFolder = res.back();
            
            lastFolder += '/';

            if(currFolder.find(lastFolder) != 0){
                // Means currFolder is not a subfolder of our lastFolder so add to res;

                res.push_back(currFolder);
            }
        }
        return res;
    }
};