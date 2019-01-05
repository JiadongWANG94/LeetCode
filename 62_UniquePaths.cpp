#include <queue>
#include <pair>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m==0 ||n==0) return 0;
        else{
            int tab[m][n]={1};
            for(int k=1;k<=m+n;++k){
                for (int i=max(0,k-n);i<min(k,m);++i){
                    int j=k-1-i;
                    if (i==0 and j==0)
                        tab[i][j]=1;
                    else if(i==0)
                        tab[i][j]=tab[i][j-1];
                    else if(j==0)
                        tab[i][j]=tab[i-1][j];
                    else 
                        tab[i][j]=tab[i-1][j]+tab[i][j-1];
                }
            }
            return tab[m-1][n-1];
        }
    }
};

/*
        queue<pair<int,int>> q;
        if (m>0 and n>0) {
            int tab[m][n]={0};
            pair<int,int> tmp={0,0};
            q.push(tmp);
            while (q.size()>0){
                pair<int,int> fron=q.front();
                if (fron.first==0 and fron.second==0) 
                    tab[fron.first][fron.second]=1;
                else if (fron.first==0)
                    tab[fron.first][fron.second]=tab[fron.first][fron.second-1];
                else if (fron.second==0)
                    tab[fron.first][fron.second]=tab[fron.first-1][fron.second];  
                else
                    tab[fron.first][fron.second]=tab[fron.first][fron.second-1]+tab[fron.first-1][fron.second];
                if (fron.first<m-1){
                    tmp.first=fron.first+1;
                    tmp.second=fron.second;
                    q.push(tmp);
                }
                if (fron.second<n-1){
                    tmp.first=fron.first;
                    tmp.second=fron.second+1;
                    q.push(tmp);
                }
                q.pop();
            }
            return tab[m-1][n-1];
        }
        else return 0;

*/