#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
class nv {

  
  private :
  int mnv;
  string hoten, gioitinh;
  double tgbatdau, tgketthuc;
  public:
  nv(){}
  virtual void nhap();
  virtual void xuat();
  
  
};

void nv::nhap() {
  fflush(stdin);
    cout<<"ma nhan vien "<<endl;
    cin>>mnv;
    cout<<"ho ten nhan vien: ";
    getline(cin,hoten);
    cout<<"gioi tinh";
    getline(cin,gioitinh);
    cout<<"nhap thoi gian bat dau";
    cin>>tgbatdau;
    cout<<"nhap thoi gian ket thuc";
      cin>>tgketthuc;
}
class nvpvu : public nv  {
private:
  int tgbatdau, tgketthuc;
public:
  nvpvu(){
    tgbatdau=0;
    tgketthuc=0;
  }
  void nhap();
  void xuat();
  int tglam();
};
void nvpvu::nhap(){
  int a,gio, phut, Gio, Phut;
double  tl, tienluong=20000, b;
int tien;
long tg1, tg2, tongtg;
cout << "tg vao lam" << endl;
cout << "gio" << endl;
cin >> gio;
cout << "phut" << endl;
cin >> phut;
tg1 = 60 * gio + phut;
cout << "tg ket thuc" << endl;
cout << "gio" << endl;
cin >> Gio;
cout << "phut" << endl;
cin >> Phut;
tg2 = 60 * Gio + Phut;
tongtg = (tg2 - tg1);
a=tongtg/60;
b=tongtg%60;
cout << "tong thoi gian lam cua ban la" <<" gio "<<b<<"phut " <<endl;
double c=a+b/60;
tl=c*tienluong;
  
}


int main() {
  int u,n;
  cout<<"vui long lua chon cac gia tri sau";
  cin>>u;
  cout<<"1. Nhap thong tin"<<endl;
  cout<<"2. xuat thong tin"<<endl;
  cout<<"3. tim nhan vien"<<endl;
  cout<<"4. tinh luong nhan vien "<<endl;
  switch(u){
  
  do{
    system ("cls");
    case 1 : 
      nv::nhap();
      break;
    default: "nhap lai";
  }
  while(u!=0);
}
}
