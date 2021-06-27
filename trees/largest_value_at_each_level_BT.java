//User function Template for Java
/*
Tree node structure  used in the program
class Node {
    int data;
    Node left;
    Node right;
    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}
*/

class Solution {
    ArrayList<Integer> maximumValue(Node root) {
       if(root == null){
           return null;
       }
       ArrayList <Integer> ans = new ArrayList <Integer> ();
       Queue <Node> Q = new LinkedList <> ();
       Q.add(root);
       Node temp;
       
       while(Q.size() != 0){
           int size = Q.size();
           int maxEle = Integer.MIN_VALUE;
           
           while(size>0){
               temp = Q.remove();
               
               if(temp.left != null){
                   Q.add(temp.left);
               }
               if(temp.right != null){
                   Q.add(temp.right);
               }
               size--;
               
               if(maxEle < temp.data){
                   maxEle = temp.data;
               }
           }
           ans.add(maxEle);
       }
       return(ans);
    }
}

