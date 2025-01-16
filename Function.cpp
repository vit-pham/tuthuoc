#include "QuanLy.h"

void chucnang1(QuanLy& ds)
{
    cin.ignore();
    bool co = 0;
    int ng, th, na;
    string kt;
    cout << "Nhap ten thuoc muon kiem tra han su dung: ";getline(cin, kt);
    for (int i = 0;i < ds.getDSThuoc().size();i++)
    {
        if (ds.getDSThuoc()[i].getTen() == kt)
        {
            cout << "Nhap ngay hom nay (Theo thu tu Ngay - Thang - Nam): ";
            cin >> ng >> th >> na;
            ds.getDSThuoc()[i].CanhBaoHSD(ng, th, na);
            co = 1;
            return;
        }
    }
    if (!co) cout << "Khong co thuoc nay trong tu!\n";
}
void chucnang2(QuanLy& ds)
{
    cin.ignore();
    bool co = 0;
    string ten;
    cout << "Nhap ten nguoi muon xem toa thuoc: ";
    getline(cin, ten);
    for (int i = 0;i < ds.getDSToaThuoc().size();i++)
    {
        if (ds.getDSToaThuoc()[i].getTen() == ten)
        {
            ds.getDSToaThuoc()[i].Xuat();
            cout << "\n";
            co = 1;
        }
    }
    if (!co) cout << "Khong co toa thuoc cua nguoi nay!\n";
}
void chucnang3(QuanLy& ds)
{
    int chon;
    string ten_capnhat;
    vector<ToaThuoc>dsToaThuoc = ds.getDSToaThuoc();
    vector<Thuoc>dsThuoc = ds.getDSThuoc();
    cout << "Ban muon cap nhat gi?\n" << "1.Thuoc\n" << "2.Toa thuoc\n";
    do
    {
        cin >> chon;
        if (chon != 1 && chon != 2) cout << "Lua chon khong hop le! Vui long nhap lai: ";
    } while (chon != 1 && chon != 2);
    if (chon == 1)
    {
        cout << "Ban muon lam gi voi thuoc?\n" << "1.Them\n" << "2.Sua\n" << "3.Xoa\n";
        do
        {
            cin >> chon;
            if (chon != 1 && chon != 2 && chon != 3) cout << "Lua chon khong hop le! Vui long nhap lai: ";
        } while (chon != 1 && chon != 2 && chon != 3);
        cin.ignore();
        if (chon == 1)
        {
            Thuoc moi;
            cout << "Nhap thong tin thuoc muon them\n";
            cin >> moi;
            moi.NhapHSD();
            dsThuoc.push_back(moi);
            cout << "Them thanh cong!\n";
            ds.setDSThuoc(dsThuoc);
        }
        if (chon == 2)
        {
            cout << "Nhap ten thuoc ban muon sua: ";getline(cin, ten_capnhat);
            for (int i = 0;i < dsThuoc.size();i++)
            {
                if (dsThuoc[i].getTen() == ten_capnhat)
                {
                    dsThuoc[i].Xuat();
                    cout << "\nBan muon sua gi?\n" << "1.Ten\n"
                        << "2.Benh lien quan (benh lien quan ban dau se bi xoa truoc khi sua)\n" << "3.So luong\n" << "4.HSD\n";
                    do
                    {
                        cin >> chon;
                        if (chon < 1 || chon>4) cout << "Lua chon khong hop le! Vui long nhap lai: ";
                    } while (chon < 1 || chon>4);
                    cin.ignore();
                    if (chon == 1) {
                        cout << "Nhap ten moi: ";
                        dsThuoc[i].setTen();
                    }
                    if (chon == 2) {
                        cout << "Nhap benh lien quan moi: ";
                        dsThuoc[i].setBenh();
                    }
                    if (chon == 3) {
                        cout << "Nhap so luong moi: ";
                        dsThuoc[i].setSL();
                    }
                    if (chon == 4) {
                        cout << "Nhap han su dung moi:\n";
                        dsThuoc[i].NhapHSD();
                    }
                    cout << "Sua thanh cong!\n";
                    ds.setDSThuoc(dsThuoc);
                    return;
                }
            }
            cout << "Khong co thuoc trong tu thuoc!\n";
            return;
        }
        if (chon == 3)
        {
            cout << "Nhap ten thuoc muon xoa: ";getline(cin, ten_capnhat);
            for (int i = 0;i < dsThuoc.size();i++)
            {
                if (dsThuoc[i].getTen() == ten_capnhat)
                {
                    dsThuoc.erase(dsThuoc.begin() + i);

                    cout << "Xoa thanh cong!\n";
                    ds.setDSThuoc(dsThuoc);
                    return;
                }
            }
            cout << "Khong co thuoc trong tu thuoc!\n";
            return;
        }
    }
    if (chon == 2)
    {
        cout << "Ban muon lam gi voi toa thuoc?\n" << "1.Them\n" << "2.Sua\n" << "3.Xoa\n";
        do
        {
            cin >> chon;
            if (chon != 1 && chon != 2 && chon != 3) cout << "Lua chon khong hop le! Vui long nhap lai: ";
        } while (chon != 1 && chon != 2 && chon != 3);
        cin.ignore();
        if (chon == 1)
        {
            ToaThuoc moi;
            cout << "Nhap thong tin toa thuoc muon them\n";
            cin >> moi;
            dsToaThuoc.push_back(moi);
            ds.setDSToaThuoc(dsToaThuoc);
            cout << "Them thanh cong!\n";
        }
        if (chon == 2)
        {
            bool co = 0;
            cout << "Nhap ten nguoi ban muon sua toa thuoc: ";getline(cin, ten_capnhat);
            for (int i = 0;i < dsToaThuoc.size();)
            {
                if (dsToaThuoc[i].getTen() == ten_capnhat)
                {
                    co = 1;
                    dsToaThuoc[i].Xuat();
                    cout << "Ban co muon sua toa thuoc nay?\n" << "1.Co\n" << "0.Khong\n";
                    do
                    {
                        cin >> chon;
                        if (chon != 1 && chon != 0) cout << "Lua chon khong hop le! Vui long nhap lai: ";
                    } while (chon != 1 && chon != 0);
                    cin.ignore();
                    if (chon == 1)
                    {
                        cout << "Ban muon sua gi?\n" << "1.Ten\n"
                            << "2.Benh lien quan (benh lien quan ban dau se bi xoa truoc khi sua)\n"
                            << "3.Noi dung toa thuoc (noi dung ban dau se bi xoa truoc khi sua)\n";
                        do
                        {
                            cin >> chon;
                            if (chon < 1 || chon>3) cout << "Lua chon khong hop le! Vui long nhap lai: ";
                        } while (chon < 1 || chon>3);
                        cin.ignore();
                        if (chon == 1) {
                            cout << "Nhap ten moi: ";
                            dsToaThuoc[i].setTen();
                        }
                        if (chon == 2) {
                            cout << "Nhap benh lien quan moi: ";
                            dsToaThuoc[i].setBenh();
                        }
                        if (chon == 3) {
                            cout << "Nhap noi dung toa thuoc moi: ";
                            dsToaThuoc[i].setND();
                        }
                        cout << "Sua thanh cong!\n";
                        ds.setDSToaThuoc(dsToaThuoc);
                    }
                    if (chon == 0)
                    {
                        ++i;
                        continue;
                    }
                }
            }
            if (!co)
            {
                cout << "Nguoi nay khong co toa thuoc trong tu thuoc!\n";
            }
            return;
        }
        if (chon == 3)
        {
            bool co = 0;
            cout << "Nhap ten nguoi ban muon xoa toa thuoc: ";getline(cin, ten_capnhat);
            for (int i = 0;i < dsToaThuoc.size();)
            {

                if (dsToaThuoc[i].getTen() == ten_capnhat)
                {
                    co = 1;
                    dsToaThuoc[i].Xuat();
                    cout << "Ban co muon xoa toa thuoc nay?\n" << "1.Co\n" << "0.Khong\n";
                    do
                    {
                        cin >> chon;
                        if (chon != 1 && chon != 0) cout << "Lua chon khong hop le! Vui long nhap lai: ";
                    } while (chon != 1 && chon != 0);
                    if (chon == 1)
                    {
                        dsToaThuoc.erase(dsToaThuoc.begin() + i);
                        cout << "Xoa thanh cong!\n";
                        ds.setDSToaThuoc(dsToaThuoc);
                    }
                    if (chon == 0)
                    {
                        ++i;
                        continue;
                    }
                }
            }
            if (!co) cout << "Nguoi nay khong co toa thuoc trong tu thuoc!\n";
        }
    }
}
void chucnang4(QuanLy& ds)
{
    cin.ignore();
    bool co = 0;
    string ten;
    cout << "Nhap ten thuoc muon xem thong tin: ";
    getline(cin, ten);
    for (int i = 0;i < ds.getDSThuoc().size();i++)
    {
        if (ds.getDSThuoc()[i].getTen() == ten)
        {
            ds.getDSThuoc()[i].Xuat();
            co = 1;
            return;
        }
    }
    if (!co) cout << "Khong co thuoc nay trong tu!\n";
}
void chucnang5(QuanLy& ds)
{
    cin.ignore();
    string tim_ten;
    bool co = 0;

    cout << "Nhap ten benh ban muon tim thuoc: ";getline(cin, tim_ten);
    cout << "Thuoc trong tu cho benh " << tim_ten << ":\n";
    for (int i = 0;i < ds.getDSThuoc().size();i++)
    {
        for (int j = 0;j < ds.getDSThuoc()[i].getBenh().size();j++)
        {
            if (ds.getDSThuoc()[i].getBenh()[j] == tim_ten)
            {
                co = 1;
                cout << ds.getDSThuoc()[i].getTen() << "\n";
                break;
            }
        }
    }
    if (!co) { cout << "Khong co thuoc nao trong tu lien quan den benh!\n"; }
}

