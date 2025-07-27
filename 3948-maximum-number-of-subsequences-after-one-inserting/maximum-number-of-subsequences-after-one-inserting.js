/**
 * @param {string} s
 * @return {number}
 */
var numOfSubsequences = function(s) {
    let n=s.length;
       let leftprec = new Array(n+1).fill(0);   // count of 'L' up to index i
    let rightprec= new Array(n+1).fill(0);
       let leftprel = new Array(n+1).fill(0);   // count of 'L' up to index i
    let rightprel= new Array(n+1).fill(0);
       let leftpret = new Array(n+1).fill(0);   // count of 'L' up to index i
    let rightpret= new Array(n+1).fill(0);
    
        for(let i=0;i<s.length;i++)
        {
                  if(s[i]=='L')
                  {
                      leftprel[i+1]=leftprel[i]+1; 
                      
                    //   console.log("k");
                  }else
                   leftprel[i+1]=leftprel[i]; 

                       if(s[i]=='C')
                  {
                      leftprec[i+1]=leftprec[i]+1; 
                      
                    //   console.log("k");
                  }else
                   leftprec[i+1]=leftprec[i]; 

                //        if(s[i]=='t')
                //   {
                //       leftprel[i+1]=leftprel[i]+1; 
                      
                //     //   console.log("k");
                //   }else
                //    leftprel[i+1]=leftprel[i]; 
              
                

        }
        for(let i=s.length-1;i>=0;i--)
        {
                  if(s[i]=='T')
                  {
                      rightpret[i]=rightpret[i+1]+1; 
                  }else
                   rightpret[i]=rightpret[i+1]; 

                    if(s[i]=='C')
                  {
                      rightprec[i]=rightprec[i+1]+1; 
                  }else
                   rightprec[i]=rightprec[i+1];

                    if(s[i]=='L')
                  {
                      rightprel[i]=rightprel[i+1]+1; 
                  }else
                   rightprel[i]=rightprel[i+1]; 

        }
        var ans=0;
        var maxxin=0;
        var maxxint=0;
        var maxxinl=0;
       for(let i=0;i<s.length;i++)
        {
                 if(s[i]==='C')
                 {
                    
                     
                         let left=leftprel[i];
                         let right=rightpret[i];
                        
                        //insert l
                         maxxinl+=(right);
                        //  insert t
                        maxxint+=(left);
                         ans+=(left*right);
                        //  console.log(ans);
                 }
                 //insert c
                   let leftl=leftprel[i];
                         let rightt=rightpret[i];
                         maxxin=Math.max(maxxin,leftl*rightt);
                //  //insert l
                //  let temc=leftprec[i];
                //  let temt=rightpret[i];
                //   maxxin=Math.max(maxxin,temc*temt);
                //   //insert t
                //    let teml=leftprel[i];
                //  let temcl=rightprec[i];
                //   maxxin=Math.max(maxxin,temcl*teml);



        }
        // var maxxin=0;
        //    for(let i=0;i<s.length;i++)
        // {
        //           //insert L
        //            let left=leftpre[i];
        //                  let right=rightpre[i];
        //            let tem=left*right;
        //            maxxin=Math.max(maxxin,tem);
        // }

        // console.log(ans);
        console.log(maxxin+" "+maxxinl+" "+maxxint);
        return ans+Math.max(maxxin,maxxinl,maxxint);
};