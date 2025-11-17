class Solution { 
public:
    int minOperations(vector<int>& nums) {
        nums.push_back(0);
        int ans=0;
        stack<int> st;
        for(int i=0; i<nums.size(); i++){
            while(!st.empty()){
                if(st.top()<nums[i]) {st.push(nums[i]); break;}
                else if(st.top()==nums[i]) break;
                else st.pop(), ans++;
            }
            if(st.empty()&&nums[i]!=0) st.push(nums[i]);
        }
        return ans;
        
    }
};