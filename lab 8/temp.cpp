#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>> adjList,int startnode,vector<bool>& visted){
    queue<int> q;

    visted[startnode] = true;
    q.push(startnode);

    while (!q.empty())
    {
        int currnode = q.front();
        q.pop();
        cout<< currnode << " ";
        
        for(int neighbour : adjList[currnode]){
            if(visted[neighbour]==false){
                visted[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
    
}
class GFG{
public:
    bool dfs(int curr , int des, vector<vector<int>>adj,vector<int>&vis){
        if( curr == des)
            return true;
        vis[curr] = 1;
        for(auto x : adj[curr]){
            if(!vis[x]){
                if(dfs(x,des,adj,vis)){
                    return true;
                }
            }
        }
        return false;
    }
    bool isPath(int src,int des,vector<vector<int>>adj){
        vector<int>vis(adj.size() + 1,0);
        return dfs(src,des,adj,vis);
    }
    vector<vector<int>> findSCC(int v,vector<vector<int>>& a){
        vector<vector<int>> adj(v);
        vector<int> is_scc(v+1,0);
        vector<vector<int>> ans(v+1);
        for (int i = 0; i < v; i++)
            adj[a[i][0]].push_back(a[i][1]);
        for (int i = 1; i <= v; i++)
        {
            if(!is_scc[i]){
                vector<int> scc;
                for (int j = i+1; j <= v; j++)
                {
                    if(!is_scc[j] && isPath(i,j,adj) && isPath(j,i,adj)){
                        is_scc[j] = 1;
                        scc.push_back(j);
                    }
                }
                ans.push_back(scc);
            }
        }
        return ans;
    } 
};