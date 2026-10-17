class BusBooking {
public:
  
    vector<vector<int>>mat;
    int  sum=0;
    int minn=0;

    BusBooking(int n) {
        
      mat=  vector<vector<int>>(n,vector<int>(4,0));
       
       
        
    }
    
    void toggle(string seat) {
        int ind=1;
        int num=0;
        while(ind<seat.length())
        {
             num=num*10+(seat[ind]-'0');
             ind++;
        }
        if(seat[0]=='A'){
            if(mat[num-1][0]==0)
            {
                  if(mat[num-1][1]==0)
                  {
                     sum+=1;
                      mat[num-1][0]=1;
                      
                  }else{
                  sum+=3;
                   mat[num-1][0]=3;
                   

                  }
                  minn+=1;
                //   cout<<"a"<<sum<<endl;
            }else{
                 sum-=mat[num-1][0];
                 mat[num-1][0]=0;
                 minn-=1;

            }
        }
        if(seat[0]=='B'){
            if(mat[num-1][1]==0)
            {
                 
                     sum+=1;
                     mat[num-1][1]=1;
                  minn+=1;

            }else{
                 sum-=mat[num-1][1];
                 mat[num-1][1]=0;
                 minn-=1;

            }
            //  cout<<"b"<<sum<<endl;
        }
        if(seat[0]=='C'){
            if(mat[num-1][2]==0)
            {
                  
                     sum+=1;
                     minn+=1;
                     mat[num-1][2]=1;
                     
            }else{
                 sum-=mat[num-1][2];
                 mat[num-1][2]=0;
                 minn-=1;

            }
        }
        if(seat[0]=='D'){
            if(mat[num-1][3]==0)
            {
                  
                  if(mat[num-1][2]==0)
                  {
                     sum+=1;
                     mat[num-1][3]=1;
                  }else{
                  sum+=3;
                      mat[num-1][3]=3;
                  }
                  minn+=1;
                 
                 
            }else{
                 sum-=mat[num-1][3];
                 mat[num-1][3]=0;
                 minn-=1;

            }
        }
        
    }
    
    int getTotalTime() {
        return sum;
    }
    
    int getMinTime() {
        return abs(minn);
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */
