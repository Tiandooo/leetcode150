# leetcode150
**面试经典 150 题**

记录解题思路和代码

链接：https://leetcode.cn/studyplan/top-interview-150/

计划：每周五题



## 1. [合并两个有序数组](https://leetcode.cn/problems/merge-sorted-array/)[双指针]

### question

给你两个按 **非递减顺序** 排列的整数数组 `nums1` 和 `nums2`，另有两个整数 `m` 和 `n` ，分别表示 `nums1` 和 `nums2` 中的元素数目。

请你 **合并** `nums2` 到 `nums1` 中，使合并后的数组同样按 **非递减顺序** 排列。

**注意：**最终，合并后数组不应由函数返回，而是存储在数组 `nums1` 中。为了应对这种情况，`nums1` 的初始长度为 `m + n`，其中前 `m` 个元素表示应合并的元素，后 `n` 个元素为 `0` ，应忽略。`nums2` 的长度为 `n` 。

 

**示例 1：**

```
输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
输出：[1,2,2,3,5,6]
解释：需要合并 [1,2,3] 和 [2,5,6] 。
合并结果是 [1,2,2,3,5,6] ，其中斜体加粗标注的为 nums1 中的元素。
```

**示例 2：**

```
输入：nums1 = [1], m = 1, nums2 = [], n = 0
输出：[1]
解释：需要合并 [1] 和 [] 。
合并结果是 [1] 。
```

**示例 3：**

```
输入：nums1 = [0], m = 0, nums2 = [1], n = 1
输出：[1]
解释：需要合并的数组是 [] 和 [1] 。
合并结果是 [1] 。
注意，因为 m = 0 ，所以 nums1 中没有元素。nums1 中仅存的 0 仅仅是为了确保合并结果可以顺利存放到 nums1 中。
```

 

**提示：**

- `nums1.length == m + n`
- `nums2.length == n`
- `0 <= m, n <= 200`
- `1 <= m + n <= 200`
- `-109 <= nums1[i], nums2[j] <= 109`

 

**进阶：**你可以设计实现一个时间复杂度为 `O(m + n)` 的算法解决此问题吗？

### answer

时间复杂度： `O(m + n)`  

空间复杂度： `O(1)`  

思路：从后往前一次遍历，哪个大选哪个，注意边界

cpp代码：

``````cpp
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
``````







## 2.[移除元素](https://leetcode.cn/problems/remove-element/)

### question

