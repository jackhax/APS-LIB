#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    vector<int> res;
	    queue<int> q;
	    vector<int> visited(V,0);
	    
	    
	    
	    q.push(0);
	    visited[0]=1;
	    while(!q.empty())
	    {
	        int temp=q.front();
	        q.pop();
	        res.push_back(temp);
	        for(int i:adj[temp])
	        {
	            if(!visited[i])
	            {
	                q.push(i);
	                visited[i]=1;
	            }
	        }
	    }
	    return res;
	}
};
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
  
    	}
       
        Solution obj;
        vector<int>ans=obj.bfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
} 
