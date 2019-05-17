#include <vector>
using namespace std;


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> table(27,vector<bool>(9,false)); 
        for (int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if (board[i][j]!='.'){
                    int num=board[i][j]-'1';
                    
                    if (table[i][num] || table[j+9][num] || table[18+i/3+j/3*3][num]){
                        return false;
                    }
                    else{
                        table[i][num] = true;
                        table[j+9][num] = true;
                        table[18+i/3+j/3*3][num] = true;
                    }
                }
            }
        }
        return true;
    }
};