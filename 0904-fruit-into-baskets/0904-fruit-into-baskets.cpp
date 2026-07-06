class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n =fruits.size();
        unordered_map<int,int> mp;
        int i =0;
        int j =0;
        int cnt =0;
        while(j < n)
        {
            mp[fruits[j]]++;
            if(mp.size() <= 2)
            {
                cnt = max(cnt , j-i+1);
            } 
            else
            {
              mp[fruits[i]]--;
              if(mp[fruits[i]] == 0)
              {
                mp.erase(fruits[i]);
              } 
              i++;
            }
            j++;
        }
        return cnt;
    }
};