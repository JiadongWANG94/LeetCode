#include <algorithm>
using namespace std;
class Solution {
public:
    bool isRobotBounded(string instructions) {
		int pos[2] = { 0,0 };
		int ori[2] = { 1,0 };
		for (auto s : instructions) {
			if (s == 'G') {
				pos[0] += ori[0];
				pos[1] += ori[1];
			}
			else {
				float theta = 0;
				int cosT, sinT;
				if (s == 'L') { cosT = 0;sinT = 1; }
				else {cosT = 0;sinT = -1; }
				int oriOld[2] = { ori[0],ori[1] };
				ori[0] = cosT*oriOld[0] - sinT*oriOld[1];
				ori[1] = sinT*oriOld[0] + cosT*oriOld[1];
			}
		}
        if (ori[0]!=1 || ori[1]!=0) return true;
        if (pos[1]==0 && pos[0]==0) return true;
        else return false;
    }
};