#include <iostream>
#include <cmath>
#include <vector>
#include<bits/stdc++.h> 

using namespace std;

int max_length_dfs_helper(vector<vector<int> > &tree, vector<bool> &visited, int u){
    visited[u] = true;
    int mx = 0;
    for(int i=0; i<tree[u].size(); i++){
        int v = tree[u][i];
        if(!visited[v]){
            int ans = max_length_dfs_helper(tree, visited, v);
            mx = max(ans+1, mx);
        }
    }

    return mx;
}

int max_length_dfs(vector<vector<int> > &tree, vector<bool> &visited, int u, int s){
    visited[u] = true;
    int mx = 0;
    for(int i=0; i<tree[u].size(); i++){
        int v = tree[u][i];
        if(!visited[v]){
            vector<bool> vis(visited.size()+1, false);
            vis[s] = true;     
            int ans = max_length_dfs_helper(tree, vis, v);
            mx = max(ans, mx);
            ans = max_length_dfs(tree, visited, v, s);
            mx = max(mx,ans);
        }
    }

    return mx;
}

int main() {
    int n;
    cin>>n;

    vector<vector<int> > tree(n+1);

    vector<vector<int> > edges(n-1, vector<int> (2));
    
    for(int i=0; i<n-1; i++)
    {   
        int u,v;
        cin>>u>>v;

        tree[u].push_back(v);
        tree[v].push_back(u);
        edges[i][0] = u;
        edges[i][1] = v;
    }
    

    int ans = 0;
    for (int i = 0; i < edges.size(); i++)
    {   
        vector<bool> visited(n+1, false);
        int u = edges[i][0];
        int v = edges[i][1];
        visited[v] = true;
        int l1 = max_length_dfs(tree, visited, u, v);
        visited[u] = true;
        int l2 = max_length_dfs(tree, visited, v, u);
        ans = max(ans, l1*l2);
    }

    cout<<ans<<endl;

    return 0;
}
