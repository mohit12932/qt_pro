//
// Created by 91901 on 29-08-2024.
//
#include "TreeNode.h"
#include "Layout.h"
#include <iostream>
#include <ostream>
#include <queue>


TreeNode::TreeNode(int x) : value(x), left(NULL), right(NULL){};

void TreeNode::display(){

    int row = treeHeight(this);
    int column = treeWidth(this)-1;
    char *mad[1] = {};

    window= new mainWindow(800, 800, 0, mad, "Binary Tree");


    Layout *layout=new Layout(window,row,column);
//    Line *line = new Line(window->getParentWindow(),123,222,345,456);
//    line->resize(500,500);
    setCoordinates(layout,this, 0,0,column-1);

    window->displayWindow();
}



int TreeNode::treeHeight(TreeNode* root) {
    if (root == nullptr) return 0;
    return 1 + std::max(treeHeight(root->left), treeHeight(root->right));
}

int TreeNode::treeWidth(TreeNode *root){
    if(root==nullptr)
        return 1;

    return treeWidth(root->left)+ treeWidth(root->right);
}

void TreeNode::setCoordinates(Layout *layout,TreeNode* node, int depth, int low,int high) {
    if (node == nullptr)
        return;

    if (node->left!= nullptr){
//        int y1 = layout->getCellCenter(depth,(low+high)/2)->first;
//        int y2 = layout->getCellCenter(depth+1,(low+((low+high)/2))/2)->first;
//        int x1 = layout->getCellCenter(depth,(low+high)/2)->second;
//        int x2 = layout->getCellCenter(depth+1,((low+(low+high)/2))/2)->second;
        layout->addLine(depth,(low+high)/2,depth+1,(low+((low+high)/2))/2);

//        Line * line = new Line(window->getParentWindow(),x1,y1,x2,y2);
    }
    if (node->right!= nullptr){
//            int y1 = layout->getCellCenter(depth,(low+high)/2)->first;
//            int y2 = layout->getCellCenter(depth+1,(((low+high)/2)+1+high)/2)->first;
//            int x1 = layout->getCellCenter(depth,(low+high)/2)->second;
//            int x2 = layout->getCellCenter(depth+1,(((low+high)/2)+1+high)/2)->second;
            layout->addLine(depth,(low+high)/2,depth+1,(((low+high)/2)+1+high)/2);
//        Line * line = new Line(window->getParentWindow(),x1,y1,x2,y2);
    }
    layout->addNode(node->value,depth,(low+high)/2);

    std::cout<<(low+(low+high)/2)/2<<" "<<depth+1<<" "<<layout->getCellCenter((low+(low+high)/2)/2,depth+1)->first<<" ";
    setCoordinates(layout,node->left, depth + 1, low,((low+high)/2));

    setCoordinates(layout,node->right, depth + 1, ((low+high)/2)+1,high);
}