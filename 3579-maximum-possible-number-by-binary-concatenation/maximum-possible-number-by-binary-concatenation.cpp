class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
       string a= bitset<32>(nums[0]).to_string(); 
        a.erase(0, a.find_first_not_of('0'));
        string b = bitset<32>(nums[1]).to_string(); 
        b.erase(0, b.find_first_not_of('0'));
        string c = bitset<32>(nums[2]).to_string(); 
        c.erase(0, c.find_first_not_of('0'));
         vector<long long> v = {
            stoll(a + b + c, nullptr, 2),
            stoll(a + c + b, nullptr, 2),
            stoll(b + a + c, nullptr, 2),
            stoll(b + c + a, nullptr, 2),
            stoll(c + a + b, nullptr, 2),
            stoll(c + b + a, nullptr, 2)
        };

        return (int)*max_element(v.begin(), v.end());
    }
};