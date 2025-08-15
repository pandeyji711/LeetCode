class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if (n == 0) return;

        // Shift nums1's first m elements to the right
        for (int i = m - 1; i >= 0; i--) {
            nums1[i + n] = nums1[i];
        }

        int l = n;  // pointer for shifted nums1
        int r = 0;  // pointer for nums2
        int k = 0;  // pointer for merged array

        while (l < m + n && r < n) {
            if (nums1[l] <= nums2[r]) {
                nums1[k++] = nums1[l++];
            } else {
                nums1[k++] = nums2[r++];
            }
        }

        while (r < n) {
            nums1[k++] = nums2[r++];
        }
    }
};