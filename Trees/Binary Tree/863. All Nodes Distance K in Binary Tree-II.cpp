
class Solution
{
private:
  int findAncestorsOfTarget(TreeNode *root, TreeNode *target, int k, int depth)
  {
    if (root == null)
      return 0;

    if (root == target)
      return 1;
    /*        10  ==> 3
           1 ==> 2
        2  => 1
     5

    */

    int lh = findAncestorsOfTarget(root->left, target, k, depth);
    int rh = findAncestorsOfTarget(root->right, target, k, depth);

    if (lh > 0)
    {
      if (lh == k)
        nodes.push_back(root->val);
      else
        findChildrenofTarget(root.right, target, k, k - lh);
    }

    if (rh > 0)
    {
      if (rh == k)
        nodes.push_back(root->val);
      else
        findChildrenofTarget(root.right, target, k, k - rh);
    }

    if (lh != 0)
      depth = lh;

    lh = (lh == 0) ? 0 : lh;

    // lh == k
  }

  void findChildrenofTarget(TreeNode *root, int depth, int k, vector<int> &nodes)
  {
    if (root == null)
      return;

    if (depth == k)
      nodes.push_back(root->val);

    findChildrenofTarget(root->left);
    findChildrenofTarget(root->right);
  }

public:
  vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
  {
    vector<int> nodes;

    findChildrenofTarget(target, 0, k, nodes);
    findAncestorsOfTarget(root, target, k, 0)
        dfs(root, target, k)

            return nodes;
  }
};
