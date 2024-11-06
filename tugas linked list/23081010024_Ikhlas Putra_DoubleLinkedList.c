#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
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
        scanf("%d", &pilih);
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
    printf("masukkan bilangan : ");
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
        pNew->data = bil;
        if (*list == NULL) {
            pNew->left = NULL;
            pNew->right = NULL;
            *list = pNew;
        } else {
            pNew->left = NULL;
            pNew->right = *list;
            (*list)->left = pNew;
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
            pNew->left = NULL;
            pNew->right = NULL;
            *list = pNew;
        } else {
            pCur = *list;
            while (pCur->right != NULL) {
                pCur = pCur->right;
            }
            pNew->left = pCur;
            pNew->right = NULL;
            pCur->right = pNew;
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
    scanf("%d", &pos);
    printf("\nbilangan : ");
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL) {
        pNew->data = bil;
        pCur = *list;
        while (pCur->right != NULL && pCur->data != pos) {
            pCur = pCur->right;
        }
        if (pCur->right == NULL) {
            printf("\nposisi tidak ditemukan");
            getch();
        } else {
            pNew->left = pCur;
            pNew->right = pCur->right;
            pCur->right->left = pNew;
            pCur->right = pNew;
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
        *list = (*list)->right;
        if (*list != NULL)
            (*list)->left = NULL;
        free(pCur);
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
    scanf("%d", &pos);
    pCur = *list;
    pPrev = NULL;
    while (pCur->right != NULL && pCur->data != pos) {
        pPrev = pCur;
        pCur = pCur->right;
    }
    if (pCur->right == NULL) {
        printf("\nposisi tidak ditemukan");
        getch();
    } else {
        pPrev->right = pCur->right;
        pCur->right->left = pPrev;
        free(pCur);
    }
}

//=============== MENGHAPUS DATA DI AKHIR LIST ========================

void hapusAkhir(node **list) {
    node *pCur, *pPrev;

    if (*list != NULL) {
        pCur = *list;
        pPrev = NULL;
        while (pCur->right != NULL) {
            pPrev = pCur;
            pCur = pCur->right;
        }
        pPrev->right = NULL;
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
    scanf("%d", &pos);
    pCur = *list;
    while (pCur->right != NULL && pCur->data != pos) {
        pCur = pCur->right;
    }
    if (pCur->right == NULL) {
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

    printf("NULL");
    pCur = list;
    while (pCur != NULL) {
        printf(" <-> %d", pCur->data);
        pCur = pCur->right;
    }
    printf(" <-> NULL\n");
}
//=============== MENGHITUNG JUMLAH ISI LIST ========================

void sumData(node **list) {
    int sum = 0;
    node *pCur;

    pCur = *list;
    while (pCur != NULL) {
        sum += pCur->data;
        pCur = pCur->right;
    }
    printf("jumlah isi list : %d\n", sum);
    getch();
}

//=============== MENGHITUNG JUMLAH NODE DALAM LIST ========================

void jumlahNode(node **list) {
    int count = 0;
    node *pCur;

    pCur = *list;
    while (pCur != NULL) {
        count++;
        pCur = pCur->right;
    }
    printf("jumlah node dalam list : %d\n", count);
    getch();
}
