#include <string.h>
#include <stdio.h>
#include<stdlib.h>
char input[] = "input.txt";
char output[] = "output2.txt";
void tachhoten(char hoten[80])
{
    char *token;
   token = strtok(hoten, " ");
   int c=0;
   char mang[5][15];
   while( token != NULL )
   {
      strcpy(mang[c],token);
      c++;
      token = strtok(NULL, " ");
   }
   printf("%s\n",mang[c-1]);
   printf("%s ",mang[0]);
   for(int i=1;i<c-1;i++)
   {
    printf("%s\n",mang[i]);
   }
  // printf("%s",mang[c-1]);
}

void writefile()
{
   FILE *Fin,*Fout;
   if((Fin = fopen(input,"r")) == NULL || (Fout = fopen(output,"w")) == NULL)
   {
      printf("Loi! Khong mo duoc file");
      exit(1); 
   }
   char s[1000],hoten[100];
   int n=0;
   while(fgets(s,sizeof(s),Fin) != NULL)
   {
      s[strlen(s) - 1] = '\0';
      n++;
   char *token;
   token = strtok(s, " ");
   int c=0;
   char mang[5][15];
      while(token != NULL)
      {
         strcpy(mang[c],token);
         c++;
         token = strtok(NULL," ");
      }
         fprintf(Fout,"%d. %s \n",n,mang[c-1]);
         printf("%s",mang[c-1]);
         fprintf(Fout,"%s ",mang[0]);
         printf("%s ",mang[0]);
         for(int i=1;i<c-1;i++)
         {
         fprintf(Fout,"%s \n",mang[i]);
         printf("%s \n",mang[i]);
         }
   }
   fclose(Fin);
   fclose(Fout);
}
int main()
{
   writefile();
   return(0);
}