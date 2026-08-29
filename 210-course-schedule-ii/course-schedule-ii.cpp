class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int m = prerequisites.size();
		vector<int>adj[numCourses];
		vector<int>in(numCourses, 0);
		
		for(int i =0;i<prerequisites.size();i++){
		    int u = prerequisites[i][0];
		    int v = prerequisites[i][1];
		    adj[v].push_back(u);
		    in[u]++;
		}
		queue<int>q;
		for (int i = 0; i<in.size(); i++) {
			if (in[i] == 0)
				q.push(i);
		}
		vector<int>ans;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			ans.push_back(node);
			
			for (int i = 0; i<adj[node].size();i++) {
				in[adj[node][i]]--;
				if (in[adj[node][i]] == 0)
					q.push(adj[node][i]);
			}
		}
				
		if (ans.size() != numCourses)
			return {};
		return ans;
    }
};