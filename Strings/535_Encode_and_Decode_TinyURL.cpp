class Solution {
public:
    unordered_map<string,string>mp;
    int i=1;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string key=to_string(i);
        i++;
        mp[key]=longUrl;
        return key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
/*Analysis Result
- Time complexity:
  - encode: O(1) expected, since it inserts into a hash map and returns a new key.
  - decode: O(1) expected, since it performs a hash map lookup.
- Space complexity:
  - O(n), where n is the number of unique URLs encoded. Storing each original URL in the map and the corresponding small key consumes linear space. The int i and map overhead are negligible relative to stored URLs.*/