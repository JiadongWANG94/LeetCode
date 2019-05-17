class Solution {
public:
    int bitwiseComplement(int N) {
        if (N==0) return 1;
        string binary ="";
        string reverse_binary = "";
        while (N>=2){
            binary = to_string(N%2) + binary;
            reverse_binary = (N%2==1?"0":"1") + reverse_binary;
            N=N/2;
        }
        binary = "1" + binary;
        reverse_binary = "0" + reverse_binary;
        int ans=0;
        for (int i=reverse_binary.size()-1;i>=0;--i){
            int num = reverse_binary.c_str()[i]-'0';
            //return num;
            ans += num*pow(2,reverse_binary.size()-1-i);
        }
        return ans;
    }
};