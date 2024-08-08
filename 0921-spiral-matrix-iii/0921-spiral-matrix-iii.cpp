class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int row, int col, int rStart, int cStart) {
        vector<vector<int>> direc = {{0 , 1} , {1 , 0}, {0 , -1}, {-1 , 0}};

        vector<vector<int>> res;

        int steps = 0;
        int dir = 0;

        res.push_back({rStart , cStart});

        while(res.size() < row * col){
            if(dir == 0 || dir == 2) steps++;

            for(int count = 0; count < steps; count++){
                rStart += direc[dir][0];
                cStart += direc[dir][1];

                if(rStart >=0 && rStart < row && cStart >= 0 && cStart < col) res.push_back({rStart , cStart});
            }

            dir = (dir + 1)%4;
        }
        return res;
    }
};