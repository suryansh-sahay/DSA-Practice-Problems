class Solution {
public:
    int func(int x, int y){
        if (x > y) swap(x,y);
        while (y != 0){
            int temp = x;
            x = y;
            y = temp;
            y %= x;
        }
        return x;
    }
    int subarrayGCD(vector<int>& nums, int k) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++){
            int g = nums[i];
            for (int j = i; j < nums.size(); j++){
                g = func(g, nums[j]);
                if (g == k) count += 1;
                if (g < k)  break;
            }
        }
        return count;
    }
};
