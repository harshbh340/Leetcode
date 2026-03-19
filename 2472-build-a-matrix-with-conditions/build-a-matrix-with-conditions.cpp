class Solution {
public:

    vector<int> topoSort(vector<vector<int>>& edges, int k){

        unordered_map<int, vector<int>> adj;
        vector<int> indegree(k + 1, 0);

        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;

        for(int i = 1; i <= k; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> topo;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            topo.push_back(u);

            for(int v : adj[u]){
                indegree[v]--;

                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }

        if(topo.size() != k) return {};

        return topo;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {

        vector<int> topoRow = topoSort(rowConditions, k);
        vector<int> topoCol = topoSort(colConditions, k);

        if(topoRow.empty() || topoCol.empty()){
            return {};
        }

        vector<vector<int>> matrix(k, vector<int>(k,0));

        unordered_map<int,int> colIndex;

        for(int i=0;i<k;i++){
            colIndex[topoCol[i]] = i;
        }

        for(int i=0;i<k;i++){
            int num = topoRow[i];
            matrix[i][colIndex[num]] = num;
        }

        return matrix;
    }
};