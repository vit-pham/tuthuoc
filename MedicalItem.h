#ifndef MEDICALITEM_H
#define MEDICALITEM_H
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

class Thuoc;
class ToaThuoc;

class MedicalItem
{
protected:
    string Ten;
    vector<string> Benh;
public:
    void setTen();
    void setBenh();
    string getTen();
    virtual istream& Nhap(istream&);
    virtual void Xuat();
    vector<string> getBenh();
    virtual void  Luu(string) = 0;
    virtual void Tai(string, vector<ToaThuoc>&);
    virtual void Tai(string, vector<Thuoc>&);
};
#endif