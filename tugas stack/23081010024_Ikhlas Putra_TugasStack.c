#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//========================================================

struct node {
    int data;
    struct node *next;
};
typedef struct node node;

struct stack {
    int count;
    int maxnode;
    node *top;
};
typedef struct stack stack;


void definecountandtop(stack *s);
void hitungStack(stack *s);
void TopStack(stack *s);
void tambahAwal(stack *s);
void hapusAwal(stack *s);
void tranverse(stack *s);
void emptyStack(stack *s);
void fullStack(stack *s);
void destroyStack(stack *s);

//========================================================

int main() {
    stack myStack;
    int pilih;

    definecountandtop(&myStack);
    do {
        system("cls");
        printf("Masukkan pilihan\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. Cetak isi STACK\n");
        printf("4. STACK COUNT\n");
        printf("5. STACK TOP\n");
        printf("6. EMPTY STACK\n");
        printf("7. FULL STACK\n");
        printf("8. DESTROY STACK\n");
        printf("MASUKKAN PILIHAN (isi 99 untuk keluar) : ");
        fflush(stdin);
        scanf("%d", &pilih);

        if (pilih == 1){
            tambahAwal(&myStack);
        } else if (pilih == 2){
            hapusAwal(&myStack);
        } else if (pilih == 3){
            tranverse(&myStack);
            getch();
        } else if (pilih == 4) {
            hitungStack(&myStack);
            getch();
        } else if (pilih == 5) {
            TopStack(&myStack);
            getch();
        } else if (pilih == 6) {
            emptyStack(&myStack);
            getch();
        } else if (pilih == 7) {
            fullStack(&myStack);
            getch();
        } else if (pilih == 8) {
            destroyStack(&myStack);
            getch();
        }
    } while (pilih != 99);

    return 0;
}

//========================================================

void definecountandtop(stack *s){
    s->count = 0;
    s->top = NULL;
    s->maxnode = 20;
}

//========================================================

void hitungStack(stack *s){
    system("cls");
    printf("Jumlah elemen dalam stack: %d\n", s->count);
}

//========================================================

void TopStack(stack *s){
    if (s->top == NULL){
        system("cls");
        printf("Stack kosong.\n");
    } else {
        system("cls");
        printf("Data teratas dalam stack: %d\n", s->top->data);
    }
}

//========================================================

void tambahAwal(stack *s) {
    if (s->count == s->maxnode){
        printf("Stack penuh. Tidak dapat menambahkan node lagi");
        getch();
        return;
    }

    int bil;
    node *pNew;

    system("cls");
    fflush(stdin);
    printf("Masukkan bilangan : ");
    fflush(stdin);
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    // Jika alokasi memori berhasil, tambahkan node baru di awal stack
    if (pNew != NULL) {
        pNew->data = bil;
        pNew->next = s->top;
        s->top = pNew;
        s->count++;
    } else {
        // Jika alokasi memori gagal
        printf("Alokasi memori gagal");
        getch();
    }
}

//========================================================

void hapusAwal(stack *s) {
    int bil;
    node *pCur;

    // Jika list kosong
    if (s->top == NULL) {
        printf("Tidak ada data yang dapat dihapus\n");
        getch();
        return;
    }
    else {
        // Hapus node pertama
        pCur = s->top;
        s->top = pCur->next;
        free(pCur);
        s->count--;
        system("cls");
        printf("node awal berhasil dihapus\n");
    }
    getch();
}

//========================================================

void tranverse(stack *s) {
    // Traverse dan tampilkan stack
    node *pWalker;

    system ("cls");
    pWalker = s->top;
    while (pWalker != NULL) {
        printf("%d\t", pWalker->data);
        pWalker = pWalker->next;
        printf(" -> ");
    }
    printf("NULL\n");
}

//========================================================

void emptyStack(stack *s) {
    if (s->top == NULL) {
        system("cls");
        printf("Stack kosong: True\n");
        return;
    } else {
        system("cls");
        printf("Stack kosong: False\n");
        return;
    }
}

//========================================================

void fullStack(stack *s) {
    if (s->count == s->maxnode) {
        system("cls");
        printf("Stack penuh: True\n");
        return 1;
    } else {
        system("cls");
        printf("Stack penuh: False\n");
        return;
    }
}

//========================================================

void destroyStack(stack *s) {
    node *pCur = s->top;
    node *pPrev;

    while (pCur != NULL) {
        pPrev = pCur;
        pCur = pCur->next;
        free(pPrev);
    }

    s->top = NULL;
    s->count = 0;
    system("cls");
    printf("Stack telah dihancurkan\n");
    return;
}