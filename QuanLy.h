#ifndef QUANLY_H
#define QUANLY_H
#include "MedicalItem.cpp"
#include "ToaThuoc.cpp"   
#include "Thuoc.cpp"

class QuanLy
{
    MedicalItem* toa;
    MedicalItem* thuoc;
    vector<ToaThuoc> dsToaThuoc;
    vector<Thuoc> dsThuoc;
public:
    QuanLy();
    void TaiDS();
    void LuuDS();
    vector<ToaThuoc> getDSToaThuoc();
    vector<Thuoc> getDSThuoc();
    void setDSToaThuoc(vector<ToaThuoc>);
    void setDSThuoc(vector<Thuoc>&);
    ~QuanLy();
};
#endif