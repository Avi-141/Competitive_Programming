
#include <bits/stdc++.h>

using namespace std;

int r[30];

vector<int>ans;

stack<int>s;

int i,j;

int main()

{

    int flag;

    for(i=0;i<30;i++) r[i]=0;

    string c;

    int b[100010];

    cin>>c;

    for(i=0;i<c.size();i++) r[b[i]=c[i]-'a']++;

 

    for(i=0;i<c.size();i++){

        s.push(b[i]);r[b[i]]--;

        flag=0;

        while(!s.empty()){

            for(j=s.top()-1;j>=0;j--)

                if(r[j])

                    flag=1;

 

            if(flag==1)

                break;

            ans.push_back(s.top());

            s.pop();

        }

    }

 

    for(i=0;i<ans.size();i++)

        printf("%c",ans[i]+'a');

}
