#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Nama : Ikhlas Putra Pambagyo
// NPM : 23081010024
// kelas : stukdat e

typedef struct Mahasiswa {
    char nama[50];
    char jenis_kelamin;
    struct Mahasiswa* next;
} Mahasiswa;

Mahasiswa* head = NULL;
int jumlah_orang = 0;
int MAX_ORANG = 20;

Mahasiswa* buatMahasiswa(char* nama, char jenis_kelamin) {
    Mahasiswa* baru = (Mahasiswa*)malloc(sizeof(Mahasiswa));
    strcpy(baru->nama, nama);
    baru->jenis_kelamin = jenis_kelamin;
    baru->next = NULL;
    return baru;
}

void aturanCindy() {
    if (head == NULL || head->next == head) {
        return;
    }

    Mahasiswa* current = head;
    Mahasiswa* prev = NULL;
    do {
        if (strcmp(current->nama, "Cindy") == 0) {
            Mahasiswa* next = current->next;
            if ((prev != NULL && prev->jenis_kelamin == 'L') ||
                (next != head && next->jenis_kelamin == 'L')) {
                printf("Cindy keluar karena di sebelahnya ada laki-laki.\n");
                if (prev == NULL) {
                    head = next;
                } else {
                    prev->next = next;
                }
                Mahasiswa* temp = current;
                current = next;
                free(temp);
                jumlah_orang--;
                continue;
            }
        }
        prev = current;
        current = current->next;
    } while (current != head);
}

void aturKembar() {
    if (head == NULL || head->next == head) {
        return;
    }

    Mahasiswa* irsad = NULL;
    Mahasiswa* arsyad = NULL;
    Mahasiswa* current = head;

    do {
        if (strcmp(current->nama, "Irsad") == 0) irsad = current;
        if (strcmp(current->nama, "Arsyad") == 0) arsyad = current;
        current = current->next;
    } while (current != head);

    if (irsad && arsyad && irsad->next != arsyad && arsyad->next != irsad) {
        Mahasiswa* irsadNext = irsad->next;
        Mahasiswa* arsyadPrev = head;
        while (arsyadPrev->next != arsyad) {
            arsyadPrev = arsyadPrev->next;
        }

        arsyadPrev->next = arsyad->next;
        irsad->next = arsyad;
        arsyad->next = irsadNext;

        printf("Irsad dan Arsyad dipindahkan agar berdekatan.\n");
    }
}

void tambahkanMahasiswa(char* nama, char jenis_kelamin) {
    if (jumlah_orang >= MAX_ORANG) {
        printf("Lingkaran sudah penuh, tidak dapat menambahkan lebih banyak mahasiswa.\n");
        return;
    }

    Mahasiswa* baru = buatMahasiswa(nama, jenis_kelamin);
    if (head == NULL) {
        head = baru;
        baru->next = head;
    } else {
        Mahasiswa* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = baru;
        baru->next = head;
    }
    jumlah_orang++;
    printf("Mahasiswa %s berhasil ditambahkan.\n", nama);

    aturanCindy();
    aturKembar();
}

void tambahkanMahasiswaInput() {
    char nama[50];
    char jenis_kelamin;

    printf("Masukkan nama mahasiswa: ");
    scanf("%s", nama);

    printf("Masukkan jenis kelamin (L/P): ");
    scanf(" %c", &jenis_kelamin);

    tambahkanMahasiswa(nama, jenis_kelamin);
}

void keluarkanMahasiswa() {
    if (head == NULL) {
        printf("Tidak ada mahasiswa dalam lingkaran.\n");
        return;
    }

    char pilihKeluar;
    do {
        printf("Apakah ada mahasiswa yang ingin keluar? (y/n): ");
        scanf(" %c", &pilihKeluar);
        if (pilihKeluar == 'n' || pilihKeluar == 'N') {
            break;
        }

        char namaKeluar[50];
        printf("Masukkan nama mahasiswa yang ingin keluar: ");
        scanf("%s", namaKeluar);

        if (strcmp(namaKeluar, "Irsad") == 0 || strcmp(namaKeluar, "Arsyad") == 0) {
            printf("Maaf, Irsad dan Arsyad adalah kembar dan tidak bisa dipisahkan.\n");
            continue;
        }

        Mahasiswa* current = head;
        Mahasiswa* prev = NULL;
        int found = 0;

        do {
            if (strcmp(current->nama, namaKeluar) == 0) {
                found = 1;
                break;
            }
            prev = current;
            current = current->next;
        } while (current != head);

        if (!found) {
            printf("Mahasiswa dengan nama %s tidak ditemukan.\n", namaKeluar);
            continue;
        }

        if (current == head && current->next == head) {
            head = NULL;
        } else if (current == head) {
            Mahasiswa* last = head;
            while (last->next != head) {
                last = last->next;
            }
            head = head->next;
            last->next = head;
        } else {
            prev->next = current->next;
        }

        printf("Mahasiswa %s keluar dari lingkaran.\n", current->nama);
        free(current);
        jumlah_orang--;

        tampilkanLingkaran();

        if (head == NULL) {
            printf("Tidak ada lagi mahasiswa dalam lingkaran.\n");
            break;
        }

    } while (1);
}

