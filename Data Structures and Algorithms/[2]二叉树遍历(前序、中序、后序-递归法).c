/*
 * @Author: jjk 
 * @Date: 2019-08-12 11:23:53 
 * @Last Modified by: jjk
 * @Last Modified time: 2019-08-12 13:57:02
 * 程序功能：遍历二叉树(递归思想：前序，中序，后序)
 * coding:gbk
 * 输入方式：AB#C##D##
 * 说明：没有节点的以‘#’代替
 */

#include <stdio.h>
#include <stdlib.h>

typedef char TypeDate; /*定义数据类型*/
/*二叉树结构*/
typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *parent;
} TreeNode; // 结构体变量

/*初始化二叉树*/
TreeNode *createBiTree(){

    char chTempdata = 0;
    TreeNode *pstNexNode = NULL;
    scanf("%c",&chTempdata); // 输入数据
    if (chTempdata == '#')
    {
        /* code */
        pstNexNode = NULL;
    }else
    {
        /*内存分配*/
        pstNexNode = (TreeNode*)malloc(sizeof(TreeNode)+1);
        pstNexNode ->data = chTempdata;
        /*d递归调用产生二叉树*/
        pstNexNode->left = createBiTree();
        pstNexNode->right = createBiTree();

    }
    return pstNexNode;
}

/*前序遍历*/
void pre_order(TreeNode *Node){
    
    if (Node == NULL)
    {
        return;
        /* code */
    }
    /*先遍历根节点*/
    printf("%c\t",Node->data); 
    /*遍历左子树*/
    pre_order(Node->left);
    /*遍历右子树*/
    pre_order(Node->right);
}

/*中序遍历*/
void in_order(TreeNode *Node){

    if (Node == NULL)
    {
        /* code */
        return;
    }
    /*先遍历左子树*/
    in_order(Node->left);
    /*遍历根节点*/
    printf("%c\t",Node->data);
    /*遍历右子树*/
    in_order(Node->right);
}

/*后序遍历*/
void post_order(TreeNode *Node){

    if (Node == NULL)
    {
        /* code */
        return;
    }
    /*先遍历左子树*/
    post_order(Node->left);
    /*遍历右子树*/
    post_order(Node->right);
    /*遍历根节点*/
    printf("%c\t",Node->data);
    
}



/*主函数*/
int main(int argc, char *argv[]) {

  printf("test......\n");
  TreeNode *pstROOT; //二叉树结构体指针变化
  /*构造一个二叉树*/
  pstROOT = createBiTree();
  /*前序遍历*/
  printf("前序遍历：");
  pre_order(pstROOT);

  /*中序遍历*/
  printf("\n中序遍历：");
  in_order(pstROOT);

  /*后序遍历*/
  printf("\n后序遍历：");
  post_order(pstROOT);


  return 0;
}