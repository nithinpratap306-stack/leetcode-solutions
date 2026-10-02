class Solution {
public:
    int n;
    vector<string>res;
    void generate(string curr, int open,int close){
        if(curr.size()==n*2){
            res.push_back(curr);
            return;
        }
        if(open<n){
            generate(curr+"(",open+1,close);
        }
        if(close<open){
            generate(curr+")",open,close+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        this->n=n;
        generate("",0,0);
        return res;
    }
};
/*Time Complexity: O(Cₙ × n) — each of the Cₙ strings has length 2n
Space Complexity: O(Cₙ × n) for the output, plus O(n) recursion stack*/