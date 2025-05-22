class Solution {
public:
    bool canTransform(string start, string result) {
     int n=start.length();
        int l=0;
        int r=0;
        int m=result.size();
         while(l<n||r<m)
         {
                 while(l<n&&start[l]=='X')
                 l++;
                 while(r<n&&result[r]=='X')
                 r++;
                 if(l==n&&r==n)return 1;
                 if(l==n&&r<n)return 0;
                 if(r==m&&l<m)return 0;
                 if(start[l]!=result[r])
                 {
                       return 0;
                 }
                 if(start[l]=='L'&&l<r)return 0; //L right move nahi kar sakta 
                 if(start[l]=='R'&&l>r) return 0; // R left move nahi kar sakta
                 l++;
                 r++;
         }
         return 1;
    }
};