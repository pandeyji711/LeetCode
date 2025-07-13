class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;
        for(int i=digits.size()-1;i>=0;i--)
        {
                   int sum=carry+digits[i];
                   if(sum>9)
                   {
                      sum=sum-10;
                      carry=1;
                   }else
                   carry=0;
                   digits[i]=sum;
        }
        if(carry>0)
        {
              reverse(digits.begin(),digits.end());
              digits.push_back(1);
              reverse(digits.begin(),digits.end());

        }
        return digits;
    }
};