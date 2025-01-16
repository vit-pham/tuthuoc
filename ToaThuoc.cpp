#include "ToaThuoc.h"

void ToaThuoc::setND()
{
    NoiDungToa.clear();
    string line;
    cout << "Nhap noi dung toa thuoc(nhap \"dung\" de dung nhap):\n";
    while (getline(cin, line) && line != "dung")
    {
        NoiDungToa.push_back(line);
    }
}
istream& ToaThuoc::Nhap(istream& in)
{
    MedicalItem::Nhap(in);
    string line;
    cout << "Nhap noi dung toa thuoc(nhap \"dung\" de dung nhap):\n";
    while (getline(cin, line) && line != "dung")
    {
        NoiDungToa.push_back(line);
    }
    return in;
}
istream& operator>>(istream& in, ToaThuoc& a)
{
    return a.Nhap(in);
}
void ToaThuoc::Xuat()
{
    MedicalItem::Xuat();
    cout << "\nNoi dung toa thuoc:\n";
    for (int i = 0; i < NoiDungToa.size(); i++)
    {
        cout << NoiDungToa[i] << "\n";
    }
}
void ToaThuoc::Luu(string tenTep)
{
    ofstream outFile(tenTep, ios::app);
    outFile << "START OF PRESCRIPTION\n";
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
    outFile << "\nNoi dung toa thuoc:\n";
    for (const auto& ndt : NoiDungToa)
    {
        outFile << ndt << "\n";
    }
    outFile << "END OF PRESCRIPTION\n";
    outFile.close();
}
void ToaThuoc::Tai(string tenTep, vector<ToaThuoc>& dsToaThuoc)
{
    ifstream inFile(tenTep);
    string line;
    ToaThuoc tt;
    while (getline(inFile, line))
    {
        if (line == "START OF PRESCRIPTION")
        {
            tt = ToaThuoc();
        }
        else if (line == "END OF PRESCRIPTION")
        {
            dsToaThuoc.push_back(tt);
        }
        else
        {
            size_t pos = line.find(':');
            string key = line.substr(0, pos);
            string value = line.substr(pos + 1);

            if (key == "Ten")
            {
                tt.Ten = value;
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
                    tt.Benh.push_back(token);
                }
            }
            else if (key == "Noi dung toa thuoc")
            {

            }
            else
            {
                tt.NoiDungToa.push_back(line);
            }
        }
    }
    inFile.close();
    ofstream outFile(tenTep, ios::trunc);
}