#include <vector>
#include <iostream>

using namespace std;
/*start*/
int findSecondIndex(vector<int>& nums, int target, int start) {
    //int low = start, high = nums.size() - 1;
    int secondIndex = 0;
    /*if(nums[0] < nums[1]) {
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] < target)
                low = mid + 1;
            else if (target < nums[mid])
                high = mid - 1;
            else
                return secondIndex = mid;
        }
    }
    else if(nums[0] > nums[1]) {
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] > target)
                low = mid + 1;
            else if (target < nums[mid])
                high = mid - 1;
            else
                return secondIndex = mid;
        }
    }*/
    //else{
    int i(start);
    while(i < nums.size()) {
        if(nums[i] == target)
            return secondIndex = i;
        i++;
    }
    //}
    return 0;
}

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> indices{0, 0};  //初始化vector对象
    int j(0);
    for(int i = 0; i < nums.size(); i++){
        indices[0] = i; //使用下标运算符访问vector对象
        j = findSecondIndex(nums, target - nums[i], i+1);
        indices[1] = j;
        if(indices[1] != 0 && i < indices[1] && indices[1] < nums.size())
            break;
    }
    return indices;
}
/*end*/
int main() {
    vector<int> givenNums{3, 2, 4};
    int givenTarget = 6;
    vector<int> coutNums = twoSum(givenNums, givenTarget);
    cout << coutNums[0] << "," << coutNums[1] << endl;
    return 0;
}