给你一个数组 `nums` 和一个值 `val`，你需要 **[原地](https://baike.baidu.com/item/原地算法)** 移除所有数值等于 `val` 的元素。元素的顺序可能发生改变。然后返回 `nums` 中与 `val` 不同的元素的数量。

假设 `nums` 中不等于 `val` 的元素数量为 `k`，要通过此题，您需要执行以下操作：

- 更改 `nums` 数组，使 `nums` 的前 `k` 个元素包含不等于 `val` 的元素。`nums` 的其余元素和 `nums` 的大小并不重要。
- 返回 `k`。

**示例 1：**

```
输入：nums = [3,2,2,3], val = 3
输出：2, nums = [2,2,_,_]
解释：你的函数函数应该返回 k = 2, 并且 nums 中的前两个元素均为 2。
你在返回的 k 个元素之外留下了什么并不重要（因此它们并不计入评测）。
```

**示例 2：**

```
输入：nums = [0,1,2,2,3,0,4,2], val = 2
输出：5, nums = [0,1,4,0,3,_,_,_]
解释：你的函数应该返回 k = 5，并且 nums 中的前五个元素为 0,0,1,3,4。
注意这五个元素可以任意顺序返回。
你在返回的 k 个元素之外留下了什么并不重要（因此它们并不计入评测）。
```

 

**提示：**

- `0 <= nums.length <= 100`
- `0 <= nums[i] <= 50`
- `0 <= val <= 100`



### answer

思路：将指定的值移动到最后边即可，使用两个指针控制前后，相遇时停止。

cpp代码

``````cpp
class Solution {
public:

    int removeElement(vector<int>& nums, int val) {
        int length = nums.size() - 1;
        int n = nums.size() - 1;
        int i = 0;


        while (i <= n){
            if (nums[i] == val){
                nums[i] = nums[n];
                n --;
            }
            else{
                i ++;
            }
        }
        // 防止越界
        if (n <= length)
            n ++;
        
        
        return n;
    }
};
``````





## 3.[删除有序数组中的重复项](https://leetcode.cn/problems/remove-duplicates-from-sorted-array/)

### question

给你一个 **非严格递增排列** 的数组 `nums` ，请你**[ 原地](http://baike.baidu.com/item/原地算法)** 删除重复出现的元素，使每个元素 **只出现一次** ，返回删除后数组的新长度。元素的 **相对顺序** 应该保持 **一致** 。然后返回 `nums` 中唯一元素的个数。

考虑 `nums` 的唯一元素的数量为 `k` ，你需要做以下事情确保你的题解可以被通过：

- 更改数组 `nums` ，使 `nums` 的前 `k` 个元素包含唯一元素，并按照它们最初在 `nums` 中出现的顺序排列。`nums` 的其余元素与 `nums` 的大小不重要。
- 返回 `k` 。



**示例 1：**

```
输入：nums = [1,1,2]
输出：2, nums = [1,2,_]
解释：函数应该返回新的长度 2 ，并且原数组 nums 的前两个元素被修改为 1, 2 。不需要考虑数组中超出新长度后面的元素。
```

**示例 2：**

```
输入：nums = [0,0,1,1,1,2,2,3,3,4]
输出：5, nums = [0,1,2,3,4]
解释：函数应该返回新的长度 5 ， 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4 。不需要考虑数组中超出新长度后面的元素。
```

 

**提示：**

- `1 <= nums.length <= 3 * 104`
- `-104 <= nums[i] <= 104`
- `nums` 已按 **非严格递增** 排列

### answer

思路：类似于上一道题，遍历数组，对于left，找到和他不重复的right，并将后面不相等的值全部填充至前面重复的值。

代码：

``````cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        
        int left = 0;
        for (int right = left + 1; right < nums.size(); right ++){
            
            
            if (nums[left] != nums[right]){
                nums[left+1] = nums[right];
                left ++;
            }
            
            
        }
        return left+1;
    }
};
``````



## 4.[删除有序数组中的重复项 II](https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/)

### question

给你一个有序数组 `nums` ，请你**[ 原地](http://baike.baidu.com/item/原地算法)** 删除重复出现的元素，使得出现次数超过两次的元素**只出现两次** ，返回删除后数组的新长度。

不要使用额外的数组空间，你必须在 **[原地 ](https://baike.baidu.com/item/原地算法)修改输入数组** 并在使用 O(1) 额外空间的条件下完成。



**示例 1：**

```
输入：nums = [1,1,1,2,2,3]
输出：5, nums = [1,1,2,2,3]
解释：函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3。 不需要考虑数组中超出新长度后面的元素。
```

**示例 2：**

```
输入：nums = [0,0,1,1,1,1,2,3,3]
输出：7, nums = [0,0,1,1,2,3,3]
解释：函数应返回新长度 length = 7, 并且原数组的前七个元素被修改为 0, 0, 1, 1, 2, 3, 3。不需要考虑数组中超出新长度后面的元素。
```

 

**提示：**

- `1 <= nums.length <= 3 * 104`
- `-104 <= nums[i] <= 104`
- `nums` 已按升序排列

### answer

思路：加个计数即可。

代码：

``````cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        
        int left = 0;

        int count = 1;
        for (int right = left + 1; right < nums.size(); right ++){
            
            
            if (nums[left] != nums[right]){
                nums[left+1] = nums[right];
                left ++;
                // 充值计数器
                count = 1;
            }
            else if (count < 2){
                nums[left+1] = nums[right];
                left ++;
                count ++;
            }else{
                count++;
            }
            
            
            
        }
        return left+1;
    }
};
``````



## 5.[多数元素](https://leetcode.cn/problems/majority-element/)（看答案了）

### question

给定一个大小为 `n` 的数组 `nums` ，返回其中的多数元素。多数元素是指在数组中出现次数 **大于** `⌊ n/2 ⌋` 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

 

**示例 1：**

```
输入：nums = [3,2,3]
输出：3
```

**示例 2：**

```
输入：nums = [2,2,1,1,1,2,2]
输出：2
```

 

