class Solution {
public:
    string freqAlphabets(string str) {
       

	//1 to a 
	
	//2 to b
// 	 stack<char>st;
// 	  string tem;
	  string ans;
	  vector<int>tem;
	   unordered_map<char,int>m;
	 
	  for(int i=0;i<str.length();i++)
	  {
	             if(str[i]=='#')
	             {
	                     int t1=tem[tem.size()-1];
	                      tem.pop_back();
	                      
	                      int t2=tem[tem.size()-1]; 
	                     tem.pop_back();
	                     int re=t2*10+t1;
	                     tem.push_back(re);
	                    
	             }else
	              tem.push_back(str[i]-'0');
	  }
    //   string ans=0;
       for(int i=0;i<tem.size();i++)
	  {
	            ans.push_back(tem[i]+'a'-1);
	  } 
      return ans;
    }
};