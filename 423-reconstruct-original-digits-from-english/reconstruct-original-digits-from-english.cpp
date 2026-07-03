class Solution {
public:
    string solve(string s,unordered_map<char,int>&m,int ind)
    {
          unordered_map<char,int>m1;
          for(char c:s)
          {
              m1[c]++;
          }
          int minn=INT_MAX;
          for(auto a1:m1)
          {
               int tem=m[a1.first]/a1.second;
               minn=min(minn,tem);
          }
           string ans="";
          if(minn>0){
         for(auto a1:m1)
          {
               m[a1.first]-=a1.second;
          }
         

          
             ans+=to_string(ind);
          }
         
           return ans;

    }
    string originalDigits(string s1) {
      
        unordered_map<char,int>m;
        for(int i=0;i<s1.length();i++)
        {
              m[s1[i]]++;
        }
//   string ans="";

   map<char,int>m1;
   m1['z']=0;
   m1['w']=2;
   m1['u']=4;
   m1['x']=6;
   m1['g']=8;
  vector<int>tt(10,0);
 for(auto a1:m1)
 {  

       int tem=m[a1.first];
       tt[a1.second]=tem;
       if(a1.first=='u'){
           m['f']-=tem;
       }
        if(a1.first=='x'){
           m['s']-=tem;
           m['i']-=tem;
       }
        if(a1.first=='z'||a1.first=='w'||a1.first=='u'){
           m['o']-=tem;
       }
        if(a1.first=='g'){
           m['h']-=tem;
           m['i']-=tem;
       }

       
 }
  m1['h']=3;
   m1['f']=5;
   m1['s']=7;
   m1['o']=1;
   m1['i']=9;
  
    for(auto a1:m1)
 {  
        // cout<<tt[9]<<endl;
       int tem=m[a1.first];
       tt[a1.second]=tem;
       
       if(a1.first=='f')
       {
        // cout<<"k";
          m['i']-=tem;
        //   cout<<m['i']<<" "<<tem<<endl;
       }
       
 }
string ans="";
 for(int i=0;i<tt.size();i++)
 {
          while(tt[i]>0)
          {
               ans+=to_string(i);
               tt[i]--;
          }
 }


    return ans;




    }
};
