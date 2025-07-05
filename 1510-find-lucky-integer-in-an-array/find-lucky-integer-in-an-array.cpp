class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int>v(501,0);
        for(int i=0;i<arr.size();i++)
        {
              v[arr[i]]++;
        }
        int lucky=-1;
        // sort(arr.begin(),arr.end());
        for(int i=1;i<v.size();i++)
        {
               
               if(v[i]==i)
                  lucky=i;
        }
        return lucky;
    }
};