#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;

class bus
{
private:
    string b_no, b_name, d_name;
    int b_seats;

public:
    void menu();
    void new_bus();
    void view_bus();
    void single_bus_view();
    void all_bus_view();
    void update_bus();
    void delete_bus();
    void routes_bus();
    void seats_details();
    void booking();
    void renew_bus();
    void search_booking();
    void update_booking();
    void del_booking();
    void show_booking();
};

void bus ::menu()
{
p:
    system("cls");
    int choice;
    cout << "\n\n\t\t\t\t _____BUS MANAGEMENT SYSTEM_____ ";
    cout << "\n\n\n ****Main Menu****";
    cout << "\n\n\n 1. ADD BUS RECORD";
    cout << "\n 2. VIEW BUS DETAIL";
    cout << "\n 3. UPDATE BUS DETAIL";
    cout << "\n 4. DELETE BUS DETAIL";
    cout << "\n 5. ROUTES OF BUSES";
    cout << "\n 6. BUS SEATS DETAILS";
    cout << "\n 7. BOOKING RECORD";
    cout << "\n 8. SEATS RENEW";
    cout << "\n 9. SEARCH BOOKING RECORD";
    cout << "\n 10. UPDATE BOOKING RECORD";
    cout << "\n 11. DELETE BOOKING RECORD";
    cout << "\n 12. SHOW ALL BOOKING RECORD";
    cout << "\n 13. EXIT";

    cout << "\n\n\n Enter Your Choice : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        new_bus();
        break;
    case 2:
        view_bus();
        break;
    case 3:
        update_bus();
        break;
    case 4:
        delete_bus();
        break;
    case 5:
        routes_bus();
        break;
    case 6:
        seats_details();
        break;
    case 7:
        booking();
        break;
    case 8:
        renew_bus();
        break;
    case 9:
        search_booking();
        break;
    case 10:
        update_booking();
        break;
    case 11:
        del_booking();
        break;
    case 12:
        show_booking();
        break;
    case 13:
        exit(0); // by default exit in 0 mili seconds
    default:
        cout << "\n\n INVALID DATA, PLEASE TRY AGAIN";
    }
    getch();
    goto p;
}

void bus ::new_bus()
{
p:
    system("cls");
    fstream file;
    string tb_no, tb_name, td_name;
    int tb_seats, found = 0;
    cout << "\n\n\t\t\t\t _____BUS MANAGEMENT SYSTEM_____ ";
    cout << "\n\n Bus Number : ";
    cin >> b_no;
    cout << "\n\n Bus Name : ";
    cin >> b_name;
    cout << "\n\n Driver Name : ";
    cin >> d_name;
    cout << "\n\n Number Of Seats : ";
    cin >> b_seats;

    file.open("bus.txt", ios::in); // file only read
    if (!file)                     // file not exist (write)
    {
        file.open("bus.txt", ios::app | ios::out);                                // opening file // file write
        file << b_no << " " << b_name << " " << b_seats << " " << d_name << endl; // adding new data to file //[<< = data write , >> = data read]
        file.close();
    }
    else // file exist (read)
    {
        file >> tb_no >> tb_name >> tb_seats >> td_name; // same sequence as taken above in write
        while (!file.eof())                              // till file data gets end
        {
            if (tb_no == b_no)
            {
                found++;
            }
            file >> tb_no >> tb_name >> tb_seats >> td_name;
        }
        file.close();
        if (found == 0)
        {
            file.open("bus.txt", ios::app | ios::out);                                // opening file
            file << b_no << " " << b_name << " " << b_seats << " " << d_name << endl; // adding new data to file
            file.close();
        }
        else
        {
            cout << "\n\n Duplicate Record Found ";
            getch();
            goto p;
        }
    }
    cout << "\n\n New Bus Record Added Successfully " << endl;
}

