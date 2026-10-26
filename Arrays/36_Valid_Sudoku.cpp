class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool>valid(9,false);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                int num=(board[i][j]-'0')-1;
                if(!valid[num]) valid[num]=true;
                else return false;
            }
            fill(valid.begin(),valid.end(),false);
        }
    
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[j][i]=='.') continue;
                int num=(board[j][i]-'0')-1;
                if(!valid[num]) valid[num]=true;
                else return false;
            }
            fill(valid.begin(),valid.end(),false);
        }
        
        for(int r=0;r<9;r+=3){
            for(int c=0;c<9;c+=3){
                fill(valid.begin(),valid.end(),false);
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        if(board[i+r][j+c]=='.') continue;
                        int num=(board[i+r][j+c]-'0')-1;
                        if(!valid[num]) valid[num]=true;
                        else return false;
                    }
                }
            }
        }
        
        return true;
    }
};
/*Time complexity:
- Row check: O(9*9) = O(81) operations.
- Column check: O(9*9) = O(81).
- 3x3 subgrid check: there are 9 subgrids, each inspecting 9 cells, so O(9*9) = O(81).
Overall time complexity is O(81 + 81 + 81) = O(243), which is O(1) in terms of input size, but more precisely O(9*9) per phase, totaling O(9*9) overall.

Space complexity:
- A single 9-element boolean vector reused across checks: O(9) space.
- Aside from input board, no extra data structures proportional to input size are used.
So total auxiliary space complexity is O(9) = O(1).*/