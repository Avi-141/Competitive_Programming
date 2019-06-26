#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
//  #define For(i,st,en) for(ull   (i) = (ull  )(st); (i) <= (ull  )(en); (i)++)
  #define pb push_back
using namespace std;
  typedef vector<ll> VI;
  #define bint int64_t



  // a^b mod m
ull power(ull a, ull b, ull m)
{
	if (!b) return 1;
	else if (b==1) return a%m;
	else 
	{
		ull req = power(a, b>>1, m);
		ull ret = (req*req*((b&1ull )?a:1ull ))%m;
//		cout << "Power: " << a << ' ' << b << ' ' << m << ' ' << ret << endl;
		return ret;
	}
}
// DONE

ull n;

// [ 1 p.first  ] ^ power
// [ 0 p.second ]
pair <ull, ull> matrix_power(pair <ull, ull> &p, ull power, ull m)
{
	if (power==0ull ) return make_pair(0ull , 1ull );
	else if (power==1ull ) return p; 
	else
	{
		pair <ull, ull> ret = matrix_power(p, (power>>1),m);
		ret.first = (ret.first * (1ull  + ret.second))%m;
		ret.second = (ret.second*ret.second)%m;
		if (power&1ull )
		{
			ret.first = (p.first + p.second*ret.first)%m;
			ret.second = (ret.second*p.second)%m;
		}
		return ret;
	}
}
// DONE

// (1 + r + r^2 + .. numb terms) mod m
ull gp(ull r, ull numb ,ull m)
{
	// [1 f(n)] = [1 f(n-1)][1 1]
	//						[0 r]
	// Use matirx exponentiation
	if (numb <= 0ull ) return 0ull ;
	else if (numb == 1ull ) return 1ull ;
	pair <ull, ull> p = make_pair(1ull , r);
	pair <ull, ull> req = matrix_power(p, numb-1,m);
	ull ret = (req.first + req.second)%m;
//	cout << "GP: " << r << ' ' << numb << ' ' << ret << endl;
	return ret;
}
// DONE



/*ull power(ull a , ull b,ull mod)
{
    if(b==0)
        return 1;
    if(b==1)
        return a%mod;
    if(b&1)//odd
    {
        ull res = power(a ,floor(b/2),mod);
        res = (res%mod)*(res%mod);
        return (a%mod)*(res%mod);
    }
    else{
        ull res = power(a , b/2,mod);
        return (res%mod)*(res%mod);
    }
}*/



int main()
{
	ull t,p;
	cin>>t>>p;
	for(ull i=1;i<=t;i++)
	{

      ull l,r;
      cin>>l>>r;
      ull terms=r+1-l;
      ull counto=0,counte=0;
      ull f=0,ff=0;
      ull fin,odd,even,fin_fin;
      int three;


      if(l%2==0)
      {
      	f=1;
      }
      if(l%2==1)
      {
      	f=2;
      }
      if(r%2==0)
      {
      	ff=1;
      } 
      if(r%2==1)
      {
      	ff=2;
      }
       //if((l/2)%2==1)
         //   three=-3;
           // else three=3;
          if(f==1)
           {
               if((l/2)%2==1)
               three=-3;
               else three=3;
           }
           if(f==2)
           {
               if(((l+1)/2)%2==1)
                 three=-3;
                 else three=3;
           }
           
     
      // even .... even
      if(f==1&&ff==1)
      {
        fin_fin=terms/2;
  
        fin=fin_fin+1;
        
        odd=(gp(3,fin_fin,p));
       
       odd=odd* power(3,l/2,p);
      
        even=gp(3,fin,p);
        
        even=even*power(3,l/2,p);
        
        if(fin%2==1)
        even=even+three;
      
        even=even/2;
       
        even=even+fin;
       
        even=odd+even;
        even=even%p;
        cout<<even<<"\n";
      }
      // odd .... odd
      else if(f==2&ff==2)
      {
      	fin_fin=terms/2;
        //cout<<fin_fin<<" ";
        fin=fin_fin+1;
    
        odd=(gp(3,fin,p));
       
        odd=odd*power(3,(l-1)/2,p);
        
        even=gp(3,fin_fin,p);
       
        even=even*power(3,(l+1)/2,p);
       
       if(fin%2==1)
      	{
         even=even+three;
        }
        even=even/2;
        
        even=even+fin_fin;
       
        even=odd+even;
        even=even%p;
        cout<<even<<"\n";
       }


     
      else if(f==1&&ff==2)
      {
      	fin=terms/2;
   
        odd=gp(3,fin,p);

      	odd=odd*power(3,(l/2),p);
     
      	even=gp(3,fin,p);
      
      	even=even*power(3,(l/2),p);
      
      	if(fin%2==1)
      	{
      	even=(even+three);
      	
      	}

      	even=even/2;
      	
        even=even+fin;
        
      	even=even+odd;
      	
      	
      	even=even%p;
      	
      	cout<<even<<"\n";

      }
      //odd ... even//
      else if(f==2&&ff==1)
      {
      	fin=terms/2;
        //cout<<fin<<" ";
        odd=gp(3,fin,p);

        odd=odd*power(3,(l-1)/2,p);
        
      	even=gp(3,fin,p);
      	
      	even=even*power(3,(l+1)/2,p);
      
      	if(fin%2==1)
      	{
      		even=even+three;
      	   
        }
      
      	even=(even/2);
    
      	even=even+fin;
        odd=even+odd;
      	odd=odd%p;
      	cout<<odd<<"\n";

      }
       
}
}

// CASES WHERE IT FAILS 
// MODULUS PROBLEM -- U CAN SEE THE LAST FEW DIGITS ARE CORRECT. 
/*

Input

3 1000000
3 44
33 999
12 113

Your Code's Output

324530
149582
400428

Expected Correct Output

324530
399581
400428

*/

// correct output on samples 
// Modulus problem for main cases. WA



/*Input

3 1000000
3 446
33 998
11 112

Your Code's Output

208752
612914
389150

Expected Correct Output

708752
862914
889150*/

