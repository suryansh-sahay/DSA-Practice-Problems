
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int last = -1, secondLast = -1;
        int count = 0;
        int curr = 0, maxi = 0;

        for(int fruit : fruits) {
            if(fruit == last || fruit == secondLast) {
                curr++;
            }
            else {
                curr = count + 1;
            }

            if(fruit == last) {
                count++;
            }
            else {
                count = 1;
                secondLast = last;
                last = fruit;
            }

            maxi = max(maxi, curr);
        }

        return maxi;
    }
};
