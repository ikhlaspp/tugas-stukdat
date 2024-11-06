
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node node;

void tambahAwal(node **list);
void tambahAkhir(node **list);
void tambahTengah(node **list);
void hapusAwal(node **list);
void hapusTengah(node **list);
void hapusAkhir(node **list);
void cariData(node **list);
void sumData(node **list);
void tranverse(node *list);
void jumlahNode(node **list);

//========================================================

int main() {
    node *list;
    int pilih;

    list = NULL;
    do {
        system("cls");
        printf("masukkan pilihan\n");
        printf("1. tambah data di awal\n");
        printf("2. tambah data di akhir list\n");
        printf("3. tambah data di tengah list\n");
        printf("4. hapus data di awal list\n");
        printf("5. hapus data di tengah list\n");
        printf("6. hapus data di akhir list\n");
        printf("7. mencari data di tengah list\n");
        printf("8. cetak isi list\n");
        printf("9. jumlahkan isi list\n");
        printf("10. jumlah node dalam list\n");
        printf("MASUKKAN PILIHAN (tekan 0 untuk keluar) : ");
        fflush(stdin);
        scanf(" %d", &pilih);
        if (pilih == 1)
            tambahAwal(&list);
        else if (pilih == 2)
            tambahAkhir(&list);
        else if (pilih == 3)
            tambahTengah(&list);
        else if (pilih == 4)
            hapusAwal(&list);
        else if (pilih == 5)
            hapusTengah(&list);
        else if (pilih == 6)
            hapusAkhir(&list);
        else if (pilih == 7)
            cariData(&list);
        else if (pilih == 8) {
            tranverse(list);
            getch();
        }
        else if (pilih == 9)
            sumData(&list);
        else if (pilih == 10)
            jumlahNode(&list);
    } while (pilih != 0);
    return 0;
}
//=============== MENAMBAHKAN DATA DI AWAL LIST ========================

void tambahAwal(node **list) {
    int bil;
    node *pNew;

    system("cls");
    fflush(stdin);
    printf("masukkan bilangan : ");
    fflush(stdin);
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
        pNew->data = bil;
        if (*list == NULL) {
            pNew->next = pNew;
            *list = pNew;
        } else {
            node *pCur = *list;
            while (pCur->next != *list) {
                pCur = pCur->next;
            }
            pNew->next = *list;
            pCur->next = pNew;
            *list = pNew;
        }
    } else {
        printf("\nalokasi memori gagal");
        getch();
    }
}

//=============== MENAMBAHKAN DATA DI AKHIR LIST ========================

void tambahAkhir(node **list) {
    int bil;
    node *pNew, *pCur;

    system("cls");
    printf("masukkan bilangan: ");
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL) {
        pNew->data = bil;
        if (*list == NULL) {
            pNew->next = pNew;
            *list = pNew;
        } else {
            pCur = *list;
            while (pCur->next != *list) {
                pCur = pCur->next;
            }
            pNew->next = pCur->next;
            pCur->next = pNew;
        }
    } else {
        printf("\nalokasi memori gagal");
        getch();
    }
}

//=============== MENAMBAHKAN DATA DI TENGAH LIST ========================

void tambahTengah(node **list) {
    int pos, bil;
    node *pNew, *pCur;

    system("cls");
    tranverse(*list);
    printf("\nposisi penyisipan setelah data bernilai : ");
 fflush(stdin);
    scanf("%d", &pos);
    printf("\nbilangan : ");
    fflush(stdin);
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL) {
        pNew->data = bil;
        pCur = *list;
        while (pCur->next != *list && pCur->data != pos) {
            pCur = pCur->next;
        }
        if (pCur->next == *list) {
            printf("\nposisi tidak ditemukan");
            getch();
        } else {
            pNew->next = pCur->next;
            pCur->next = pNew;
        }
    } else {
        printf("\nalokasi memori gagal");
        getch();
    }
}

//=============== MENGHAPUS DATA DI AWAL LIST ========================

void hapusAwal(node **list) {
    node *pCur;

    if (*list != NULL) {
        pCur = *list;
        while (pCur->next != *list) {
            pCur = pCur->next;
        }
        pCur->next = (*list)->next;
        free(*list);
        *list = pCur->next;
    } else {
        printf("\nlist kosong");
        getch();
    }
}

//=============== MENGHAPUS DATA DI TENGAH LIST ========================

void hapusTengah(node **list) {
    int pos;
    node *pCur, *pPrev;

    system("cls");
    tranverse(*list);
    printf("\nposisi penghapusan data bernilai : ");
    fflush(stdin);
    scanf("%d", &pos);
    pCur = *list;
    pPrev = NULL;
    while (pCur->next != *list && pCur->data != pos) {
        pPrev = pCur;
        pCur = pCur->next;
    }
    if (pCur->next == *list) {
        printf("\nposisi tidak ditemukan");
        getch();
    } else {
        pPrev->next = pCur->next;
        free(pCur);
    }
}

//=============== MENGHAPUS DATA DI AKHIR LIST ========================

void hapusAkhir(node **list) {
    node *pCur, *pPrev;

    if (*list != NULL) {
        pCur = *list;
        pPrev = NULL;
        while (pCur->next != *list) {
            pPrev = pCur;
            pCur = pCur->next;
        }
        pPrev->next = pCur->next;
        free(pCur);
    } else {
        printf("\nlist kosong");
        getch();
    }
}

//=============== MENCARI DATA DI TENGAH LIST ========================

void cariData(node **list) {
    int pos;
    node *pCur;

    system("cls");
    tranverse(*list);
    printf("\ndata yang dicari : ");
    fflush(stdin);
    scanf("%d", &pos);
    pCur = *list;
    while (pCur->next != *list && pCur->data != pos) {
        pCur = pCur->next;
    }
    if (pCur->next == *list) {
        printf("\ndata tidak ditemukan");
        getch();
    } else {
        printf("\ndata ditemukan");
        getch();
    }
}

//=============== MENCETAK ISI LIST ========================

void tranverse(node *list) {
    node *pCur;

    pCur = list;
    do {
        printf("%d ", pCur->data);
        pCur = pCur->next;
    } while (pCur != list);
    printf("\n");
}

//=============== MENGHITUNG JUMLAH ISI LIST ========================

void sumData(node **list) {
    int sum = 0;
    node *pCur;

    pCur = *list;
    do {
        sum += pCur->data;
        pCur = pCur->next;
    } while (pCur != *list);
    printf("jumlah isi list : %d\n", sum);
    getch();
}

//=============== MENGHITUNG JUMLAH NODE DALAM LIST ========================

void jumlahNode(node **list) {
    int count = 0;
    node *pCur;

    pCur = *list;
    do {
        count++;
        pCur = pCur->next;
    } while (pCur != *list);
    printf("jumlah node dalam list : %d\n", count);
    getch();
}
