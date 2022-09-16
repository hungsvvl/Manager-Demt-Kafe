#include <iostream>
#include <string>
using namespasce std;
struct NhanVien{
	string tenNV;
	string TgVoCa;
	string TgRoiCa;
	string TongTien;		
	
};
NhanVien NhapNV(){
	NhanVien x;
	cout <<"Nhap vao ten nhan vien : ";
	getline(cin, x.tenNV);		
}
NhanVien CaLam(){
	TgVoCa	x;
	cout <<"Nhap thoi gian vo ca lam : ";
	getline(cin, x.TgVoCa);
	return x;
}
int main (){
	
}
