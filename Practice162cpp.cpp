// 163. Code: Construct Tree from Preorder and Inorder: For a given preorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. You just need to construct the tree and return the root.

/***********************************************************
    Following is the Binary Tree Node class structure

    template <typename T>
    class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

***********************************************************/

BinaryTreeNode<int> *helper(int *preorder, int *inorder, int preS, int preE, int inS, int inE)
{
    if (preS > preE)
    {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(preorder[preS]);

    int length = 0;
    for (int i = inS; inorder[i] != root->data; i++)
    {
        length++;
    }

    int lPreS = preS + 1;
    int lPreE = preS + length;
    int lInS = inS;
    int lInE = inS + length - 1;
    int rPreS = lPreE + 1;
    int rPreE = preE;
    int rInS = lInE + 2;
    int rInE = inE;

    BinaryTreeNode<int> *leftChild = helper(preorder, inorder, lPreS, lPreE, lInS, lInE);
    BinaryTreeNode<int> *rightChild = helper(preorder, inorder, rPreS, rPreE, rInS, rInE);

    root->left = leftChild;
    root->right = rightChild;

    return root;
}
BinaryTreeNode<int> *buildTree(int *preorder, int preLength, int *inorder, int inLength)
{
    return helper(preorder, inorder, 0, preLength - 1, 0, inLength - 1);
}