class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int total = n1 + n2;
        int median1 = 0, median2 = 0;
        int i = 0, j = 0;
        
        for (int k = 0; k <= total / 2; ++k) {
            median1 = median2;
            if (i < n1 && (j >= n2 || nums1[i] < nums2[j])) {
                median2 = nums1[i++];
            } else {
                median2 = nums2[j++];
            }
        }
        
        if (total % 2 == 0) {
            return (median1 + median2) / 2.0;
        } else {
            return median2;
        }
    }
};
