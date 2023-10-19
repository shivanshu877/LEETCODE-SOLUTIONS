class WordDictionary {
public:
    unordered_map<int,vector<string>>mp;   
    WordDictionary() 
    {
    }
    void addWord(string word) 
    {
        mp[word.size()].push_back(word);
    }
    
    bool search(string word) 
    {
        int k=word.size();
        for(auto &it:mp[k])// the & used to reduce time again creating a copy
        {
            int c=0;
            for(int i=0;i<it.size();i++)
            {
                if(word[i]!='.' && word[i]!=it[i]) 
                {
                    break;
                }
                else c++;
            }
            if(c==word.size())
            {
                return true;
            }
        }
        return false;
    }
};
