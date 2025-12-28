//
// Created by 91901 on 28-08-2024.
//

#ifndef TRY_TREENODE_H
#define TRY_TREENODE_H
class mainWindow;
class Layout;

class TreeNode{
public:
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x);

    void display();


private:
    mainWindow *window;
    int  treeHeight(TreeNode* root);
    int treeWidth(TreeNode *root);
    void setCoordinates(Layout *layout,TreeNode* node, int depth, int low,int high);
};

#endif //TRY_TREENODE_H