void bus ::single_bus_view()
{
p:
    system("cls");
    string tb_no;
    int found = 0;
    fstream file;
    cout << "\n\n\t\t\t\t _____BUS MANAGEMENT SYSTEM_____ ";
    file.open("bus.txt", ios::in);
    if (!file)
    {
        cout << endl;
        cout << "\n\n Bus Number does not Exist";
    }
    else
    {
        cout << "\n\n Enter Bus Number : " << endl;
        cin >> tb_no;
        file >> b_no >> b_name >> b_seats >> d_name;
        while (!file.eof()) // eof - end of file
        {
            if (tb_no == b_no)
            {
                system("cls");
                cout << "\n\n\t\t\t\t _____BUS MANAGEMENT SYSTEM_____ ";
                cout << endl;
                cout << "Bus Number \t Bus Name \t Bus Seats \t Bus Driver Name" << endl;
                cout << " " << b_no << " \t\t" << b_name << " \t\t" << b_seats << " \t\t" << d_name;
                found++;
            }
            file >> b_no >> b_name >> b_seats >> d_name;
        }
        file.close();
        if (found == 0)
        {
            cout << endl;
            cout << "\n\n Invalid Bus Number..";
        }
    }
}
void bus ::all_bus_view()
{
p:
    system("cls");
    fstream file;
    cout << "\n\n\t\t\t\t _____BUS MANAGEMENT SYSTEM_____ ";
    file.open("bus.txt", ios::in);
    if (!file)
    {
        cout << "\n\n Bus Number does not Exist";
    }
    else
    {
        file >> b_no >> b_name >> b_seats >> d_name;
        cout << endl;
        cout << "Bus Number \t Bus Name \t Bus Seats \t Bus Driver Name" << endl;
        while (!file.eof())
        {
            cout << " " << b_no << "\t \t" << b_name << " \t  " << b_seats << "\t  \t" << d_name;
            cout << endl;
            file >> b_no >> b_name >> b_seats >> d_name;
        }
        file.close();
    }
}

void bus ::view_bus()
{
p:
    system("cls");
    int choice;
    cout << "\n\n\t\t\t\t _____BUS MANAGEMENT SYSTEM_____ " << endl;
    cout << "/n/n 1.Single Bus Record View" << endl;
    cout << "/n/n 2.All Bus Record View" << endl;
    cout << "/n/n 3.Go Back" << endl;
    cout << "/n/n Enter Your Choice : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        single_bus_view();
        break;
    case 2:
        all_bus_view();
        break;
    case 3:
        menu();
    default:
        cout << "\n\n Invalid Data, Please Enter Again";
    }
    getch();
    goto p;
}

void bus ::update_bus()
{
    system("cls");
    cout << "\n\t\t\t\t _____BUS MANAGEMENT SYSTEM_____ ";
    fstream file, file1;
    string tb_no, tb_name, td_name, no;
    int tb_seats, found = 0;
    file.open("bus.txt", ios::in);
    if (!file)
    {
        cout << endl;
        cout << "\n\n\t\t File does not exist.." << endl;
    }
    else
    {
        cout << endl;
        cout << "\n\n\t\t Bus Number : ";
        cin >> tb_no;
        file1.open("bus1.txt", ios::app | ios::out);
        file >> b_no >> b_name >> b_seats >> d_name;
        while (!file.eof())
        {
            if (tb_no == b_no)
            {
                cout << "\n\n New Bus Number : ";
                cin >> no;
                cout << "\n\n New Bus Name : ";
                cin >> tb_name;
                cout << "\n\n New Bus No. of Seats : ";
                cin >> tb_seats;
                cout << "\n\n New Driver Name : ";
                cin >> td_name;
                file1 << no << " " << tb_name << " " << tb_seats << " " << td_name << endl;
                cout << "\n\n\t\t Update Successfully" << endl;
                found++;
            }
            else
            {
                file1 << b_no << " " << b_name << " " << b_seats << " " << d_name << endl;
            }
            file >> b_no >> b_name >> b_seats >> d_name;
        }
        file.close();
        file1.close();
        remove("bus.txt");
        rename("bus1.txt", "bus.txt");
        if (found == 0)
        {
            cout << endl;
            cout << "\n\n\t\t Bus Record Invalid.." << endl;
        }
    }
}
void bus ::delete_bus()
{
    system("cls");
    cout << "\n\n\t\t\t\t _____BUS MANAGEMENT SYSTEM_____ ";
    fstream file, file1;
    string tb_no;
    int found = 0;
    file.open("bus.txt", ios::in);
    if (!file)
    {
        cout << endl;
        cout << "\n\n\t\t File does not exist.." << endl;
    }
    else
    {
        cout << endl;
        cout << "\t\t Bus Number : ";
        cin >> tb_no;
        file1.open("bus1.txt", ios::app | ios::out);
        file >> b_no >> b_name >> b_seats >> d_name;
        while (!file.eof())
        {
            if (tb_no == b_no)
            {
                cout << "\n\n\t\t Delete Successfully" << endl;
                found++;
            }
            else
            {
                file1 << b_no << " " << b_name << " " << b_seats << " " << d_name << endl;
            }
            file >> b_no >> b_name >> b_seats >> d_name;
        }
        file.close();
        file1.close();
        remove("bus.txt");
        rename("bus1.txt", "bus.txt");
        if (found == 0)
        {
            cout << endl;
            cout << "\n\n\t\t Bus Record Invalid.." << endl;
        }
    }
}

