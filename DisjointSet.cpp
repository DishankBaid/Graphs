#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int>rank,parent;
    public:
    
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    
    int findPar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findPar(parent[node]);
    }
    
    void UnionByRank(int u,int v){
        int ulp_u=findPar(u);
        int ulp_v=findPar(v);
        
        if(ulp_u == ulp_v)return ;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v]< rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] =ulp_u;
            rank[ulp_u]++;
        }
    }
};

int main(){
    DisjointSet ds(7);
    ds.UnionByRank(1,2);
    ds.UnionByRank(2,3);
    ds.UnionByRank(4,5);
    ds.UnionByRank(6,7);
    ds.UnionByRank(5,6);
    
    //lets check 3 and 7 belongs to same component or not
    if(ds.findPar(3) == ds.findPar(7)) cout << "Same" << endl;
    else cout <<"Not same" << endl;
    ds.UnionByRank(3,7);
    if(ds.findPar(3) == ds.findPar(7)) cout << "Same" << endl;
    else cout <<"Not same" << endl;
    return 0;
}
