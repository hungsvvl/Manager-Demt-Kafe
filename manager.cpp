#include <iostream>
#include <string>
using namespace std;
class NhanVien {

protected:
    string HoTen;
    int NamVaoLam;
public:
    NhanVien() {
        HoTen = "";
        NamVaoLam = 0;

    }
    virtual void NhapTT();
    virtual void XuatTT();

};
void NhanVien::NhapTT() {
    cout << "ho ten:";
    getline(cin, HoTen);
    cout << "nam vao lam :";
    cin >> NamVaoLam;


}
void NhanVien::XuatTT() {
    cout << "Ho ten :" << HoTen << endl;

}
class NhanVienSanXuat : public NhanVien {
private:
    int Sosanpham;
public:
    NhanVienSanXuat() {
        Sosanpham = 0;

    }
    void NhapTT();
    void XuatTT();
    int TinhLuong=0;
};
void NhanVienSanXuat::NhapTT() {
    NhanVien::NhapTT();
    cout << "so san pham";
    cout << "luong" << TinhLuong();

}
int NhanVienSanXuat::TinhLuong() {
    int Luong = 0;
    Luong = (Sosanpham * 10000 ) + (100000 + ((2016 - NamVaoLam) * 2000));
    return Luong;

}
class NhanVienVanPhong : public NhanVien{
    private:
        int MucLuong, SoNgayNghi;
        public:
            NhanVienVanPhong() {
                MucLuong = 0;

            }
            void NhapTT();
            void XuatTT();
            int TinhLuong;
};
void NhanVienVanPhong::NhapTT() {
    NhanVien::NhapTT();
    cout << "Muc luong";
    cin >> MucLuong;
    cout << "so ngay nghi";
    cin >> SoNgayNghi;
    
}
void NhanVienVanPhong::XuatTT() {
    NhanVien::XuatTT();
    cout << "muc luong" << MucLuong << endl;
    cout << "so ngay nghi" << SoNgayNghi << endl;
    cout<<"luong"<<TinhLuong();
}
int NhanVienVanPhong::TinhLuong() {
    int Luong = 0;
    Luong = MucLuong - SoNgayNghi * 10000 + 100000 + ((2016 - NamVaoLam) * 20000);
    return Luong;
}
class QuanLyNhanVien {
private:
    vector<NhanVien*> dsNhanVien;
    void NhapDanhSach();
    void XuatDanhSach();
    

};
void QuanLyNhanVien::NhapDanhSach() {
    int chon;
    NhanVien* nv;
    do{
        system("cls");
        cout << "1.Nhan vien san xuat" << endl;
        cout << "2. Nhan vien van phong" << endl;
        cout << "0. Thoat" << endl;
        cin >> chon;
        switch (chon) {
        case 1:
        {
            nv = new NhanVienSanXuat();
            nv->NhapTT();
            dsNhanVien.push_back(nv);
            break;

        }
        case 2: 
        {
            nv = new NhanVienVanPhong();
            nv->NhapTT();
            dsNhanVien.push_back(nv);
            break;
        }
        case 3:
        {
            break;
        }
    }
        }while (chon != 0);

}
void QuanLyNhanVien::XuatDanhSach(){
    for (int i = 0; i < dsNhanVien.size(); i++) {
        dsNhanVien[i]->XuatTT();
        cout << "========================" << endl;
    }

int main(){
int chon;
do
{
	system("cls");
	cout<<"1. nhap nv"<<endl;
	cout<<"2. xuat nv"<<endl;
	cout<<"moi chon";
	cin>>chon;
	switch(chon){
	case 1:
		{
			QLNV.NhapDanhSach();
			break;
		}
		case 2:
			{
				QLNV.XuatDanhSach();
				system("pause");
				break;
			}
	}while(chon !=0);
}}