**提示：**

- `n == nums.length`
- `1 <= n <= 5 * 104`
- `-109 <= nums[i] <= 109`

 

**进阶：**尝试设计时间复杂度为 O(n)、空间复杂度为 O(1) 的算法解决此问题。

### answer

思路：摩尔投票，将数分为众数和非众数，并依次更新。**这种问题一般要想到状态转移。**

代码：

``````cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int votes = 0; 
        int x;

        for (int i = 0; i < n; i ++){
            int num = nums[i];
            if (votes == 0){
                x = num;
              
            }
            if (x == num)
                votes ++;
            else
                votes --;
        }
        return x;
    }
};
``````



## 6.[轮转数组](https://leetcode.cn/problems/rotate-array/)

### question

给定一个整数数组 `nums`，将数组中的元素向右轮转 `k` 个位置，其中 `k` 是非负数。

 

**示例 1:**

```
输入: nums = [1,2,3,4,5,6,7], k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右轮转 1 步: [7,1,2,3,4,5,6]
向右轮转 2 步: [6,7,1,2,3,4,5]
向右轮转 3 步: [5,6,7,1,2,3,4]
```

**示例 2:**

```
输入：nums = [-1,-100,3,99], k = 2
输出：[3,99,-1,-100]
解释: 
向右轮转 1 步: [99,-1,-100,3]
向右轮转 2 步: [3,99,-1,-100]
```

 

**提示：**

- `1 <= nums.length <= 105`
- `-231 <= nums[i] <= 231 - 1`
- `0 <= k <= 105`

 

**进阶：**

- 尽可能想出更多的解决方案，至少有 **三种** 不同的方法可以解决这个问题。
- 你可以使用空间复杂度为 `O(1)` 的 **原地** 算法解决这个问题吗？

### answer

思路1：转圈圈更新value，直到尾碰到头。使用count计数转的次数，等于n时结束。

代码1

``````cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if (n == 0 || n == 1 || k == 0)
            return;

        int count = 0;  // 记录已经旋转了多少个元素
        for (int start = 0; count < n; start++) {
            int current = start;
            int prev = nums[start];  // 暂存当前元素
            
            do {
                int next = (current + k) % n;  // 计算新位置
                swap(nums[next], prev);  // 交换当前位置和下一个位置的元素
                current = next;
                count++;  // 记录已处理的元素
            } while (start != current);  // 回到起始位置时停止
        }

    }
};
``````

思路2：

reverse三次，整体reverse，前k个reverse，后n-k个reverse，评价为纯纯的找规律

代码2：

``````cpp
class Solution {
public:
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start += 1;
            end -= 1;
        }
    }

    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
};


``````



## 7.[买卖股票的最佳时机](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/)

### question

给定一个数组 `prices` ，它的第 `i` 个元素 `prices[i]` 表示一支给定股票第 `i` 天的价格。

你只能选择 **某一天** 买入这只股票，并选择在 **未来的某一个不同的日子** 卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 `0` 。

 

**示例 1：**

```
输入：[7,1,5,3,6,4]
输出：5
解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
```

**示例 2：**

```
输入：prices = [7,6,4,3,1]
输出：0
解释：在这种情况下, 没有交易完成, 所以最大利润为 0。
```

 

**提示：**

- `1 <= prices.length <= 105`
- `0 <= prices[i] <= 104`





### answer

第一想法是肯定有O(N)的解法，于是想到状态转移，只需要维护一个l_min和l_max变量来表示到当前位置时刻的最佳利润，并逐渐更新。一遍AC。

cpp代码

``````cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || n == 1)
            return 0;

        int g_min = prices[0]; // 截止到目前的全局最低
        int l_min, l_max = prices[0]; // 截止到目前利润最大的购入点和出售点

        for (int i = 0; i < prices.size(); i ++){
            int cur = prices[i];
			// 当前值减去最小值大于当前最大利润时，更新lmax和lmin
            if (cur - g_min > l_max - l_min){
                l_min = g_min;
                l_max = cur;
            }
			// 当碰到更低的值时，更新g_min
            if(cur < g_min)
                g_min = cur;
            
        }

        return l_max - l_min;
    }
};
``````

时间复杂度：O(N) 

空间复杂度： O(1)
