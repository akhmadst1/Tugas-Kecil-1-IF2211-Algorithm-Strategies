# Tugas kecil 1 Strategi Algoritma

## Daftar Isi

- [Tugas kecil 1 Strategi Algoritma](#tugas-kecil-1-strategi-algoritma)
  - [Daftar Isi](#daftar-isi)
  - [Author](#author)
  - [Deskripsi Persoalan](#deskripsi-persoalan)
  - [Struktur Program](#struktur-program)
  - [Cara Menjalankan Program](#cara-menjalankan-program)
  - [Library yang Digunakan](#library-yang-digunakan)

## Author

Akhmad Setiawan - 13521164 - K2

## Deskripsi Persoalan

Permainan Kartu 24 adalah permainan di mana pemain berusaha mengoperasikan 4 buah kartu remi dari A hingga K (direpresentasikan sebagai 1-13) duntuk menghubungkan keempat angka tersebut sehingga terbentuk sebuah angka 24. Permainan berakhir ketika pemain berhasil menemukan solusi untuk memperoleh nilai menjadi 24. Pengubahan nilai tersebut dapat dilakukan menggunakan operasi dasar matematika penjumlahan (+), pengurangan (-), perkalian (×), divisi (/) dan tanda kurung ( () ). Tiap kartu harus digunakan tepat sekali dan urutan penggunaannya dibebaskan.
Tugas kali ini adalah membuat penyelesaian solusi permainan kartu 24 ini menggunakan algoritma dengan pendekatan *brute force*.

## Struktur Program

```
├─── bin
│       │ main.exe
│
├─── doc
│       │ Tucil1_K2_13521164_Akhmad Setiawan.pdf
│       | Tucil1_K2_13521164_Akhmad Setiawan.docx
|
├─── src
│       │ main.cpp
│
├─── test
|        │ output solusi dalam bentuk .txt
|
|
│ .gitattributes
│ README.md
│ run.bat
```

## Cara Menjalankan Program

Untuk menjalankan program pada *root directory* di *Windows*, jalankan run.bat dengan perintah:
```
./run.bat
```
Program akan berjalan dengan diawali proses *compile main.cpp* lalu menjalankan *main.exe*
Pengguna dapat memasukkan input sesuai instruksi yang ada. Pengguna dapat memilih untuk menginput kartunya sendiri, atau ingin mendapatkan 4 random kartu untuk kemudian dicari solusi operasi yang menghasilkan nilai 24. Pengguna juga dapat menyimpan solusi hasil operasi ke dalam .txt file.

## Library yang Digunakan

1. iostream
2. cstdlib
3. string
4. vector
5. fstream
