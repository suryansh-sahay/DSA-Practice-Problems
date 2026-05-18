class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto ed:prerequisites)
        {
            int u=ed[0];
            int v=ed[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)  q.push(i);
        }
        vector<int>topo;
        while(q.size())
        {
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(int neighbour:adj[node])
            {
                indegree[neighbour]--;
                if(indegree[neighbour]==0)  q.push(neighbour);
            }
        }
        if (topo.size()==numCourses)    return true;
        else return false;
    }
};