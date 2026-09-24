#include <iostream>
#include <string>

using namespace std;

const int MAX_DAUSACH = 10000;

struct Date {
    int ngay;
    int thang;
    int nam;
};

struct MuonTra {
    string MASACH;
    Date NgayMuon;
    Date NgayTra;
    int trangThai;
};

struct nodeMuonTra {
    MuonTra data;
    nodeMuonTra* next;
};
typedef nodeMuonTra* PTRMuonTra;

struct TheDocGia {
    int MATHE;
    string Ho;
    string Ten;
    string Phai;
    int trangThai;
    PTRMuonTra dsmT = NULL;
};

struct nodeTheDocGia {
    TheDocGia data;
    nodeTheDocGia* left;
    nodeTheDocGia* right;
};
typedef nodeTheDocGia* treeTheDocGia;

struct DanhMucSach {
    string MASACH;
    int trangThai;
    string viTri;
};

struct nodeDanhMucSach {
    DanhMucSach data;
    nodeDanhMucSach* next;
};
typedef nodeDanhMucSach* PTRDanhMucSach;

struct DauSach {
    string ISBN;
    string tenSach;
    int soTrang;
    string tacGia;
    int namXuatBan;
    string theLoai;
    PTRDanhMucSach dms = NULL;
};

struct ListDauSach {
    DauSach* nodes[MAX_DAUSACH];
    int n = 0;
};

int main() {
    ListDauSach dsDauSach;
    treeTheDocGia dsTheDocGia = NULL;
    return 0;
}
