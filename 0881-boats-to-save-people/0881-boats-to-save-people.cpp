class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin() , people.end() );
        int left = 0 ;
        int right = people.size() -1;
        int count = 0 ;
     
        while(left <= right) {
            if(left == right){
                count++;
                break;
            }
            if(people[left] + people[right] <= limit){
                count++;
                left++;
                right--;
                cout << left << " " << right<< " "  << endl; 
            } 
            else if(people[right] <= limit){
                count++;
                right--;
                cout << "right" << " " << right<< " "  << endl; 
                
            }
            else {
                count++;
                left++;
                 cout << "left" << " " << right<< " "  << endl; 
               
            }
            
        }
        return count;
    }
};