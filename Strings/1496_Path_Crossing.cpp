class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<string,int>mp;
        mp["0,0"]++;
        int x=0,y=0;
        for(char c: path){
            if(c=='N') x+=1;
            else if(c=='S') x-=1;
            else if(c=='E') y+=1;
            else y-=1;
            string pt=to_string(x)+","+to_string(y);
            if(mp[pt]==1){ 
                return true;
            }
            mp[pt]++;
        }
        return false;
    }
};
/*Time Complexity: O(n) average
Space Complexity: O(n)*/