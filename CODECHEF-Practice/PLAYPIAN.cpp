#include<bits/stdc++.h>
using namespace std;

int main(){
int t;
cin>>t;
while(t--){
    int i,len;
    int flag=1;
    string str;
    cin>>str;
    
    len=str.size();
    for(i=0;i<len;i=i+2)
    {
        if(str[i]==str[i+1])
           flag=0;
    }

    if(flag)
    cout<<"yes"<<endl;
    else 
    cout<<"no"<<endl;

}

return 0;
}
