#include<iostream>
#include<vector>
using namespace std;

void disp(vector<vector<int>> v,int n,int m){
    for(int i=0;i<n;i++){
        cout<<endl;
        for(int j=0;j<m;j++){
            cout<<v[i][j]<<"\t";
        }
    }
    cout<<endl;
}
template<typename T>
bool is_min(T a, T b){
    return a<b;
}

template<typename T>
vector<vector<int>> lookup(T arr[],int n,bool (*f)(T,T)){
    vector<vector<int>> v(n,vector<int>(n,-1));

    for(int i=0;i<n;i++){
        int m = i;
        for(int j=i;j<n;j++){
            if(f(arr[j],arr[m])){
                m = j;
            }
            v[i][j] = arr[m];
        }
    }
    return v;
}


int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    vector<vector<int>> v = lookup(arr,n,&is_min);
    disp(v,n,n);

    return 0;
}
