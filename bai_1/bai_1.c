#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
struct linkerlist
{
    int data;
    struct linkerlist *pnext;
};
typedef struct linkerlist *node;

char input[] = "solieu.txt";
char output[] = "ketqua.txt";

node inistack()
{
    node stack;
    stack = NULL;
    return stack;
}

node cratenode(int value)
{
    node head = (node)malloc(sizeof(struct linkerlist));
    head->data = value;
    head->pnext = NULL;
    return head;
}

node Push(node head, int value)
{
    node p = cratenode(value);
    if(head == NULL)
    {
        head = p;
    }
    else
    {
        p->pnext = head;
        head = p;
    }
    return head;
}

node Pop(node head)
{
    if(head == NULL)
    {
        printf("stack rong!");
    }
    else
    {
        head = head->pnext;
    }
    return head;
}

int isemptystack(node head)
{
    if(head == NULL)
    return 1;
    else
    return 0;
}
int peekstack(node head)
{
    return head->data;
}

void getstack(node head)
{
    for(node p = head; p != NULL; p = p->pnext)
    {
        printf("%8d",p->data);
    }
}

void chuyendoicoso2(node head)
{
    int a[100],n;
            FILE *Fin,*Fout;
            if((Fin = fopen(input,"r")) == NULL || (Fout = fopen(output,"wa")) == NULL)
            {
                printf("Loi! Khong mo duoc file");
                exit(1);
            }
            n = 0;
    node p = inistack();
        n = head->data;
    while (n != 0)
    {
        p = Push(p , n % 2 );
        n = (int)n / 2;
    }
    while (!isemptystack(p))
    {
            fprintf(Fout, "%d", peekstack(p));
            printf("%d",peekstack(p));
            p = Pop(p);
    } 
    fclose(Fin);
    fclose(Fout);
}

void chuyendoicoso16(node head)
{
    node p = inistack();
    int n;
        n = head->data;
    while (n != 0)
    {
        p = Push(p , n % 16);
        n = (int)n / 16;
    }
    while (!isemptystack(p))
    {
            int a = peekstack(p);
            p = Pop(p);
            printf("%c","0123456789ABCDEF"[a]);
    } 
}
int main()
{
    //ghi_file(node head);
    int chon;
    node head = inistack();
    while (69)
    {
        system("cls");
        printf("1.Push to stack\n");
        printf("2.Pop to stack\n");
        printf("3.Getstack\n");
        printf("4.Chuyen doi co so 2\n");
        printf("5.Chuyen doi co so 16\n");
        printf("6.Doc va ghi file\n");
        scanf("%d",&chon);
        if(chon == 1)
        {
            int n;
            printf("Nhap node : "); scanf("%d",&n);
            head = Push(head,n);
        }
        else if (chon == 2)
        {
            head = Pop(head);
            system("pause");
        }
        else if (chon == 3)
        {
            getstack(head);
            printf("\n");
            system("pause");
        }
        else if (chon == 4)
        {
            chuyendoicoso2(head);
            printf("\n");
            system("pause");
        }
         else if (chon == 5)
        {
            chuyendoicoso16(head);
            printf("\n");
            system("pause");
        }
           else if (chon == 6)
        {
            int a[100],n;
            FILE *Fin,*Fout;
            if((Fin = fopen(input,"r")) == NULL || (Fout = fopen(output,"w")) == NULL)
            {
                printf("Loi! Khong mo duoc file");
                exit(1);
            }
            int num=0;
            n = 0;
            while (fscanf(Fin,"%d",&num) != EOF)
            {
                printf("%8d",num);
                a[n] = num;
                n++;
            }
            for(int i = 0; i < n; i++)
            {
                head = Push(head,a[i]);
            }
            printf("\n");
            system("pause");
        }
    }
    
}