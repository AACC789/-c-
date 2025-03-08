#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define TRUE 1
#define FALSE 0
#define ERROR -1
typedef int ElemType;
typedef int Status;

// ����˳���ṹ
typedef struct {
    ElemType data[MAXSIZE];
    int length;
} SqList;

// ��ʼ����
Status InitList(SqList* L) {
    L->length = 0;
    return TRUE;
}

// ���ٱ�
Status DestroyList(SqList* L) {
    free(L);
    return TRUE;
}

// ��ձ�
Status ClearList(SqList* L) {
    L->length = 0;
    return TRUE;
}

// �ж��ձ�
Status ListEmpty(SqList L) {
    return L.length == 0 ? TRUE : FALSE;
}

// ���
int ListLength(SqList L) {
    return L.length;
}

// ���Ԫ��
Status GetElem(SqList L, int i, ElemType* e) {
    if (i < 1 || i > L.length) {
        return ERROR;
    }
    *e = L.data[i - 1];
    return TRUE;
}

// ����Ԫ��
int LocateElem(SqList L, ElemType e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) {
            return i + 1;
        }
    }
    return ERROR;
}

// ���ǰ��
Status PriorElem(SqList L, ElemType cur, ElemType* pre_e) {
    int pos = LocateElem(L, cur);
    if (pos == ERROR || pos == 1) {
        return ERROR;
    }
    *pre_e = L.data[pos - 2];
    return TRUE;
}

// ��ú��
Status NextElem(SqList L, ElemType cur, ElemType* next_e) {
    int pos = LocateElem(L, cur);
    if (pos == ERROR || pos == L.length) {
        return ERROR;
    }
    *next_e = L.data[pos];
    return TRUE;
}

// ����Ԫ��
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

// ɾ��Ԫ��
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

// ������
Status ListTraverse(SqList L) {
    printf("-all elements\n");
    for (int i = 0; i < L.length; i++) {
        printf("%d", L.data[i]);
    }
    printf("\nend\n");
    return TRUE;
}

// д���ļ�
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
    printf("д��ɹ�!\n");
    return TRUE;
}

// ��ȡ�ļ�
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
    printf("��ȡ�ɹ�!\n");
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
        printf("��������ĸ����Ա���в���(1-99),����0�˳�!\n");
        scanf("%d", &listNum);
        if (listNum == 0) {
            break;
        }
        if (listNum < 1 || listNum > 99) {
            printf("��������Ա������Ч�����������룡\n");
            continue;
        }
        if (lists[listNum - 1] == NULL) {
            lists[listNum - 1] = (SqList*)malloc(sizeof(SqList));
            if (lists[listNum - 1] == NULL) {
                printf("�ڴ����ʧ�ܣ�\n");
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
            printf("��ѡ����Ĳ���[0~14]:\n");
            scanf("%d", &choice);
            switch (choice) {
            case 0:
                goto outer;
            case 1:
                if (InitList(lists[listNum - 1])) {
                    printf("���Ա����ɹ�!\n");
                }
                else {
                    printf("���Ա���ʧ��!\n");
                }
                break;
            case 2:
                if (DestroyList(lists[listNum - 1])) {
                    printf("���Ա����ٳɹ�!\n");
                    free(lists[listNum - 1]);
                    lists[listNum - 1] = NULL;
                }
                else {
                    printf("���Ա�����ʧ��!\n");
                }
                break;
            case 3:
                if (ClearList(lists[listNum - 1])) {
                    printf("������Ա�!\n");
                }
                else {
                    printf("���ʧ��!\n");
                }
                break;
            case 4:
                if (ListEmpty(*lists[listNum - 1])) {
                    printf("���Ա�Ϊ��!\n");
                }
                else {
                    printf("���Ա�Ϊ��!\n");
                }
                break;
            case 5:
                printf("���Ա�ĳ���Ϊ%d!\n", ListLength(*lists[listNum - 1]));
                break;
            case 6:
                printf("��������Ҫ���Ԫ�ص�λ��: ");
                scanf("%d", &pos);
                if (GetElem(*lists[listNum - 1], pos, &e) == TRUE) {
                    printf("��%d��Ԫ��Ϊ%d!\n", pos, e);
                }
                else {
                    printf("λ����Ч!\n");
                }
                break;
            case 7:
                printf("��������Ҫ���ҵ�Ԫ��: ");
                scanf("%d", &elem);
                pos = LocateElem(*lists[listNum - 1], elem);
                if (pos != ERROR) {
                    printf("��%d��Ԫ�����Ԫ����ͬ\n", pos);
                }
                else {
                    printf("û���ҵ���Ԫ��!\n");
                }
                break;
            case 8:
                printf("��������Ҫ�����ǰ����Ԫ��: ");
                scanf("%d", &elem);
                if (PriorElem(*lists[listNum - 1], elem, &e) == TRUE) {
                    printf("��Ԫ�ص�ǰ��Ϊ%d\n", e);
                }
                else {
                    printf("����ʧ��!\n");
                }
                break;
            case 9:
                printf("��������Ҫ������̵�Ԫ��: ");
                scanf("%d", &elem);
                if (NextElem(*lists[listNum - 1], elem, &e) == TRUE) {
                    printf("��Ԫ�صĺ��Ϊ%d\n", e);
                }
                else {
                    printf("����ʧ��!\n");
                }
                break;
            case 10:
                printf("����������:�ڵ�_��λ��֮ǰ����Ԫ�� ");
                scanf("%d %d", &pos, &elem);
                if (ListInsert(lists[listNum - 1], pos, elem) == TRUE) {
                    printf("����ɹ�!\n");
                }
                else {
                    printf("����ʧ��!\n");
                }
                break;
            case 11:
                printf("����������:ɾ����_��λ�õ�Ԫ�� ");
                scanf("%d", &pos);
                if (ListDelete(lists[listNum - 1], pos, &e) == TRUE) {
                    printf("ɾ���ɹ�!\n");
                }
                else {
                    printf("ɾ��ʧ��!\n");
                }
                break;
            case 12:
                if (ListTraverse(*lists[listNum - 1]) == ERROR) {
                    printf("����ʧ��!\n");
                }
                break;
            case 13:
                if (Write(*lists[listNum - 1]) == ERROR) {
                    printf("д��ʧ��!\n");
                }
                break;
            case 14:
                if (Read(lists[listNum - 1]) == ERROR) {
                    printf("��ȡʧ��!\n");
                }
                break;
            default:
                printf("��Ч��ѡ�����������룡\n");
            }
        }
    }
outer:
    printf("��ӭ�´���ʹ�ñ�ϵͳ!\n");
    return 0;
}