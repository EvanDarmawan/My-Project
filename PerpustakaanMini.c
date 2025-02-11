#include <stdio.h>

#define MAX_BUKU 100

typedef struct {
    int id;
    char judul[50];
    int dipinjam;
} Buku;

Buku perpustakaan[MAX_BUKU];
int jumlahBuku = 0;

void tbk_bk();
void tpk_bk();
void pinjam();
void kbl_bk();
void keluar();

int main() {
    int pilih;
    do {
        printf("\n====== Perpustakaan Mini JONBOOK ======\n");
        printf("1. Tambahkan Buku\n");
        printf("2. Tampilkan Buku\n");
        printf("3. Pinjam Buku\n");
        printf("4. Kembalikan Buku\n");
        printf("5. Keluar\n");
        printf("Pilih 1-5: ");
        scanf("%i", &pilih);
        

        switch (pilih) {
            case 1: tbk_bk(); 
                break;
            case 2: tpk_bk();
                break;
            case 3: pinjam();
                break;
            case 4: kbl_bk(); 
                break;
            case 5: keluar(); 
                break;
            default: printf("Pilihan tidak valid!\n");
        }
    } while (pilih != 5);

    return 0;
}

void tbk_bk() {
    if (jumlahBuku < MAX_BUKU) {
        printf("Masukkan ID Buku: ");
        scanf("%i", &perpustakaan[jumlahBuku].id);
        printf("Masukkan Judul Buku: ");
        scanf(" %[^\n]", perpustakaan[jumlahBuku].judul);
        perpustakaan[jumlahBuku].dipinjam = 0;  // Status buku awal: belum dipinjam
        jumlahBuku++;
        printf("Buku berhasil ditambahkan!\n");
    } else {
        printf("Perpustakaan penuh, tidak dapat menambah buku.\n");
    }
}

void tpk_bk() {
    if (jumlahBuku == 0) {
        printf("Belum ada buku di perpustakaan.\n");
    } else {
        printf("Daftar Buku di Perpustakaan:\n");
        for (int i = 0; i < jumlahBuku; i++) {
            printf("ID: %d, Judul: %s, Status: %s\n", 
                   perpustakaan[i].id, perpustakaan[i].judul, 
                   perpustakaan[i].dipinjam ? "Dipinjam" : "Tersedia");
        }
    }
}

void pinjam() {
    int id, ditemukan = 0;
    printf("Masukkan ID Buku yang dipinjam: ");
    scanf("%i", &id);

    for (int i = 0; i < jumlahBuku; i++) {
        if (perpustakaan[i].id == id) {
            if (perpustakaan[i].dipinjam == 0) {
                perpustakaan[i].dipinjam = 1;  // Tandai buku sebagai dipinjam
                printf("Buku '%s' berhasil dipinjam.\n", perpustakaan[i].judul);
            } else {
                printf("Buku sudah dipinjam.\n");
            }
            ditemukan = 1;
            break;
        }
    }

    if (!ditemukan) {
        printf("Buku dengan ID %d tidak ditemukan.\n", id);
    }
}

void kbl_bk() {
    int id, terlambat, ditemukan = 0;
    printf("Masukkan ID Buku yang ingin dikembalikan: ");
    scanf("%i", &id);

    for (int i = 0; i < jumlahBuku; i++) {
        if (perpustakaan[i].id == id) {
            if (perpustakaan[i].dipinjam == 1) {
                printf("Masukkan jumlah hari keterlambatan: ");
                scanf("%i", &terlambat);

                perpustakaan[i].dipinjam = 0;  // Tandai buku sebagai dikembalikan
                printf("Buku '%s' berhasil dikembalikan.\n", perpustakaan[i].judul);

                if (terlambat > 0) {
                    printf("Anda terlambat %d hari. Denda sebesar Rp%d.\n", terlambat, terlambat * 1000);
                }
            } else {
                printf("Buku tersebut belum dipinjam.\n");
            }
            ditemukan = 1;
            break;
        }
    }

    if (!ditemukan) {
        printf("Buku dengan ID %d tidak ditemukan.\n", id);
    }
}

void keluar() {
    printf("Terima kasih Telah Mengunjungi dan Meminjam Buku di Perpustakaan Mini JONBOOK\n");
}
