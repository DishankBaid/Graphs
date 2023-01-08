#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    
    // N is the Number of Nodes
    // M is the Number of Edges
    //For undirecetd graph 
    vector<int>adjUDG[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        
        adjUDG[u].push_back(v);
        adjUDG[v].push_back(u);
    }
    
    for(int i=0;i<n+1;i++){
        cout << i <<"->";
        
        for(auto it:adjUDG[i]){
            cout << it << " ";
        }
        cout << endl;
    }
    
    int i,j;
    vector<int>adjDG[i+1];
    
    for(int k=0;k<j;k++){
      int u,v;
      cin >> u >> v;
      
      adjDG[u].push_back(v);
   }
   
   for(int k=0;k<i+1;k++){
        cout << k <<"->";
        for(auto it:adjDG[k]){
            cout << it << " ";
          }
        cout << endl;
     }
   return 0;
}
