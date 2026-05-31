class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long val=1LL*mass;
        sort(asteroids.begin(), asteroids.end());
        for(int i: asteroids){
            if(val<i) return false;
            val+=i;
        }
        return true;
    }
};