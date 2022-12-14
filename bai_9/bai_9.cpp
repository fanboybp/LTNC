#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


char input[100];

struct Linkerlist
{
    char data;
    struct Linkerlist  *next;
};

typedef struct Linkerlist *node;

// Khoi tao mot node moi va gan gia tri cho no
//------------------------------------------------------------------------------------------------//
node newNode(char value)
{
    node temp;// bien temp theo kieu node
    temp = (node)malloc(sizeof(struct Linkerlist));// cap phat vung nho dung malloc()
    temp->next = NULL;// ch next tro toi null
    temp->data = value;// gan gia tri cho node
    return temp;// tra ve gia tri da duoc gan
}

// them mot node vao dau danh sach
//------------------------------------------------------------------------------------------------//
node Push(node head, char value)
{
    node temp,p = head;// bien temp theo kieu node
    temp = newNode(value);// khoi tao temp voi data = value
    if(head == NULL)
    {
        head = temp;// neu node dang trong thi node se = head
    }
    else
    {
       while(p->next != NULL)
       {
        p = p->next;
       }
        p->next = temp;
    }
    return head;// tra gia tri da duoc gan
}

// Xoa node dau tien
//------------------------------------------------------------------------------------------------//
node Pop(node head)
{
    if(head == NULL)
    {
        printf("Khong co gia tri de xoa\n");
    }
    if(head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        node p = head;
        while(p->next->next != NULL)
        {
            p = p->next;
        }
        p->next = NULL;
    }
    return head;// tra ve gia tri da duoc gan
}

// Ham lay gia tri cua mot nut bat ki
//------------------------------------------------------------------------------------------------//
int peekstack(node head)
{
    node p = head;
    while(p->next != NULL)
    {
    p = p->next;
    }
    return p->data;
}

// Ham kiem tra xem stack co rong khong
//------------------------------------------------------------------------------------------------//
int isEmptystack(node head)
{
    if(head == NULL)
        return 1;// neu head khong tro ve gia tri gi thi tra ve ket qua la 1(rong)
    else
        return 0;// co gia tri thi tra ve 0
}

// Ham khoi tao stack
//------------------------------------------------------------------------------------------------//
node initstack()
{
    node head;//bien kieu node
    head = NULL;// neu chua co gi thi head se = null
    return head;// tra ve head duoc gan gia tri
}

// H??m ki???m tra xem chu???i s c?? th??? ngo???c ????ng kh??ng
//------------------------------------------------------------------------------------------------//
int Parser(char s[])
{
    int n = strlen(s); // g??n n l?? chi???u d??i chu???i s
    node stack = initstack(); // kh???i t???o stack
    for(int i = 0; i < n; i++) // duy???t t??? ?????u chu???i ?????n cu???i chu???i
    {
        switch (s[i])
        {
            case '(':
            case '{':
            case '[':
                stack = Push(stack, s[i]); // n???u chu???i l?? c??c k?? t??? (,{,[ th?? th??m v??o stack
                break;
            case ')':
                if(peekstack(stack) == '(') // n???u stack ???????c so sanh l?? ????ng
                    stack = Pop(stack); // th?? l???y stack ???? ra
                else
                    return 0; // ng?????c l???i tr??? v??? 0;
                break; // v?? d???ng l???i
            case '}':
                if(peekstack(stack) == '{')
                    stack = Pop(stack);
                else
                    return 0;
                break;
            case ']':
                if(peekstack(stack) == '[')
                    stack = Pop(stack);
                else
                    return 0;
                break;
        }
    }
    if(isEmptystack(stack))
        return 1;
    else
        return 0;
}

//in danh s??ch li??n k???t
void getStack(node head){
    if (head == NULL){
        return;
    }
    for (node p = head; p != NULL; p = p->next){
        printf("%2c", p->data);
    }
}

// ?????c d??? li???u t??? file
//------------------------------------------------------------------------------------------------//
void readfile(char s[])
{
    FILE *Fin;
    char input[30];
    printf("\tNhap file vao: ");
    gets(input);
    Fin = fopen(input,"r");
    if(Fin == NULL)
    {
        printf("Mo file that bai!");
        exit(1);//thoat khi mo file khong thanh cong
    }
    while(fgets(s,100,Fin) != NULL){
        printf("\t%s\n",s);
        s[strlen(s) - 1] = '\0';
    }

    fclose(Fin);
}

// Ch????ng tr??nh ch??nh
//------------------------------------------------------------------------------------------------//

int main()
{
    char s[1000];
    printf("\t\t\t|-------------------------------------------------------------------------|\n");
    printf("\t\t\t|                 STACK de kiem tra cu phap co dung hay khong             |\n");
    printf("\t\t\t|                         CODE BY: LUAN CODER                             |\n");
    printf("\t\t\t|-------------------------------------------------------------------------|\n");
    readfile(s);
    Parser(s);
    if(Parser(s) == 1)
    {
        printf("\tChuoi dung !");
    }
    else
    {
         printf("\tChuoi sai !");
    }
    return 0;
}