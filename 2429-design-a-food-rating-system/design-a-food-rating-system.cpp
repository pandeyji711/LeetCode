class FoodRatings {
public:
       unordered_map<string,int>m;
     //comparator 
      struct com{
            bool operator()(const pair<int,string>&a, const pair<int,string>&b)const{
                            if(a.first==b.first)
                                return a.second>b.second;
                           return a.first<b.first;
        }
      };
        // priority_queue<pair<int,string>,vector<pair<int,string>>,com>pq;
         unordered_map<string,  priority_queue<pair<int,string>,vector<pair<int,string>>,com>>mp;
      unordered_map<string,string>revm;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
      
     
           for(int i=0;i<foods.size();i++)
            {
                 mp[cuisines[i]].push({ratings[i],foods[i]});
                  m[foods[i]]=ratings[i]; //current price
                  revm[foods[i]]=cuisines[i];
                   
            }
           
        
    }
    
    void changeRating(string food, int newRating) {

           m[food]=newRating;
            string cui=revm[food];
           mp[cui].push({newRating,food});
    }
    
    string highestRated(string cuisine) {

             while(!mp[cuisine].empty()&&mp[cuisine].top().first!=m[mp[cuisine].top().second])
                 mp[cuisine].pop();

              return mp[cuisine].top().second;
           
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */