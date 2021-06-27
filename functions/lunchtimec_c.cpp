#include <iostream>
using namespace std;

bool can_heaven(int l,string s){
    int bad = 0;
    int good = 0;

    for(int i=0;i<l;i++){
        if(s[i] == '0')
            bad++;
        else if(s[i] == '1')
            good++;

        float deeds = (good+0.0)/(good+bad);
        if(deeds >= 0.5)
            return true;
    }
    return false;
}

int main() {
	int tc;
	cin>>tc;
	for(int i=0;i<tc;i++){
	    int l;
	    string deeds;
	    cin>>l>>deeds;
	    if(can_heaven(l,deeds))
	        cout<<"YES";
	    else
	        cout<<"NO";
	   if(i<tc-1)
	    cout<<endl;
	}
}
