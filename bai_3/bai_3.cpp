// BAI CAU TRUC SINH VIEN
//------------------------------------------------------------------------------------------------//
#include<conio.h>
#include<stdio.h>
#include <iostream>
#include <string.h>
#define MAX 100
using namespace std;

struct SinhVien
{
    int id;
    char ten[30];
    char gioiTinh[5];
    int tuoi;
    float diemTB = 0;
    char hocluc[10] = "-";
    char trangthai[20] = "-";
};

typedef struct SinhVien SV;

 // Hàm vẽ đường
 //------------------------------------------------------------------------------------------------//
void printLine(int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("_");
    }
    printf("\tCODE BY: LUAN\n");
    printf("\n");
}

// Hàm xếp lại học lực
//------------------------------------------------------------------------------------------------//
void xeploai(SV &sv)
{
    if(sv.diemTB >= 8) strcpy(sv.hocluc, "Gioi");
    else if(sv.diemTB >= 6.5) strcpy(sv.hocluc, "Kha");
    else if(sv.diemTB >= 5) strcpy(sv.hocluc, "Trung-binh");
    else strcpy(sv.hocluc, "Yeu");
}
// hàm in danh sách sinh viên ra màn hình
//------------------------------------------------------------------------------------------------//
void showStudent(SV a[], int n)
{
    printLine(100);
    printf("\nSTT\tID\tHo va ten\t\tGioi tinh\t\tTuoi\t\tDiem TB\t\tHoc luc\t\n");
    for(int i = 0; i < n; i++)
    {
        // in sinh vien thu i ra man hinh
        printf("%2d %7d %20s %15s %19d %20f %13s\n",i+1,a[i].id,a[i].ten,a[i].gioiTinh,a[i].tuoi,a[i].diemTB,a[i].hocluc);
    }
    printLine(100);
}

// Hàm nhập thông tin sinh viên
//------------------------------------------------------------------------------------------------//
void nhapThongTinSV(SV &sv, int id)
{
    printf("\n Nhap ten: "); fflush(stdin); gets(sv.ten);
    printf(" Nhap gioi tinh: "); gets(sv.gioiTinh);
    printf(" Nhap tuoi: "); scanf("%d", &sv.tuoi);
    printf(" Nhap diem trung binh: "); scanf("%f", &sv.diemTB);
    sv.id = id;
    xeploai(sv);
}

// Hàm nhập sinh viên lần lượt
//------------------------------------------------------------------------------------------------//
void nhapSV(SV a[], int id, int n)
{
    printLine(40);
    printf("\n Nhap sinh vien thu %d:", n + 1);
    nhapThongTinSV(a[n], id);
    printLine(40);
}

// hàm xóa sinh viên theo id
//------------------------------------------------------------------------------------------------//
int xoaTheoID(SV a[], int id, int n)
{
    int found = 0; // khởi tạo số lượng phần tử là 0
    for(int i = 0; i < n; i++)
    {
        if (a[i].id == id)
        {
            found = 1; // cho số lượng cần xóa là 1
            printLine(40);
            for (int j = i; j < n; j++)
            {
                a[j] = a[j+1]; // thế chỗ
            }
            cout << "\n Da xoa SV co ID = " << id;
            printLine(40);
            break;
        }
    }
    if (found == 0) {
        printf("\n Sinh vien co ID = %d khong ton tai.", id);
        return 0;
    } else {
        return 1;
    }
}

// Tìm kiếm theo tên
//------------------------------------------------------------------------------------------------//
void timKiemTheoTen(SV a[], char ten[], int n)
{
    SV arrayFound[MAX]; // biến để trả về kết quả tìm được
    char tenSV[30];
    int found = 0; // số lượng phần tử
    for(int i = 0; i < n; i++)
    {
        strcpy(tenSV, a[i].ten); // thực hiện copy chuỗi
        if(strstr(strupr(tenSV), strupr(ten))) // so sánh chuỗi vừa copy với chuỗi cần tìm
        {
            arrayFound[found] = a[i];
            found++; // số lượng phần tử them 1 tối đa là 100
        }
    }
    showStudent(arrayFound, found); // xuất ra màn hình
}

// hàm tăng thêm sinh viên tiếp theo
//------------------------------------------------------------------------------------------------//
int idLonNhat (SV a[], int n)
{
    int idMax = 0;
    if (n > 0)
    {
        idMax = a[0].id; // cho id lớn nhất là id đầu tiên
        for(int i = 0;i < n; i++)
        {
            if (a[i].id > idMax) // nếu id tiếp theo lớn hơn
            {
                idMax = a[i].id; // cập nhật idmax là id vừa kiểm tra
            }
        }
    }
    return idMax; // trả về id lớn nhất
}

