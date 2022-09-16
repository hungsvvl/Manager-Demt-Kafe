// sinh vien: ten, tuoi, diem ktlt

// hanh dong: nhap, xuat, so sanh diem 2 sinh vien

#include<iostream>

using namespace std;

class SinhVien{

	private:

		char Ten[10];

		int Tuoi;

		float Diem;

	public:

		float getDiem();

		void nhap();

		void xuat();

		void SoSanh1(SinhVien sv1);

};

float SinhVien::getDiem(){

	return Diem;

}

void SinhVien::nhap(){

	cout<<"Nhap ten: ";

	cin>>Ten;

	cout<<"Nhap tuoi: ";

	cin>>Tuoi;

	cout<<"Nhap diem: ";

	cin>>Diem;

}

void SinhVien::xuat(){

	cout<<"Ten: "<<Ten<<endl;

	cout<<"Tuoi: "<<Tuoi<<endl;

	cout<<"Diem: "<<Diem<<endl;

}

// Thiet ke ham so sanh la ham ngoai lop

void SoSanh(SinhVien sv1, SinhVien sv2){

	if(sv1.getDiem() == sv2.getDiem())

		cout<<"Bang nhau";

	else if(sv1.getDiem() > sv2.getDiem())

		cout<<"Lon hon";

	else

		cout<<"Be hon";

}

// Thiet ke ham so sanh la phuong thuc cua lop

void SinhVien::SoSanh1(SinhVien sv1){

	if(Diem == sv1.Diem)

		cout<<"Bang nhau";

	else if(Diem > sv1.Diem)

		cout<<"Lon hon";

	else

		cout<<"Be hon";

}

int main(){

	SinhVien sv1, sv2;

	sv1.nhap();

	sv2.nhap();

	cout<<"\nDiem cua sv1 ";

	//SoSanh(sv1,sv2);

	sv1.SoSanh1(sv2);

	cout<<" diem cua sv2";

}

