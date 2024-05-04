class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int l=0,r=people.size()-1;
        int ans=0;
        while(l<=r)
        {    
            if(people[r]==limit)
            {
                r--;
                ans++;
            }else if(people[r]+people[l]<=limit)
            {
                ans++;
                l++;
                r--;
            }
            else{
                ans++;
                r--;
            }

        }
        return ans;
    }
};