void buatLingkaranKecil() {
    if (head == NULL) {
        printf("Tidak ada mahasiswa dalam lingkaran.\n");
        return;
    }

    int ada_laki = 0;
    int ada_perempuan = 0;
    Mahasiswa* temp = head;

    do {
        if (temp->jenis_kelamin == 'L') ada_laki = 1;
        if (temp->jenis_kelamin == 'P') ada_perempuan = 1;
        temp = temp->next;
    } while (temp != head && !(ada_laki && ada_perempuan));

    printf("Membagi menjadi lingkaran kecil:\n");

    if (ada_laki) {
        printf("Lingkaran Mahasiswa (Laki-laki):\n");
        temp = head;
        int irsadArsyadPrinted = 0;
        do {
            if (temp->jenis_kelamin == 'L') {
                if ((strcmp(temp->nama, "Irsad") == 0 || strcmp(temp->nama, "Arsyad") == 0) && !irsadArsyadPrinted) {
                    printf("Irsad -> Arsyad");
                    irsadArsyadPrinted = 1; } else if (strcmp(temp->nama, "Irsad") != 0 && strcmp(temp->nama, "Arsyad") != 0) {
                    printf("%s", temp->nama);
                }
                Mahasiswa* next = temp->next;
                while (next != head && next->jenis_kelamin != 'L') {
                    next = next->next;
                }
                if (next != head && next->jenis_kelamin == 'L' &&
                    (strcmp(next->nama, "Irsad") != 0 && strcmp(next->nama, "Arsyad") != 0)) {
                    printf(" -> ");
                }
            }
            temp = temp->next;
        } while (temp != head);
        printf(" kembali ke awal\n");
    } else {
        printf("Tidak ada mahasiswa laki-laki untuk membuat lingkaran kecil.\n");
    }

    if (ada_perempuan) {
        printf("\nLingkaran Mahasiswi (Perempuan):\n");
        temp = head;
        do {
            if (temp->jenis_kelamin == 'P') {
                printf("%s", temp->nama);
                Mahasiswa* next = temp->next;
                while (next != head && next->jenis_kelamin != 'P') {
                    next = next->next;
                }
                if (next != head && next->jenis_kelamin == 'P') {
                    printf(" -> ");
                }
            }
            temp = temp->next;
        } while (temp != head);
        printf(" kembali ke awal\n");
    } else {
        printf("Tidak ada mahasiswi perempuan untuk membuat lingkaran kecil.\n");
    }
}

void tampilkanLingkaran() {
    if (head == NULL) {
        printf("Lingkaran kosong.\n");
        return;
    }

    printf("Lingkaran saat ini:\n");
    Mahasiswa* temp = head;
    do {
        printf("%s (%c)", temp->nama, temp->jenis_kelamin);
        if (temp->next != head) {
            printf(" -> ");
        }
        temp = temp->next;
    } while (temp != head);
    printf(" kembali ke awal\n");
}

int main() {
    tambahkanMahasiswa("Irsad", 'L');
    tambahkanMahasiswa("Arsyad", 'L');
    tambahkanMahasiswa("Cindy", 'P');

    tampilkanLingkaran();

    char pilihan;
    do {
        tambahkanMahasiswaInput();
        tampilkanLingkaran();
        printf("Apakah ingin menambahkan mahasiswa lagi? (y/n): ");
        scanf(" %c", &pilihan);
    } while (pilihan == 'y' || pilihan == 'Y');

    keluarkanMahasiswa();

    if (head != NULL) {
        buatLingkaranKecil();
    } else {
        printf("Tidak dapat membuat lingkaran kecil karena semua mahasiswa telah keluar.\n");
    }

    return 0;
}
