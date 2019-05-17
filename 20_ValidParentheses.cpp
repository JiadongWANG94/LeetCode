class Solution {
public:
    bool isValid(string s) {
        if (s.size()==0)return true;
        stack<char> sta;
        string::iterator c=s.begin();
        while (c!=s.end()){
            switch (*c){
                case '{':{
                    sta.push('}');
                    break;
                }
                case '[':{
                    sta.push(']');
                    break;
                }
                case '(': {
                    sta.push(')');
                    break;
                }
                case '}':{
                        if (sta.size()!=0 && sta.top()=='}') sta.pop();
                        else return false;
                        break;
                }
                case ']':{
                        if (sta.size()!=0 && sta.top()==']') sta.pop();
                        else return false;
                        break;
                }
                case ')':{
                        if (sta.size()!=0 && sta.top()==')') sta.pop();
                        else return false;
                        break;
                }   
            }
            ++c;
        }
        if (sta.size()==0) return true;
        else return false;
    }
};