

class Solution {
public:
    std::vector<int> assignTasks(std::vector<int>& servers, std::vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        
        std::priority_queue<std::pair<int, int>, 
                            std::vector<std::pair<int, int>>, 
                            std::greater<std::pair<int, int>>> available;
        
        for (int i = 0; i < n; ++i) {
            available.push({servers[i], i});
        }
        
        std::priority_queue<std::tuple<long long, int, int>, 
                            std::vector<std::tuple<long long, int, int>>, 
                            std::greater<std::tuple<long long, int, int>>> busy;
        
        std::vector<int> ans(m);
        long long current_time = 0;
        
        for (int j = 0; j < m; ++j) {
            current_time = std::max(current_time, (long long)j);
            
            if (available.empty()) {
                current_time = std::max(current_time, std::get<0>(busy.top()));
            }
            
            while (!busy.empty() && std::get<0>(busy.top()) <= current_time) {
                auto [free_time, w, i] = busy.top();
                busy.pop();
                available.push({w, i});
            }
            
            auto [w, i] = available.top();
            available.pop();
            
            ans[j] = i;
            busy.push({current_time + tasks[j], w, i});
        }
        
        return ans;
    }
};