<p>一个机器人位于一个 <code>m x n</code><em> </em>网格的左上角 （起始点在下图中标记为 “Start” ）。</p>

<p>机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。</p>

<p>问总共有多少条不同的路径？</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img src="https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png" />
<pre>
<strong>输入：</strong>m = 3, n = 7
<strong>输出：</strong>28</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>m = 3, n = 2
<strong>输出：</strong>3
<strong>解释：</strong>
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右
3. 向下 -> 向右 -> 向下
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>m = 7, n = 3
<strong>输出：</strong>28
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>m = 3, n = 3
<strong>输出：</strong>6</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= m, n <= 100</code></li>
	<li>题目数据保证答案小于等于 <code>2 * 10<sup>9</sup></code></li>
</ul>
<details><summary><strong>Related Topics</strong></summary>数学 | 动态规划 | 组合数学</details><br>

<div>👍 1521, 👎 0</div>

<div id="labuladong"><hr>

**通知：[数据结构精品课 V1.8](https://aep.h5.xeknow.com/s/1XJHEO) 持续更新中。**

<details><summary><strong>labuladong 思路</strong></summary>

## 基本思路

如果你看过前文 [动态规划框架详解](https://labuladong.github.io/article/fname.html?fname=动态规划详解进阶)，就知道这道题是非常基本的动态规划问题。

对 `dp` 数组的定义和状态转移方程如下：

```java
public int uniquePaths(int m, int n) {
    return dp(m - 1, n - 1);
}

// 定义：从 (0, 0) 到 (x, y) 有 dp(x, y) 条路径
int dp(int x, int y) {
    if (x == 0 && y == 0) {
        return 1;
    }
    if (x < 0 || y < 0) {
        return 0;
    }
    // 状态转移方程：
    // 到达 (x, y) 的路径数等于到达 (x - 1, y) 和 (x, y - 1) 路径数之和
    return dp(x - 1, y) + dp(x, y - 1);
}
```

添加备忘录或者改写为自底向上的迭代解法即可降低上述暴力解法的时间复杂度。

**标签：[二维动态规划](https://mp.weixin.qq.com/mp/appmsgalbum?__biz=MzAxODQxMDM0Mw==&action=getalbum&album_id=2122017695998050308)，二维矩阵，[动态规划](https://mp.weixin.qq.com/mp/appmsgalbum?__biz=MzAxODQxMDM0Mw==&action=getalbum&album_id=1318881141113536512)**

## 解法代码

```java
class Solution {
    // 备忘录
    int[][] memo;

    public int uniquePaths(int m, int n) {
        memo = new int[m][n];
        return dp(m - 1, n - 1);
    }

    // 定义：从 (0, 0) 到 (x, y) 有 dp(x, y) 条路径
    int dp(int x, int y) {
        // base case
        if (x == 0 && y == 0) {
            return 1;
        }
        if (x < 0 || y < 0) {
            return 0;
        }
        // 避免冗余计算
        if (memo[x][y] > 0) {
            return memo[x][y];
        }
        // 状态转移方程：
        // 到达 (x, y) 的路径数等于到达 (x - 1, y) 和 (x, y - 1) 路径数之和
        memo[x][y] = dp(x - 1, y) + dp(x, y - 1);
        return memo[x][y];
    }
}
```

**类似题目**：
  - [剑指 Offer II 098. 路径的数目 🟠](/problems/2AoeFn)

</details>
</div>





