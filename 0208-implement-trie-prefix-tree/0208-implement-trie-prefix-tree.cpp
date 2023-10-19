class Trie {
public:
 set<string> sat ;
    Trie() {
        
    }
    
    void insert(string word) {
             sat.insert(word) ;
    }
    
    bool search(string word) {
         auto pos =   sat.find(word);
           if (pos != sat.end())
              return true;
	        else
            return false ;
    }
    
    bool startsWith(string prefix) {
         for(auto x: sat)
            if(x.starts_with(prefix)) return true;
            return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */