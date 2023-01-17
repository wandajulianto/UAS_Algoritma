#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

string namaPetugas, namaCustomer, namaHewan, jenisLayanan;
int kodeLayanan, biaya, jumlahHewan, total, uangBayar, uangKembali;
char kodeHewan, dataInput;;
int no = 1;

void judul()
{
	cout << "\t\t\t======================================================================\n";
	cout << "\t\t\t\t\t SISTEM PEMBAYARAN PENITIPAN HEWAN \n";
	cout << "\t\t\t\t\t\t\"WXYZ PETSHOP\"\n";
	cout << "\t\t\t======================================================================\n";

}

void inputData()
{
	cout << "\tNama Petugas : ";
	cin >> namaPetugas;
	cout << "\tNama Customer : ";
	cin >> namaCustomer;
	cout << "\tNama Hewan : ";
	cin >> namaHewan;
	cout << "\tJenis Layanan : \n\t1. Lux\n \t2. Intensif\n \tPilih Jenis Layanan [1/2] : ";
	cin >> kodeLayanan;
	cout << "\tJumlah Hewan : ";
	cin >> jumlahHewan;
	cout << endl;

	kodeHewan = toupper((char)namaHewan[0]);

	if (kodeLayanan == 1) {
		jenisLayanan = "Lux";
		biaya = 250000;
	}
	else if (kodeLayanan == 2) {
		jenisLayanan = "Intensif";
		biaya = 300000;
	}
	else {
		cout << "\tMohon maaf menu layanan belum tersedia\n";
	}

	total = biaya * jumlahHewan;
}

void displayData()
{
	cout << "\tNama Petugas : " << namaPetugas << endl;
	cout << "\tNama Customer : " << namaCustomer << endl;

	cout << "\t=========================================================================================================\n";
	cout
		<< "\t"
		<< left << setw(5) << "NO"
		<< left << setw(13) << "Kode Hewan"
		<< left << setw(13) << "Nama Hewan"
		<< left << setw(17) << "Kode Perawatan"
		<< left << setw(18) << "Jenis Perawatan"
		<< left << setw(18) << "Biaya Perawatan"
		<< left << setw(15) << "Jumlah Hewan"
		<< left << setw(8) << "Total"
		<< endl
		<< "\t=========================================================================================================\n";

	for (int i = no; i < 10; i++) {
		cout
			<< "\t"
			<< left << setw(8) << i
			<< left << setw(12) << kodeHewan
			<< left << setw(18) << namaHewan
			<< left << setw(14) << kodeLayanan
			<< left << setw(18) << jenisLayanan
			<< left << setw(18) << biaya
			<< left << setw(11) << jumlahHewan
			<< left << setw(8) << total
			<< endl;
	}

	cout << "\t=========================================================================================================\n";
}

int main()
{
	judul();
	inputData();
	judul();
	displayData();


	return 0;
}