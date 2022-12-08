#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
char input1[] = "day_so_nguyen.txt";
char input2[] = "day_so_nguyen.bin";
char output[] = "ket_qua.txt";
void doc_file()
{
    FILE *fin,*fout;
    int a[100],num = 0, n = 0;
    if(((fin = fopen(input1,"r")) == NULL) || ((fout = fopen(input2,"wb")) == NULL))
    {
        printf("Loi! Khong mo duoc file");
        exit(1);
    }
    while (fscanf(fin,"%d",&num) != EOF)
    {
        a[n] = num;
        fwrite(&num,1,sizeof(num),fout);
        n++;
    }
    fclose(fin);
    fclose(fout);
}
void ghi_file()
{
    FILE *fin,*fout;
    int b[100],num = 0, n = 0;
    if(((fin = fopen(input2,"rb")) == NULL) || ((fout = fopen(output,"w")) == NULL))
    {
        printf("Loi! Khong mo duoc file");
        exit(1);
    }
    while (fread(&num,1,sizeof(num),fin))
    {
        b[n] = num;
        n++;
        printf("%8d",num);
    }
    int i,max = 0, min = b[0], so_chan = 0, so_le = 0;
    for(i = 0; i < n; i++)
    {
        if(b[i]%2 == 0)
        {
            so_chan++;
        }
        if(b[i]%2 != 0)
        {
            so_le++;
        }
        if(b[i] > max)
        {
            max = b[i];
        }
        else if(b[i] < min)
        {
            min = b[i];
        }
    }
    printf("\nSo luong cac phan tu: %d\n",n);
    printf("so lon nhat: %d\n",max);
    printf("so nho nhat: %d\n",min);
    printf("So luong cac so chan: %d\n",so_chan);
    printf("So luong cac so le: %d\n",so_le);

        fprintf(fout,"So luong cac phan tu: %d\n",n);
        fprintf(fout,"So lon nhat: %d\n",max);
        fprintf(fout,"So nho nhat: %d\n",min);
        fprintf(fout,"So luong cac so chan: %d\n",so_chan);
        fprintf(fout,"So luong cac so le: %d\n",so_le);
    fclose(fin);
    fclose(fout);
}

int main()
{
    doc_file();
    printf("Day so nguyen trong file:");
    ghi_file();
    return 0;
}
