#include <map>
#include <pair>
using namespace std;


class Solution {
public:
    int min_value=0;
    map<int,int> m;
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        if (n==0) return -1;
        min_value=coins[0];
        for (int i=0;i<n;++i){
            if (min_value>coins[i]) min_value=coins[i];
        }
        return sub_func(coins,amount);
    }
private:
    int sub_func(vector<int>& coins,int amount){
        if (amount==0) return 0;
        if (amount<min_value) return -1;
        if (m.find(amount)!=m.end()) return (*m.find(amount)).second;
        int opt=-1;
        for (int i=0;i<coins.size();++i){
            if (sub_func(coins,amount-coins[i])!=-1 && (opt>sub_func(coins,amount-coins[i])+1 || opt==-1) )
                opt=sub_func(coins,amount-coins[i])+1;
        }
        m.insert(pair<int,int>(amount,opt));
        return opt;
    }
};