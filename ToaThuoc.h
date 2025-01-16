#ifndef TOATHUOC_H
#define TOATHUOC_H
#include "MedicalItem.h"

class ToaThuoc : public MedicalItem
{
    vector<string> NoiDungToa;
public:
    void setND();
    istream& Nhap(istream&) override;
    friend istream& operator>>(istream&, ToaThuoc&);
    void Xuat() override;
    void Luu(string);
    void Tai(string, vector<ToaThuoc>&) override;
};
#endif