#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int>bfsofgraph(int n,vector<int>adj[]){
        vector<int>ls;//created to store the BFS.
        int start=0;
        queue<int>q;
        int vis[n]={0};//maintaing a visited array.
        q.push(start);
        vis[start]=1;//marking the visited element.
        
        while(!q.empty()){
            int node=q.front();
            ls.push_back(node);//storing elements in level wise manner with the help of queue.
            q.pop();
            for(auto it:adj[node]){ //traversing over each node neighbours and if not visited then visit and push them.
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return ls;
    }
};

int main(){
    int n,m;
    cin >> n >> m;
    
    vector<int>adj[n];
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Solution obj;//created a class for the solution and them called bfs function to do traversal.
    vector<int>ans=obj.bfsofgraph(n,adj);
    for(auto it:ans) cout << it <<" ";
    return 0;
}
