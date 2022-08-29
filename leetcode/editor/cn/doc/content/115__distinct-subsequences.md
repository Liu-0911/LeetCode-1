<p>给定一个字符串 <code>s</code><strong> </strong>和一个字符串 <code>t</code> ，计算在 <code>s</code> 的子序列中 <code>t</code> 出现的个数。</p>

<p>字符串的一个 <strong>子序列</strong> 是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，<code>"ACE"</code> 是 <code>"ABCDE"</code> 的一个子序列，而 <code>"AEC"</code> 不是）</p>

<p>题目数据保证答案符合 32 位带符号整数范围。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "rabbbit", t = "rabbit"<code>
<strong>输出</strong></code><strong>：</strong><code>3
</code><strong>解释：</strong>
如下图所示, 有 3 种可以从 s 中得到 <code>"rabbit" 的方案</code>。
<code><strong><u>rabb</u></strong>b<strong><u>it</u></strong></code>
<code><strong><u>ra</u></strong>b<strong><u>bbit</u></strong></code>
<code><strong><u>rab</u></strong>b<strong><u>bit</u></strong></code></pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "babgbag", t = "bag"
<code><strong>输出</strong></code><strong>：</strong><code>5
</code><strong>解释：</strong>
如下图所示, 有 5 种可以从 s 中得到 <code>"bag" 的方案</code>。 
<code><strong><u>ba</u></strong>b<u><strong>g</strong></u>bag</code>
<code><strong><u>ba</u></strong>bgba<strong><u>g</u></strong></code>
<code><u><strong>b</strong></u>abgb<strong><u>ag</u></strong></code>
<code>ba<u><strong>b</strong></u>gb<u><strong>ag</strong></u></code>
<code>babg<strong><u>bag</u></strong></code>
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 <= s.length, t.length <= 1000</code></li>
	<li><code>s</code> 和 <code>t</code> 由英文字母组成</li>
</ul>
<details><summary><strong>Related Topics</strong></summary>字符串 | 动态规划</details><br>

<div>👍 856, 👎 0</div>

<div id="labuladong"><hr>

**通知：[数据结构精品课 V1.8](https://aep.h5.xeknow.com/s/1XJHEO) 持续更新中。**



<p><strong><a href="https://labuladong.github.io/article?qno=115" target="_blank">⭐️labuladong 题解</a></strong></p>
<details><summary><strong>labuladong 思路</strong></summary>

## 基本思路

关于动态规划的解题步骤和思维方法见前文 [动态规划核心套路](https://labuladong.github.io/article/fname.html?fname=动态规划详解进阶) 和 [动态规划答疑篇](https://labuladong.github.io/article/fname.html?fname=最优子结构)，这里就不赘述了，直接给出最关键的状态转移方程。

前文 [我的刷题心得](技术/算法心得.md) 说了，算法的本质就是穷举，首先你得知道如何用暴力穷举得出正确答案，才能写出状态转移方程。

**针对这道题，可以有两种视角的穷举思路**。

第一种视角，站在 `t` 的视角：

我们的原问题是求 `s[0..]` 中不同子序列 `t[0..]`，可以先看 `t[0]` 在 `s` 中的什么位置，假设 `s[2], s[6]` 是字符 `t[0]`，那么原问题转化成了在 `s[2..]` 和 `s[6..]` 中寻找不同子序列 `t[1..]`。

这就是状态转移关系，我直接翻译成代码：

```java
// 站在 t 视角的暴力解，超时，就算加备忘录效率也比较低
class Solution1 {
    public int numDistinct(String s, String t) {
        return dp(s, 0, t, 0);
    }

    // 定义：返回 s[i..] 中包含子序列 t[j..] 的数量
    int dp(String s, int i, String t, int j) {
        if (j == t.length()) {
            // 子序列全部匹配完成
            return 1;
        }
        if (i == s.length()) {
            return 0;
        }
        int res = 0;
        // 在 s[i..] 中寻找匹配 t[j] 的那个索引 k
        for (int k = i; k < s.length(); k++) {
            if (s.charAt(k) == t.charAt(j)) {
                // 然后去 s[k+1..] 中寻找子序列 t[j+1..]
                res += dp(s, k + 1, t, j + 1);
            }
        }
        return res;
    }
}
```

这个解法当然超时，因为没有用 `memo` 备忘录消除重叠子问题。但就算你加上备忘录优化之后，算法依然可能超时，因为我们的递归函数 `dp` 中包含一个 for 循环。

带备忘录的动态规划算法的时间复杂度 = 子问题的个数 x 函数本身的时间复杂度 = O(MN) * O(M)，`M, N` 分别代表 `s, t` 的长度。

下面尝试用第二种视角进行穷举，即站在 `s` 的视角：

我们的原问题是求 `s[0..]` 中不同子序列 `t[0..]`，可以先看看 `s[0]` 是否能匹配 `t[0]`，如果不可以，那没得说，原问题就转化为让 `s[1..]` 去匹配 `t[0..]`；

但如果 `s[0]` 可以匹配 `t[0]`，那么又有两种情况，这两种情况是累加的关系：

1、让 `s[0]` 匹配 `t[0]`，那么原问题转化为让 `s[1..]` 去匹配 `t[1..]`。

2、不让 `s[0]` 匹配 `t[0]`，那么原问题转化为让 `s[1..]` 去匹配 `t[0..]`。

比如 `s = "aab", t = "ab"`，就有两种匹配方式：`a_b` 和 `_ab`。

按照这个思路，状态转移方程就是：

```java
// 站在 s 视角的状态转移方程
int dp(s, i, t, j) {
    if (s[i] == t[j]) {
        return dp(s, i+1, t, j+1) + dp(s, i+1, t, j);
    } else {
        return dp(s, i+1, t, j);
    }
}
```

然后，就能翻译成代码，处理一下 base case，加个备忘录，具体代码我写在下面。如果你愿意，也可以改写成自底向上的迭代解法。

这个解法函数本身没有循环，递归次数（子问题个数）经过优化之后就是 O(MN)，所以总的时间复杂度就是 O(MN)。

**详细题解：[动态规划问题的两种穷举视角](https://labuladong.github.io/article/fname.html?fname=动归两种视角)**

**标签：[动态规划](https://mp.weixin.qq.com/mp/appmsgalbum?__biz=MzAxODQxMDM0Mw==&action=getalbum&album_id=1318881141113536512)**

## 解法代码

```java
class Solution {
    public int numDistinct(String s, String t) {
        memo = new int[s.length()][t.length()];
        for (int[] row : memo) {
            Arrays.fill(row, -1);
        }
        return dp(s, 0, t, 0);
    }

    int[][] memo;

    // 定义：该函数返回 s[i..] 中的子序列 t[j..] 的数量
    int dp(String s, int i, String t, int j) {
        int m = s.length(), n = t.length();
        if (j == n) {
            // 子序列全部匹配完成
            return 1;
        }
        if (n - j > m - i) {
            // 待匹配子序列的长度不应该比字符串的长度还要短
            return 0;
        }
        if (memo[i][j] != -1) {
            // 已经计算过对应状态
            return memo[i][j];
        }
        int res = 0;
        // 状态转移方程
        if (s.charAt(i) == t.charAt(j)) {
            res += dp(s, i + 1, t, j + 1) + dp(s, i + 1, t, j);
        } else {
            res += dp(s, i + 1, t, j);
        }
        memo[i][j] = res;
        return res;
    }
}
```

**类似题目**：
  - [剑指 Offer II 097. 子序列的数目 🔴](/problems/21dk04)

</details>
</div>