void Menu(QuanLy& ds)
{
    while (true)
    {
        cout << "\t\t =========== MENU ===========\n";
        cout << "1.Canh bao han su dung\n";
        cout << "2.Xem thong tin toa thuoc\n";
        cout << "3.Cap nhat tu thuoc\n";
        cout << "4.Xem thong tin thuoc\n";
        cout << "5.Tim thuoc theo benh\n";
        cout << "0.Thoat va luu\n";
        cout << "\t\t ============================\n";

        int luachon;
        cout << "Nhap lua chon cua ban: ";
        cin >> luachon;
        if (luachon < 0 || luachon > 5)
        {
            cout << "Lua chon khong hop le! Vui long nhap lai:\n";
        }
        else if (luachon == 1)
        {
            cout << "Thuc hien chuc nang canh bao han su dung:\n";
            chucnang1(ds);
            while (true)
            {
                cout << "Ban co muon tiep tuc?\n";
                cout << "1.Co\n";
                cout << "0.Khong\n";
                int luachon2;
                cout << "Nhap lua chon cua ban: ";
                do {
                    cin >> luachon2;
                    if (luachon2 < 0 || luachon2 > 1)
                    {
                        cout << "Lua chon khong hop le! Vui long nhap lai: ";
                    }
                } while (luachon2 < 0 || luachon2 > 1);
                if (luachon2 == 1)
                {
                    chucnang1(ds);
                }
                if (luachon2 == 0)
                {
                    break;
                }
            }

        }
        else if (luachon == 2)
        {
            cout << "Thuc hien chuc nang xem thong tin toa thuoc:\n";
            chucnang2(ds);
            while (true)
            {
                cout << "Ban co muon tiep tuc?\n";
                cout << "1.Co\n";
                cout << "0.Khong\n";
                int luachon2;
                cout << "Nhap lua chon cua ban: ";
                do {
                    cin >> luachon2;
                    if (luachon2 < 0 || luachon2 > 1)
                    {
                        cout << "Lua chon khong hop le! Vui long nhap lai: ";
                    }
                } while (luachon2 < 0 || luachon2 > 1);
                if (luachon2 == 1)
                {
                    chucnang2(ds);
                }
                if (luachon2 == 0)
                {
                    break;
                }
            }
        }
        else if (luachon == 3)
        {
            cout << "Thuc hien chuc nang cap nhat tu thuoc:\n";
            chucnang3(ds);
            while (true)
            {
                cout << "Ban co muon tiep tuc?\n";
                cout << "1.Co\n";
                cout << "0.Khong\n";
                int luachon2;
                cout << "Nhap lua chon cua ban: ";
                do {
                    cin >> luachon2;
                    if (luachon2 < 0 || luachon2 > 1)
                    {
                        cout << "Lua chon khong hop le! Vui long nhap lai: ";
                    }
                } while (luachon2 < 0 || luachon2 > 1);
                if (luachon2 == 1)
                {
                    chucnang3(ds);
                }
                if (luachon2 == 0)
                {
                    break;
                }
            }
        }
        else if (luachon == 4)
        {
            cout << "Thuc hien chuc nang xem thong tin thuoc:\n";
            chucnang4(ds);
            while (true)
            {
                cout << "Ban co muon tiep tuc?\n";
                cout << "1.Co\n";
                cout << "0.Khong\n";
                int luachon2;
                cout << "Nhap lua chon cua ban: ";
                do {
                    cin >> luachon2;
                    if (luachon2 < 0 || luachon2 > 1)
                    {
                        cout << "Lua chon khong hop le! Vui long nhap lai: ";
                    }
                } while (luachon2 < 0 || luachon2 > 1);
                if (luachon2 == 1)
                {
                    chucnang4(ds);
                }
                if (luachon2 == 0)
                {
                    break;
                }
            }
        }
        else if (luachon == 5)
        {
            cout << "Thuc hien chuc nang tim thuoc theo benh:\n";
            chucnang5(ds);
            while (true)
            {
                cout << "Ban co muon tiep tuc?\n";
                cout << "1.Co\n";
                cout << "0.Khong\n";
                int luachon2;
                cout << "Nhap lua chon cua ban: ";
                do {
                    cin >> luachon2;
                    if (luachon2 < 0 || luachon2 > 1)
                    {
                        cout << "Lua chon khong hop le! Vui long nhap lai: ";
                    }
                } while (luachon2 < 0 || luachon2 > 1);
                if (luachon2 == 1)
                {
                    chucnang5(ds);
                }
                if (luachon2 == 0)
                {
                    break;
                }
            }
        }
        else
        {
            break;
        }
    }
}



//////////
