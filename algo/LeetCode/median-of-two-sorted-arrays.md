

There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

__Example 1:__
```
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
```
__Example 2:__

```
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
```

```c++
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double sum = 0;
        vector<int> result;        
        result = nums1;
        result.insert(result.end(), nums2.begin(), nums2.end());        
        sort(result.begin(), result.end());
        return (result.size() % 2 == 1)?result.at(result.size()/2)
            :(result.at(result.size()/2-1)+result.at(result.size()/2))/2.0;
        
    }
};
```

vector 두개를 합치고 sort 한뒤 중앙값을 구해주면 끝

std::merge 함수를 쓰면 정렬된채로 합쳐주기도 함
