#include<bits/stdc++.h>
using namespace std;

void dfs(int v,vector<vector<int>>&adj,vector<bool>&vis, vector<int>&comp) {
    vis[v] = true;
    comp.push_back(v);
    for(int u : adj[v]){
        if(!vis[u]){
            dfs(u, adj, vis, comp);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;  
    vector<vector<int>>adj(n + 1);
    for (int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<bool>vis(n + 1, false);
    vector<vector<int>>comps;
    for (int i=1;i<=n;i++){
        if(!vis[i]){
            vector<int>comp;
            dfs(i,adj,vis,comp);
            comps.push_back(comp);
        }
    }
    
    int k=comps.size()-1;
    cout<<k<<endl;
    
    for(int i=0;i<k;i++){
        cout<<comps[i][0]<<" "<<comps[i + 1][0]<<endl;
    }
    
    return 0;
}
