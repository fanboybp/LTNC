#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

char input1[] = "day_so_nguyen.txt";
char input2[] = "day_so_nguyen.bin";

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void sapxep(int a[],long n)
{
    int Left=0;
    int Right=n-1;
    while(Left < Right)
    {
        for(int i=Left; i<Right; i++)
            if(a[i] > a[i+1])
           swap(&a[i], &a[i+1]);
           Right--;
           for(int j=Right; j > Left; j--)
            if(a[j] < a[j-1])
            swap(&a[j], &a[j-1]);
           Left++;
    }
}

void doc_file()
{
    FILE *fin,*fout;
    int a[100],num = 0, n = 0;
    if(((fin = fopen(input1, "r")) == NULL) || ((fout = fopen(input2, "wb")) == NULL))
    {
        printf("Loi! Khong mo duoc file"); 
        exit(1);
    }
    while (fscanf(fin,"%d",&num) != EOF)
    {
        a[n] = num;
        printf("%8d",num);
        n++;
    }
    printf("\nFile co %d so \n",n);
    sapxep(a,n);
    printf("File sau khi sap xep \n");
    for(int i=0;i<n;i++)
    {
        //printf("%8d",a[i]);
        fwrite(&a[i],1,sizeof(int),fout);
    }
    fclose(fin);
    fclose(fout);   
}

void ghi_file()
{
     FILE *fin, *fout;
    int a[100],num = 0, n = 0;
    if(((fin = fopen(input2, "rb")) == NULL) || ((fout = fopen(input2, "ab")) == NULL))
    {
        printf("Loi! Khong mo duoc file"); 
        exit(1);
    }
    while (fread(&a[n],1,sizeof(int),fin))
    {
        printf("%8d", a[n]);
        n++;
    }
    printf("\nNhap so phan tu ma ban muon nhap them :");
    scanf("%d",&num);
    for(int i=0; i<num; i++)
    {
       printf("Nhap so thu b[%d]: ",i);
       scanf("%d", &a[i]);
       fwrite(&a[i],1,sizeof(int),fout);
    }
    fclose(fin);
    fclose(fout);
}

void ghi_file2()
{
    FILE *fin,*fout;
    int a[100],num = 0, n = 0;
    if(((fin = fopen(input2, "rb")) == NULL) || ((fout = fopen(input2, "ab")) == NULL))
    {
        printf("Loi! Khong mo duoc file"); 
        exit(1);
    }
    while(fread(&a[n],1,sizeof(int),fin))
    {
        printf("%8d", a[n]);
        n++;
    }
    printf("\nFile co %d so \n",n);
    sapxep(a,n);
    printf("File sau khi sap xep \n");
    for(int i=0; i<n; i++)
    {
        printf("%8d",a[i]);
        fwrite(&a[i],1,sizeof(int),fout);
    }
    fclose(fin);
    fclose(fout);   
}
int main()
{
    doc_file();
    system("pause");
    ghi_file();
    ghi_file2();
    return 0;
}