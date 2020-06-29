int hIndex(vector<int>& citations) {
        int n = citations.size();
        int start = 0;
        int end = n;
        while(start < end)
        {
            int mid = (end + start)/2;
            if(n - mid <= citations[mid])
                end = mid;
            else
                start = mid+1;
        }
        return n-end;
    }