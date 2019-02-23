#include <iostream>
#include <cmath>
#include <vector>
#include<bits/stdc++.h> 

using namespace std;
#define ll long long

#define maxn 200000

int n,k;
vector<bool> univs(maxn+1);

ll dfs(vector<vector<int> > &tree, vector<bool> &visited, vector<int> &num_univs, int u){
    num_univs[u] = (int)univs[u];
    visited[u] = true;
    ll ans = 0;
    for(int i=0; i<tree[u].size(); i++){
        int v = tree[u][i];
        if(!visited[v]){
            ans +=dfs(tree, visited, num_univs, v);
            num_univs[u] += num_univs[v];
            ans += (ll) min(num_univs[v] , 2*k - num_univs[v]) ;
        }
    }

    return ans;
}

int main() {

    cin>>n>>k;

    for(int i=1; i<=2*k; i++){
        int x;
        cin>>x;
        univs[x]=true;
    }

    vector<vector<int> > tree(n+1);
    
    for(int i=0; i<n-1; i++)
    {   
        int u,v;
        cin>>u>>v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    vector<int> num_univs(n+1, 0);
    vector<bool> visited(n+1, false);
    ll ans = dfs(tree, visited, num_univs, 1);

    cout<<ans;
    cout<<endl;

    return 0;
}
