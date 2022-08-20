<p>给你二叉树的根节点 <code>root</code> ，返回它节点值的 <strong>前序</strong><em> </em>遍历。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg" style="width: 202px; height: 324px;" />
<pre>
<strong>输入：</strong>root = [1,null,2,3]
<strong>输出：</strong>[1,2,3]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>root = []
<strong>输出：</strong>[]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>root = [1]
<strong>输出：</strong>[1]
</pre>

<p><strong>示例 4：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/15/inorder_5.jpg" style="width: 202px; height: 202px;" />
<pre>
<strong>输入：</strong>root = [1,2]
<strong>输出：</strong>[1,2]
</pre>

<p><strong>示例 5：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/15/inorder_4.jpg" style="width: 202px; height: 202px;" />
<pre>
<strong>输入：</strong>root = [1,null,2]
<strong>输出：</strong>[1,2]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数目在范围 <code>[0, 100]</code> 内</li>
	<li><code>-100 <= Node.val <= 100</code></li>
</ul>

<p> </p>

<p><strong>进阶：</strong>递归算法很简单，你可以通过迭代算法完成吗？</p>
<details><summary><strong>Related Topics</strong></summary>栈 | 树 | 深度优先搜索 | 二叉树</details><br>

<div>👍 868, 👎 0</div>

<div id="labuladong"><hr>

**通知：[数据结构精品课 V1.7](https://aep.h5.xeknow.com/s/1XJHEO) 持续更新中；B 站可查看 [核心算法框架系列视频](https://space.bilibili.com/14089380/channel/series)。**



<p><strong><a href="https://labuladong.github.io/article?qno=144" target="_blank">⭐️labuladong 题解</a></strong></p>
<details><summary><strong>labuladong 思路</strong></summary>

## 基本思路

> 本文有视频版：[二叉树/递归的框架思维（纲领篇）](https://www.bilibili.com/video/BV1nG411x77H)

不要瞧不起二叉树的前中后序遍历。

前文 [手把手刷二叉树总结篇](https://labuladong.github.io/article/fname.html?fname=二叉树总结) 说过二叉树的递归分为「遍历」和「分解问题」两种思维模式，分别代表回溯算法和动态规划的底层思想。

本题用两种思维模式来解答，注意体会其中思维方式的差异。

**详细题解：[东哥带你刷二叉树（纲领篇）](https://labuladong.github.io/article/fname.html?fname=二叉树总结)**

**标签：[二叉树](https://mp.weixin.qq.com/mp/appmsgalbum?__biz=MzAxODQxMDM0Mw==&action=getalbum&album_id=2121994699837177859)**

## 解法代码

```java
class Solution {
    /* 动态规划思路 */
    // 定义：输入一个节点，返回以该节点为根的二叉树的前序遍历结果
    public List<Integer> preorderTraversal(TreeNode root) {
        LinkedList<Integer> res = new LinkedList<>();
        if (root == null) {
            return res;
        }
        // 前序遍历结果特点：第一个是根节点的值，接着是左子树，最后是右子树
        res.add(root.val);
        res.addAll(preorderTraversal(root.left));
        res.addAll(preorderTraversal(root.right));
        return res;
    }

    /* 回溯算法思路 */
    LinkedList<Integer> res = new LinkedList<>();

    // 返回前序遍历结果
    public List<Integer> preorderTraversal2(TreeNode root) {
        traverse(root);
        return res;
    }

    // 二叉树遍历函数
    void traverse(TreeNode root) {
        if (root == null) {
            return;
        }
        // 前序遍历位置
        res.add(root.val);
        traverse(root.left);
        traverse(root.right);
    }
}
```

**类似题目**：
  - [104. 二叉树的最大深度 🟢](/problems/maximum-depth-of-binary-tree)
  - [543. 二叉树的直径 🟢](/problems/diameter-of-binary-tree)
  - [剑指 Offer 55 - I. 二叉树的深度 🟢](/problems/er-cha-shu-de-shen-du-lcof)

</details>
</div>



