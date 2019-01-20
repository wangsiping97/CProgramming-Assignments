// 描述
// 编写一个“一元稀疏多项式加法器”，输入两个一元稀疏多项式，然后对它们进行加法操作。
// 在具体实现上，要求用线性链表的形式来存储一个多项式，
// 每个链表结点包括两个成员变量，即int类型的系数coef和int类型的指数exp，
// 例如：对于两个多项式A(x) = 75 + 30*x + 95*x^8 + 50*x^9，B(x) = 80*x + 25*x^7 - 90*x^8。

// (75,0)->(30,1)->(95,8)->(50,9)->NULL
// (80,1)->(25,7)->(-90,8)->NULL
// 说明：
// （1）为了减少内存空间的浪费，必须采用动态链表的方法，即每一个链表结点都是根据需要动态创建的；
// （2）为了增强程序的可读性，应采用多函数的形式来实现，至少应包含如下的函数：创建链表、加法函数、打印链表等；
// （3）多项式的系数可正可负，而指数肯定是非负整数。

// 输入
// 第一行是一个整数M，表示第一个多项式的项数，
// 接下来有M行，每一行是两个整数ci和ei，其中，ci表示第i项的系数，ei表示第i项的指数。
// 接下来的一行是一个整数N，表示第二个多项式的项数，
// 再接下来有N行，每一行也是两个整数，表示相应项的系数和指数。

// 输出
// 输出两个多项式相加的结果。
// 第一行是一个整数K，表示在新生成的多项式中有多少项，接下来有K行，每一行是两个整数，表示相应项的系数和指数。

// 输入样例
// 4
// 75 0
// 30 1
// 95 8
// 50 9
// 3
// 80 1
// 25 7
// -90 8
// 输出样例
// 5
// 75 0
// 110 1
// 25 7
// 5 8
// 50 9
// 知识点
// 结构体、指针、链表、函数调用

// 编程模式
// 链表创建、链表访问

// 难度系数
// 5

#include<stdio.h>
#include<stdlib.h>

typedef struct polynomial *list;
typedef list position;

struct polynomial{
    int coef;
    int exp;
    position next;
};

list CreatePolymonial(int M)
{
    struct polynomial *head;
    position p;
    p = head = NULL;
    for(int i = 0; i < M; i++){
        if(p == NULL){
            head = p = malloc(sizeof(struct polynomial));
        }
        else{
            p->next = malloc(sizeof(struct polynomial));
            p = p->next;
        }
        scanf("%d %d", &p->coef, &p->exp);
        p->next = NULL;
    }
    return head;
}

void AddNode(position p) // add a node q as the next of p
{
    position q = malloc(sizeof(struct polynomial));
    q->next = p->next;
    p->next = q;
}

void DeleteZeroNode(list L)
{
    position p = L, q = L;
    int i = 0;
    while(p){
        if(p->coef == 0){
            for(int j = 0; j < i - 1; j++){
                q = q->next;
            }
            q->next = p->next;
            i--;
        }
        p = p->next;
        q = L;
        i++;
    }
    L->coef = i - 1;
}

list AddPolynomial(int ma, list A, int mb, list B)
{
    list C;
    position p = C;
    p = C = malloc(sizeof(struct polynomial));
    p->next = NULL; 
    position q = A, r = B;
    int mc = 0;
    while(q && r){
        if(q->exp < r->exp){
            AddNode(p);
            mc++;
            p = p->next;
            p->coef = q->coef;
            p->exp = q->exp;
            q = q->next;
        }
        if(q->exp > r->exp){
            AddNode(p);
            mc++;
            p = p->next;
            p->coef = r->coef;
            p->exp = r->exp;
            r = r->next;
        }
        if(q->exp == r->exp){
            AddNode(p);
            mc++;
            p = p->next;
            p->coef = q->coef + r->coef;
            p->exp = q->exp;
            q = q->next;
            r = r->next;
        }
    }
    while(q){
        AddNode(p);
        mc++;
        p = p->next;
        p->coef = q->coef;
        p->exp = q->exp;
        q = q->next;
    }
    while(r){
        AddNode(p);
        mc++;
        p = p->next;
        p->coef = r->coef;
        p->exp = r->exp;
        r = r->next;
    }
    p->next = NULL;
    C->coef = mc;
    DeleteZeroNode(C);
    return C;
}

void Retrive(list C)
{
    printf("%d\n", C->coef);
    position p = C;
    p = p->next;
    while(p){
        printf("%d %d\n", p->coef, p->exp);
        p = p->next;
    }
}

int main()
{
    int ma, mb;
    scanf("%d", &ma);
    list A = CreatePolymonial(ma);
    scanf("%d", &mb);
    list B = CreatePolymonial(mb);
    list C = AddPolynomial(ma, A, mb, B);
    Retrive(C);
    return 0;
}