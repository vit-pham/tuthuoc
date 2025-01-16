#include "Thuoc.h"

void Thuoc::setSL() { cin >> soLuong; }
istream& operator>>(istream& in, Thuoc& a)
{
    return a.Nhap(in);
}
istream& Thuoc::Nhap(istream& in)
{
    MedicalItem::Nhap(in);
    cout << "Nhap so luong thuoc: ";
    in >> soLuong;
    return in;
}
void Thuoc::NhapHSD()
{
    cout << "Nhap han su dung cua loai thuoc nay (Theo thu tu Ngay - Thang - Nam): ";
    cin >> ngay >> thang >> nam;
}
void Thuoc::CanhBaoHSD(int ng, int th, int na)
{
    int new_ngay = stoi(ngay);
    int new_thang = stoi(thang);
    int new_nam = stoi(nam);
    bool kt;
    if (new_nam < na)
    {
        kt = 0;
    }
    else if (new_nam > na)
    {
        kt = 1;
    }
    else if (new_thang < th)
    {
        kt = 0;
    }
    else if (new_thang > th)
    {
        if (new_thang - th == 1)
        {
            cout << "Thuoc nay sap het han. Hay chu y!\n";
            return;
        }
        kt = 1;
    }
    else if (new_ngay <= ng)
    {
        kt = 0;
    }
    else
    {
        cout << "Thuoc nay sap het han. Hay chu y!\n";
        return;
    }
    if (kt)
    {
        cout << "Thuoc nay van con han su dung. Ban co the su dung binh thuong!\n";
    }
    else cout << "Thuoc nay da het han su dung. Vui long dung su dung!\n";

    return;
}
void Thuoc::Tai(string tenfile, vector<Thuoc>& dsThuoc)
{
    ifstream inFile(tenfile);
    string line;
    Thuoc t;
    while (getline(inFile, line))
    {
        if (line == "START OF MEDICINE")
        {
            t = Thuoc();
        }
        else if (line == "END OF MEDICINE")
        {
            dsThuoc.push_back(t);
        }
        else
        {
            size_t pos = line.find(':');
            string key = line.substr(0, pos);
            string value = line.substr(pos + 1);

            if (key == "Ten")
            {
                t.Ten = value;
            }
            else if (key == "Benh")
            {
                stringstream ss(value);
                string token;
                while (getline(ss, token, ','))
                {
                    size_t first = token.find_first_not_of(' ');
                    size_t last = token.find_last_not_of(' ');
                    token = token.substr(first, (last - first + 1));
                    t.Benh.push_back(token);
                }
            }
            else if (key == "So luong")
            {
                t.soLuong = value;
            }
            else
            {
                stringstream ss(value);
                getline(ss, t.ngay, '/');
                getline(ss, t.thang, '/');
                getline(ss, t.nam);
            }
        }
    }
    inFile.close();
    ofstream outFile(tenfile, ios::trunc);
}
void Thuoc::Xuat()
{
    MedicalItem::Xuat();
    cout << "\nSo luong: " << soLuong;
    cout << "\nHSD: " << ngay << "/" << thang << "/" << nam;

}
void Thuoc::Luu(string tenTep)
{
    ofstream outFile(tenTep, ios::app);
    outFile << "START OF MEDICINE\n";
    outFile << "Ten:" << Ten << "\n";
    outFile << "Benh:";
    for (int i = 0; i < Benh.size(); i++)
    {
        outFile << Benh[i];
        if (i != Benh.size() - 1)
        {
            outFile << ", ";
        }
    }
    outFile << "\nSo luong:";
    outFile << soLuong;
    outFile << "\nHSD:";
    outFile << ngay << "/" << thang << "/" << nam << "\n";
    outFile << "END OF MEDICINE\n";
    outFile.close();
}