#include <iostream>
using namespace std;

class MataKuliah {
private:
	float presensi;
	float activity;
	float exercise;
	float tugasAkhir;


public:
	// constructor
	MataKuliah() {
		presensi = 0;
		activity = 0;
		exercise = 0;
		tugasAkhir = 0;

	}

	void setPresensi(float nilai) {
		this->presensi = nilai;
	}

	float getPresensi() {
		return presensi;
	}

	void setActivity(float nilai) {
		this->activity = nilai;
	}

	float getActivity() {
		return activity;
	}

	void setExercise(float nilai) {
		this->exercise = nilai;
	}

	float getExercise() {
		return exercise;
	}

	void setTugasAkhir(float nilai) {
		this->tugasAkhir = nilai;
	}

	float getTugasAkhir() {
		return tugasAkhir;
	}

	virtual float hitungNilaiAkhir() = 0;
	virtual void cekKelulusan() = 0;
	virtual void input() = 0;
};

class Pemrograman : public MataKuliah { // inheritance
public:
	void input() {
		float presensi, activity, exercise, tugasAkhir;

		cout << "Masukkan nilai presensi: ";
		cin >> presensi;
		setPresensi(presensi); //enkapsulasi

		cout << "Masukkan nilai activity: ";
		cin >> activity;
		setActivity(activity); //enkapsulasi

		cout << "Masukkan nilai exercise: ";
		cin >> exercise;
		setExercise(exercise); //enkapsulasi

		cout << "Masukkan nilai tugas akhir: ";
		cin >> tugasAkhir;
		setTugasAkhir(tugasAkhir); //enkapsulasi
	}
	float hitungNilaiAkhir() {
		//enkapsulasi
		return  (getPresensi() * 10 / 100) + (getActivity() * 20 / 100) + (getExercise() * 30 / 100) + (getTugasAkhir() * 40 / 100);
	}

	void cekKelulusan() {
		float nilaiAkhir = hitungNilaiAkhir();
		if (nilaiAkhir >= 70) { // If Else
			cout << "Selamat, Anda lulus mata kuliah Pemrograman dengan nilai akhir " << nilaiAkhir << endl;
		}
		else {
			cout << "Maaf, Anda tidak lulus mata kuliah Pemrograman. Silakan coba lagi pada semester berikutnya." << "nilai anda: " << nilaiAkhir << endl;
		}
	}
};

int main() {
	MataKuliah* mataKuliah;
	char pilihan;

	do { // Looping
		mataKuliah = new Pemrograman();
		mataKuliah->input(); // polymorphysm
		mataKuliah->cekKelulusan(); // polymorphysm

		cout << "Apakah anda akan keluar? Tekan Y jika anda akan keluar";
		cin >> pilihan;

	} while (pilihan != 'Y' || pilihan != 'y');

	system("pause");

	return 0;
}
