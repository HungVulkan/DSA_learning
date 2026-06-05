#include <stdio.h>
typedef struct { 
char MSSV[10];
char Ten[30];
char Lop [10];
int NS;
int Khoa;
} SinhVien;
SinhVien SV1,*SVPtr;
int main()
{
            SVPtr = &SV1;
            printf("Nhap thong tin SV1:\n");
            printf("MSSV của SV1:"); scanf("%s",SV1.MSSV);
            printf("Ten của SV1:"); scanf("%s",SV1.Ten);
            printf("Lop của SV1:"); scanf("%s",SV1.Lop);
            printf("Nam sinh của SV1:"); scanf("%d",&SV1.NS);
            printf("Khoa hoc của SV1:"); scanf("%d",&SV1.Khoa);
            printf("------------------------\n");
        
            printf("Thong tin cua SV1:\n");
            printf("MSSV %s, Ten %s, SN %d, Lop %s, Khoa %d \n",SVPtr->MSSV,SVPtr->Ten,SVPtr->NS,SVPtr->Lop,SVPtr->Khoa);
            
    
    return 0;
}
