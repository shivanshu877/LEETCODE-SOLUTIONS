class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans ((nums1.size() +nums2.size()));
        merge(nums1.begin() , nums1.end() , nums2.begin() , nums2.end() , ans.begin());
        sort(ans.begin() , ans.end());
        return ((nums1.size() +nums2.size()) % 2 == 0) ?     double(
            (ans[((nums1.size() +nums2.size()) /2)] +
            ans[((nums1.size() +nums2.size()) /2) -1]) 
            /2.0) 
            : double(ans[((nums1.size() +nums2.size()) /2)] );
    }
};