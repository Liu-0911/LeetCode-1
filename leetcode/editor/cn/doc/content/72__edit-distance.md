<p>给你两个单词&nbsp;<code>word1</code> 和&nbsp;<code>word2</code>， <em>请返回将&nbsp;<code>word1</code>&nbsp;转换成&nbsp;<code>word2</code> 所使用的最少操作数</em> &nbsp;。</p>

<p>你可以对一个单词进行如下三种操作：</p>

<ul>
	<li>插入一个字符</li>
	<li>删除一个字符</li>
	<li>替换一个字符</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1：</strong></p>

<pre>
<strong>输入：</strong>word1 = "horse", word2 = "ros"
<strong>输出：</strong>3
<strong>解释：</strong>
horse -&gt; rorse (将 'h' 替换为 'r')
rorse -&gt; rose (删除 'r')
rose -&gt; ros (删除 'e')
</pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre>
<strong>输入：</strong>word1 = "intention", word2 = "execution"
<strong>输出：</strong>5
<strong>解释：</strong>
intention -&gt; inention (删除 't')
inention -&gt; enention (将 'i' 替换为 'e')
enention -&gt; exention (将 'n' 替换为 'x')
exention -&gt; exection (将 'n' 替换为 'c')
exection -&gt; execution (插入 'u')
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= word1.length, word2.length &lt;= 500</code></li>
	<li><code>word1</code> 和 <code>word2</code> 由小写英文字母组成</li>
</ul>
<details><summary><strong>Related Topics</strong></summary>字符串 | 动态规划</details><br>

<div>👍 2562, 👎 0</div>

<div id="labuladong"><hr>

**通知：[数据结构精品课 V1.8](https://aep.h5.xeknow.com/s/1XJHEO) 持续更新中。**



<p><strong><a href="https://labuladong.github.io/article?qno=72" target="_blank">⭐️labuladong 题解</a></strong></p>
<details><summary><strong>labuladong 思路</strong></summary>

## 基本思路

> 本文有视频版：[编辑距离详解动态规划](https://www.bilibili.com/video/BV1uv411W73P)

PS：这道题在[《算法小抄》](https://mp.weixin.qq.com/s/tUSovvogbR9StkPWb75fUw) 的第 123 页。

解决两个字符串的动态规划问题，一般都是用两个指针 `i, j` 分别指向两个字符串的最后，然后一步步往前走，缩小问题的规模。

对于每对儿字符 `s1[i]` 和 `s2[j]`，可以有四种操作：

```python
if s1[i] == s2[j]:
    啥都别做（skip）
    i, j 同时向前移动
else:
    三选一：
        插入（insert）
        删除（delete）
        替换（replace）
```

那么「状态」就是指针 `i, j` 的位置，「选择」就是上述的四种操作。

如果使用自底向上的迭代解法，这样定义 `dp` 数组：`dp[i-1][j-1]` 存储 `s1[0..i]` 和 `s2[0..j]` 的最小编辑距离。`dp` 数组索引至少是 0，所以索引会偏移一位。

然后把上述四种选择用 `dp` 函数表示出来，就可以得出最后答案了。

**详细题解：[经典动态规划：编辑距离](https://labuladong.github.io/article/fname.html?fname=编辑距离)**

**标签：[二维动态规划](https://mp.weixin.qq.com/mp/appmsgalbum?__biz=MzAxODQxMDM0Mw==&action=getalbum&album_id=2122017695998050308)，[动态规划](https://mp.weixin.qq.com/mp/appmsgalbum?__biz=MzAxODQxMDM0Mw==&action=getalbum&album_id=1318881141113536512)**

## 解法代码

```java
class Solution {
    public int minDistance(String s1, String s2) {
        int m = s1.length(), n = s2.length();
        int[][] dp = new int[m + 1][n + 1];
        // base case
        for (int i = 1; i <= m; i++)
            dp[i][0] = i;
        for (int j = 1; j <= n; j++)
            dp[0][j] = j;
        // 自底向上求解
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (s1.charAt(i - 1) == s2.charAt(j - 1))
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(
                        dp[i - 1][j] + 1,/**<extend up -300>

![](https://labuladong.github.io/algo/images/editDistance/delete.gif)
*/
                        dp[i][j - 1] + 1,/**<extend up -300>

![](https://labuladong.github.io/algo/images/editDistance/insert.gif)
*/
                        dp[i - 1][j - 1] + 1/**<extend up -300>

![](https://labuladong.github.io/algo/images/editDistance/replace.gif)
*/
                    );
        // 储存着整个 s1 和 s2 的最小编辑距离
        return dp[m][n];
    }

    int min(int a, int b, int c) {
        return Math.min(a, Math.min(b, c));
    }
}
```

</details>
</div>



