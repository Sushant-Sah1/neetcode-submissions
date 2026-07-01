class DisjointSet{
    vector<int>parent; 
    vector<int>size; 
public:
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUPar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUPar(parent[node]);
    }
    void unionBySize(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v){
            return;
        }else if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        DisjointSet ds(n*m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i-1>=0){
                    if(grid[i-1][j]==grid[i][j]){
                        ds.unionBySize(m*i+j,m*(i-1)+j);
                    }
                }
                if(j-1>=0){
                    if(grid[i][j-1]==grid[i][j]){
                        ds.unionBySize(m*i+j,m*(i)+j-1);
                    }
                }
                if(i+1<n){
                    if(grid[i+1][j]==grid[i][j]){
                        ds.unionBySize(m*i+j,m*(i+1)+j);
                    }
                }
                if(j+1<m){
                    if(grid[i][j+1]==grid[i][j]){
                        ds.unionBySize(m*i+j,m*(i)+j+1);
                    }
                }
            }
        }
        set<int>st;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<i<<' '<<j<<' '<<(i*m+j)
        //     }
        // }
        for(int i=0;i<n*m;i++){
            // cout<<"I->"<<i<<' '<<grid[i/m][i%m]<<' '<<endl;
            if(grid[i/m][i%m]=='1'){
                int val=ds.findUPar(i);
                int x=val/m,y=val%m;
                // cout<<"uo"<<' '<<grid[x][y]<<' '<<grid[i/m][i%m]<<endl;
                // cout<<val<<' '<<x<<' '<<y<<endl;
                st.insert(val);
            }
        }
        return st.size();
    }
};
