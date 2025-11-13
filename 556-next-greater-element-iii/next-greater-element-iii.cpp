class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        int size = str.size();

        int right = size - 1;
        int left = right - 1;
        while(left >= 0 && str[left] >= str[left+1]){
            left -= 1;
        }
        if(left <= -1) return -1;

        while(str[right] <= str[left]){
            right--;
        }
        swap(str[right],str[left]);
        sort(str.begin() + left + 1, str.end());

        using ll = long long;
        ll result = stoll(str);

        if(result > INT_MAX ) return -1;
        return stoi(str);
    }
};