void bus ::routes_bus()
{
p:
    system("cls");
    int choice;
    cout << "\n\n\t\t\t\t _____BUS MANAGEMENT SYSTEM_____ ";
    cout << endl;
    cout << "1. 1st Route Details" << endl;
    cout << "2. 2nd Route Details" << endl;
    cout << "3. 3rd Route Details" << endl;
    cout << "4. 4th Route Details" << endl;
    cout << "5. 5th Route Details" << endl;
    cout << "\n\n Enter Your Choice : ";
    cout << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        system("cls");
        cout << "\n\n\t\t\t\t _____BUS MANAGEMENT SYSTEM_____ ";
        cout << endl;
        cout << "\n From Bhopal to Indore";
        cout << "\n 9:00 am -------- 12:00pm";
        cout << "\n From Indore to Jabalpur";
        cout << "\n 01:00 pm --------2:00pm";
        cout << "\n From Jabalpur to Gwalior";
        cout << "\n 2:00 pm -------- 8:00pm";
        break;
    case 2:
        system("cls");
        cout << "\n\n\t\t\t\t _____BUS MANAGEMENT SYSTEM_____ ";
        cout << endl;
        cout << "\n From Bhopal to Indore";
        cout << "\n 9:00 am -------- 12:00pm";
        cout << "\n From Indore to Jabalpur";
        cout << "\n 01:00 pm --------2:00pm";
        cout << "\n From Jabalpur to Gwalior";
        cout << "\n 2:00 pm -------- 8:00pm";
        break;
    case 3:
        system("cls");
        cout << "\n\n\t\t\t\t _____BUS MANAGEMENT SYSTEM_____ ";
        cout << endl;
        cout << "\n From Bhopal to Indore";
        cout << "\n 9:00 am -------- 12:00pm";
        cout << "\n From Indore to Jabalpur";
        cout << "\n 01:00 pm --------2:00pm";
        cout << "\n From Jabalpur to Gwalior";
        cout << "\n 2:00 pm -------- 8:00pm";
        break;
    case 4:
        system("cls");
        cout << "\n\n\t\t\t\t _____BUS MANAGEMENT SYSTEM_____ ";
        cout << endl;
        cout << "\n From Bhopal to Indore";
        cout << "\n 9:00 am -------- 12:00pm";
        cout << "\n From Indore to Jabalpur";
        cout << "\n 01:00 pm --------2:00pm";
        cout << "\n From Jabalpur to Gwalior";
        cout << "\n 2:00 pm -------- 8:00pm";
        break;
    case 5:
        system("cls");
        cout << "\n\n\t\t\t\t _____BUS MANAGEMENT SYSTEM_____ ";
        cout << endl;
        cout << "\n From Bhopal to Indore";
        cout << "\n 9:00 am -------- 12:00pm";
        cout << "\n From Indore to Jabalpur";
        cout << "\n 01:00 pm --------2:00pm";
        cout << "\n From Jabalpur to Gwalior";
        cout << "\n 2:00 pm -------- 8:00pm";
        break;
    default:
        cout << "\n\n Invalid Data, Please Enter Again..";
        getch();
        goto p;
    }
}

