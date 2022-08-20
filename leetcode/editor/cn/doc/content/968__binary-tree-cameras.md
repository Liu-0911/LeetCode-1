<p>给定一个二叉树，我们在树的节点上安装摄像头。</p>

<p>节点上的每个摄影头都可以监视<strong>其父对象、自身及其直接子对象。</strong></p>

<p>计算监控树的所有节点所需的最小摄像头数量。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/29/bst_cameras_01.png" style="height: 163px; width: 138px;"></p>

<pre><strong>输入：</strong>[0,0,null,0,0]
<strong>输出：</strong>1
<strong>解释：</strong>如图所示，一台摄像头足以监控所有节点。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/29/bst_cameras_02.png" style="height: 312px; width: 139px;"></p>

<pre><strong>输入：</strong>[0,0,null,0,null,0,null,null,0]
<strong>输出：</strong>2
<strong>解释：</strong>需要至少两个摄像头来监视树的所有节点。 上图显示了摄像头放置的有效位置之一。
</pre>

<p><br>
<strong>提示：</strong></p>

<ol>
	<li>给定树的节点数的范围是&nbsp;<code>[1, 1000]</code>。</li>
	<li>每个节点的值都是 0。</li>
</ol>
<details><summary><strong>Related Topics</strong></summary>树 | 深度优先搜索 | 动态规划 | 二叉树</details><br>

<div>👍 455, 👎 0</div>

<div id="labuladong"><hr>

**通知：[数据结构精品课 V1.8](https://aep.h5.xeknow.com/s/1XJHEO) 持续更新中；第十期刷题打卡挑战 [开始报名](https://mp.weixin.qq.com/s/eUG2OOzY3k_ZTz-CFvtv5Q)。**

<details><summary><strong>labuladong 思路</strong></summary>

## 基本思路

前文 [手把手刷二叉树总结篇](https://labuladong.github.io/article/fname.html?fname=二叉树总结) 说过后序位置的特殊之处，后序位置可以接收到子树的信息，同时也可以通过函数参数接收到父节点传递的信息，这道题就可以比较完美地体现这一特点。

首先我们列举一下一个节点可能存在的几种状态：

该节点不在监控区域内，称为 uncover 状态；该节点在附近节点的监控范围内，称为 cover 状态；该节点自己装了摄像头，称为 set 状态。

如何保证安装的摄像头数量尽可能少呢？显然就是要尽可能分散，让每个摄像头物尽其用。

具体来说就是自底向上安装摄像头，在叶子节点的父节点上安装摄像头，然后每隔两层再安装（因为每个摄像头都可以管三层）。

那么一个节点在什么情况下需要被安装摄像头呢？显然是当这个节点的子节点处于 uncover 的状态的时候必须安装摄像头，以便覆盖子节点。

综上，我们需要利用后序位置自底向上遍历二叉树，同时要利用子节点的状态以及父节点的状态，判断当前节点是否需要安装摄像头。

解法中 `setCamera` 函数就负责按照最优方式给二叉树安装摄像头，同时返回节点的状态。

**标签：[二叉树](https://mp.weixin.qq.com/mp/appmsgalbum?__biz=MzAxODQxMDM0Mw==&action=getalbum&album_id=2121994699837177859)**

## 解法代码

```java
class Solution {
    public int minCameraCover(TreeNode root) {
        setCamera(root, false);
        return res;
    }

    int res = 0;

    // 定义：输入以 root 为根的二叉树，以最优策略在这棵二叉树上放置摄像头，
    // 然后返回 root 节点的情况：
    // 返回 -1 代表 root 为空，返回 0 代表 root 未被 cover，
    // 返回 1 代表 root 已经被 cover，返回 2 代表 root 上放置了摄像头。
    int setCamera(TreeNode root, boolean hasParent) {
        if (root == null) {
            return -1;
        }
        // 获取左右子节点的情况
        int left = setCamera(root.left, true);
        int right = setCamera(root.right, true);

        // 根据左右子节点的情况和父节点的情况判断当前节点应该做的事情
        if (left == -1 && right == -1) {
            // 当前节点是叶子节点
            if (hasParent) {
                // 有父节点的话，让父节点来 cover 自己
                return 0;
            }
            // 没有父节点的话，自己 set 一个摄像头
            res++;
            return 2;
        }

        if (left == 0 || right == 0) {
            // 左右子树存在没有被 cover 的
            // 必须在当前节点 set 一个摄像头
            res += 1;
            return 2;
        }

        if (left == 2 || right == 2) {
            // 左右子树只要有一个 set 了摄像头
            // 当前节点就已经是 cover 状态了
            return 1;
        }

        // 剩下 left == 1 && right == 1 的情况
        // 即当前节点的左右子节点都被 cover
        if (hasParent) {
            // 如果有父节点的话，可以等父节点 cover 自己
            return 0;
        } else {
            // 没有父节点，只能自己 set 一个摄像头
            res++;
            return 2;
        }
    }
}
```

</details>
</div>



