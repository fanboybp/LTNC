#include<stdio.h>
#include<stdlib.h>
//Khởi tạo liên kết đơn
struct linkedlist
{
    int data;
    struct linkedlist *next;
};
typedef struct linkedlist *node;
//Hàm khởi tạo một node mới và gán giá trị cho nó
node createnode(int value)
{
    node temp;
    temp = (node)malloc(sizeof(struct linkedlist));
    temp -> next = NULL;
    temp -> data = value;
    return temp;
}
//Thêm một phần tử vào cuối QUEUE
node enQueue(node head,int value)
{
  node temp, p;
  temp = createnode(value);
  if(head==NULL)
    {
        head = temp;
    }
    else
        {
             p=head;
             while(p -> next != NULL){
             p = p -> next;
        }
    p -> next = temp;
  }
  return head;
}
//Xoá một phần tử ở đỉnh ra khỏi QUEUE
node delQueue(node head)
{
    if(head==NULL)
    {
        printf("\nCha co gi de xoa het!");
    }
        else
            {
                head=head -> next;
            }
    return head;
}
// Tạo hàm lấy giá trị của node đầu tiên
int peekHeadQueue(node head)
{
    return head -> data;
}
//Tạo hàm lấy giá trị của node cuối cùng
int peekTailQueue(node head)
{
    node p;
    p = head;
    while(p -> next != NULL) p = p -> next;
    return p -> data;
}
//Khởi tạo QUEUE
node initQueue()
{
    node head;
    head = NULL;
    return head;
}

int main()
{
    int a[100], n=0, num=0, k, i=0, sum;
    float tbd[100];
    FILE *input, *output;
    if((input=fopen("input.txt","r"))==NULL)
    {
        printf("Loi! Khong mo duoc file");
        exit(1);
    }

    while(fscanf(input,"%d",&num)!=EOF)
    {
        a[n] = num;
        printf("%8d",num);
        n++;
    }
    //khởi tạo QUEUE
    node head = initQueue();
    output = fopen("output.txt", "w");
    printf("\nNhap bac tinh trung binh dong k=");    
        scanf("%d", &k);
        //Thêm các phân tử vào hàng đợi
    for(i=0; i<k; i++)
    {
        sum += a[i];
        head = enQueue(head, a[i]);
    }
    printf("Day trung binh dong k = %d\n", k);
    fprintf(output,"Day trung binh dong k = %d\n", k);
    for(i=k; i<=n; i++)
    {
        tbd[i-k] = (float)sum/k;
        sum = sum - peekHeadQueue(head);
        head = delQueue(head);
        head = enQueue(head,a[i]);
        sum += peekTailQueue(head);
        printf("%10.2f ",tbd[i-k]);
        fprintf(output,"%10.2f ",tbd[i-k]);
    }
    printf("\ndone!");
    fclose(input);
    fclose(output);
    return 0;
}