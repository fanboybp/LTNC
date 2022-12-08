#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define M  10

struct LinkedList
{
    int data;
    struct LinkedList *next;
};
typedef struct LinkedList *node;  
node CreateNode(int value)
{
    node temp; 
    temp = (node)malloc(sizeof(struct LinkedList));  
    temp ->next = NULL;  
    temp->data = value;  
    return temp;  
}
node Bucket[M];
int Hashfunc(int key)
{
    return (key % M);
}
void InitBucket( )
{
    for(int b = 0; b< M; b++)
        Bucket[b] = NULL;
}
int isEmptyBucket(int b)
{
    return (Bucket[b]  == NULL? TRUE : FALSE);
}
void Insert(int k)
{
    int b = Hashfunc(k);
    node p,q=NULL;
    for(p = Bucket[b]; p!=NULL && k > p->data; p = p->next)
    q = p;
    if(q == NULL)
    {
        node temp = CreateNode(k);
        temp->next = Bucket[b];
        Bucket[b] = temp;
    }
    else
    if(p == NULL)
    {
        node temp = CreateNode(k);
        q->next = temp;
    }
    else
        {
            node temp = CreateNode(k);
            temp->next = q->next;
            q->next = temp;
        }
    return ;
}
void Remove (int k)
{
    int b = Hashfunc(k);
    node  p = Bucket[b], q = Bucket[b];
    for(p = Bucket[b]; p != NULL && p->data !=k; p = p->next)
        q = p;
    if( p == NULL )
        printf("\nkhong co nut khoa %d", k);
    else if( p == Bucket[b] ) 
    {
        Bucket[b] = p->next;
        free(p); 
    }
    else  
        {
            q->next = p->next;
            free(p);
        }
}
void ClearBucket (int b)
{
    node p = Bucket[b], q = NULL;
    while(p != NULL)
    {
        q = p;
        p = p->next;
        free(q);
    }
    Bucket[b] = NULL;
}
void Clear ( )
{
    for(int b=0; b<M; b++)
        ClearBucket(b);
}
void TraverseBucket(int b)
{
    node p = Bucket[b];
    while( p !=NULL)
    {
        printf("%8d", p->data);
         p = p->next;
    }
}
void Traverse( )
{
    for(int b = 0; b< M; b++)
    {
        printf("\nBucket %d:",b);
        TraverseBucket(b);
    }
}
int Search(int k)
{
    int b = Hashfunc(k);
    node p = Bucket[b];
    while (k > p->data && p != NULL)
        p = p->next;
    if( p == NULL || k!=p->data)
        return -1;
    else
        return 1;
}
void main( )
{
    int b, key, i, n, chucnang;
    char c;
    InitBucket( ); 
    do
    {
        printf("\n-----------------------------\n");
        printf(" Cac chuc nang cua chuong trinh: \n");
        printf("--------------------------------\n");
        printf("1: Them mot nut vao bang bam \n");
        printf("2: Xoa nut trong bang bam \n");
        printf("3: Xoa toan bo bang bam \n");
        printf("4: Duyet bang bam \n");
        printf("5: Tim kiem tren bang bam \n");
        printf("0: Ket thuc chuong trinh \n");
        printf("\n Chuc nang ban chon : ");  scanf("%d", &chucnang);
    switch (chucnang)
    {
    case 1:
        {
            printf("\nTHEM MOT NUT VAO BANG BAM");
            printf("\nKhoa cua nut moi : "); scanf("%d", &key);
            Insert(key);
            break;
        }
    case 2:
        {
            printf("\nXOA TREN BANG BAM");
            printf("\nKhoa cua can xoa : "); scanf("%d", &key);
            Remove(key);
            break;
        }
    case 3:
        {
            printf("\nXOA TOAN BO BANG BAM");
            printf("\nBan co chac chan khong (c/k) : "); 
            c = getch();
            if( c== 'c' || c== 'C')
                Clear();
            break;
        }
    case 4:
        {
            printf("\nDUYET BANG BAM");
            Traverse ( );
            break;
        }
    case 5:
        {
            printf("\nTIM KIEM TREN BANG BAM");
            printf("\nKhoa can tim : "); scanf("%d", &key);
            
            if(Search(key)== -1)
                printf(" Khong thay");
            else
                printf(" Tim thay trong Bucket %d", Hashfunc(key));
            break;
        }
    }
    } while (chucnang !=0);
return ;
    
}