//
// Created by 1655664358@qq.com on 2019/5/31.
//
#include <stdio.h>

#define ERROR 0
#define OK 1
#define MAX_TREE_SIZE 100
typedef int TElemType;//结点的数据类型
typedef struct PTNode{ //结点结构
    TElemType data;//本身的数据
    int parent;//双亲位置
}PTNode;

typedef struct {  //树结构
    PTNode nodes[MAX_TREE_SIZE];//结点数组
    int r,n;//根结点和结点数量
}PTree;
int main()
{

    return 0;
}
