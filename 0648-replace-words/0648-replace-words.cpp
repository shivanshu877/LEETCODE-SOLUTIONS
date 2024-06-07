class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<string , int> dict ;
        for(auto x : dictionary){
            dict[x]++;
        }
        vector<string> words ;
        string temp = "" ;
        for(auto it : sentence){
            if(it == ' '){
             words.push_back(temp);
              temp = "" ;
            }
            else
            temp += it ;
            
        }
        if(temp.size()) words.push_back(temp);
        for(int i = 0 ; i< words.size() ;i++) {
            auto x = words[i];
            string t = "" ;
        for(auto y : x) {
            t+=y;
            if(dict.find(t) != dict.end()){
                words[i] = t ;
                break ;
                }
            }
        }
         temp = "";
        for(int i = 0 ; i< words.size() ;i++){
            auto it  = words[i] ;
            temp+=it ;
            if(i != words.size() - 1 )temp+=" "; 
        }
        return temp ;
    }
};