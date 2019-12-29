#include <bits/stdc++.h>
#define ll long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define VECTOR(v) cout << '>' << #v << ':' ; vector_out(v);
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ip(x) cin>>x
#define out(x) cout<<x
#define op(x) cout<<x<<endl
#define ops(x) cout<<x<<" "
#define forloop(i,n) for(ll i=0;i<n;i++)
#define pb push_back
#define mp make_pair
#define GREATEST_COMMON_DIVISOR(x,y) __gcd(x,y)
#define f first 
#define s second
#define dd double
using namespace std;
typedef pair<ll,ll> pairs;

dd pi = 3.141592653589;
int main(int argc, char const *argv[])
{

ll x1,y1,x2,y2,r;
cin>>x1>>y1>>x2>>y2>>r;
ll theta1,theta2,thetaf,dist1,dist2,flag=0;
dd temp1,temp2,mini;

dd t1=abs(x1);
dd t2=abs(x2);
dd t3=abs(y1-r);
dd t4=abs(y2-r);
dd s1=sqrt((x1*x1)-(r*r));// when an arc of a circle has to be taken in the path 
dd s2=sqrt((x2*x2)-(r*r));

dd ys=(y1-y2);

//cout<<s1<<"dnjdl"<<s2<<endl;

dd x1y1=sqrt(dd(x1*x1)+dd(t3*t3));
dd x2y2=sqrt(dd(x2*x2)+dd(t4*t4));


dd circ=2.00000000*pi*r;
dd circby4=dd(circ/4.00000000);

theta1=(ll)(acos(r/t1)*180.0/pi);  // if one of the points is on the x axis 
theta1=90-theta1;  
//cout<<theta1<<"dnbjkfb"<<endl;
theta2=(ll)(acos(r/t1)*180.0/pi);
theta2=90-theta2;
//cout<<theta2<<"bdsakf"<<endl;

thetaf=min(theta1,theta2); // calculate the minimum theta if y2==0 or y1==0

dd ds1=((t1-x2)*(t1-x2)+(y2*y2));
ds1=ds1-(s1*s1);
ds1=sqrt(ds1);

dd ds2=((t2-x1)*(t2-x1)+(y1*y1));
ds2=ds2-(s2*s2);
ds2=sqrt(ds2);

//cout<<thetaf<<"dnsaj"<<endl;

dd d1=dd(s1+s2)+2.0*dd((thetaf/360.0)*circ);
if(thetaf==theta1&&(theta1!=theta2))
{
    flag=1;
    dist1=dd(s1)+2.0*dd((theta1/360.0)*circ)+ds1;
}
if(thetaf==theta2&&(theta1!=theta2))
{
    flag=2;
    dist2=dd(s2)+2.0*dd((theta2/360.0)*circ)+ds2;
}

//case 1
if(y2==0&&y1==0)
{
    
    if(theta1==theta2)
    {
        cout<<fixed<<setprecision(6)<<d1;
        exit(0);
    }
   else if(flag==1)
	{
	    cout<<fixed<<setprecision(6)<<dist1;
	    exit(0);
	}
	else if(flag==2)
	{
	    cout<<fixed<<setprecision(6)<<dist2;
	    exit(0);
	}
    
}


//case 2 ---to be modified
else if((y1==0||y2==0)&&(y1!=y2))
{
	/*if(theta1==theta2){
	cout<<fixed<<setprecision(6)<<d1;
	exit(0);
	}*/
	if(flag==1)
	{
	    cout<<fixed<<setprecision(6)<<dist1;
	    exit(0);
	}
	else if(flag==2)
	{
	    cout<<fixed<<setprecision(6)<<dist2;
	    exit(0);
	}
	//cout<<setprecision(6)<<d1;
}

//case 3
else if((x1==r&&x2==-r)||(x1==-r&&x2==r))
{
	   if(y1>0&&y2>0){
	   	cout<<fixed<<setprecision(6)<<x1y1+x2y2;
  	    exit(0);
       }
   if((y1>0&&y2<0)||(y1<0&&y2>0))
   {
     cout<<fixed<<setprecision(6)<<(x1y1+x2y2+circby4);
     exit(0);
   }

}
/*else if(x1==x2)
{
	cout<<fixed<<setprecision(6)<<ys;
	exit(0);
}*/
else if((x1==y1)&&(x2==y2)&&((x1/y1)==(x2/y2)))
{
  mini=min(x1,x2);
  if(mini==x1)
  {
  	temp1=sqrt(dd(x1*x1)+dd(y1*y1));
  	temp1=temp1-r;
  	temp1*=2;
  	temp2=sqrt(dd((x1-x2)*(x1-x2))+dd((y1-y2)*(y1-y2)));
  	temp1=temp1+temp2;
  	cout<<fixed<<setprecision(6)<<temp1;
  	exit(0);

  }
  else if(mini==x2)
  {
  	temp1=sqrt(dd(x2*x2)+dd(y2*y2));
  	temp1=temp1-r;
  	temp1*=2;
  	temp2=sqrt(dd((x1-x2)*(x1-x2))+dd((y1-y2)*(y1-y2)));
  	temp1=temp1+temp2;
  	cout<<fixed<<setprecision(6)<<temp1;
  	exit(0);

  }
}
else if((x1==y1)&&(x2==y2)&&((x1/y1)==(x2/y2))&&((x1==-x2)||(x2==-x1)))
{
	 mini=min(x1,x2);
     if(mini==x1)
    {
  	temp1=sqrt(dd(x1*x1)+dd(y1*y1));
  	temp1=temp1-r;
  	temp1+=pi*r;
  	temp2=sqrt(dd(x2*x2)+dd(y2*y2));
  	temp2=temp2-r;
  	temp1+=temp2;
  	cout<<fixed<<setprecision(6)<<temp1;
  	exit(0);
  }
  if(mini==x2)
    {
  	temp2=sqrt(dd(x2*x2)+dd(y2*y2));
  	temp2=temp2-r;
  	temp2+=pi*r;
  	temp1=sqrt(dd(x2*x2)+dd(y2*y2));
  	temp1=temp2-r;
  	temp2+=temp1;
  	cout<<fixed<<setprecision(6)<<temp2;
  	exit(0);
  }
}
}
