int dp[20] = {0};
class Solution {
public:

    int numTrees(int n) {
        dp[0] = 1; //for n = 0
        dp[1] = 1; //for n = 1
        for(int nodes = 2;nodes <= n; nodes++){
            int value_for_nodes = 0;
           for(int root_node = 1; root_node <= nodes; root_node++){
            value_for_nodes += dp[root_node - 1] * dp[nodes - root_node];
           }
           dp[nodes] = value_for_nodes;
        }
        return dp[n];
     }
};