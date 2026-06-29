// Last updated: 6/29/2026, 10:19:27 AM
class Solution {
public:
bool isvowel(char ch){
    if(ch=='a'|| ch=='e'|| ch=='i'|| ch=='o'|| ch=='u'){
        return true;
    }
    return false;
}
    string sortVowels(string s) {
        int n = s.size();
        unordered_map<char,int> freq;
        unordered_map<char,int> pos;
        for(int i =0;i<n;i++){
            if(isvowel(s[i])){
                if(freq.find(s[i])==freq.end()){
                    pos[s[i]]=i;
                }
                freq[s[i]]++;
            }

        }
        vector<char> temp;
        for(auto it : freq){
            temp.push_back(it.first);
        }
        sort(temp.begin(),temp.end(),[&](char &ch1 , char &ch2){
            if(freq[ch1]==freq[ch2]){
                return pos[ch2]>pos[ch1];
            }
            return freq[ch1]>freq[ch2];
        });
        vector<char>allvowels;
        for(int i =0;i<temp.size();i++){
            for(int j =0;j<freq[temp[i]];j++){
                allvowels.push_back(temp[i]);
            }
        }
        string final="";
        int j =0;
        for(int i =0;i<n;i++){
            if(isvowel(s[i])){
                final.push_back(allvowels[j++]);
            }
            else{
                final.push_back(s[i]);
            }
            
        }
        return final;    
    }
};