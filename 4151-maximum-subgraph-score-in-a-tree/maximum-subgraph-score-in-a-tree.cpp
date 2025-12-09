class Solution {
public:
    int indp[100005], outdp[100005];
    unordered_map<int, vector<int>> tree;
    vector<int> good;

    void dfs1 (int node, int parentNode) {
        indp[node] = (good[node] == 1 ? 1 : -1);
        for (int childNode: tree[node]) {
            if (childNode == parentNode) continue;

            dfs1(childNode, node);
            indp[node] += max(0, indp[childNode]);
        }
    }

    void dfs2 (int node, int parentNode) {
        if (parentNode == -1) {
            outdp[node] = 0;
        } else {
            int val = outdp[parentNode] + (indp[parentNode] - max(0, indp[node]));
            outdp[node] += max(0, val);
        }

        for (int childNode: tree[node]) {
            if (childNode == parentNode) continue;
            dfs2(childNode, node);
        }
    }

    vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& _good) {
        good = _good;
        for (vector<int> &edge: edges) {
            int u = edge[0], v = edge[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        dfs1(0, -1);
        dfs2(0, -1);

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = indp[i] + outdp[i];
        }

        return ans;
    }
};