class Solution {
public:
 bool is_vowel(char a)
 {
       return (a=='a'||a=='e'||a=='i'||a=='o'||a=='u');
 }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int>v(n+1,0);
        v[0]=0;
        //  if(is_vowel(words[0][0])&&is_vowel(words[0][words[0].length()-1]))
        //  v[0]=1;

        for( int i=0;i<words.size();i++)
        {
              if(is_vowel(words[i][0])&&is_vowel(words[i][words[i].length()-1])){
                // cout<<i<<" ";
                 v[i+1]=v[i]+1;
                //  cout<<v[i+1]<<" "; 

              }
                 else{
                 v[i+1]=v[i];
                //   cout<<v[i+1]<<" "; 
                 }

        }
        vector<int>ans;

        for(int i=0;i<queries.size();i++)
        {
                int first=v[queries[i][0]];
                int second=v[queries[i][1]+1];
                ans.push_back(second-first);
        }
        return ans;
    }
};