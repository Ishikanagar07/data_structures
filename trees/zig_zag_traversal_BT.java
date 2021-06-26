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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        Stack <TreeNode> ms = new Stack <> ();
        ms.push(root);
        Stack <TreeNode> cs = new Stack <> ();
        int level = 1;
        TreeNode temp;
        ArrayList <Integer> ans = new ArrayList <Integer> ();
        
        
        while(ms.size() > 0){
            temp = ms.pop();
            ans.add(temp.val);
            
            if(level%2 == 1){
                if(temp.left != null){
                    cs.push(temp.left);
                }
                if(temp.right != null){
                    cs.push(temp.right);
                }
            }
            else {
                if(temp.right != null){
                    cs.push(temp.right);
                }
                if(temp.left != null){
                    cs.push(temp.left);
                }
            }
            
            if(ms.size() == 0){
                ms = cs;
                cs = new Stack <> ();
                level ++;
            }
        }
        return ans;
    }
}
