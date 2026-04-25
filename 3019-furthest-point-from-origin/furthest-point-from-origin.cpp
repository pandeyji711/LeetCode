class Solution {
public:
//  int solve(string &moves, int ind )
//  {
//       if(ind>=moves.size())return 0;
//       int l=0;
//       int r=0;
//       if(moves[ind]=='L')
//       l=1+solve(moves,ind+1);
//       else if(moves[ind]=='R')
//       r=1+solve(moves)
//  }
    int furthestDistanceFromOrigin(string moves) {
        int l=0;
        int r=0;
        int d=0;
        for(int i=0;i<moves.length();i++)
        {
             if(moves[i]=='L')l++;
              else if(moves[i]=='R')r++;
              else
              d++;
        }
        return abs(r-l)+d;
    }
};