#include<string>


class Solution {
public:
    string reverseString(string s) {
        if (s.size()<=1) return s;
        int front=0;
        int back=s.size()-1;
        string tmp(s);
        while(front<back){
            swap(tmp[front],tmp[back]);
            front++;
            back--;
        }
        return tmp;
    }
};