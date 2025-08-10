class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> count=digCoun(n);
        for(int i=0; i<30; i++){
            if(count == digCoun(1<<i)) return true;
        }
        return false;
    }
private: 
    vector<int> digCoun(int n){
        vector<int> coun(10, 0);
        while(n!=0){
           coun[n%10]++;
           n/=10;
        }
        return coun;
    }
};