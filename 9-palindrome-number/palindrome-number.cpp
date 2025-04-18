class Solution {
public:
   bool isPalindrome(int x)
{

    long int x1 = 0;
    long int s = x;

    if (x < 0)
    {
        return 0;
    }

    while (x > 0)
    {

        x1 *= 10;
        x1 += x % 10;
        x /= 10;
    }

    if (s == x1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
};