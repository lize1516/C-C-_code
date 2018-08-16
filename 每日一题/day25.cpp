 //1.求最短路径的长度
 
 int Depth(TreeNode* head)
    {
        if(head->left==NULL&&head->right==NULL)
            return 1;
        if(head->left==NULL)
            return Depth(head->right)+1;
        if(head->right==NULL)
            return Depth(head->left)+1;
        int left=Depth(head->left);
        int right=Depth(head->right);
        
        return left<right?left+1:right+1;
    }
    int run(TreeNode *root) {
        if(root==NULL)
            return 0;
        if(root->left==NULL&&root->right==NULL)
            return 1;
       return Depth(root);
    }

//
//2.根据中序遍历与后序遍历重建二叉树
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    TreeNode *buildTree(vector<int> &inorder, int iLeft, int iRight, vector<int> &postorder, int pLeft, int pRight) {
        if (iLeft > iRight || pLeft > pRight) return NULL;
        TreeNode *cur = new TreeNode(postorder[pRight]);
        int i = 0;
        for (i = iLeft; i < inorder.size(); ++i) {
            if (inorder[i] == cur->val) break;
        }
        cur->left = buildTree(inorder, iLeft, i - 1, postorder, pLeft, pLeft + i - iLeft - 1);
        cur->right = buildTree(inorder, i + 1, iRight, postorder, pLeft + i - iLeft, pRight - 1);
        return cur;
    }
