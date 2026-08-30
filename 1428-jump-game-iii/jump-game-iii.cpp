class Solution {
public:
    bool canReach(vector<int>& A, int cur) {
        queue<int> q;
        q.push(cur);
        while(size(q)) {
            cur = q.front(); q.pop();
            if(A[cur] == 0) return true;
            if(A[cur] < 0)  continue;
            if(cur + A[cur] < size(A)) q.push(cur + A[cur]);
            if(cur - A[cur] >= 0)      q.push(cur - A[cur]);
            A[cur] *= -1;
        }
        return false;
    }
};