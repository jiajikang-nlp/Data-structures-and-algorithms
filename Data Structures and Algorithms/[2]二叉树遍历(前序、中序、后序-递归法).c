/*
 * @Author: jjk 
 * @Date: 2019-08-12 11:23:53 
 * @Last Modified by: jjk
 * @Last Modified time: 2019-08-12 13:57:02
 * �����ܣ�����������(�ݹ�˼�룺ǰ�����򣬺���)
 * coding:gbk
 * ���뷽ʽ��AB#C##D##
 * ˵����û�нڵ���ԡ�#������
 */

#include <stdio.h>
#include <stdlib.h>

typedef char TypeDate; /*������������*/
/*�������ṹ*/
typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *parent;
} TreeNode; // �ṹ�����

/*��ʼ��������*/
TreeNode *createBiTree(){

    char chTempdata = 0;
    TreeNode *pstNexNode = NULL;
    scanf("%c",&chTempdata); // ��������
    if (chTempdata == '#')
    {
        /* code */
        pstNexNode = NULL;
    }else
    {
        /*�ڴ����*/
        pstNexNode = (TreeNode*)malloc(sizeof(TreeNode)+1);
        pstNexNode ->data = chTempdata;
        /*d�ݹ���ò���������*/
        pstNexNode->left = createBiTree();
        pstNexNode->right = createBiTree();

    }
    return pstNexNode;
}

/*ǰ�����*/
void pre_order(TreeNode *Node){
    
    if (Node == NULL)
    {
        return;
        /* code */
    }
    /*�ȱ������ڵ�*/
    printf("%c\t",Node->data); 
    /*����������*/
    pre_order(Node->left);
    /*����������*/
    pre_order(Node->right);
}

/*�������*/
void in_order(TreeNode *Node){

    if (Node == NULL)
    {
        /* code */
        return;
    }
    /*�ȱ���������*/
    in_order(Node->left);
    /*�������ڵ�*/
    printf("%c\t",Node->data);
    /*����������*/
    in_order(Node->right);
}

/*�������*/
void post_order(TreeNode *Node){

    if (Node == NULL)
    {
        /* code */
        return;
    }
    /*�ȱ���������*/
    post_order(Node->left);
    /*����������*/
    post_order(Node->right);
    /*�������ڵ�*/
    printf("%c\t",Node->data);
    
}



/*������*/
int main(int argc, char *argv[]) {

  printf("test......\n");
  TreeNode *pstROOT; //�������ṹ��ָ��仯
  /*����һ��������*/
  pstROOT = createBiTree();
  /*ǰ�����*/
  printf("ǰ�������");
  pre_order(pstROOT);

  /*�������*/
  printf("\n���������");
  in_order(pstROOT);

  /*�������*/
  printf("\n���������");
  post_order(pstROOT);


  return 0;
}