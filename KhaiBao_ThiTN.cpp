#include<iostream>
#include<string>
using namespace std;
const int MAX_LOP=10000;


struct CHT_SV{
	int id;
	char chonluaSV;
};
struct NodeCHT_SV{
	CHT_SV data;
	NodeCHT_SV *next= nullptr;
};
typedef NodeCHT_SV * PTRCTBT;
struct DIEMTHI{
	string MAMH;
	float Diem;
	PTRCTBT dsCTBT=nullptr;
};

struct NodeDIEMTHI{
	DIEMTHI data;
	NodeDIEMTHI* Next=nullptr;
};
typedef NodeDIEMTHI* PTRDIEMTHI;
struct SINHVIEN{
	string HO, TEN, MASV, PHAi, PASSWORD;
	PTRDIEMTHI Diem=nullptr;
};
struct NodeSINHVIEN{
	SINHVIEN data;
	NodeSINHVIEN* next=nullptr;
};
typedef NodeSINHVIEN* PTRSINHVIEN;
struct LOP{
	string MALOP, TENLOP;
	PTRSINHVIEN Dssv=nullptr;
};
struct DsLOP{
	int n=0; //so luong lop
	LOP* nodes[MAX_LOP];
	DsLOP(){
		for(int i=0; i<MAX_LOP;i++){
			nodes[i]=nullptr;
		}
	}
};

PTRSINHVIEN timKiemSV(DsLOP &dslop, string maSV) {
    for (int i = 0; i < dslop.n; i++) {
        PTRSINHVIEN p = dslop.nodes[i]->Dssv;
        while (p != nullptr) {
            if (p->data.MASV == maSV) return p;
            p = p->next;
        }
    }
    return nullptr;
}

struct CAUHOI{
	int id;
	string NoiDung, a, b, c, d;
	char DapAn;
};
struct Node_CAUHOI{
	CAUHOI data;
	Node_CAUHOI* next=nullptr;
};
typedef Node_CAUHOI* PTRCAUHOI;

struct MONHOC{
	string MAMH, TENMH;
	PTRCAUHOI dsCHT=nullptr;
};
struct Node_MONHOC{
	MONHOC data;
	Node_MONHOC* right=nullptr;
	Node_MONHOC* left=nullptr;
};
typedef Node_MONHOC* treeMH;
//1.Dang nhap dua vao ma sinh vien hoac ma giao vien
int dangNhap(DsLOP &dslop, string &taiKhoanDangNhap) {
    string user, pass;
    cout << "Dang nhap" << endl;
    cout << "Tai khoan (Ma SV/GV): "; cin >> user;
    cout << "Mat khau: "; cin >> pass;

    // Kiem tra quyen Giang vien
    if (user == "GV" && pass == "GV") {
        cout << "Dang nhap thanh cong voi quyen GIANG VIEN (Toan quyen).\n";
        taiKhoanDangNhap = "GV";
        return 1;
	}PTRSINHVIEN sv = timKiemSV(dslop, user);
	// Kiem tra quyen Sinh vien	
    if (sv != nullptr && sv->data.PASSWORD == pass) {
        cout << "Dang nhap thanh cong voi Sinh vien: "
             << sv->data.HO << " " << sv->data.TEN << "\n";
        taiKhoanDangNhap = sv->data.MASV;
        return 2;
    }
	cout<<"Dang nhap khong thanh cong" <<endl;
	return 0;
}
//cau b
// Tim Kiem Lop Theo Ma Lop (Tra ve vi tri trong màng neu thay, nguoc lai tra ve -1)
int timKiemLop(DsLOP &dslop, string maLop) {
    for (int i = 0; i < dslop.n; i++) {
        if (dslop.nodes[i]->MALOP == maLop) {
            return i;
        }
    }
    return -1;
}
void nhapLop(DsLOP &dslop) {
    cout << "NHAP DANH SACH LOP \n";
    while (true) {
        // Kiem tra mang day
        if (dslop.n >= MAX_LOP) {
            cout << "Danh sach lop da day!\n";
            break;
        }

        string maLop;
        cout << "Nhap Ma Lop (Nhap '0' de dung): ";
        cin >> maLop;
        
        if (maLop == "0") break;

        // Kiem tra trung
        if (timKiemLop(dslop, maLop) != -1) {
            cout << "Ma lop '" << maLop << "' da ton tai! \n";
            continue;
        }

        //lop moi
        LOP* lopMoi = new LOP();
        lopMoi->MALOP = maLop;
        
        cout << "Nhap Ten Lop: ";
        cin.ignore(); // Xóa bộ đệm
        getline(cin, lopMoi->TENLOP);

        // Đưa con trỏ vào mảng và tăng số lượng lớp
        dslop.nodes[dslop.n] = lopMoi;
        dslop.n++;
        
        cout << " Them lop thanh cong!\n\n";
    }
}

// ================= HÀM NẠP DỮ LIỆU GIẢ ĐỂ TEST =================
void taoDuLieuGia(DsLOP &dslop) {
    // Tạo Lớp 1
    LOP* l1 = new LOP();
    l1->MALOP = "D19CQCN01";
    l1->TENLOP = "Lop Cong Nghe Thong Tin 1";

    // Sinh viên 1 (SV01 / pass: 123456)
    PTRSINHVIEN sv1 = new NodeSINHVIEN();
    sv1->data = {"SV01", "Nguyen Van", "A", "Nam", "123456", nullptr};
    sv1->next = l1->Dssv;
    l1->Dssv = sv1;

    // Sinh viên 2 (SV02 / pass: 654321)
    PTRSINHVIEN sv2 = new NodeSINHVIEN();
    sv2->data = {"SV02", "Tran Thi", "B", "Nu", "654321", nullptr};
    sv2->next = l1->Dssv;
    l1->Dssv = sv2;

    dslop.nodes[dslop.n++] = l1;
}
int main (){
	treeMH dsmh=nullptr;
	DsLOP dslop;
taoDuLieuGia(dslop);

    string userDangNhap = "";
    int quyen = 0;

    cout << "=== CHECK CHUC NANG DANG NHAP (CAU A) ===\n";
    cout << "Thu voi:\n";
    cout << " - Giang vien : User = GV   | Pass = GV\n";
    cout << " - Sinh vien 1: User = SV01 | Pass = 123456\n";
    cout << " - Sinh vien 2: User = SV02 | Pass = 654321\n";

    while (quyen == 0) {
        quyen = dangNhap(dslop, userDangNhap);
    }

    cout << "\n--> Dang nhap thanh cong, Quyen id = " << quyen 
         << " | Tai khoan: " << userDangNhap << endl;

    return 0;
}
