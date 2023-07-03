#include <iostream>
using namespace std;

class bidangDatar {
private:
	int x, y; //variabel untuk menyimpan input dari lingkaran maupun bujursangkar
public:
	bidangDatar() { //constructor
		x = 0;
		y = 0;
	}
	virtual void input() {} // fungsi yang menerima input dan mengirim input melalui fungsi setX untuk disimpan di x dan atau setY untuk disimpan di y
	virtual float Luas() = 0; //fungsi untuk menghitung luas (pure virtual function)
	virtual float Keliling() = 0; //fungsi untuk menghitung keliling (pure virtual function)
	virtual void output() {}
	void setX(int a) {
		this->x = a;
	}
	int getX() {
		return x;
	}

	void setY(int b) { // encapsulasi
		this->y = b;
	}
	int getY() {  // encapsulasi
		return y;
	}
};

class Lingkaran : public bidangDatar {
public:
	void input() { //override fungsi input
		int r;
		cout << "Masukkan jari-jari lingkaran: ";
		cin >> r;
		setX(r); // encapsulasi
	}
	float Luas() { //override fungsi Luas
		float r = getX(); // encapsulasi
		return 3.14 * r * r;
	}
	float Keliling() { //override fungsi Keliling
		float r = getX(); // encapsulasi
		return 2 * 3.14 * r;
	}
	void output() {
		if (Keliling() <= 30) { // conditions
			cout << "Lingkaran berukuran kecil, dengan keliling: " << Keliling() << endl;
		}
		else
		{
			cout << "Lingkaran berukuran Besar, dengan keliling: " << Keliling() << endl;

		}
	}
};

class Persegipanjang : public bidangDatar {
public:
	void input() { //override fungsi input
		int p, l;
		cout << "Masukkan panjang persegipanjang: ";
		cin >> p;
		setX(p); // encapsulasi
		cout << "Masukkan lebar persegipanjang: ";
		cin >> l;
		setY(l); // encapsulasi
	}
	float Luas() { //override fungsi Luas
		float p = getX();// encapsulasi
		float l = getY(); // encapsulasi
		return p * l;
	}
	float Keliling() { //override fungsi Keliling
		float p = getX(); // encapsulasi
		float l = getY(); // encapsulasi
		return 2 * (p + l);
	}
	void output() {
		if (Keliling() <= 30) {
			cout << "Persegi berukuran kecil, dengan keliling: " << Keliling() << endl;
		}
		else
		{
			cout << "Persegi berukuran Besar, dengan keliling: " << Keliling() << endl;

		}
	}
};

int main() {
	bidangDatar* objek;
	char ch;
	do { //Looping

		// Lingkaran
		cout << "Lingkaran" << endl;
		Lingkaran lingkaran;
		objek = &lingkaran; // polymorphysm
		objek->input(); // polymorphysm
		cout << "Luas lingkaran: " << objek->Luas() << endl;
		cout << "Keliling lingkaran: " << objek->Keliling() << endl;
		objek->output();

		// Persegi Panjang
		cout << endl << "Persegi Panjang" << endl;
		Persegipanjang persegiPanjang;
		objek = &persegiPanjang; // polymorphysm
		objek->input(); // polymorphysm
		cout << "Luas persegi panjang: " << objek->Luas() << endl;
		cout << "Keliling persegi panjang: " << objek->Keliling() << endl;
		objek->output();


		cout << "Apakah anda ingin mengulang? (Y/N) ";
		cin >> ch;

	} while (ch == 'Y' || ch == 'y');
	return 0;
}
