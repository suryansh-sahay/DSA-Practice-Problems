class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        int dir = 0;

        map<pair<int,int>, bool> mp;
        for(auto it : obstacles){
            mp[{it[0], it[1]}] = true;
        }

        int x = 0, y = 0;
        int ans = 0;

        for(auto it : commands){

            if(it < 0){
                if(it == -1) 
                    dir = (dir + 1) % 4;
                else 
                    dir = (dir - 1 + 4) % 4;
            }

            else{

                if(dir == 0){
                    int maxi = y + it;
                    while(y < maxi && !mp[{x, y+1}])
                        y++;
                }

                else if(dir == 1){
                    int maxi = x + it;
                    while(x < maxi && !mp[{x+1, y}])
                        x++;
                }

                else if(dir == 2){
                    int mini = y - it;
                    while(y > mini && !mp[{x, y-1}])
                        y--;
                }

                else if(dir == 3){
                    int mini = x - it;
                    while(x > mini && !mp[{x-1, y}])
                        x--;
                }

                ans = max(ans, x*x + y*y);
            }
        }

        return ans;
    }
};