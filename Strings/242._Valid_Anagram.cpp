#include<bits/stdc++.h>
using namespace std;
int main(){
    string a,b;
    cin>>a>>b;
    unordered_set<char,int>mp;
    for(char c: a){
        mp[c]++;
    }
    for(char c: b){
        mp[c]--;
    }
    for(auto[c,i]: mp){
        if(i!=0){
            cout<<a<<" and "<<b<<" are not anagram";
            return 0;
        }
    }
    cout<<a<<" and "<<b<<" are anagram";
}