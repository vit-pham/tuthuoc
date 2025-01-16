#include "QuanLy.h"

QuanLy::QuanLy()
{
    toa = nullptr;
    thuoc = nullptr;
}
void QuanLy::TaiDS()
{
    toa = new ToaThuoc();
    thuoc = new Thuoc();
    toa->Tai("toathuoc.txt", dsToaThuoc);
    thuoc->Tai("thuoc.txt", dsThuoc);
}
void QuanLy::LuuDS()
{
    for (int i = 0;i < dsToaThuoc.size();i++)
    {
        dsToaThuoc[i].Luu("toathuoc.txt");
    }
    for (int i = 0;i < dsThuoc.size();i++)
    {
        dsThuoc[i].Luu("thuoc.txt");
    }
}
vector<ToaThuoc> QuanLy::getDSToaThuoc()
{
    return dsToaThuoc;
}
vector<Thuoc> QuanLy::getDSThuoc()
{
    return dsThuoc;
}
void QuanLy::setDSToaThuoc(vector<ToaThuoc> ds_toa)
{
    dsToaThuoc = ds_toa;
}
void QuanLy::setDSThuoc(vector<Thuoc>& ds_thuoc)
{
    dsThuoc = ds_thuoc;
}
QuanLy::~QuanLy()
{
    if (toa != nullptr)
    {
        delete toa;
    }
    if (thuoc != nullptr)
    {
        delete thuoc;
    }
}