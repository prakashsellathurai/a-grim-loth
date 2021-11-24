class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        cur = root

        while cur:
            if not cur.left:
                res.append(cur.val)
                cur = cur.right
            else:
                pre = cur.left

                while pre and pre.right:
                    pre = pre.right
                pre.right = cur
                temp = cur
                cur = cur.left
                temp.left = None

        return res
