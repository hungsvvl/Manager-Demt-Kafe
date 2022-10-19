#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <conio.h>
#include <iomanip>
class sach;
class dausach;
class phieumuon;
class bandoc {
    friend class phieumuon;
private:
    char* ten;
    char* ma;
    phieumuon* sachmuon[5];
    int somuon;
    static int sobandoc;
    static bandoc* cacbandoc[100];
public:
    bandoc(char* m, char* t)
    {
        ma = new char[strlen(m) + 1];
        ten = new char[strlen(t) + 1];
        strcpy(ma, m);
        strcpy(ten, t);
        somuon = 0;
    }
    ~bandoc()
    {
        delete[] ma;
        delete[] ten;
    }
    static void dangki();
    static bandoc* timbd(char*);
    phieumuon* muon(char*);
    void tra(dausach*);
    static void xoadl();
    void muon(dausach* dausach);
    static void inds();
};
class sach
{
    friend class dausach;
private:
    char* ma;
    char* ten;
    int sodausach;
    dausach** cacdausach;
    static int sosach;
    static sach* khosach[500];
public:
    sach(char* m, char* t, int n);
    ~sach();
    dausach* timchuamuon();
    static sach* timsach(char* masach);
    static dausach* timdausach(char*, int);
    static void nhapsach();
    static void xoadl();
    static void inds();
};
class phieumuon
{
    friend class bandoc;
private:
    dausach* dausach1;
    bandoc* bandoc1;
public:
    phieumuon(dausach* ds, bandoc* bd) :
        dausach1(ds), bandoc1(bd)
    {
    }
};
class dausach
{
    friend class phieumuon;
    friend class bandoc;
    friend class sach;
private:
    sach* sach1;
    int id;
    phieumuon* muon;
public:
    dausach(sach* right, int _id)
        : sach1(right), id(_id), muon(0)
    {
    }
    ~dausach()
    {
        if (muon) delete muon;
    }
    int chuamuon()
    {
        return muon == 0;
    }
    phieumuon* chomuon(bandoc* bd)
    {
        muon = new phieumuon(this, bd);
        return muon;
    }
    void tra()
    {
        delete[] muon;
        muon = 0;
    }
};
int bandoc::sobandoc = 0;
bandoc* bandoc::cacbandoc[100];
void bandoc::dangki()	
{
	int k;
    char ma[80];
    cin.getline(ma, sizeof(k));
    cout << "Ma ban doc : ";
    cin.getline(ma, sizeof(ma));
    char ten[80];
    cout << "Ten ban doc : ";
    cin.getline(ten, sizeof(ten));
    cacbandoc[sobandoc++] = new bandoc(ma, ten);
    cout << " Ban doc " << ten << " voi ma so la "<< ma << " da duoc dang ki "<<endl;
}
bandoc* bandoc::timbd(char* ma)
{
    for (int i = 0; i < sobandoc; i++)
        if (strcmp(ma, cacbandoc[i]->ma) == 0)
            return cacbandoc[i];
    return 0;
}
void bandoc::xoadl()
{
    for (int i = 0; i < sobandoc; i++)
        delete[] cacbandoc[i];
    sobandoc = 0;
}
phieumuon* bandoc::muon(char* masach)
{
    if (somuon == 5)
    {
        cout << "Ban da muon du 5 dau sach \n";
        return 0;
    }
    sach* sach = sach::timsach(masach);	
    if (sach == 0)
    {
        cout << "Khong co ma sach " << masach << " trong kho \n";
        return 0;
    }
    dausach* dausach = sach->timchuamuon();
    if (dausach == 0)
    {
        cout << "Sach nay da bi muon het \n";
        return 0;
    }
    phieumuon* phieu = dausach->chomuon(this);
    sachmuon[somuon++] = phieu;
    cout << "Ban da duoc dau sach so " << dausach->id << endl;
    return phieu;
}
void bandoc::muon(dausach* dausach)
{
    sachmuon[somuon++] = dausach->chomuon(this);
}
void bandoc::tra(dausach* right)
{
    for (int i = 0; i < somuon; i++)
        if (sachmuon[i]->dausach1 == right)
        {
            right->tra();
            for (int j = i + 1; j < somuon; j++)
                sachmuon[j - 1] = sachmuon[j];
            somuon--;
            cout << "Ban da tra xong sach \n";
            return;
        }
    cout << "Ban da ko muon quyen sach nay \n";
}
void bandoc::inds()

{
	if (sobandoc==0){
         cout<<"khong co ban doc nao trong thu vien"<<endl;
     }
    else {
		cout << "Ma\tTen\tSomuon"<<endl;
    	for (int i = 0; i < sobandoc; i++)
        	cout << cacbandoc[i]->ma << "\t" << cacbandoc[i]->ten << "\t" << cacbandoc[i]->somuon<<endl;
     }
}

