class Solution {
public:
    bool canTransform(string start, string end) {
        string::iterator s_ite=start.begin(),e_ite=end.begin();
        while (s_ite!=start.end() && *s_ite=='X') s_ite++;
        while (e_ite!=end.end() && *e_ite=='X') e_ite++;
        while (s_ite!=start.end() && e_ite!=end.end()){
            if (*s_ite==*e_ite &&((*s_ite=='L' && e_ite-end.begin()<=s_ite-start.begin())||(*s_ite=='R' && e_ite-end.begin()>=s_ite-start.begin()))) {
                s_ite++;
                e_ite++;
            }
            else return false;
            while (s_ite!=start.end() && *s_ite=='X') s_ite++;
            while (e_ite!=end.end() && *e_ite=='X') e_ite++;            
        }
        if (s_ite==start.end() xor e_ite==end.end()) return false;
        return true;
    }
};