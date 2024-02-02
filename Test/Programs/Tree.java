

class TreeNode {
    int data;
    TreeNode left, right;

    TreeNode(int data) {
        this.data = data;
        left = right = null;
    }
}

public class Tree {
    TreeNode root;

    Tree() {
        root = null;
    }

    void insert(int data) {
        root = insertRec(root, data);
    }

    TreeNode insertRec(TreeNode root, int data) {
        if(root == null) {
            root = new TreeNode(data);
            return root;
        }

        if(data < root.data) 
            root.left = insertRec(root.left, data);
        else if(data > root.data)
            root.right = insertRec(root.right, data);
        
        return root;
    }

    void inorderTraversal(TreeNode root) {
        if(root != null) {
            inorderTraversal(root.left);
            System.out.print(root.data + " ");
            inorderTraversal(root.right);
        }
    }

    void preorderTraversal(TreeNode root) {
        if(root != null) {
            System.out.print(root.data + " ");
            inorderTraversal(root.left);
            inorderTraversal(root.right);
        }
    }
    
    void postorderTraversal(TreeNode root) {
        if(root != null) {
            inorderTraversal(root.left);
            inorderTraversal(root.right);
            System.out.print(root.data + " ");
        }
    }

    boolean search(TreeNode root, int key) {
        if(root == null) return false;
        if(root.data == key) return true;
        if(root.data < key) return search(root.right, key);
        return search(root.left, key);
    }
    
    int height(TreeNode root) {
        if(root == null) {
            return 0;
        }
        int leftHeight = height(root.left);
        int rightHeight = height(root.right);
        return Math.max(leftHeight, rightHeight) + 1;
    }

    void levelOrderTraversal() {
        int h = height(root);
        for(int i=1; i<=h; i++) {
            printGivenLevel(root, i);
        }
    }

    void printGivenLevel(TreeNode root, int level) {
        if(root == null) return;
        if(level == 1) System.out.print(root.data + " ");
        else if(level > 1) {
            printGivenLevel(root.left, level-1);
            printGivenLevel(root.right, level-1);
        }
    }

    TreeNode delete(TreeNode root, int key) {
        if(root == null) return root;
        if(key < root.data) root.left = delete(root.left, key);
        else if(key > root.data) root.right = delete(root.right, key);
        else {
            if(root.left == null) return root.right;
            else if(root.right == null) return root.left;
            root.data = minValue(root.right);
            root.right = delete(root.right, root.data);
        }
        return root;
    }

    int minValue(TreeNode root) {
        int minV = root.data;
        while (root.left != null) {
            minV = root.left.data;
            root = root.left;
        }
        return minV;
    }

    void findMinAndMax() {
        TreeNode current = root;
        while(current.left != null) {
            current = current.left;
        }
        System.out.println("Minimum value in the tree: " + current.data);
        current = root;
        while(current.right != null) {
            current = current.right;
        }
        System.out.println("Maximum value in the tree: " + current.data);
    }

    public static void main(String[] args) {
        Tree tree = new Tree();
        tree.insert(50);
        tree.insert(30);
        tree.insert(20);
        tree.insert(40);
        tree.insert(70);
        tree.insert(60);
        tree.insert(80);

        System.out.println("Inorder traversal:");
        tree.inorderTraversal(tree.root);
        System.out.println("\nPreorder traversal:");
        tree.preorderTraversal(tree.root);
        System.out.println("\nPostorder traversal:");
        tree.postorderTraversal(tree.root);

        int key = 70;
        if (tree.search(tree.root, key))
            System.out.println("\nFound " + key + " in the tree");
        else
            System.out.println("\n" + key + " not found in the tree");

        System.out.println("Height of the tree: " + tree.height(tree.root));

        System.out.println("Level order traversal:");
        tree.levelOrderTraversal();

        key = 30;
        tree.root = tree.delete(tree.root, key);
        System.out.println("\nInorder traversal after deleting " + key + ":");
        tree.inorderTraversal(tree.root);

        System.out.println();
        tree.findMinAndMax();
    }
}