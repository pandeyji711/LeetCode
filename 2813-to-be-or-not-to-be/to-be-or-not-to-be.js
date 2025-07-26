/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
       return { 
         toBe: function (val1)
          {
            //  return {val,val1};
             if(val===val1)
            return true;
            else
            throw "Not Equal";
          },
           notToBe: function (val1)
          {
            //  return {val,val1};
             if(val===val1)
            throw "Equal";
            else
            return true;
          }
       }
    //  return toBe;
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */