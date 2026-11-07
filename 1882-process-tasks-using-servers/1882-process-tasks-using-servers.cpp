class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        using Idle = pair<int, int>; // weight, index
        using Busy = tuple<long long, int, int>; // finish, weight, index

        priority_queue<Idle, vector<Idle>, greater<Idle>> idle;
        priority_queue<Busy, vector<Busy>, greater<Busy>> busy;

        for (int i = 0; i < servers.size(); ++i)
            idle.push({servers[i], i});

        vector<int> ans;
        long long time = 0;

        for (int i = 0; i < tasks.size(); ++i) {
            time = max(time, (long long)i);

            if (idle.empty())
                time = max(time, get<0>(busy.top()));

            while (!busy.empty() && get<0>(busy.top()) <= time) {
                auto [finish, weight, index] = busy.top();
                busy.pop();
                idle.push({weight, index});
            }

            auto [weight, index] = idle.top();
            idle.pop();
            ans.push_back(index);
            busy.push({time + tasks[i], weight, index});
        }
        return ans;
    }
};