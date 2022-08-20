<p>一个机器人位于一个<meta charset="UTF-8" />&nbsp;<code>m x n</code>&nbsp;网格的左上角 （起始点在下图中标记为 “Start” ）。</p>

<p>机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。</p>

<p>现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？</p>

<p>网格中的障碍物和空位置分别用 <code>1</code> 和 <code>0</code> 来表示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/04/robot1.jpg" />
<pre>
<strong>输入：</strong>obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
<strong>输出：</strong>2
<strong>解释：</strong>3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 <code>2</code> 条不同的路径：
1. 向右 -&gt; 向右 -&gt; 向下 -&gt; 向下
2. 向下 -&gt; 向下 -&gt; 向右 -&gt; 向右
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/04/robot2.jpg" />
<pre>
<strong>输入：</strong>obstacleGrid = [[0,1],[0,0]]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m ==&nbsp;obstacleGrid.length</code></li>
	<li><code>n ==&nbsp;obstacleGrid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>obstacleGrid[i][j]</code> 为 <code>0</code> 或 <code>1</code></li>
</ul>
<details><summary><strong>Related Topics</strong></summary>数组 | 动态规划 | 矩阵</details><br>

<div>👍 858, 👎 0</div>

<div id="labuladong"><hr>

**通知：[数据结构精品课 V1.8](https://aep.h5.xeknow.com/s/1XJHEO) 持续更新中；第十期刷题打卡挑战 [开始报名](https://mp.weixin.qq.com/s/eUG2OOzY3k_ZTz-CFvtv5Q)。**

<details><summary><strong>labuladong 思路</strong></summary>

## 基本思路

动态规划问题层层优化的通用步骤：

1、根据 [动态规划核心套路](https://labuladong.github.io/article/fname.html?fname=动态规划详解进阶)，思考如何分解问题（状态转移方程），明确函数定义，写出暴力递归解；然后用 `memo` 备忘录消除重叠子问题，并根据 [这篇文章](https://labuladong.github.io/article/fname.html?fname=备忘录等基础) 确定 base case 的初始值。

2、（可选）根据 [动态规划核心套路](https://labuladong.github.io/article/fname.html?fname=动态规划详解进阶) 将自顶向下的递归解法改为自底向上的迭代解法，根据 [这篇文章](https://labuladong.github.io/article/fname.html?fname=最优子结构) 确定 `dp` 数组的迭代方向。

3、（可选）根据 [这篇文章](https://labuladong.github.io/article/fname.html?fname=状态压缩技巧) 尝试对多维 `dp` 数组进行降维打击，优化空间复杂度。

这道题分解问题规模的关键是：

到达 `(i, j)` 的路径条数等于到达 `(i-1, j)` 和到达 `(i, j-1)` 的路径条数之和。

那么 `dp` 函数的定义就是：

从 `grid[0][0]` 出发到达 `grid[i][j]` 的路径条数为 `dp(grid, i, j)`。

然后走流程，一步步优化，我把所有步骤都写在解法代码中了。

**标签：[动态规划](https://mp.weixin.qq.com/mp/appmsgalbum?__biz=MzAxODQxMDM0Mw==&action=getalbum&album_id=1318881141113536512)**

## 解法代码

```java
// 第一步：自顶向下带备忘录的递归
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        memo = new int[m][n];
        return dp(obstacleGrid, m - 1, n - 1);
    }

    // 备忘录
    int[][] memo;

    // 定义：从 grid[0][0] 出发到达 grid[i][j] 的路径条数为 dp(grid, i, j)
    int dp(int[][] grid, int i, int j) {
        int m = grid.length, n = grid[0].length;
        // base case
        if (i < 0 || i >= m || j < 0 || j >= n
                || grid[i][j] == 1) {
            // 数组越界或者遇到阻碍
            return 0;
        }
        if (i == 0 && j == 0) {
            // 起点到起点的路径条数就是 1
            return 1;
        }
        if (memo[i][j] > 0) {
            // 避免冗余计算
            return memo[i][j];
        }
        // 状态转移方程：
        // 到达 grid[i][j] 的路径条数等于
        // 到达 grid[i-1][j] 的路径条数加上到达 grid[i][j-1] 的路径条数
        int left = dp(grid, i, j - 1);
        int upper = dp(grid, i - 1, j);
        int res = left + upper;
        // 存储备忘录
        memo[i][j] = res;
        return res;
    }
}

// 第二步：自底向上迭代的动态规划
class Solution2 {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        // 数组索引偏移一位，dp[0][..] dp[..][0] 代表 obstacleGrid 之外
        // 定义：到达 obstacleGrid[i][j] 的路径条数为 dp[i-1][j-1]
        int[][] dp = new int[m + 1][n + 1];
        // base case：如果没有障碍物，起点到起点的路径条数就是 1
        dp[1][1] = obstacleGrid[0][0] == 1 ? 0 : 1;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 1 && j == 1) {
                    // 跳过 base case
                    continue;
                }
                if (obstacleGrid[i - 1][j - 1] == 1) {
                    // 跳过障碍物的格子
                    continue;
                }
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        // 返回到达 obstacleGrid[m-1][n-1] 的路径数量
        return dp[m][n];
    }
}

// 第三步：优化二维 dp 数组为一维 dp 数组
class Solution3 {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        // 根据二维 dp 数组优化为一维 dp 数组
        int[] dp = new int[n + 1];
        dp[1] = obstacleGrid[0][0] == 1 ? 0 : 1;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 1 && j == 1) {
                    // 跳过 base case
                    continue;
                }
                if (obstacleGrid[i - 1][j - 1] == 1) {
                    // 跳过障碍物的格子
                    dp[j] = 0;
                    continue;
                }
                dp[j] = dp[j] + dp[j - 1];
            }
        }
        // 返回到达 obstacleGrid[m-1][n-1] 的路径数量
        return dp[n];
    }
}
```

</details>
</div>





