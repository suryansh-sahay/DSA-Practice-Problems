class Solution {
public:
    bool judgeCircle(string moves) {
        int h=0, v=0;
        for(char c: moves){
            if(c=='U') v++;
            else if(c=='D') v--;
            else if(c=='R') h++;
            else h--;
        }
        return !h&&!v;
    }
};