class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        #step1: find R
        int row=0;
        int col=0;
        pair<int,int> posiR=findR(board);
        row=posiR.first;
        col=posiR.second;
        #step2: 4direction
        int count=0;
        int r=row;
        while(r+1<8){
            r++;
            if (board[r][col]=='B') break;
            if (board[r][col]=='p') {
                count++;
                break;
            }
        }
        r=row;
        while(r-1>=0){
            r--;
            if (board[r][col]=='B') break;
            if (board[r][col]=='p') {
                count++;
                break;
            }
        }
        
        int c=col;
        while(c+1<8){
            c++;
            if (board[row][c]=='B') break;
            if (board[row][c]=='p') {
                count++;
                break;
            }
        }
        c=col;
        while(c-1>=0){
            c--;
            if (board[row][c]=='B') break;
            if (board[row][c]=='p') {
                count++;
                break;
            }
        }
        return count;
        
        
    }
private:
    pair<int,int> findR(vector<vector<char>>& board){
        int row=0;
        int col=0;
        for (int i=0;i<8;++i){
            for (int j=0;j<8;++j){
                if (board[i][j]=='R'){
                    row=i;
                    col=j;
                    return make_pair(row,col);
                }
            }
        }
        return make_pair(-1,-1);
    }
};