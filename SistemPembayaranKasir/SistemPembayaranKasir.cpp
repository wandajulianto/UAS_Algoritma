#include <iostream>
#include <iomanip>
#include <cctype>
#include <vector>
#include <numeric>
#include <algorithm>
#include <string>
using namespace std;

struct Data {
	string namaHewan;
	int kodeLayanan, jumlahHewan, uangBayar, subTotal, biaya, uangKembali;
	char kodeHewan;
};

vector<Data> dataList;

string namaPetugas, namaCustomer, jenisLayanan;
int total;
char cekInputLagi, cekYT;
bool inputLagi = false;

void judul()
{
	cout
		<< "\t\t\t======================================================================\n"
		<< "\t\t\t\t\t SISTEM PEMBAYARAN PENITIPAN HEWAN \n"
		<< "\t\t\t\t\t\t\"SABO PETSHOP\"\n"
		<< "\t\t\t======================================================================\n";
}

void inputData()
{
	Data data;

	cout << "\tNama Petugas  : ";
	cin >> namaPetugas;
	cout << "\tNama Customer : ";
	cin >> namaCustomer;
	cout << "\tNama Hewan : ";
	cin >> data.namaHewan;
	cout << "\tJenis Layanan : \n\t1. Lux\n \t2. Intensif\n \tPilih Jenis Layanan [1/2] : ";
	cin >> data.kodeLayanan;
	cout << "\tJumlah Hewan : ";
	cin >> data.jumlahHewan;
	cout << endl;

	data.kodeHewan = toupper((char)data.namaHewan[0]);

	transform(data.namaHewan.begin(), data.namaHewan.end(), data.namaHewan.begin(), toupper);

	if (data.namaHewan == "HAMSTER") {
		data.biaya = data.kodeLayanan == 1 ? 50000 : 100000;
	}
	else {
		data.biaya = data.kodeLayanan == 1 ? 250000 : 300000;
	}

	data.subTotal = data.biaya * data.jumlahHewan;

	dataList.push_back(data);
}

void subJudul()
{
	cout << "\tNama Petugas  : " << namaPetugas << endl;
	cout << "\tNama Customer : " << namaCustomer << endl;
	cout << "\tInput Data Lagi [Y/T] : ";
	cin >> cekInputLagi;
	cout << endl;

	cekYT = toupper((char)cekInputLagi);

	if (cekYT == 'Y') {
		inputLagi = true;
	}
	else if (cekYT == 'T') {
		inputLagi = false;
	}
}

void displayData()
{
	cout << "\tNama Petugas  : " << namaPetugas << endl;
	cout << "\tNama Customer : " << namaCustomer << endl;
	cout << endl;

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

	for (int i = 0; i < dataList.size(); i++) {
		cout
			<< "\t"
			<< left << setw(8) << i + 1
			<< left << setw(12) << dataList[i].kodeHewan
			<< left << setw(18) << dataList[i].namaHewan
			<< left << setw(14) << dataList[i].kodeLayanan
			<< left << setw(18) << (dataList[i].kodeLayanan == 1 ? "Lux" : "Intensif")
			<< left << setw(18) << dataList[i].biaya
			<< left << setw(11) << dataList[i].jumlahHewan
			<< left << setw(8) << dataList[i].subTotal
			<< endl;
	}

	cout << "\t=========================================================================================================\n";

	total = accumulate(
		dataList.begin(),
		dataList.end(), 0,
		[] (int acc, Data p) {
			return acc + p.subTotal;
		}
	);

	cout << "\tTotal Bayar  : " << total << endl;
	cout << "\tUang Bayar   : ";
	cin >> dataList.back().uangBayar;
	
	while (dataList.back().uangBayar < dataList.back().subTotal) {
		cout << "\tMohon maaf uang tidak cukup, silahkan input kembali!\n";
		cout << "\tUang Bayar   : ";
		cin >> dataList.back().uangBayar;
	}

	cout << "\tUang Kembali : " << dataList.back().uangBayar - total << endl;
}

int main()
{
	do {
		judul();
		cout << endl;
		inputData();
		cout << endl;
		judul();
		cout << endl;
		subJudul();
	} while (inputLagi);

	judul();
	cout << endl;
	displayData();

	return 0;
}