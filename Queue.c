#include <stdio.h>
#define MAX 3 

typedef struct
{
    int data[MAX];
    int head;
    int tail;
} queue;

queue antrian;

void awal()
{
    antrian.head = antrian.tail = -1;
}

int kosong()
{
    if(antrian.tail == -1)
     return 1;
    else
     return 0;
}

int penuh()
{
    if(antrian.tail == MAX-1)
     return 1;
    else
     return 0;
}

int enqueue(int data)
{
    if(kosong() == 1)
    {
        antrian.head = antrian.tail = 0;
        antrian.data[antrian.tail] = data;
        printf("%d masuk! \n", antrian.data[antrian.tail]);
        void tampil();
        {
            if(kosong() == 0)
            {
                for(int i = antrian.head; i <= antrian.tail; i++)
                {
                    printf("%d ", antrian.data[i]);
                }
                printf("\n");
            }
            else
            printf("Isi antrian kosong.");
        }
    }
    else if(penuh() == 0)
    {
        antrian.tail++;
        antrian.data[antrian.tail] = data;
        printf("%d masuk! \n", antrian.data[antrian.tail]);

    }
}

int Dequeue()
{
    int i, antri = antrian.data[antrian.head];
    for(i = antrian.head; i <= antrian.tail; i++);
    {
        antrian.data[i] = antrian.data[i+1];
    }
    antrian.tail--;
    return antri;
}

void tampil()
{
    if(kosong() == 0)
    {
        printf("Isi antrian: ");
        for(int i = antrian.head; i <= antrian.tail; i++)
        {
            printf("%d ", antrian.data[i]);
        }
        printf("\n");
    }
    else
    printf("Tidak ada data dalam antrian.");
}

void hapus()
{
    antrian.head = antrian.tail = -1;
    printf("Data sudah dibersihkan.\n");
}

void main()
{
    int pilihan;
    int data;
    
    awal();
    do
    {
    printf("\n");
    printf("1. MasukSatuData\n");
    printf("2. KeluarSatuData\n");
    printf("3. Lihat isi antrian\n");
    printf("4. Hapus isi antrian\n");
    printf("5. Keluar...\n");
    printf("Pilihan anda? ");
    scanf("%d", &pilihan);
    
    switch(pilihan)
    {
        case 1: 
        printf("Data yang diinput = ");
        scanf("%d", &data);
        enqueue(data);
        break;
        
        case 2:
        printf("Data yang keluar: %d\n", Dequeue());
        break;
        
        case 3:
        tampil();
        break;
        
        case 4:
        hapus();
        break;
    }
  }while(pilihan!=5);
}