int sach::sosach = 0;
sach* sach::khosach[500];
sach::sach(char* ma_, char* ten_, int n)
{
    ma = new char[strlen(ma_) + 1];
    ten = new char[strlen(ten_) + 1];
    strcpy(ma, ma_);
    strcpy(ten, ten_);
    sodausach = n;
    cacdausach = new dausach * [sodausach];
    for (int i = 0; i < sodausach; i++)
        cacdausach[i] = new dausach(this, i + 1);
}
sach::~sach()
{
    delete[] ma;
    delete[] ten;
    for (int i = 0; i < sodausach; i++)
        delete cacdausach[i];
    delete[] cacdausach;
}
dausach* sach::timchuamuon()
{
    for (int i = 0; i < sodausach; i++)
        if (cacdausach[i]->chuamuon())
            return cacdausach[i];
    return 0;
}
sach* sach::timsach(char* masach)
{
    for (int i = 0; i < sosach; i++)
        if (strcmp(khosach[i]->ma, masach) == 0)
            return khosach[i];
    return 0;
}
dausach* sach::timdausach(char* masach, int id)
{
    sach* sach1 = timsach(masach);
    if (sach1 == 0) return 0;
    for (int i = 0; i < sach1->sodausach; i++)
        if (sach1->cacdausach[i]->id == id)
            return sach1->cacdausach[i];
    return 0;
}
void sach::nhapsach()
{
	int h;
    char ma[80];
    cin.getline(ma, sizeof(h));
    cout << "Ma sach :";
    cin.getline(ma, sizeof(ma));
    char ten[80];
    cout << "Ten sach : ";
    cin.getline(ten, sizeof(ten));
    int n;
    cout << "So dau sach : ";
    cin >> n;
    cin.ignore(1);
    khosach[sosach++] = new sach(ma, ten, n);
    cout << "Sach nay da duoc nhap vao \n";
}
void sach::xoadl()
{
    for (int i = 0; i < sosach; i++)
        delete khosach[i];
    sosach = 0;
}
void sach::inds()
{
	if(sosach==0){
        cout<<"khong co sach nao duoc nhap vao"<<endl;
    }
    else {
    	cout << "Ma sach\tTen sach\tSo dau sach"<<endl;
    	for (int i = 0; i < sosach; i++){
    		cout << khosach[i]->ma  << " \t" <<  khosach[i]->ten  << " \t" << khosach[i]->sodausach<<endl;
		}
}
}
void muon()
{	int k;
	
    char mabd[80];
    cin.getline(mabd, sizeof(k));
    cout << "Ma ban doc : ";
    cin.getline(mabd, sizeof(mabd));
    bandoc* bd = bandoc::timbd(mabd);
    if (bd == 0)
    {
        cout << "Ma ban doc nay chua duoc dang ki \n ";
        return;
    }
    char mas[80];
    cout << "Ma sach muon : ";
    cin.getline(mas, sizeof(mas));
    bd->muon(mas);
}
void tra()
{
    char mabd[80], mas[80];
    cout << "Ma ban doc : ";
    cin.getline(mabd, sizeof(mabd));
    bandoc* bd = bandoc::timbd(mabd);
    if (bd == 0)
    {
        cout << "Ma ban doc nay chua duoc dang ki \n";
        return;
    }
    cout << "Ma sach tra : ";
    cin.getline(mas, sizeof(mas));
    int id;
    cout << "Ma dau sach : ";
    cin >> id;
    dausach* ds = sach::timdausach(mas, id);
    if (ds == 0)
    {
        cout << " ko co dau sach nay \n ";
        return;
    }
    bd->tra(ds);
}
int main() {
	int u;
	do{
	system ("cls");
	 		cout << "************************************"<<endl;
	 		cout << "*             MENU                 *"<<endl;
	    	cout << "* 1. Dang ki ban doc               *"<<endl;
	    	cout << "* 2. Nhap sach                     *"<<endl;
	    	cout << "* 3. Muon sach                     *"<<endl;
	    	cout << "* 4. Tra sach                      *"<<endl;
	    	cout << "* 5. Danh sach ban doc             *"<<endl;
	    	cout << "* 6. Danh sach sach                *"<<endl;
	    	cout << "* 0. Thoat khoi chuong trinh       *"<<endl;
	    	cout << "************************************"<<endl;
	    	cout << "chon cong viec ban muon thuc hien: ";
    cin >> u;
     switch(u){

    case 1 : 
    {
	
      bandoc::dangki();
      system("pause");
      break;
  }
      case 2: 
      {
      	sach::nhapsach();
      	system("pause");
      	break;
      }
    case 3:
    	{
      	muon();
      	system("pause");
    break;
}
    case 4 :
	{
    	tra();
		system("pause");
		break;
	}

    case 5: 
	{
			bandoc::inds();
			system("pause");
		break;
  }

    case 6:
    	{
      	sach::inds();
      	system("pause");
    break;
}
    case 0:
    	{
		
    break;
}
    default: "nhap lai";
    system("pause");
    break;
  }
  }while(u!=0);
  system("pause");
  return 0;	
}
