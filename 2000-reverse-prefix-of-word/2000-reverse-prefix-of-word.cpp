class Solution {
public:
    void f(string& s , int j  ){
        int i =0 ;
        while(i < j ){
            char temp =  s[i] ;
            s[i] = s[j] ;
            s[j] = temp ;
            i++;
            j--;
        }
    }
     
    string reversePrefix(string word, char ch) {
     for(int i =0 ; i < word.size() ; i++){
         if(word[i] ==  ch){
             f( word  , i );
             break;
         }
     }
        return word;
    }
};