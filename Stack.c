#include <stdio.h>
#include <string.h>
#include <conio.h>
#define MAX_STACK 5

typedef struct 
{
    int top;
    char data[5][5];
}STACK;

STACK tumpuk;

void inisialisasi()
{
    tumpuk.top=-1;
}

int IsFull()
{
    if(tumpuk.top == MAX_STACK -1) 
    return 1;
    else
    return 0;
}

int IsEmpty()
{
    if(tumpuk.top == -1)
    return 1;
    else
    return 0;
}

void Push(char d[5])
{
    tumpuk.top++;
    strcpy(tumpuk.data[tumpuk.top], d);
}

void Pop()
{
    printf("Data yang diambil = %s\n", tumpuk.data[tumpuk.top]);
    tumpuk.top--;
    printf("\n");
}

void CetakStack()
{
    for(int i = tumpuk.top; i >= 0; i--)
    {
        printf("Data: %s\n", tumpuk.data[i]);
    }
}

void Clear()
{
    tumpuk.top = -1;
}

int main()
{
    int pilihan;
    inisialisasi();
    char dt[5];
    do
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Cetak isi array stack!\n");
        printf("4. Hapus isi arrat stack!\n");
        printf("5. Keluar\n");
        printf("Pilihan anda? ");
        scanf("%d", &pilihan);
        
        switch(pilihan)
        {
            case 1: if(IsFull() !=1)
            {
                printf("Data yang ingin diinput = ");
                scanf("%s", dt);
                Push(dt);
                printf("\n");
            }
            else
                printf("Stack sudah penuh!\n");
                break;
                
            case 2: if(IsEmpty() !=1)
                Pop();
                else
                printf("Stack masih kosong!\n");
                break;
                
            case 3: if(IsEmpty() !=1)
            CetakStack();
            else
            printf("\n Tidak ada data. \n");
            break;
            
            case 4: Clear();
            printf("Data dihapus.\n");
            break;
            }
            getch();
        }
        while(pilihan !=5);
        printf("Keluar dari program...\n");
        getch();
}

