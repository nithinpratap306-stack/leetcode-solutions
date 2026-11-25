class Solution {
public:
    string pushDominoes(string dominoes) {
        int i=0,j=0;
        dominoes='L'+dominoes+'R';
        int n=dominoes.size();
        while(i<n-1){
            for(int k=i+1;k<n;k++){
                if(dominoes[k]!='.'){
                    j=k;
                    break;
                }
            }
            if(dominoes[j]==dominoes[i]){
                for(int k=i+1;k<j;k++){
                    dominoes[k]=dominoes[j];
                }
            }
            else if(dominoes[i]=='R' && dominoes[j]=='L'){
                int left=i+1;
                int right=j-1;
                while(left<right){
                    dominoes[left]='R';
                    dominoes[right]='L';

                    left++;
                    right--;
                }
            }
            i=j;
        }
        return dominoes.substr(1,n-2);
    }
};
/*Time complexity: O(n), where n is the length of the input string. Each position is processed a constant number of times as the pointers i and j move forward through the string (the inner loop advances j to the next non-dot, and the updates between i and j touch each character at most once).
Space complexity: O(1) extra space (besides the modified input string). The algorithm modifies the string in place and uses a few indices. The only additional space is a few integers.*/