class Solution {
public:
    int bulbSwitch(int n) {
        
        return (int)sqrt(n);
        /*
        int ans=0;
        for (int i=1;i<=n;i++){
            if (pow((int)sqrt(i),2.0)==i) ans++;
        }
        return ans;*/
    }
};