#include<queue>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn=500005;
int cnt,head[maxn],n,m,now;
int in[maxn],dp[maxn][26];
char s[maxn];
vector<int> ans;
struct node{
    int to,next;
}e[maxn*2];
void add(int u,int v){
    e[cnt].to=v;
    e[cnt].next=head[u],head[u]=cnt++;
}
void init(){
    memset(head,-1,sizeof(head));
    cnt=0;
}
int topo(){
    queue<int> q;
    int now=0;
    for(int i=1;i<=n;i++){
        if(!in[i]){
            q.push(i);
            dp[i][s[i]-'a']++;
        }
    }
    while(!q.empty()){
        int u=q.front(); q.pop();
        now++;
        for(int i=head[u];~i;i=e[i].next){
            int t=e[i].to,add=s[t]-'a';
            for(int j=0;j<26;j++){
                dp[t][j]=max(dp[t][j],dp[u][j]+(j==add?1:0));
            }
            if(--in[t]==0){
                q.push(t);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<26;j++)
            ans=max(ans,dp[i][j]);
    }
    if(now!=n) return -1;
    return ans;
}
int main(){
    init();
    int x,y;
    scanf("%d%d%s",&n,&m,s+1);
    cout<<"s: "<<s;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
        add(x,y);
        in[y]++;
    }
    printf("%d\n",topo());
    return 0;
}