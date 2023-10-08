class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        set<string> dict(bank.begin(), bank.end());
        string possible =  "ACGT" ;
        if (!dict.contains(endGene))
        return -1 ;
        queue<pair <string , int >> q ;
        q.push(make_pair(startGene  , 0 )) ;
        set<string> visited ;
        visited.insert(startGene);
        while(!q.empty()) {
             pair<string , int > temp =  q.front();
             string gene  =  temp.first;
             int level = temp.second ;
             q.pop();
             if (gene  ==  endGene)
             return level;
             for( int i = 0 ; i<gene.size() ; i++){
                 for(auto x: possible){
                     string new_gene = gene.substr(0 , i) + x + gene.substr(i+1 ,gene.size()-1 );
                     if ((!visited.contains(new_gene)) && (dict.contains(new_gene))){
                         q.push(make_pair(new_gene , level+1));
                         visited.insert(new_gene);
                     }
                 }
             }


        }
     return -1 ;

    }
};