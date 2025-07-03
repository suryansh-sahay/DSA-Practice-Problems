class Solution {

private:
    int helper(int k, int shift) {
        if (k == 1)
            return 'a' + shift;

        int len = 1;
        while (2 * len < k)
            len *= 2;

        if (k <= len)
            return helper(k, shift);
        else
            return helper(k - len, (shift + 1) % 26);
    }

public:
    char kthCharacter(int k) {
        // string current ='a';
        // while(current.length()<k){
        //     string newstr ="";
        //     for(char c: current){
        //         if(c=='z') newstr+='a';
        //         else newstr+=c+1;
        //     }
        //     current+=newstr;
        // }
        // return current[k-1];
        return helper(k, 0);
    }
};