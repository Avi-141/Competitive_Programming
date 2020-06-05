/*One fine day Harry was told a story about the microorganisms society. The speciality of microorganisms is that they split in certain conditions.Which means a microorganism of size D can split into two insects of positive integral sizes E and F such that D = E + F. Also sometimes they attack each other i.e. two microorganisms of sizes P and Q will become R = P XOR Q . You are given numbers representing the sizes of the microorganisms . Your job is to determine whether it is possible for the microorganism society to become extinct after several attacks and or splits.

Input:
The first line contains an integer T, indicating the number of test cases.
For each test case, the first line contains an integer N, indicating the number of microorganisms in the microorganisms society, followed by N space separated positive integers y1,y2,...,yN denoting the sizes of the microorganisms.
Output :
For each test case, output "Yes" if it is a possibility that the microorganism colony will become extinct. after several attacks and/or splits otherwise output "No" (without quotes).(each word on a different line).
Constraints :

1 ≤ T ≤ 100
1 ≤ N ≤ 100
1 ≤ yi ≤ 109 where i =1,2...,N */

/*#include <stdio.h>
    #include <string.h>
    #include <math.h>
    #include <stdlib.h>
     
     
     
    int main(){
     
            int T,N,i,j,l,max,flag,k;
     
            int XOR = 0,exp;
     
            scanf("%d",&T);
     
            int res[T];
     
            // printf("T is %d\n",T);
     
            for(l = 0; l < T; l++){
     
                scanf("%d",&N);
     
                int y[N];
 
                int count_odd = 0;
     
                for (j = 0; j < N; j++)
                {
                    scanf("%d",&y[j]);
                    // printf("%d\n",y[j]);
                }
     
                for (k = 0; k < N; k++)
                {
                    
                       if(y[k] % 2 != 0)
                          count_odd++;                          // number of odd elements
 
                  }
     
                // for (i = 0; i < N; i++)
                //         XOR ^= y[i];
     
                // if(XOR == 0){
                //     // printf("Yes\n");
                //     res[l] = 1;
                // }
                // else{
                //     // printf("No\n");
                //     res[l] = 0;
                // }
     
                // if(flag == 1)
                //  printf("Yes\n");
 
                if(count_odd % 2 == 0)
                    res[l] = 1;
                else
                    res[l] = 0; 
 
     
            }
     
            for(i = 0; i < T ; i++){
                if(res[i] == 1)
                    printf("Yes\n");
                else
                    printf("No\n");
            }
     
     
            
        } */

        #include <iostream>
#include <vector>
 
using namespace std;
 
int main()
{
	int T;
	cin >> T;
 
	int N;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
 
		vector <int> y(N), z;
		for (int j = 0; j < N; j++)
		{
			cin >> y[j];
 
			if (y[j] % 2)
				z.push_back(y[j]);
		}
 
		if (z.size() % 2)
			cout << "No\n";
 
		else
			cout << "Yes\n";
	}
 
	return 0;
}