class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        if(courses.size() <= 0) return 0;
        sort(courses.begin(), courses.end(), [](const vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        for(auto num: courses) cout<<num[0]<<' '<<num[1]<<endl;

        priority_queue<int> q;
        int sum = 0;
        for(auto i : courses) {
            sum += i[0];
            q.push(i[0]);
            if(sum > i[1]) {
                cout<<q.size()<<" ";
                sum -= q.top();
                q.pop();
            }
        }
        return q.size();
    }
};