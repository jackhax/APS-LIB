#include <iostream>
#include<vector>
using namespace std;
int main() {
	int tc;
	cin>>tc;
	while(tc--){
	    string s;
        cin>>s;
	    int n = s.length();
	    int l,u;
	    if(n%2==0){
	        l = n/2 - 1;
	        u = n/2;
	    }else{
	        l = n/2 - 1;
	        u = n/2 + 1;
	    }
	    
	    vector<int> freq(26,0);
	    int nonZero = 0;
	    for(int i=0;i<n;i++){
	        if(i<=l){
	            freq[s[i] - 97] ++;
	            if(freq[s[i] - 97] == 1)
	                nonZero++;
	        }else if(i>=u){
	            freq[s[i] - 97] --;
	            if(freq[s[i] - 97] == 0)
	                nonZero--;
	        }
	    }
	    
	    if(nonZero == 0)
	        cout<<"YES"<<endl;
	    else
	        cout<<"NO"<<endl;
	}

	return 0;
}