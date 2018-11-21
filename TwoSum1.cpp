#include <vector>
#include <iostream>
#include <map>

using namespace std;

/*start*/
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> indices{0, 0};
    multimap<int, int> numsMultimap;  //关键字可重复出现的map，定义在头文件map中

    for(int i = 0;i < nums.size(); i++)
        numsMultimap.insert( {nums[i], i} );  //insert成员向容器中添加一个元素

    for(int i = 0; i < nums.size(); i++){
        indices[0] = i;
        
        //find成员返回一个迭代器，指向第一个关键字为target-nums[i]的元素，若不在容器中，则返回指向尾元素下一个位置
        auto iter = numsMultimap.find(target - nums[i]);  
        if( iter != numsMultimap.end()) {
            if( iter->second == i ) {
            //如果一个multimap中有多个元素具有给定关键字，则这些元素在容器中会相邻存储
            //++iter令iter指示容器中的下一个元素
                if( ((++iter) != numsMultimap.end()) && (iter->first == target - nums[i]) ){
                    indices[1] = iter->second;
                    break;
                }
            }else if( iter->second != i){
                indices[1] = iter->second;
                break;
            }
        }
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
