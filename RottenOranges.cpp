#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
  int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int vis[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vis[i][j]=0;
            }
        }
        int cntfresh=0;
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                    vis[i][j]=2;
                }
                else if(grid[i][j]==1)cntfresh++;
                else if(grid[i][j]==0)vis[i][j]=0;
            }
        }
        
    int drow[]={-1,0,1,0};
    int dcol[]={0,1,0,-1};
    int maxi=0;
    int cnt=0;
    while(!q.empty()){
        int steps=q.front().first;
        int row=q.front().second.first;
        int col=q.front().second.second;
        maxi=max(maxi,steps);
        q.pop();
        for(int i=0;i<4;i++){
            int nrow=drow[i]+row;
            int ncol=dcol[i]+col;

            if(nrow<n && ncol<m && nrow>=0 && ncol>=0 && grid[nrow][ncol]==1 && vis[nrow][ncol]!=2){
                cnt++;
                    q.push({steps+1,{nrow,ncol}});
                    vis[nrow][ncol]=2;
                }
            }
        }
        if(cnt!=cntfresh)return -1;
        return maxi;
    }
};
int main(){
  vector<vector<int>>grid={{2,1,1},{1,1,0},{0,1,1}};
  Solution obj;
  cout << obj.orangesRotting(grid);  
  return 0;
}
  
