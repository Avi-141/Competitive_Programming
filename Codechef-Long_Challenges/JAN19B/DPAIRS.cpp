#include<bits/stdc++.h>
using namespace std;

typedef pair<long long int, long long int> pairs; 
set<pairs> set1; 
//set<pairs> set2;
void disp1() 
{ 
    int f = 0; 
    for (auto itr = set1.begin(); itr != set1.end(); itr++) { 
  
        f = 1; 
        pairs x = *itr; 
        cout << x.first<<" "<<x.second<<"\n"; 
    } 
} 
int main()
{
long long int iter1,iter2;
long long int n,m;

cin>>n>>m;
long long int s1[n],s2[m];
int flag1=0,flag2=0,flag3=0;

for(int i=0;i<n;i++)
{
    cin>>s1[i];
    
}
for(int j=0;j<m;j++)
{
    cin>>s2[j];}

int max1 = s1[0];
int index1 = 0;
for (iter1= 0;iter1<n;iter1++) 
{
    if (max1<s1[iter1]) {
        max1=s1[iter1];
        index1= iter1;
            }}

int max2 = s2[0];
int index2 = 0;
for (iter2= 0; iter2<m; iter2++) 
{
    if (max2<s2[iter2]) 
    {
         max2=s2[iter2];
            index2=iter2;
            }}

int small1= s1[0];
int st1=0;
  for (int c = 0; c <n; c++)
    {
        if (s1[c] <small1)
        {
          small1= s1[c];
             st1=c;
        }
    }
int small2=s2[0];
int st2=0;
  for (int c = 0; c <m; c++)
    {
        if (s2[c] <small2)
        {
          small2= s2[c];
             st2=c;
        }
    }
long long int *l1=std::max_element(s1,s1+n);
long long int *l2=std::max_element(s2,s2+m);
pairs x;
//std::set<std::pair<int,int>>s;
pairs check1=make_pair(st1,index2);
pairs check=make_pair(index1,st2);
if(*l1>*l2)
{
    flag1=1;
for(int i=0;i<m;i++)
{
    x=make_pair(index1,i);
    set1.insert(x);
}
for(int i=0;i<n;i++)
{
    x=make_pair(i,st2);
    set1.insert(x);
}
set1.erase(check);
set1.insert(check);
}
else if(*l2>*l1)
{
    flag2=1;
 for(int i=0;i<n;i++)
{
    x=make_pair(i,index2);
    set1.insert(x);
}

for(int i=0;i<m;i++)
{
    x=make_pair(st1,i);
    set1.insert(x);
    //if(set1.find(check1))
    //set1.erase(check1);
}
set1.erase(check1);
set1.insert(check1);
}
else if(*l1==*l2)
{
 flag3=1;
 for(int i=0;i<n;i++)
 {
    x=make_pair(i,index2);
    set1.insert(x);
 }
 for(int i=0;i<m;i++)
 {
    x=make_pair(st1,i);
    set1.insert(x);
 }
 set1.erase(check1);
 set1.insert(check1);
}

if(flag1)
{
  disp1();
}
else if(flag2)
{
  disp1();
}
else if(flag3)
{
    disp1();
}
return 0;
}
