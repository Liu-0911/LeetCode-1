<p>给你一个字符串 <code>s</code> ，找出其中最长的回文子序列，并返回该序列的长度。</p>

<p>子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "bbbab"
<strong>输出：</strong>4
<strong>解释：</strong>一个可能的最长回文子序列为 "bbbb" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "cbbd"
<strong>输出：</strong>2
<strong>解释：</strong>一个可能的最长回文子序列为 "bb" 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= s.length <= 1000</code></li>
	<li><code>s</code> 仅由小写英文字母组成</li>
</ul>
<details><summary><strong>Related Topics</strong></summary>字符串 | 动态规划</details><br>

<div>👍 875, 👎 0</div>

<div id="labuladong"><hr>

**通知：[数据结构精品课 V1.8](https://aep.h5.xeknow.com/s/1XJHEO) 持续更新中。**



<p><strong><a href="https://labuladong.github.io/article?qno=516" target="_blank">⭐️labuladong 题解</a></strong></p>
<details><summary><strong>labuladong 思路</strong></summary>

## 基本思路

PS：这道题在[《算法小抄》](https://mp.weixin.qq.com/s/tUSovvogbR9StkPWb75fUw) 的第 136 页。

`dp` 数组的定义是：**在子串 `s[i..j]` 中，最长回文子序列的长度为 `dp[i][j]`**。

状态转移方程：

```java
if (s[i] == s[j])
    // 它俩一定在最长回文子序列中
    dp[i][j] = dp[i + 1][j - 1] + 2;
else
    // s[i+1..j] 和 s[i..j-1] 谁的回文子序列更长？
    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
```

![](https://labuladong.github.io/algo/images/最长回文子序列/3.jpg)

**详细题解：[动态规划之子序列问题解题模板](https://labuladong.github.io/article/fname.html?fname=子序列问题模板)**

**标签：回文问题，字符串**

## 解法代码

```java
class Solution {
    public int longestPalindromeSubseq(String s) {
        int n = s.length();
        // dp 数组全部初始化为 0
        int[][] dp = new int[n][n];
        // base case
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        // 反着遍历保证正确的状态转移
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                // 状态转移方程
                if (s.charAt(i) == s.charAt(j)) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = Math.max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        // 整个 s 的最长回文子串长度
        return dp[0][n - 1];
    }
}
```

**类似题目**：
  - [1312. 让字符串成为回文串的最少插入次数 🔴](/problems/minimum-insertion-steps-to-make-a-string-palindrome)

</details>
</div>



