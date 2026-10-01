class Solution {
public:
    bool isCircularSentence(string sentence) {
        stringstream ss(sentence);
        string word,first,prev;
        ss>>first;
        prev=first;
        while(ss>>word){
            if(prev.back()!=word.front()) return false;

            prev=word;
        }
        return first.front()==prev.back();
    }
};
/*Time: O(n)
Space: O(n) — because of stringstream/temporary word handling.*/