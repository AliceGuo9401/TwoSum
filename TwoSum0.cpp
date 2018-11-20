class Solution {
public:
    int findSecondIndex(vector<int>& nums, int target, int start) {
        int secondIndex = 0;
        int i(start);
        
        while(i < nums.size()) {
            if(nums[i] == target)
                return secondIndex = i;
            i++;
            }
        return 0;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices{0, 0};  //初始化vector对象
        int j(0);
        
        for(int i = 0; i < nums.size(); i++){
            indices[0] = i; //下标运算符访问vector对象的元素
            
            j = findSecondIndex(nums, target - nums[i], i+1);
            indices[1] = j;
            if(indices[1] != 0 && i < indices[1] && indices[1] < nums.size())
                break;
        }
        return indices;
    }
};
