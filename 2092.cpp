class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        unordered_map<int,int> secret;
        secret[0]++;
        secret[firstPerson]++;

        sort(meetings.begin(), meetings.end(),
            [](const vector<int>& a, const vector<int>& b) {
                return a[2] < b[2];
            });

        int j = 0;
        int m = meetings.size();

        while (j < m) {

            int time = meetings[j][2];
            int i = j;

            
            unordered_map<int, vector<int>> graph;
            unordered_map<int, bool> involved;

            while (i < m && meetings[i][2] == time) {
                int u = meetings[i][0];
                int v = meetings[i][1];
                graph[u].push_back(v);
                graph[v].push_back(u);
                involved[u] = true;
                involved[v] = true;
                i++;
            }

           
            queue<int> q;
            unordered_map<int,bool> visited;

            for (auto &p : involved) {
                if (secret.find(p.first) != secret.end()) {
                    q.push(p.first);
                    visited[p.first] = true;
                }
            }

            while (!q.empty()) {
                int u = q.front(); q.pop();
                secret[u]++;

                for (int v : graph[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }

            j = i;  
        }

        vector<int> ans;
        for (auto &p : secret) {
            ans.push_back(p.first);
        }

        return ans;
    }
};