int ca=0,cb=0;
	    for(int i=0;i<n+m;i++)
	    {
	        if(ca<n&&cb<m)
	        {
	        if(arr[ca]<=arr1[cb])
	        {
	            cout<<arr[ca++]<<" ";
	        }
	        else if(arr[ca]>arr1[cb])
	        {
	            cout<<arr1[cb++]<<" ";
	        }
	        }
	        else if(ca>=n)
	        {
	            cout<<arr1[cb++]<<" ";
	        }
	         else if(cb>=m)
	        {
	            cout<<arr[ca++]<<" ";
	        }
	    }