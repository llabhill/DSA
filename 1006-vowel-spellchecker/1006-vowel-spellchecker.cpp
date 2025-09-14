class Solution {
public:
    unordered_set<string> s;
    unordered_map<string,string> caseerror;
    unordered_map<string,string> vowelerror;
    string toLower(string r){
        string z="";
        for(char &s:r){
            z+=tolower(s);
        }
        return z;
    }
    string vowelasterisk(string z){
        for(char &ch : z){
         ch = tolower(ch);
        }
        string vowel=z;
        for(char &ch:vowel){
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
                ch='*';
            }
        }
        return vowel;
    }
    string checkformatch(string &query){
        if(s.count(query)){
            return query;
        }
        //caseerror check
        string lowercase=toLower(query);
        if(caseerror.count(lowercase)){
            return caseerror[lowercase];
        }

        string vowelCase=vowelasterisk(query);
        if(vowelerror.count(vowelCase)){
            return vowelerror[vowelCase]; 
        }
        return "";

    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        for(string word:wordlist){
            s.insert(word);
            string lowercase=toLower(word);
            if(caseerror.find(lowercase)==caseerror.end()){
                caseerror[lowercase]=word;
            }
            string vowelconvert=vowelasterisk(word);
            if(vowelerror.find(vowelconvert)==vowelerror.end()){
                vowelerror[vowelconvert]=word;
            }
        }
        vector<string> ans;
        for(string query:queries){
            ans.push_back(checkformatch(query));
        }
        return ans;
    }
};