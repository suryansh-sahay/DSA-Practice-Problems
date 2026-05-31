class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {

        int maxi=*max_element(asteroids.begin(), asteroids.end());
        long long val=mass;
        sort(asteroids.begin(), asteroids.end());
        for(int i: asteroids){
            if(val<i) return false;
            val+=i;
            if(val>maxi) return true;
        }
        return true;
    }
};