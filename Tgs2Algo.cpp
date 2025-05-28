#include <iostream>
#include <string>
using namespace std;

struct queue1
{
    string nama;
    string jenisRoti;
    int totalHarga;
    queue1 *next;
};

struct riwayat
{
    string nama;
    string jenisRoti;
    int totalHarga;
    riwayat *next;
};

queue1 *depan = NULL, *belakang = NULL;
riwayat *history = NULL;

void buatqueue()
{
    depan = NULL;
    belakang = NULL;
}

bool queuekosong()
{
    return (depan == NULL);
}

void enqueue(string nama, string jenisRoti, int totalHarga)
{
    queue1 *NB = new queue1();
    NB->nama = nama;
    NB->jenisRoti = jenisRoti;
    NB->totalHarga = totalHarga;
    NB->next = NULL;

    if (depan == NULL)
    {
        depan = NB;
    }
    else
    {
        belakang->next = NB;
    }
    belakang = NB;
    cout << "Pesanan berhasil ditambahkan\n";
}

void dequeue()
{
    if (queuekosong())
    {
        cout << "Queue masih kosong" << endl;
        return;
    }

    queue1 *hapus = depan;

    riwayat *baru = new riwayat();
    baru->nama = hapus->nama;
 baru->jenisRoti = hapus->jenisRoti;
    baru->totalHarga = hapus->totalHarga;
    baru->next = history;
    history = baru;

    cout << "Melayani: " << hapus->nama << " - " << hapus->jenisRoti << " - Rp" << hapus->totalHarga << endl;

    depan = depan->next;
    delete hapus;

    if (depan == NULL)
    {
        belakang = NULL;
    }
}

void cetakqueue()
{
    queue1 *bantu = depan;
    if (bantu == NULL)
    {
        cout << "Queue masih kosong!" << endl;
        return;
    }

    cout << "Isi Antrian:\n";
    while (bantu != NULL)
    {
        cout << bantu->nama << " - " << bantu->jenisRoti << " - Rp" << bantu->totalHarga << endl;
        bantu = bantu->next;
    }
}
void batalkanPesanan()
{
    if (depan == NULL)
    {
        cout << "Queue kosong, tidak ada yang bisa dibatalkan" << endl;
        return;
    }

    if (depan == belakang)
    {
        delete depan;
        depan = belakang = NULL;
    }
    else
    {
        queue1 *bantu = depan;
        while (bantu->next != belakang)
        {
            bantu = bantu->next;
        }
        delete belakang;
        belakang = bantu;
        belakang->next = NULL;
    }

    cout << "Pesanan terakhir di batalkan" << endl;
}

void cetakHistory()
{
    if (history == NULL)
    {
        cout << "Belum ada pesanan yang dilayani" << endl;
        return;
    }
cout << "Riwayat Pesanan\n";
    riwayat *bantu = history;
    while (bantu != NULL)
    {
        cout << bantu->nama << " - " << bantu->jenisRoti << " - Rp" << bantu->totalHarga << endl;
        bantu = bantu->next;
    }
}

int main()
{
    buatqueue();
    int pilihan;
    string nama, roti;
    int harga;

    do
    {
        cout << "\n==== Sistem Antrean Toko Roti Manis Lezat ====\n";
        cout << "1. Ambil Antrean\n";
        cout << "2. Layani Pembeli\n";
        cout << "3. Tampilkan Pesanan\n";
        cout << "4. Batalkan Pesanan Terakhir\n";
        cout << "5. Tampilkan Riwayat Pesanan\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan)
        {
        case 1:
            cout << "Nama: ";
 getline(cin, nama);
            cout << "Jenis Roti: ";
            getline(cin, roti);
            cout << "Total Harga: Rp";
            cin >> harga;
            enqueue(nama, roti, harga);
            system("pause");
            system("cls");
            break;
        case 2:
            dequeue();
            system("pause");
            system("cls");
            break;
        case 3:
            cetakqueue();
            system("pause");
            system("cls");
            break;
        case 4:
            batalkanPesanan();
            system("pause");
            system("cls");
            break;
        case 5:
            cetakHistory();
            system("pause");
            system("cls");
            break;
        case 0:
            cout << "Makasih kak telah mengunjungi Toko Roti Manis Lezat" << endl;
            break;
        default:
            cout << "Eror Kak" << endl;
 break;
        }
    } while (pilihan != 0);

    return 0;
}