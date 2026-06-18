// Last updated: 6/18/2026, 12:09:32 PM
1class Solution {
2public:
3bool isvowel(char ch){
4    if(ch=='a'|| ch=='e'|| ch=='i'|| ch=='o'|| ch=='u'){
5        return true;
6    }
7    return false;
8}
9    string sortVowels(string s) {
10        int n = s.size();
11        unordered_map<char,int> freq;
12        unordered_map<char,int> pos;
13        for(int i =0;i<n;i++){
14            if(isvowel(s[i])){
15                if(freq.find(s[i])==freq.end()){
16                    pos[s[i]]=i;
17                }
18                freq[s[i]]++;
19            }
20
21        }
22        vector<char> temp;
23        for(auto it : freq){
24            temp.push_back(it.first);
25        }
26        sort(temp.begin(),temp.end(),[&](char &ch1 , char &ch2){
27            if(freq[ch1]==freq[ch2]){
28                return pos[ch2]>pos[ch1];
29            }
30            return freq[ch1]>freq[ch2];
31        });
32        vector<char>allvowels;
33        for(int i =0;i<temp.size();i++){
34            for(int j =0;j<freq[temp[i]];j++){
35                allvowels.push_back(temp[i]);
36            }
37        }
38        string final="";
39        int j =0;
40        for(int i =0;i<n;i++){
41            if(isvowel(s[i])){
42                final.push_back(allvowels[j++]);
43            }
44            else{
45                final.push_back(s[i]);
46            }
47            
48        }
49        return final;    
50    }
51};