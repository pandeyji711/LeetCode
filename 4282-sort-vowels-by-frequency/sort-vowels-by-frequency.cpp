class Solution {
public:
 bool isvoval(char s)
 {
      return s=='a'||s=='e'||s=='i'||s=='o'||s=='u';
 }
    string sortVowels(string s) {
       unordered_map<int,int>m;
       

       for(int i=0;i<s.length();i++)
       {
           if(isvoval(s[i]))
            m[s[i]]++;
       }
       vector<pair<int,char>>vp;
        for(int i=0;i<s.length();i++)
       { 
               if(m.count(s[i]))
               {
                 vp.push_back({m[s[i]],s[i]});
                 m.erase(s[i]);
               }
       }
       auto com=[](const pair<int,char>&a,const pair<int,char>&b){
                               
                        return a.first>b.first;
               
                   };
       stable_sort(vp.begin(),vp.end(),com);
     int ind=0;
       for(int i=0;i<s.length();i++)
       {
                    if(isvoval(s[i])){
                        
                        s[i]=vp[ind].second;
                        vp[ind].first--;
                        if(vp[ind].first==0)
                        {
                             ind++;
                        }
                    }
       }
      return  s;
    }
};