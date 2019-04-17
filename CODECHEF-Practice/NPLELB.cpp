#include <bits/stdc++.h>
 using namespace std;
 
int main()
{
	int n,x,dicenum,i,score;
	cin>>n>>x;
	int striker=0;
	int unstriker=0;
	score=0;
	for(i=1;i<=n;i++)
	{
		cin>>dicenum;
		if(dicenum==-1)
		{
		    if(i>x && i%x==1)
			{
				swap(striker,unstriker);
			}
			cout<<striker<<" "<<score<<endl;
			striker=0;
		
		}
		else if(i>x && i%x==1)
		{
			swap(striker,unstriker);
			striker+=dicenum;
			score+=dicenum;
			if(dicenum%2)
			swap(striker,unstriker);
		}
		else if(dicenum%2)
		{
			striker+=dicenum;
			swap(striker,unstriker);
			score+=dicenum;
		}
		else
		{
			striker+=dicenum;
			score+=dicenum;
		}}
	cout<<score<<endl;
	return 0;} 