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

// ������������ ������ʱ���������������������н���ֵ,�� # �ַ���ʾ������
BiTree createBiTree()
{
    BiTree T;

    char c;
    scanf("%c", &c);

    if (c == '#')
        T = NULL;
    else
    {
        T = new BiNode; // �� T = (BiTree)malloc(sizeof(BiNode));
        T->data = c;

        T->lchild = createBiTree();
        T->rchild = createBiTree();
    }

    return T;
}

// ����������ȣ��ݹ飩
int treeDepth(BiTree T)
{
    if (T == NULL)
        return 0;

    int depLeft = treeDepth(T->lchild);
    int depRight = treeDepth(T->rchild);

    return (depLeft > depRight) ? (depLeft + 1) : (depRight + 1);
}


// ����������ȣ��ǵݹ飩
int treeDepth2(BiTree T)
{
    if (T == NULL)
        return 0;

    deque<BiTree> q; // ����һ��BiTree���ͱ���q
    q.push_back(T);// ��β������һ������

    int curLevelNum;  // ��ǰ��Ľڵ���
    int curLevel = 0; // ����

    while (q.size()) /*����������ʵ�����ݵĸ���*/
    {
      curLevelNum = (int)q.size(); // �˴�Ҫ������ת������Ϊsize()����ֵΪsize_type���ͣ�
      while (curLevelNum-- > 0) // һֱ���ʵ���ǰ������һ���ڵ�
      {
          BiTree tmp = q.front(); // ��������que�ĵ�һ��Ԫ�ص����á����queΪ�գ���ò���Ϊ�ա�

          q.pop_front(); //  ɾ��ͷ������

          if (tmp->lchild)
              q.push_back(tmp->lchild); //  ��β������һ������
          if (tmp->rchild)
              q.push_back(tmp->rchild); //  ��β������һ������
      }
      curLevel++;
    }

    return curLevel;
}

int main(int argc, const char *argv[])
{

    BiTree T = createBiTree(); // ����

    // �ݹ�
    //    int depth = treeDepth(T);
    //    printf("�������Ϊ = %d\n", depth);

    // �ǵݹ�
    int depth2 = treeDepth2(T);
    printf("�������Ϊ = %d\n", depth2);

    return 0;
}