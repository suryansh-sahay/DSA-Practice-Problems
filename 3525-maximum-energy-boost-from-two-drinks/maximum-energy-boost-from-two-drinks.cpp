class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        long long dpA1 = 0, dpB1 = 0, dpA0=0, dpB0=0;
        long long dpA, dpB;
        for (int i = 0; i < energyDrinkA.size(); i++) {
            dpA = energyDrinkA[i] + max(dpA1, dpB0);
            dpB = energyDrinkB[i] + max(dpB1, dpA0);
            dpA0 = dpA1, dpB0 = dpB1;
            dpA1 = dpA, dpB1 = dpB;
        
        }
        return max(dpA, dpB);
    }
};