class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        auto f = [](int x, int y) {
            return x * 60010 + y;
        };

        unordered_set<int> st;
        for(auto &obs : obstacles){
            st.insert( f(obs[0], obs[1]) ) ;
        }

        vector<pair<int,int>> dir = { {0,1} , {1,0} , {0,-1}, {-1,0}};

        int x = 0 , y =0;
        int d = 0; //north
        long long max_dist = 0;

        for(int cmd : commands){
            if(cmd == -2){
                d = (d+3)%4 ;
            } else if (cmd == -1){
                d = (d+1)%4 ;
            } else {
                for(int i = 0; i<cmd; i++){
                    int nx = x + dir[d].first;
                    int ny = y + dir[d].second;

                    int key = f(nx , ny);

                    if(st.find(key) != st.end()){
                        break;
                    }

                    x = nx;
                    y = ny;

                    max_dist = max( max_dist, 1LL*x*x + 1LL* y*y);
                
                }
            }
        }
        
        return max_dist;
    }
};