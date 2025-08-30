# 💡 Problem: Subarrays with K Distinct Integers
[Link](https://leetcode.com/problems/subarrays-with-k-different-integers/)
<br>
**Tags:** `#array`, `#sliding-window`, `#hash-table`

---

## The "Aha!" Moment / Core Idea
The key to this problem is realizing that directly counting subarrays with **exactly K** distinct elements is very difficult with a standard sliding window. The problem becomes much easier if you rephrase it using a clever mathematical trick: the number of subarrays with **exactly K** distinct elements is equal to `(number of subarrays with at most K distinct elements) - (number of subarrays with at most K-1 distinct elements)`.

---

## Approach & Data Structures
**Algorithm:** The solution uses the **"At Most K"** technique, which requires a helper function that solves the subproblem of counting subarrays with at most `K` distinct elements.
<br>
**Helper Function:** The `atMostK(k)` helper function is implemented using a classic sliding window with two pointers (`left`, `right`).
<br>
**Main Data Structure:** A frequency map (`map<int, int>`) is used inside the helper to track the count of distinct numbers within the current window.

---

## How It Works
The main function solves the problem by calling a helper function twice. The magic happens inside this `atMostK` helper.

1.  **The `atMostK(k)` Helper Function**
    This function uses a sliding window to count all subarrays with `k` or fewer distinct integers.

    ```cpp
    int atMostK(vector<int>& nums, int k) {
        int left = 0;
        int count = 0;
        map<int, int> mp;

        for (int right = 0; right < nums.size(); ++right) {
            mp[nums[right]]++;

            while (mp.size() > k) {
                mp[nums[left]]--;
                if (mp[nums[left]] == 0) {
                    mp.erase(nums[left]);
                }
                left++;
            }
            count += (right - left + 1);
        }
        return count;
    }
    ```
    **Logic:** The `right` pointer expands the window. The `while` loop shrinks the window from the left whenever the number of distinct elements (`mp.size()`) exceeds `k`, ensuring the window is always valid.
    <br>
    **Why the Counting Works:** For a valid window from `left` to `right`, every subarray that ends at `right` and starts at or after `left` is also valid. The number of such subarrays is exactly the size of the current window, which is `right - left + 1`. By adding this size in every iteration, we count all possible valid subarrays.

2.  **The Main `subarraysWithKDistinct` Function**
    ```cpp
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
    ```
    **Logic:** It calculates the number of subarrays with at most `k` distinct elements and subtracts the number of subarrays with at most `k-1` distinct elements.
    <br>
    **Why:** The set of subarrays with `at most k-1` distinct elements is a perfect subset of the subarrays with `at most k` distinct elements. Subtracting the smaller set from the larger set leaves you with only the subarrays that have **exactly k** distinct elements.
    

---

## Complexity Analysis
* **Time Complexity:** $O(N)$ - The `atMostK` helper function is $O(N)$, and we call it twice. $O(N) + O(N)$ is still $O(N)$.
* **Space Complexity:** $O(K)$ - The map will store at most `K` (or `K+1`) distinct elements at any time.

---

## Key Learnings / Pitfalls
* This problem introduces the powerful **"at most" technique**, which is a crucial pattern for converting "exactly K" counting problems into a solvable sliding window format.
* The logic for counting within the `atMostK` helper (`count += right - left + 1`) is a key pattern for these types of problems.
* Recognizing when a simple sliding window won't work for counting is as important as knowing the pattern itself.
