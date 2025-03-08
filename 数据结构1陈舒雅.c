#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define TRUE 1
#define FALSE 0
#define ERROR -1
typedef int ElemType;
typedef int Status;

// 定义顺序表结构
typedef struct {
    ElemType data[MAXSIZE];
    int length;
} SqList;

// 初始化表
Status InitList(SqList* L) {
    L->length = 0;
    return TRUE;
}

// 销毁表
Status DestroyList(SqList* L) {
    free(L);
    return TRUE;
}

// 清空表
Status ClearList(SqList* L) {
    L->length = 0;
    return TRUE;
}

// 判定空表
Status ListEmpty(SqList L) {
    return L.length == 0 ? TRUE : FALSE;
}

// 求表长
int ListLength(SqList L) {
    return L.length;
}

// 获得元素
Status GetElem(SqList L, int i, ElemType* e) {
    if (i < 1 || i > L.length) {
        return ERROR;
    }
    *e = L.data[i - 1];
    return TRUE;
}

// 查找元素
int LocateElem(SqList L, ElemType e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) {
            return i + 1;
        }
    }
    return ERROR;
}

// 获得前驱
Status PriorElem(SqList L, ElemType cur, ElemType* pre_e) {
    int pos = LocateElem(L, cur);
    if (pos == ERROR || pos == 1) {
        return ERROR;
    }
    *pre_e = L.data[pos - 2];
    return TRUE;
}

// 获得后继
Status NextElem(SqList L, ElemType cur, ElemType* next_e) {
    int pos = LocateElem(L, cur);
    if (pos == ERROR || pos == L.length) {
        return ERROR;
    }
    *next_e = L.data[pos];
    return TRUE;
}

// 插入元素
Status ListInsert(SqList* L, int i, ElemType e) {
    if (i < 1 || i > L->length + 1) {
        return ERROR;
    }
    if (L->length >= MAXSIZE) {
        return ERROR;
    }
    for (int j = L->length; j >= i; j--) {
        L->data[j] = L->data[j - 1];
    }
    L->data[i - 1] = e;
    L->length++;
    return TRUE;
}

// 删除元素
Status ListDelete(SqList* L, int i, ElemType* e) {
    if (i < 1 || i > L->length) {
        return ERROR;
    }
    *e = L->data[i - 1];
    for (int j = i; j < L->length; j++) {
        L->data[j - 1] = L->data[j];
    }
    L->length--;
    return TRUE;
}

// 遍历表
Status ListTraverse(SqList L) {
    printf("-all elements\n");
    for (int i = 0; i < L.length; i++) {
        printf("%d", L.data[i]);
    }
    printf("\nend\n");
    return TRUE;
}

// 写入文件
Status Write(SqList L) {
    char filename[50];
    printf("input file name: ");
    scanf("%s", filename);
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        return ERROR;
    }
    for (int i = 0; i < L.length; i++) {
        fprintf(fp, "%d ", L.data[i]);
    }
    fclose(fp);
    printf("写入成功!\n");
    return TRUE;
}

// 读取文件
Status Read(SqList* L) {
    char filename[50];
    printf("input file name: ");
    scanf("%s", filename);
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return ERROR;
    }
    int i = 0;
    while (fscanf(fp, "%d", &L->data[i]) != EOF && i < MAXSIZE) {
        i++;
    }
    L->length = i;
    fclose(fp);
    printf("读取成功!\n");
    return TRUE;
}

