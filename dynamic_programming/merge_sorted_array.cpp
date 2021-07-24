class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int nPointer = n-1;
        int mPointer = m-1;
        int i = m+n-1;
        while(nPointer >=0 && mPointer >=0){
            if(nums1[mPointer] <= nums2[nPointer]){
                nums1[i] = nums2[nPointer];
                i--;
                nPointer--;
            } else {
                nums1[i] = nums1[mPointer];
                i--;
                mPointer--;
            }
        }
        while(nPointer >=0){
            nums1[i] = nums2[nPointer];
            i--;
            nPointer--;
        }
    }
};