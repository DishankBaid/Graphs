#include<bits/stdc++.h>
using namespace std;

//Adjacency Matrix for the UNDIRECTED GRAPH

int main(){
    int n,m;
    cin >> n >> m;
    //Here n is the NUmber of Nodes in the graph
    // Here m is the Number of edges between the nodes in the Graph
    int adj[n+1][n+1];;
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            adj[i][j]=0;
        }
    }
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v; //Taking input for the nodes in which edge exists.
        
        adj[u][v]=1;//Marking 1 shows that there is a edge between u and v;
        adj[v][u]=1;//Marking 1 shows that there is a edge between v and u;
    }
  //Printing the matrix;
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            cout << adj[i][j] <<" ";
        }
        cout << endl;
    }
    return 0;
}
