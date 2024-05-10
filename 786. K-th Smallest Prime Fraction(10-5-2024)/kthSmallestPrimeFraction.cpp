class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        unordered_map<float,vector<int>>m;
        priority_queue<float>pq;
        int n=arr.size()-1;
        for(int i=n;i>=0;i--)
        { 
            for(int j=0;j<i;j++)
            {
                float x=(float)arr[j]/arr[i];
        
                pq.push(x);
                if(pq.size()>k)
                pq.pop();
                m[x].push_back(arr[j]);
                m[x].push_back(arr[i]);

            }
        }
        return m[pq.top()];
    }
};