#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int vis[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vis[i][j]=0;
            }
        }
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vis[sr][sc]=1;
        int intial=image[sr][sc];
        image[sr][sc]=color;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nrow=drow[i]+row;
                int ncol=dcol[i]+col;

                if(nrow<n && ncol<m && nrow>=0 && ncol>=0 && image[nrow][ncol]==intial && !vis[nrow][ncol]){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                    image[nrow][ncol]=color;
                }
            } 
        }
        return image;
    }
};

int main(){
  vector<vector<int>>image={{1,1,1},{1,1,0},{1,0,1}};
  Solution obj;
  image = obj.floodFill(image,1,1,2);
  for(auto it:image){
    for(auto i:it) cout << i << " ";
    cout << endl;
  }
    return 0;
}
