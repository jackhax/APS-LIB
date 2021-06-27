#include<iostream>
#include<climits>
#include<vector>

using namespace std;

void insert(int a,int i,vector<int> &v){
    if(v[i] == INT_MIN){
        v[i] = a;
        cout<<"inserting at: "<<i<<" "<<v[i]<<endl;
        return ;
    }

    if(a<=v[i]){
        insert(a,2*i+1,v);
    }
    if(a>=v[i]){
        insert(a,2*i+2,v);
    }
}

void disp(vector<int> v,int n){
    cout<<endl;
    for(int i=0;i<2*n;i++)
        cout<<v[i]<<" ";
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    vector<int> tree(2*n,INT_MIN);

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        insert(a,0,tree);
    }
    disp(tree,n);

    return 0;
}
