#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        
        if (m == 0){
            nums1 = nums2;
            return;
        }
            
        else if (n == 0)
            return;
        else{
            int key1 = m-1, key2 = n-1;
            int total_key = m + n - 1;
            for (int total_key = m + n - 1; total_key >= 0; total_key --){
                if (key2 < 0)
                    break;
                if (key1 >= 0 && nums1[key1] >= nums2[key2])
                    nums1[total_key] = nums1[key1 --];
                else
                    nums1[total_key] = nums2[key2 --];
                    
                
            }
        }
        
    }
};

int main(){
    Solution sol;
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 2;

    sol->merge(nums1, m, nums2, n);

    for (int num : nums1) {
        cout << num << " ";
    }

    cout << endl;

    return 0;

}