int main11() {
    SqList* lists[100];
    for (int i = 0; i < 100; i++) {
        lists[i] = NULL;
    }
    int choice, listNum, pos, elem;
    ElemType e;
    while (1) {
        printf("请输入对哪个线性表进行操作(1-99),输入0退出!\n");
        scanf("%d", &listNum);
        if (listNum == 0) {
            break;
        }
        if (listNum < 1 || listNum > 99) {
            printf("输入的线性表序号无效，请重新输入！\n");
            continue;
        }
        if (lists[listNum - 1] == NULL) {
            lists[listNum - 1] = (SqList*)malloc(sizeof(SqList));
            if (lists[listNum - 1] == NULL) {
                printf("内存分配失败！\n");
                return ERROR;
            }
        }
        while (1) {
            printf("Menu for Linear Table On Sequence Structure\n");
            printf("1. InitList\n");
            printf("2. DestroyList\n");
            printf("3. ClearList\n");
            printf("4. ListEmpty\n");
            printf("5. ListLength\n");
            printf("6. GetElem\n");
            printf("7. LocateElem\n");
            printf("8. PriorElem\n");
            printf("9. NextElem\n");
            printf("10. ListInsert\n");
            printf("11. ListDelete\n");
            printf("12. ListTraverse\n");
            printf("13. Write\n");
            printf("14. Read\n");
            printf("0. Exit\n");
            printf("请选择你的操作[0~14]:\n");
            scanf("%d", &choice);
            switch (choice) {
            case 0:
                goto outer;
            case 1:
                if (InitList(lists[listNum - 1])) {
                    printf("线性表创建成功!\n");
                }
                else {
                    printf("线性表创建失败!\n");
                }
                break;
            case 2:
                if (DestroyList(lists[listNum - 1])) {
                    printf("线性表销毁成功!\n");
                    free(lists[listNum - 1]);
                    lists[listNum - 1] = NULL;
                }
                else {
                    printf("线性表销毁失败!\n");
                }
                break;
            case 3:
                if (ClearList(lists[listNum - 1])) {
                    printf("清空线性表!\n");
                }
                else {
                    printf("清空失败!\n");
                }
                break;
            case 4:
                if (ListEmpty(*lists[listNum - 1])) {
                    printf("线性表为空!\n");
                }
                else {
                    printf("线性表不为空!\n");
                }
                break;
            case 5:
                printf("线性表的长度为%d!\n", ListLength(*lists[listNum - 1]));
                break;
            case 6:
                printf("请输入想要获得元素的位置: ");
                scanf("%d", &pos);
                if (GetElem(*lists[listNum - 1], pos, &e) == TRUE) {
                    printf("第%d个元素为%d!\n", pos, e);
                }
                else {
                    printf("位置无效!\n");
                }
                break;
            case 7:
                printf("请输入需要查找的元素: ");
                scanf("%d", &elem);
                pos = LocateElem(*lists[listNum - 1], elem);
                if (pos != ERROR) {
                    printf("第%d个元素与该元素相同\n", pos);
                }
                else {
                    printf("没有找到该元素!\n");
                }
                break;
            case 8:
                printf("请输入需要获得其前驱的元素: ");
                scanf("%d", &elem);
                if (PriorElem(*lists[listNum - 1], elem, &e) == TRUE) {
                    printf("该元素的前驱为%d\n", e);
                }
                else {
                    printf("操作失败!\n");
                }
                break;
            case 9:
                printf("请输入需要获得其后继的元素: ");
                scanf("%d", &elem);
                if (NextElem(*lists[listNum - 1], elem, &e) == TRUE) {
                    printf("该元素的后继为%d\n", e);
                }
                else {
                    printf("操作失败!\n");
                }
                break;
            case 10:
                printf("请依次输入:在第_个位置之前插入元素 ");
                scanf("%d %d", &pos, &elem);
                if (ListInsert(lists[listNum - 1], pos, elem) == TRUE) {
                    printf("插入成功!\n");
                }
                else {
                    printf("插入失败!\n");
                }
                break;
            case 11:
                printf("请依次输入:删除第_个位置的元素 ");
                scanf("%d", &pos);
                if (ListDelete(lists[listNum - 1], pos, &e) == TRUE) {
                    printf("删除成功!\n");
                }
                else {
                    printf("删除失败!\n");
                }
                break;
            case 12:
                if (ListTraverse(*lists[listNum - 1]) == ERROR) {
                    printf("遍历失败!\n");
                }
                break;
            case 13:
                if (Write(*lists[listNum - 1]) == ERROR) {
                    printf("写入失败!\n");
                }
                break;
            case 14:
                if (Read(lists[listNum - 1]) == ERROR) {
                    printf("读取失败!\n");
                }
                break;
            default:
                printf("无效的选择，请重新输入！\n");
            }
        }
    }
outer:
    printf("欢迎下次再使用本系统!\n");
    return 0;
}