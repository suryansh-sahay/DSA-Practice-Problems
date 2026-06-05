class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        long long dpA1=energyDrinkA[0], dpB1=energyDrinkB[0];
        long long dpA0=dpA1, dpB0=dpB1;
        long long dpA, dpB;
        for(int i=1; i<energyDrinkA.size(); i++){

            if(i<2) dpA=dpA1+energyDrinkA[i], dpB=dpB1+energyDrinkB[i], dpA1=dpA, dpB1=dpB;
            else {
            dpA=max(dpA1+energyDrinkA[i], dpB0+energyDrinkA[i]);
            dpB=max(dpB1+energyDrinkB[i], dpA0+energyDrinkB[i]);
            dpA0=dpA1, dpB0=dpB1;
            dpA1=dpA, dpB1=dpB;
            }
        }
        return max(dpA, dpB);
    }
};