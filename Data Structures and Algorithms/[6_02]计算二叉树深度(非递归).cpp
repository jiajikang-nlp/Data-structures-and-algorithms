/*
 * @Author: jjk
 * @Date: 2019-08-14 10:58:38
 * @Last Modified by: jjk
 * @Last Modified time: 2019-08-14 11:06:14
 */
#include <iostream>
#include <deque>
using namespace std;

typedef struct node
{
    char data;
    struct node *lchild;
    struct node *rchild;
} BiNode, *BiTree;

// 先序建立二叉树 （输入时，按先序次序输入二叉树中结点的值,以 # 字符表示空树）
BiTree createBiTree()
{
    BiTree T;

    char c;
    scanf("%c", &c);

    if (c == '#')
        T = NULL;
    else
    {
        T = new BiNode; // 或 T = (BiTree)malloc(sizeof(BiNode));
        T->data = c;

        T->lchild = createBiTree();
        T->rchild = createBiTree();
    }

    return T;
}

// 二叉树的深度（递归）
int treeDepth(BiTree T)
{
    if (T == NULL)
        return 0;

    int depLeft = treeDepth(T->lchild);
    int depRight = treeDepth(T->rchild);

    return (depLeft > depRight) ? (depLeft + 1) : (depRight + 1);
}


// 二叉树的深度（非递归）
int treeDepth2(BiTree T)
{
    if (T == NULL)
        return 0;

    deque<BiTree> q; // 定义一个BiTree类型变量q
    q.push_back(T);// 在尾部插入一个数据

    int curLevelNum;  // 当前层的节点数
    int curLevel = 0; // 层数

    while (q.size()) /*返回容器中实际数据的个数*/
    {
      curLevelNum = (int)q.size(); // 此处要做类型转换，因为size()返回值为size_type类型；
      while (curLevelNum-- > 0) // 一直访问到当前层的最后一个节点
      {
          BiTree tmp = q.front(); // 返回容器que的第一个元素的引用。如果que为空，则该操作为空。

          q.pop_front(); //  删除头部数据

          if (tmp->lchild)
              q.push_back(tmp->lchild); //  在尾部插入一个数据
          if (tmp->rchild)
              q.push_back(tmp->rchild); //  在尾部插入一个数据
      }
      curLevel++;
    }

    return curLevel;
}

int main(int argc, const char *argv[])
{

    BiTree T = createBiTree(); // 建立

    // 递归
    //    int depth = treeDepth(T);
    //    printf("树的深度为 = %d\n", depth);

    // 非递归
    int depth2 = treeDepth2(T);
    printf("树的深度为 = %d\n", depth2);

    return 0;
}