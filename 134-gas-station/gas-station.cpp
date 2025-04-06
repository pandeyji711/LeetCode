class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int x=0;
        int y=0;
        for(int i=0;i<gas.size();i++)
        x+=gas[i];

           for(int i=0;i<gas.size();i++)
        y+=cost[i];

        if(y>x)
        return -1;
        int ans=0;
        int tem=0;
        int tank=0;
        for(int i=0;i<gas.size();i++)
        {
               //fill
               tank+=gas[i];
               //cost
               tank-=cost[i];
               if(tank<0)
               {
                    tank=0;
                    ans=i+1;
               }
        }
        return ans;
    }
};