#ifndef THUOC_H
#define THUOC_H
#include "MedicalItem.h"

class Thuoc : public MedicalItem
{
    string soLuong;
    string ngay, thang, nam;
public:
    void setSL();
    friend istream& operator>>(istream&, Thuoc&);
    istream& Nhap(istream&) override;
    void NhapHSD();
    void CanhBaoHSD(int, int, int);
    void Tai(string, vector<Thuoc>&) override;
    void Xuat() override;
    void Luu(string);
};
#endif