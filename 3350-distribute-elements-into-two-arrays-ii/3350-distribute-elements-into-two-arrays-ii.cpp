#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;   
#define ordered_multiset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> 

class Solution {
public:
    int greaterCount(ordered_multiset &st, int num){
        int elements_smaller_or_equal_to_num = st.order_of_key(num + 1);
        int total_elements = st.size();

        return total_elements - elements_smaller_or_equal_to_num;
    }
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1, arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        ordered_multiset set1, set2;
        set1.insert(nums[0]);
        set2.insert(nums[1]);
        
        for(int i = 2; i < nums.size(); i++){
            int n1 = greaterCount(set1, nums[i]); 
            int n2 = greaterCount(set2, nums[i]);

            if(n1 > n2)
                arr1.push_back(nums[i]), set1.insert(nums[i]);

            else if(n1 < n2)
                arr2.push_back(nums[i]), set2.insert(nums[i]);

            else{
                if(arr2.size() < arr1.size())
                    arr2.push_back(nums[i]), set2.insert(nums[i]);
                else 
                    arr1.push_back(nums[i]), set1.insert(nums[i]);
            }
        }

        vector<int> ans;
        for(auto x:arr1) ans.push_back(x);
        for(auto x:arr2) ans.push_back(x);
        
        return ans;
    }
};