class TaskManager {
public:
    priority_queue<vector<int>> pq;
    unordered_map<int, int> prior;
    unordered_map<int, int> user;
    TaskManager(vector<vector<int>>& tasks) {
        int n = tasks.size();
        for (int i = 0 ; i < n; i++){
            pq.push({tasks[i][2], tasks[i][1], tasks[i][0]});
            prior[tasks[i][1]] = tasks[i][2];
            user[tasks[i][1]] = tasks[i][0];
        }
    }
    
    void add(int userId, int taskId, int priority) {
        pq.push({priority, taskId, userId});
        prior[taskId] = priority;
        user[taskId] = userId;
    }
    
    void edit(int taskId, int newPriority) {
        prior[taskId] = newPriority;
        pq.push({newPriority, taskId, user[taskId]});
    }
    
    void rmv(int taskId) {
        prior[taskId] = -1;
        user[taskId] = -1;
    }
    
    int execTop() {
        while(!pq.empty() && (prior[pq.top()[1]] == -1 || pq.top()[0] != prior[pq.top()[1]])){
            pq.pop();
        }
        if(pq.empty()){
            return -1;
        }
        vector<int> exec = pq.top();
        prior[exec[1]] = -1;
        user[exec[1]] = -1;
        pq.pop();
        return exec[2];
    }
};©leetcode