void bus ::seats_details()
{
    system("cls");
    fstream file, file1;
    string t_no, s_no, s_b_no;
    int count = 0, found = 0;
    cout << "\n\n\t\t\t\t _____BUS MANAGEMENT SYSTEM_____ ";
    file.open("bus.txt", ios::in);
    file1.open("seat.txt", ios::in);
    if (!file || !file1)
    {
        cout << "\n\n File Opening Error..";
    }
    else
    {
        cout << "\n\n Bus Number : ";
        cin >> t_no;
        file1 >> s_b_no >> s_no;
        while (!file1.eof())
        {
            if (t_no == s_b_no)
            {
                count++;
            }
            file1 >> s_b_no >> s_no;
        }
        file1.close();
        file >> b_no >> b_name >> b_seats >> d_name;
        while (!file.eof())
        {
            if (t_no == b_no)
            {
                system("cls");
                cout << "\n\n\t\t\t\t _____BUS MANAGEMENT SYSTEM_____ ";
                cout << "\n\n Total Number of Seats : " << b_seats;
                cout << "\n\n Reserved Seats : " << count;
                cout << "\n\n Seats Available : " << b_seats - count;
                found++;
            }
            file >> b_no >> b_name >> b_seats >> d_name;
        }
        file.close();
        if (found == 0)
        {
            cout << "\n\n Bus Number not found...";
        }
    }
}

void bus ::booking()
{
p:
    system("cls");
    fstream file;
    int found = 0, s_no, seats, count = 0, s_s_no, ss_no[25], i = 0, total_amount = 0, r_amount;
    char x;
    string t_no, s_b_no, customer_name, phone, from, to;
    cout << "\n\n\t\t\t\t _____BUS MANAGEMENT SYSTEM_____ ";
    file.open("bus.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Opening Error......";
    }
    else
    {
        cout << "\n\n Bus No. : ";
        cin >> t_no;
        file.close();
        file.open("seat.txt", ios::in);
        if (file)
        {
            file >> s_b_no >> s_s_no;
            while (!file.eof())
            {
                if (t_no == s_b_no)
                {
                    count++;
                }
                file >> s_b_no >> s_s_no;
            }
            file.close();
        }
        file.open("bus.txt", ios::in);
        file >> b_no >> b_name >> b_seats >> d_name;
        while (!file.eof())
        {
            if (t_no == b_no)
            {
                seats = b_seats;
                found++;
            }
            file >> b_no >> b_name >> b_seats >> d_name;
        }
        file.close();
        if (seats - count == 0)
        {
            cout << "\n\n All Seats are already Reserved.....";
        }
        else if (found == 1)
        {
            do
            {
            h:
                cout << "\n\n Seat No : ";
                cin >> s_no;
                if (s_no > seats)
                {
                    cout << "\n\n Seat No. is Invalid.... Please try again...";
                    goto h;
                }
                file.open("seat.txt", ios::in);
                if (!file)
                {
                    file.open("seat.txt", ios::app | ios::out);
                    file << t_no << " " << s_no << "\n";
                    file.close();
                }
                else
                {
                    file >> s_b_no >> s_s_no;
                    while (!file.eof())
                    {
                        if (t_no == s_b_no && s_no == s_s_no)
                        {
                            cout << "\n\n Seat is Already Reserved.. Please book another seat...";
                            file.close();
                            goto h;
                        }
                        file >> s_b_no >> s_s_no;
                    }
                    file.close();
                    file.open("seat.txt", ios::app | ios::out);
                    file << t_no << " " << s_no << "\n";
                    file.close();
                }
                ss_no[i] = s_no;
                i++;
                cout << "\n\n  Book another seat (Y,N) : ";
                cin >> x;
            } while (x == 'Y' || x == 'y');
            system("cls");
            cout << "\n\n\t\t\t\t _____BUS MANAGEMENT SYSTEM_____ ";
            cout << "\n\n Customer Name : ";
            cin >> customer_name;
            cout << "\n\n Phone No. : ";
            cin >> phone;
            cout << "\n\n From : ";
            cin >> from;
            cout << "\n\n To : ";
            cin >> to;
            string s_amount = "Rs. 500";
            cout << "\n\n Single Seat Amount : " << s_amount;
            total_amount = 500 * i;
            cout << "\n\n Total Amount : " << "Rs. " << total_amount;
            cout << "\n\n Receive Amount : ";
            cin >> r_amount;
            file.open("customer.txt", ios::app | ios::in);
            file << customer_name << " " << t_no << " " << phone << " " << i << " " << total_amount << "\n";
            file.close();
            system("cls");
            cout << "\n\n\t\t\t\t _____BUS MANAGEMENT SYSTEM_____ ";
            cout << "\n\n\n\t\t ************************************ ";
            cout << "\n\n\n\t\t\t _____Booking Information_______ ";
            cout << "\n\n\n\t\t ************************************ ";
            cout << "\n\n\t Name                      :" << customer_name;
            cout << "\n\t\t From                      :" << from;
            cout << "\n\t\t To                        :" << to;
            cout << "\n\t\t Total Seats               :" << i;
            cout << "\n\t\t Reserved Seats            :";
            for (int a = 0; a < i; a++)
            {
                if (a != 0)
                    cout << ",";
                cout << ss_no[a];
            }
            cout << "\n\t\t Single Seat Amount        : " << s_amount;
            cout << "\n\t\t Total Amount              : " << "Rs. " << total_amount;
            cout << "\n\t\t Receive Amount            : " << "Rs. " << r_amount;
            cout << "\n\t\t Return Amount             : " << "Rs. " << r_amount - total_amount;
            cout << "\n\n\n\t\t ************************************";
            cout << "\n\n\n\t\t ***********  Thank You  ************";
            cout << "\n\n\n\t\t ************************************";
        }
        else
        {
            cout << "\n\n Bus No. is Invalid... Please try again...";
            getch();
            goto p;
        }
    }
}

