<p>给定一个二叉树</p>

<pre>
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}</pre>

<p>填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 <code>NULL</code>。</p>

<p>初始状态下，所有 next 指针都被设置为 <code>NULL</code>。</p>

<p> </p>

<p><strong>进阶：</strong></p>

<ul>
	<li>你只能使用常量级额外空间。</li>
	<li>使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。</li>
</ul>

<p> </p>

<p><strong>示例：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/02/15/117_sample.png" style="height: 218px; width: 640px;" /></p>

<pre>
<strong>输入</strong>：root = [1,2,3,4,5,null,7]
<strong>输出：</strong>[1,#,2,3,#,4,5,7,#]
<strong>解释：</strong>给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。序列化输出按层序遍历顺序（由 next 指针连接），'#' 表示每层的末尾。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中的节点数小于 <code>6000</code></li>
	<li><code>-100 <= node.val <= 100</code></li>
</ul>

<p> </p>

<ul>
</ul>
<details><summary><strong>Related Topics</strong></summary>树 | 深度优先搜索 | 广度优先搜索 | 链表 | 二叉树</details><br>

<div>👍 607, 👎 0</div>

<div id="labuladong"><hr>

**通知：[数据结构精品课 V1.7](https://aep.h5.xeknow.com/s/1XJHEO) 持续更新中；B 站可查看 [核心算法框架系列视频](https://space.bilibili.com/14089380/channel/series)。**

<details><summary><strong>labuladong 思路</strong></summary>

## 基本思路

前文 [我的算法学习经验](https://labuladong.github.io/article/fname.html?fname=算法心得) 说过二叉树的递归分为「遍历」和「分解问题」两种思维模式。

但这题和 [116. 填充每个节点的下一个右侧节点指针](/problems/populating-next-right-pointers-in-each-node) 还不一样，输入的不是完全二叉树，所以不好直接用递归。

这题用 [BFS 算法](https://labuladong.github.io/article/fname.html?fname=BFS框架) 进行层序遍历比较直观，在 for 循环，无非就是想办法遍历所有节点，然后把这个节点和相邻节点连起来罢了。

当然，还有效率更高的方式，就是直接操作指针，不过略有些难懂，暂时不写。

**标签：[BFS 算法](https://mp.weixin.qq.com/mp/appmsgalbum?__biz=MzAxODQxMDM0Mw==&action=getalbum&album_id=2122002916411604996)，[二叉树](https://mp.weixin.qq.com/mp/appmsgalbum?__biz=MzAxODQxMDM0Mw==&action=getalbum&album_id=2121994699837177859)**

## 解法代码

```java
class Solution {
    public Node connect(Node root) {
        if (root == null) {
            return null;
        }
        // 二叉树层序遍历框架
        Queue<Node> q = new LinkedList<>();
        q.offer(root);
        while (!q.isEmpty()) {
            int sz = q.size();
            // 遍历一层
            Node pre = null;
            for (int i = 0; i < sz; i++) {
                Node cur = q.poll();
                // 链接当前层所有节点的 next 指针
                if (pre != null) {
                    pre.next = cur;
                }
                pre = cur;
                // 将下一层节点装入队列
                if (cur.left != null) {
                    q.offer(cur.left);
                }
                if (cur.right != null) {
                    q.offer(cur.right);
                }
            }
        }
        return root;
    }
}
```

</details>
</div>



