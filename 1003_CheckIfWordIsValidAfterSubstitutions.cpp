class Solution {
public:
    bool isValid(string S) {
        //return true;
        stack<string> my_stack;
        string::iterator ite=S.begin();
        while(ite!=S.end()){
            if ((S.end()-ite>=3)&&(*ite=='a')&&(*(ite+1)=='b')&&(*(ite+2)=='c')){
                ite+=3;
            }
            else if ((S.end()-ite>=2)&&(*ite=='a')&&(*(ite+1)=='b')){
                my_stack.push("ab");
                ite+=2;
            }
            else if ((S.end()-ite>=1)&&(*ite=='a')){
                my_stack.push("a");
                ite++;
            }
            else if ((S.end()-ite>=2)&&(*ite=='b')&&(*(ite+1)=='c')){
                if (my_stack.size()>0 && my_stack.top()=="a") {
                    my_stack.pop();
                    ite+=2;
                }
                else{
                    return false;
                }
            }
            else if ((S.end()-ite>=1)&&(*ite=='c')){
                if (my_stack.size()>0 && my_stack.top()=="ab") {
                    my_stack.pop();
                    ite++;
                }
                else{
                    return false;
                }
            }
            else if (*ite=='b'){
                if (my_stack.size()>0 && my_stack.top()=="a"){
                    my_stack.pop();
                    my_stack.push("ab");
                    ite++;
                }
                else return false;
            }
            else return false;
        }
        if (my_stack.size()==0) return true;
        else return false;
    }
};