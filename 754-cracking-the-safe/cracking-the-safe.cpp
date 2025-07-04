class Solution {
public:
//    void dfs(string &res,  unordered_map<string,int>&m,int k,int n)
//    {              
//             string last=res.substr(res.size()-n+1,n-1);

//             for(int i=0;i<k;i++)
//             {
                   
//                    string tem=last+=to_string(i);
//                    if(m.find(tem)==m.end())
//                    {
//                         m[last]=1;
//                         res+=to_string(i);
//                         dfs(res,m,k,n);
//                    }

//             }


//    }
    string crackSafe(int n, int k) {
      unordered_map<string,int>m;
       string str(n,'0');
       m[str]=1;
       int total=pow(k,n);
    for(int i=0;i<total;i++)
    {
           //last n-1 digit 
           string last=str.substr(str.length()-(n-1));
           for(int j=k-1;j>=0;j--){
           last+=('0'+j);
                if(m.find(last)==m.end())
                {
                       m[last]=1;
                       if(i==0)
                       {
                        str.pop_back();
                       str+=('0'+j);

                       }else
                        str+=('0'+j);

                       break;
                }

           }

    }
    return str;
     
    }
};