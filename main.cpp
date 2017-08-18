#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pi;
vector<ll>g[100001];
ll mod=1000000007;
typedef vector<ll>::iterator vit;
ll n,m,ar[1000001],i,aj[1000001],yo=0;
bool visited[1000001];

void dfs(ll n,ll distance)
{
    visited[n]=true;
    distance+=1;
    if(aj[distance]==1){
        yo++;}
    for(int j=0;j<g[n].size();j++)
    {
        ll curr=g[n][j];
        if(!visited[curr]){
            dfs(curr,distance);
        }
    }
    visited[n]=false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(i=1;i<=m;i++){
        cin>>ar[i];
        aj[ar[i]]=1;
    }
    for(i=1;i<n;i++)
    {
        ll t;
        cin>>t;
        g[t].push_back(i+1);
    }
    for(i=1;i<=n;i++)
    {
        dfs(i,-1);
    }
    cout<<yo;
    return 0;
}
