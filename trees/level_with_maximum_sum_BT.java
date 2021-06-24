/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int maxLevelSum(TreeNode root) {
        if(root == null){
            return -1;
        }
        Queue <TreeNode> q = new LinkedList <TreeNode> ();
        q.add(root);
        int level = 1;
        int maxSum = Integer.MIN_VALUE;
        int smLevel = 1;
        
        while(true){
            int size = q.size();
            if(size == 0){
                break;
            }
            int sum = 0;
            while(size > 0){
                TreeNode temp = q.remove();
                if(temp.left != null){
                    q.add(temp.left);
                }
                if(temp.right != null){
                    q.add(temp.right);
                }
                size --;
                sum += temp.val;
            }
            
            if(sum > maxSum){
                maxSum = sum;
                smLevel = level;
            }
            level += 1;
        }
        return smLevel;
    }
}

//refer => Leetcode
