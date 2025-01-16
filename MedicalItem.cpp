#include "MedicalItem.h"

void MedicalItem::setTen() { getline(cin, Ten); }
void MedicalItem::setBenh() {
    Benh.clear();
    string line;
    getline(cin, line);
    stringstream ss(line);
    string token;
    while (getline(ss, token, ','))
    {
        size_t first = token.find_first_not_of(' ');
        size_t last = token.find_last_not_of(' ');
        token = token.substr(first, (last - first + 1));
        Benh.push_back(token);
    }
}
string MedicalItem::getTen() { return Ten; }
istream& MedicalItem::Nhap(istream& in)
{
    string line;
    cout << "Nhap ten: "; getline(in, Ten);
    cout << "Nhap benh lien quan: "; getline(in, line);
    stringstream ss(line);
    string token;
    while (getline(ss, token, ','))
    {
        size_t first = token.find_first_not_of(' ');
        size_t last = token.find_last_not_of(' ');
        token = token.substr(first, (last - first + 1));
        Benh.push_back(token);
    }
    return in;
}
void MedicalItem::Xuat()
{
    cout << "Ten: " << Ten << "\n";
    cout << "Benh lien quan: ";
    for (int i = 0; i < Benh.size(); i++)
    {
        cout << Benh[i];
        if (i != Benh.size() - 1)
        {
            cout << ", ";
        }
    }
}
vector<string> MedicalItem::getBenh() { return Benh; }
void MedicalItem::Tai(string tenTep, vector<ToaThuoc>& dsToaThuoc) { return; }
void MedicalItem::Tai(string tenfile, vector<Thuoc>& dsThuoc) { return; }