void bus::renew_bus()
{
    system("cls");
    fstream file;
    char x;
    cout << "\n\n\t\t\t\t _____BUS MANAGEMENT SYSTEM_____ ";
    file.open("seat.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Opening Error........";
    }
    else
    {
        cout << "\n\n Do You Want to Renew All the Seats (Y,N) : ";
        cin >> x;
        if (x == 'Y' || x == 'y')
        {
            remove("seat.txt");
            cout << "\n\n\t\t\t All Seats are Empty Now.....";
        }
        else if (x == 'N' || x == 'n')
        {
            cout << "\n\n\t\t\t Thank You All Seats are Successfully Reserverd.....";
        }
    }
}

void bus::search_booking()
{
    system("cls");
    fstream file;
    int t_seats, t_amo, found = 0;
    string name, no, phone, t_phone;
    cout << "\n\n\t\t\t\t _____BUS MANAGEMENT SYSTEM_____ ";
    file.open("customer.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Opening Error.....";
    }
    else
    {
        cout << "\n\n Phone No. : ";
        cin >> t_phone;
        file >> name >> no >> phone >> t_seats >> t_amo;
        while (!file.eof())
        {
            if (t_phone == phone)
            {
                if (found == 0)
                {
                    system("cls");
                    cout << "\n\n\t\t\t\t _____BUS MANAGEMENT SYSTEM_____ ";
                }
                cout << "\n\n\n Customer Name : " << name;
                cout << "\n\n Bus No.         : " << no;
                cout << "\n\n Phone No.       : " << phone;
                cout << "\n\n Reserved Seats  : " << t_seats;
                cout << "\n\n Total Amount    : " << "Rs. " << t_amo;
                cout << "\n\n===================================";
                found++;
            }
            file >> name >> no >> phone >> t_seats >> t_amo;
        }
        file.close();
        if (found == 0)
        {
            cout << "\n\n Customer Name Is Invalid.......";
        }
    }
}

void bus::update_booking()
{
    system("cls");
    fstream file, file1;
    int t_seats, t_amo, found = 0, del_seats, i = 0;
    string name, no, phone, t_phone, del_no;
    cout << "\n\n\t\t\t\t _____BUS MANAGEMENT SYSTEM_____ ";
    file.open("customer.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Opening Error.....";
    }
    else
    {
        cout << "\n\n Phone No. : ";
        cin >> t_phone;
        file >> name >> no >> phone >> t_seats >> t_amo;
        while (!file.eof())
        {
            if (t_phone == phone)
            {
                file.close();
                file.open("customer.txt", ios::in);
                file1.open("customer1.txt", ios::app | ios::out);
                file >> name >> no >> phone >> t_seats >> t_amo;
                while (!file.eof())
                {
                    if (t_phone == phone)
                    {
                        del_no = no;
                        del_seats = t_seats;
                    }
                    if (t_phone != phone)
                    {
                        file1 << name << " " << no << " " << phone << " " << t_seats << " " << t_amo << endl;
                    }
                    file >> name >> no >> t_seats >> t_amo;
                }
                file.close();
                file1.close();
                remove("customer.txt");
                rename("customer1.txt", "customer.txt");
                file.open("seat.txt", ios::in);
                file1.open("seat1.txt", ios::app | ios::out);
                file >> no >> t_seats;
                while (!file.eof())
                {
                    if (!(del_no == no && i < del_seats))
                    {
                        file1 << no << " " << t_seats << endl;
                    }
                    file >> no >> t_seats;
                }
                file.close();
                file1.close();
                remove("seat.txt");
                rename("seat1.txt", "seat.txt");
                booking();
                cout << "\n\n\t\t\t Booking Update Successfull...";
                found++;
                goto h;
            }
            file >> name >> no >> phone >> t_seats >> t_amo;
        }
        file.close();
    h:
        if (found == 0)
            cout << "\n\n Phone No. Is Invalid.......";
    }
}

