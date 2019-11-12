//
// Created by ubuntu on 11/12/19.
//

#ifndef TEAT_SEARCH_H
#define TEAT_SEARCH_H

namespace algorithms{

// 搜索某一位置(LC-35):搜索某个数在有序数组中的插入位置，要求时间复杂度O(logn)
// 例如：[1,3,5,6], 5，则返回2，表示在index=2的位置插入
// 常规暴力解法是遍历O(n)，所以需要采用二分法进行搜索(二分法的前提是有序数组，否则不能用)
void searchInsertPosition(std::vector<int> &nums, int target){
    int left = 0;
    int right = nums.size - 1;
    while(left < right){
        mid = left + (right - left) / 2;     // 为了防止溢出，避免使用(l+r)/2
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            right = mid;
        else if (nums[mid] < target)
            left = mid;
    }
    if(nums[left] < target)
        return left;
}


}

#endif //TEAT_SEARCH_H
