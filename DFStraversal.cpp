#include<bits/stdc++.h>
using namespace std;

class Solution{
    void dfs(int node,vector<int>&traverse,vector<int>adj[],vector<int>&vis){
        vis[node]=1;
        traverse.push_back(node);
        
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                dfs(it,traverse,adj,vis);
            }
        }
    }
    public:
    vector<int>dfsofGraph(int V,vector<int>adj[]){
        vector<int>vis(V);
        for(int i=0;i<V;i++)vis[i]=0;
        int start=0;
        vector<int>traverse;
        dfs(start,traverse,adj,vis);
        return traverse;
    }
};
int main(){
   int V,e;
   cin >> V >> e;
   
   vector<int>adj[V];
   for(int i=0;i<e;i++){
       int u,v;
       cin >> u >> v;
       
       adj[u].push_back(v);
       adj[v].push_back(u);
   }
   
   Solution obj;
   vector<int>ans=obj.dfsofGraph(V,adj);
   
   for(auto it:ans)cout << it << " ";
   cout << endl;
   
   return 0;
}
