class Solution {
public:

    bool canReach(vector<int>& arr, int start) {
        vector<bool>tem(arr.size(),false);
        queue<int>q;
        tem[start]=true;
        q.push(start);
        if(arr[start]==0)return true;
        while(!q.empty())
        {
               int n=q.size();
               for(int i=0;i<n;i++)
               {
                      int ind=q.front();
                      q.pop();
                      int front=(ind+arr[ind]<arr.size())?ind+arr[ind]:-1;
                      int back=(ind-arr[ind]>=0)?ind-arr[ind]:-1;
                    //   cout<<front<<" "<<back<<endl;
                      if(front!=-1&&tem[ind+arr[ind]]==false)
                      {
                         if(arr[ind+arr[ind]]==0)return true;
                           q.push(ind+arr[ind]);
                          
                           tem[ind+arr[ind]]=true;
                      }
                       if(back!=-1&&tem[ind-arr[ind]]==false)
                      {  if(arr[ind-arr[ind]]==0)return true;
                           q.push(ind-arr[ind]);
                           tem[ind-arr[ind]]=true;
                      }
               }
        }
        // for(int i=0;i<arr.size();i++)
        // {
        //       if(arr[i]==0&&tem[i])
        //       return true;
        //     //   cout<<tem[i]<<" ";
        // }
        return false;
    }
};