void bus::del_booking()
{
    system("cls");
    fstream file, file1;
    int t_seats, t_amo, found = 0, del_seats, i = 0;
    string name, no, phone, t_phone, del_no;
    cout << "\n\n\t\t\t\t _____BUS MANAGEMENT SYSTEM_____ ";
    file.open("customer.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Opening Error.....";
    }
    else
    {
        cout << "\n\n Phone No. : ";
        cin >> t_phone;
        file >> name >> no >> phone >> t_seats >> t_amo;
        while (!file.eof())
        {
            if (t_phone == phone)
            {
                file.close();
                file.open("customer.txt", ios::in);
                file1.open("customer1.txt", ios::app | ios::out);
                file >> name >> no >> phone >> t_seats >> t_amo;
                while (!file.eof())
                {
                    if (t_phone == phone)
                    {
                        del_no = no;
                        del_seats = t_seats;
                    }
                    if (t_phone != phone)
                    {
                        file1 << name << " " << no << " " << phone << " " << t_seats << " " << t_amo << endl;
                    }
                    file >> name >> no >> t_seats >> t_amo;
                }
                file.close();
                file1.close();
                remove("customer.txt");
                rename("customer1.txt", "customer.txt");
                file.open("seat.txt", ios::in);
                file1.open("seat1.txt", ios::app | ios::out);
                file >> no >> t_seats;
                while (!file.eof())
                {
                    if (!(del_no == no && i < del_seats))
                    {
                        file1 << no << " " << t_seats << endl;
                    }
                    file >> no >> t_seats;
                }
                file.close();
                file1.close();
                remove("seat.txt");
                rename("seat1.txt", "seat.txt");
                cout << "\n\n\t\t\t Booking Deleted Successfull... ";
                found++;
                goto h;
            }
            file >> name >> no >> phone >> t_seats >> t_amo;
        }
        file.close();
    h:
        if (found == 0)
            cout << "\n\n Phone No. Is Invalid.......";
    }
}

void bus::show_booking()
{
    system("cls");
    fstream file;
    int t_seats, t_amo, found = 0;
    string name, no, phone;
    cout << "\n\n\t\t\t\t _____BUS MANAGEMENT SYSTEM_____ ";
    file.open("customer.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Opening Error.....";
    }
    else
    {
        file >> name >> no >> phone >> t_seats >> t_amo;
        while (!file.eof())
        {
            cout << "\n\n\n Customer Name : " << name;
            cout << "\n\n Bus No.         : " << no;
            cout << "\n\n Phone No.       : " << phone;
            cout << "\n\n Reserved Seats  : " << t_seats;
            cout << "\n\n Total Amount    : " << "Rs. " << t_amo;
            cout << "\n\n===================================";
            found++;

            file >> name >> no >> phone >> t_seats >> t_amo;
        }
        file.close();
        if (found == 0)
        {
            cout << "\n\n No Record Found.......";
        }
    }
}
main()
{
    bus b;
p:
    system("cls"); // clear previous screen
    string email, pass;
    cout << "\n\n\n\t\t\t\t\t***Securities are required*" << endl;
    cout << "\n\n Email : ";

    cin >> email;
    cout << "\n\n Password : ";

    for (int i = 0; i < 8; i++)
    {
        char ch = getch(); // getch takes all the input one by one
        pass = pass + ch;
        cout << "*";
    }
    if (email == "khushi@gmail.com" && pass == "goodtogo")
    {
        cout << "\n\n\t\t Loading";
        for (int z = 0; z < 5; z++)
        {
            cout << ".";
        }
        b.menu();
    }
    else
    {
        cout << "\n\n\t\t INVALID Email or Password" << endl;
        getch();
        goto p;
    }
}