// Sắp xếp theo tên
//------------------------------------------------------------------------------------------------//
void sapXepTheoTen(SV a[], int n)
{
    //Sap xep sinh vien theo ten theo thu tu tang dan
    SV tmp;
    char tenSV1[30];
    char tenSV2[30];
    for(int i = 0;i < n; i++)
    {
        strcpy(tenSV1, a[i].ten);
        for(int j = i+1; j < n; j++)
        {
            strcpy(tenSV2, a[j].ten);
            if(strcmp(strupr(tenSV1), strupr(tenSV2)) > 0) // so sánh tên sv1 với tên sv2
            {
                //thực hiện đổi vị trí
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

// Đọc sinh viên từ file
//------------------------------------------------------------------------------------------------//
int docFile(SV a[], char fileName[])
{
    FILE *f1;
    int i = 0;
    f1 = fopen (fileName, "r");
    printf("Chuan bi doc file: "); puts(fileName);
    // doc thong tin sinh vien
    while (fread(&a[i],1,sizeof(struct SinhVien),f1) != NULL)
    {
       printf("\tBAT DAU DOC");
       i++;
    }
    printf(" So luong sinh vien co san trong file la: %d\n",i);
    printf("\n");
    fclose (f1);
    // tra ve so luong sinh vien duoc doc tu file
    return i;
}

// Cập nhật vào file
//------------------------------------------------------------------------------------------------//
void ghiFile(SV a[], int n, char fileName[], char fileName2[])
{
    FILE *f1,*f2;
    f1 = fopen (fileName,"wb");
    f2 = fopen (fileName2,"w");
    fprintf(f2,"STT\tID\t\tHo va ten\tgioi tinh\ttuoi\tDTB\thoc luc\t\n");
    for(int i = 0;i < n;i++)
    {
        fwrite(&a[i],sizeof(struct SinhVien),1,f1);
        fprintf(f2,"%d %4d %10s %12s %14d %16f %18s\n",i+1,a[i].id,a[i].ten,a[i].gioiTinh,a[i].tuoi,a[i].diemTB,a[i].hocluc);
    }
    fclose (f1);
    fclose (f2);
}

// Thay cho lệnh system("pause"); là việt hóa :))
//------------------------------------------------------------------------------------------------//
void pressAnyKey()
{
    printf("\n\nBam phim bat ky de tiep tuc...");
    _getch();
    system("cls");
}

// Chương trình chinh
//------------------------------------------------------------------------------------------------//
int main()
{
    int key;
    char fileName2[] = "sinhvien.txt";
    char fileName[] = "sinhvien.Dat";
    SV aSV[MAX]; // tối đa 100 sinh viên
    int soluongSV = 0,idsv = 0;
    // nhap danh sach sinh vien tu file
    soluongSV = docFile(aSV, fileName); // kiểm tra trong file có sinh viên chưa nếu có thì in ra
    idsv = idLonNhat (aSV, soluongSV);

    while(true) {
        printf("|------------------------MENU-----------------------|\n");
        printf("|  1. Them sinh vien.                               |\n");
        printf("|  2. Xoa sinh vien boi ID.                         |\n");
        printf("|  3. Tim kiem sinh vien theo ten.                  |\n");
        printf("|  4. Sap xep sinh vien theo ten.                   |\n");
        printf("|  5. Hien thi danh sach sinh vien.                 |\n");
        printf("|  6. Ghi danh sach sinh vien vao file.             |\n");
        printf("|  0. Thoat                                         |\n");
        printf("|---------------------------------------------------|\n");
        printf("Nhap tuy chon: ");
        scanf("%d", &key);
        switch(key)
        {
            case 1:
                printf("\n1. Them sinh vien.");
                idsv++;
                nhapSV(aSV, idsv, soluongSV);
                printf("\nThem sinh vien thanh cong!");
                soluongSV++;
                pressAnyKey();
                break;

            case 2:
                if(soluongSV > 0)
                {
                    int id;
                    printf("\n2. Xoa sinh vien.");
                    printf("\n Nhap ID: "); scanf("%d", &id);
                    if (xoaTheoID(aSV, id, soluongSV) == 1)
                    {
                        printf("\nSinh vien co id = %d da bi xoa.", &id);
                        soluongSV--;
                    }
                }else{
                    printf("\nSanh sach sinh vien trong!");
                }
                pressAnyKey();
                break;
                case 3:
                if(soluongSV > 0)
                {
                    printf("\n3. Tim kiem sinh vien theo ten.");
                    char strTen[30];
                    printf("\nNhap ten de tim kiem: "); fflush(stdin); gets(strTen);
                    timKiemTheoTen(aSV, strTen, soluongSV);
                }else
                {
                    printf("\nSanh sach sinh vien trong!");
                }
                pressAnyKey();
                break;
            case 4:
                if(soluongSV > 0)
                {
                    printf("\n4. Sap xep sinh vien theo ten.");
                    sapXepTheoTen(aSV, soluongSV);
                    showStudent(aSV, soluongSV);
                } else {
                    printf("\nSanh sach sinh vien trong!");
                }
                pressAnyKey();
                break;
            case 5:
                if(soluongSV > 0)
                {
                    printf("\n5. Hien thi danh sach sinh vien.");
                    showStudent(aSV, soluongSV);
                }else
                {
                    printf("\nDanh sach sinh vien trong!");
                }
                pressAnyKey();
                break;
            case 6:
                if(soluongSV > 0)
                {
                    printf("\n6. Ghi danh sach sinh vien vao file.");
                    ghiFile(aSV, soluongSV, fileName, fileName2);
                }else
                {
                    printf("\nSanh sach sinh vien trong!");
                }
                printf("\nGhi danh sach sinh vien vao file %s thanh cong!", fileName);
                pressAnyKey();
                break;
            case 0:
                printf("\nBan da chon thoat chuong trinh!");
                getch();
                return 0;
            default:
                printf("\nKhong co chuc nang nay!");
                printf("\nHay chon chuc nang trong hop menu.");
                pressAnyKey();
                break;
        }
    }
}
