#include<bits/stdc++.h>
using namespace std;
int main()
{
    
    
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        
        int  res=a[0],mine=a[0],maxe=a[0];
        
        for(i=1;i<n;i++)
        {
            if(a[i]<0)
            swap(mine,maxe);
            
            maxe=max(maxe*a[i],a[i]);
            mine=min(mine*a[i],a[i]);
            
            res=max(res,maxe);
            
        }
        cout<<res<<endl;
        
    }

return 0;
}
/*5)    download
copy

    #include <iostream>
    #include <vector>
    using namespace std;
     
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        int maxprod;
        vector<int> pos(n); // pos[i] contains positive product till num[i]
        vector<int> neg(n); // neg[i] contains negative product till num[i]
        pos[0]=neg[0]=maxprod=nums[0];
     
        for(int i=1;i<n;i++){
            pos[i] = max(max(pos[i-1]*nums[i],neg[i-1]*nums[i]),nums[i]);   //maximum of the three
            neg[i] = min(min(pos[i-1]*nums[i],neg[i-1]*nums[i]),nums[i]);   //minimum of the three
            maxprod=max(maxprod,pos[i]);
        }
     
        return maxprod;
    }
     
    int main() {
        // your code goes here
        vector<int> nums={2,3,-2,4};
        cout<<maxProduct(nums);
        return 0;
    }*/