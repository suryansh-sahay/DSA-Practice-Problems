class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int last=-1, secondlast=-1;
        int count=0, curr=0, maxi=0;

        for(int fruit: fruits){
            if(fruit==last || fruit==secondlast) curr++;
            else curr=count+1;

            if(fruit==last) count++;
            else {
                count=1;
                secondlast=last;
                last=fruit;
            }
            maxi=max(maxi, curr);
        }
        return maxi;
    }
};