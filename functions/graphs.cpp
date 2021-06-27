#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void disp(vector<vector<int>> &graph,int m,int n){
    cout<<endl;
    for(int i=0;i<m;i++){
        cout<<'\n';
        for(int j=0;j<n;j++){
            cout<<graph[i][j]<<" ";
        }
    }
}

void bfs(vector<vector<int>> graph,int nodes,int root){
    queue<int> q;
    vector<bool> vis(nodes+1,false);
    q.push(root);
    vis[root] = true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        cout<<v<<" ";
        for(int i=1;i<nodes;i++){
            if(graph[v][i]==1 && !vis[i]){
                q.push(i);
                vis[i] = true;
            }
        }
    }
}

vector<int> dijkstra(vector<vector<int>> graph,int nodes,int source){
    queue<int> q;
    vector<bool> vis(n+1,false);
    q.push(source);

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for(int i=0;i<=n;i++){

        }
    }
    

}



int main(){
    int nodes, edges;
    cin>>nodes>>edges;
    vector<vector<int>> graph(nodes+1,vector<int>(nodes+1,0));
    disp(graph,nodes+1,nodes+1);
    for(int i=0;i<edges;i++){
        int x, y,w;
        cin>>x>>y>>w;
        graph[x][y] = w;
    }
    disp(graph,nodes+1,nodes+1);
    cout<<endl;
    bfs(graph,nodes,1);
    return 0;
}