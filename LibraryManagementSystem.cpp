#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <sstream>
using namespace std;

class Books
{
private:
    int book_id;
    string title;
    string author;
    string subject;
    string isbn;
    float price;

public:
    Books() : book_id(0), title(""), author(""), subject(""), isbn(""), price(0.00) {}

    Books(int id, string title, string author, string subject, string isbn, float price)
    {
        book_id = id;
        this->title = title;
        this->author = author;
        this->subject = subject;
        this->isbn = isbn;
        this->price = price;
    }

    Books(int id)
    {
        book_id = id;
    }
    // function for accepting the book record
    void setBook()
    {
        cout << "\nEnter the Book_id: ";
        cin >> book_id;
        cout << "Enter the title: ";
        cin >> title;
        cout << "Enter the author: ";
        cin >> author;
        cout << "Enter the subject: ";
        cin >> subject;
        cout << "Enter the isbn: ";
        cin >> isbn;
        cout << "Enter the price: ";
        cin >> price;
        cout << endl;
    }

    // function for getting the book record

    void getBook()
    {
        cout << "\nBook_Id: " << book_id << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Subject: " << subject << endl;
        cout << "Isbn: " << isbn << endl;
        cout << "Price: " << price;
        cout << endl;
    }

    // getters for all the data members

    int getId()
    {
        return this->book_id;
    }
    string getTitle()
    {
        return this->title;
    }
    string getAuthor()
    {
        return this->author;
    }
    string getSubject()
    {
        return this->subject;
    }
    string getIsbn()
    {
        return this->isbn;
    }
    float getPrice()
    {
        return this->price;
    }

    // setters for the all the data members

    void setId(int id)
    {
        this->book_id = id;
    }
    void setTitle(string title)
    {
        this->title = title;
    }
    void setAuthor(string author)
    {
        this->author = author;
    }
    void setSubject(string subject)
    {
        this->subject = subject;
    }
    void setIsbn(string isbn)
    {
        this->isbn = isbn;
    }
    void setPrice(float price)
    {
        this->price = price;
    }
};

class Copys : public Books
{
private:
    static int counter;
    int copyId;
    string rack;
    string status;

public:
    Copys() : rack(""), status("")
    {
        copyId++;
    }
    Copys(int Book_id, string title, string author, string subject, string isbn, float price, string rack)
        : Books(Book_id, title, author, subject, isbn, price)
    {
        this->rack = rack;
        copyId = ++counter;
        this->status = "UnAssigned";
    }

    void getCopys()
    {
        Books::getBook();
        cout << "copyId: " << copyId << endl;
        cout << "rack: " << rack << endl;
        cout << "status :" << status << endl;
    }

    void setCopy()
    {
        Books::setBook();
        cout << "\nEnter the rack: ";
        cin >> rack;
        status = "UnAssigned";
    }

    bool isAvailable()
    {
        if (status == "UnAssigned")
            return true;
        return false;
    }

    void setCopyasAssigned()
    {
        status = "Assigned";
    }
    void setCopyAsUnassigned()
    {
        this->status = "UnAssigned";
    }
    int getCopy_id()
    {
        return copyId;
    }
};
int Copys::counter = 0;

class Members
{
private:
    static int counter;
    int id;
    string name;
    string email;
    string phone;
    time_t nextPayement_dueDate;
    string paymentStatus;

public:
    Members()
    {
        paymentStatus = "Unpaid";
        nextPayement_dueDate = 0;
        id = ++counter;
    }
    // Setters
    void accept_record()
    {
        cout << endl;
        cout << "Enter Member Name:";
        cin >> name;
        cout << "Enter Member email:";
        cin >> email;
        cout << "Enter Member phone:";
        cin >> phone;
        // cout << "Enter Member nextPayement_dueDate";

        // int date;
        // int month;
        // int year;

        // cout << "\nEnter Date: ";
        // cin >> date;
        // cout << "Enter Month: ";
        // cin >> month;
        // cout << "Enter Year: ";
        // cin >> year;

        // tm t = {};
        // t.tm_mday = date;
        // t.tm_mon = month - 1;
        // t.tm_year = year - 1900;

        // nextPayement_dueDate = mktime(&t);

        // cout << "Enter Member paymentStatus:" << endl;

        // int ch;
        // cout << "1.Paid" << endl;
        // cout << "2.Unpaid" << endl;
        // cin >> ch;

        // if (ch == 1)
        //     paymentStatus = "Paid";
        // else
        //     paymentStatus = "Unpaid";
    }

    void display_record()
    {
        cout << "Member_id:" << id << endl;
        cout << "name: " << name << endl;
        cout << "email: " << email << endl;
        cout << "phone: " << phone << endl;

        if (paymentStatus == "Unpaid")
        {
            cout << "paymentStatus: " << paymentStatus << endl;
            cout << "nextPayement_dueDate:No Payement Has Done Yet!!!" << endl;
        }
        else
        {
            tm *t = localtime(&nextPayement_dueDate);
            cout << "paymentStatus: " << paymentStatus << endl;
            cout << "nextPayement_dueDate: " << t->tm_mday << "/" << t->tm_mon + 1 << "/" << t->tm_year + 1900 << endl;
        }
    }

    int getId()
    {
        return id;
    }
    bool getPayementStatus()
    {
        bool ans = 0;
        if (paymentStatus == "Paid")
            ans = 1;
        return ans;
    }
    string getName()
    {
        return name;
    }
    string getemail()
    {
        return email;
    }
    void setPaymentStatus()
    {
        paymentStatus = "Paid";
    }
};

int Members::counter = 0;

class issueRecords
{
private:
    static int counter;
    int issueRecordId;
    int copy_id;
    int member_id;
    time_t issue_date;
    time_t return_dueDate;
    time_t return_date;
    float fine_amount;

public:
    issueRecords()
    {
        issueRecordId = ++counter;
        return_date = 0;
    }
    issueRecords(int copy_id, int member_id, time_t issue_date, time_t return_dueDate, float fine_amount)
    {
        this->copy_id = copy_id;
        this->member_id = member_id;
        this->issue_date = issue_date;
        this->return_dueDate = return_dueDate;
        this->fine_amount = fine_amount;
        this->return_date = 0;
        issueRecordId = ++counter;
    }
    void acceptIssueRecords()
    {
        cout << "\nEnter the issue record id: ";
        cin >> issueRecordId;
        cout << "\nEnter the issue_date: ";
        cin >> issue_date;
        cout << "\nEnter the return due date: ";
        cin >> return_dueDate;
        cout << "\nEnter the fine_amount: ";
        cin >> fine_amount;
    }
    void displayIssueRecords()
    {
        cout << "\nissueRecordId:" << issueRecordId << endl;
        cout << "copy_id:" << copy_id << endl;
        cout << "member_id:" << member_id << endl;

        tm issue_time = *localtime(&issue_date);
        tm return_due_time = *localtime(&return_dueDate);
        tm return_date_time = *localtime(&return_date);

        cout
            << "issue_date:"
            << issue_time.tm_mday << "/"
            << (issue_time.tm_mon + 1)
            << "/" << (issue_time.tm_year + 1900)
            << endl;

        cout << "return_due_date:" << (return_due_time.tm_mday) << "/"
             << (return_due_time.tm_mon + 1) << "/"
             << (return_due_time.tm_year + 1900)
             << endl;

        if (return_date == 0)
        {
            cout << "Member Has Not yet Returned Book!!.. " << endl;
        }
        else
        {
            cout << "return_date:" << (return_date_time.tm_mday) << "/"
                 << (return_date_time.tm_mon + 1) << "/"
                 << (return_date_time.tm_year + 1900)
                 << endl;
        }
        cout << "fine_amount:" << fine_amount << endl;
    }

    void setReturn_date(time_t return_date)
    {
        this->return_date = return_date;
    }

    int getCopy_id()
    {
        return copy_id;
    }
    bool isFine()
    {
        return return_date > return_dueDate;
    }
    int datediff()
    {
        return ((return_date - return_dueDate) / 86400);
    }
    void setfine_amount(float amt)
    {
        fine_amount = amt;
    }
    float getFine()
    {
        return fine_amount;
    }
};

int issueRecords::counter = 0;

class Payments
{
private:
    static int counter;
    int payment_id;
    int member_id;
    float amount;
    string type;
    time_t transaction_time;
    time_t nextpayment_dueDate;

public:
    Payments()
    {
        payment_id = ++counter;
    }
    void accept_records()
    {
        cout << "Enter Member_Id:";
        cin >> member_id;
        cout << "Enter Amount:";
        cin >> amount;

        int n;
        cout << "Choose Type of Transaction" << endl;
        cout << "1.Online \n2.Cash" << endl;
        cout << "Enter type:";
        cin >> n;

        if (n == 2)
            type = "Cash";
        else
            type = "Online";

        time_t now = time(0); // current date

        tm temp = *localtime(&now); // convert to tm (copy)
        temp.tm_mday += 30;         // add 7 days

        time_t nextPay_dueDate = mktime(&temp); // convert back

        transaction_time = now;
        nextpayment_dueDate = nextPay_dueDate;
    }
    void display_records()
    {

        cout << "\npayement_id:" << payment_id << endl;
        cout << "Member_Id:" << member_id << endl;
        cout << "Amount:" << amount << endl;
        cout << "Type:" << type << endl;

        tm transaction_Time = *localtime(&transaction_time);
        tm next_Transaction = *localtime(&nextpayment_dueDate);

        cout
            << "Payement_Date:"
            << transaction_Time.tm_mday << "/"
            << (transaction_Time.tm_mon + 1)
            << "/" << (transaction_Time.tm_year + 1900)
            << endl;

        cout << "Next Payement due date:" << (next_Transaction.tm_mday) << "/"
             << (next_Transaction.tm_mon + 1) << "/"
             << (next_Transaction.tm_year + 1900)
             << endl;
    }
    int getpayment_id()
    {
        return payment_id;
    }
};

int Payments::counter = 0;

namespace booksFuncn
{
    // Add Books
    void addBooks(vector<Books *> &books)
    {
        Books *ptr = new Books();
        ptr->setBook();
        books.push_back(ptr);
    }
    // Display Books
    void displayBooks(vector<Books *> &books)
    {
        for (int i = 0; i < books.size(); i++)
        {
            books[i]->getBook();
        }
        return;
    }
    // Display Book Title and its id;
    void displayBooksTitleandId(vector<Books *> &books)
    {
        for (int i = 0; i < books.size(); i++)
        {
            cout << books[i]->getId() << ". " << books[i]->getTitle();
            cout << endl;
        }
        return;
    }
}

namespace MemberFuncn
{
    // Add Members
    void addMember(vector<Members *> &members)
    {
        Members *ptr = new Members();
        ptr->accept_record();
        members.push_back(ptr);
    }
    // Display Members
    void displayMembers(vector<Members *> &members)
    {
        cout << endl;
        for (int i = 0; i < members.size(); i++)
        {
            members[i]->display_record();
            cout << endl;
        }
        return;
    }

    bool checkMemberisPresent(vector<Members *> &members, int member_id)
    {
        bool ans = 0;
        for (int i = 0; i < members.size(); i++)
        {
            if (members[i]->getId() == member_id)
            {
                ans = 1;
                break;
            }
        }
        return ans;
    }
}

namespace CopyFuncn
{
    // Add Books
    void addCopy(vector<Books *> &books, vector<Copys *> &booksCopy)
    {
        // Display Books Title with Book id
        cout << endl;
        for (int i = 0; i < books.size(); i++)
        {
            cout << books[i]->getId() << ". " << books[i]->getTitle();
            cout << endl;
        }

        int book_id;
        cout << "\nEnter Book_id Which You want to make Copy: ";
        cin >> book_id;

        int i;
        bool bookFound = 0;

        for (i = 0; i < books.size(); i++)
        {
            if (book_id == books[i]->getId())
            {
                bookFound = 1;
                break;
            }
        }
        if (!bookFound)
        {
            cout << "Book Not Found!!!" << endl;
            return;
        }

        string rack;
        cout << "Enter Rack:";
        cin >> rack;

        int count = 0;
        for (int i = 0; i < booksCopy.size(); i++)
        {
            if (booksCopy[i]->getId() == book_id)
            {
                count++;
            }
        }

        static int copy_id = 1;

        // int Book_id, string title, string author, string isbn, float price, int copy_id, string rack
        Copys *ptr = new Copys(books[i]->getId(), books[i]->getTitle(), books[i]->getAuthor(), books[i]->getSubject(), books[i]->getIsbn(), books[i]->getPrice(), rack);

        booksCopy.push_back(ptr);

        return;
    }

    // Display Books
    void displayCopyBooks(vector<Copys *> &copys)
    {
        for (int i = 0; i < copys.size(); i++)
        {
            copys[i]->getCopys();
            cout << endl;
        }
        return;
    }
}

namespace AssignCopiesFuncn
{
    void assignCopyToMember(vector<Copys *> &bookCopys, vector<Members *> &members, vector<Books *> &books, vector<issueRecords *> &issueRecordsv)
    {
        cout << endl;
        int member_id;
        cout << "Enter Member_Id :";
        cin >> member_id;

        if (!MemberFuncn::checkMemberisPresent(members, member_id))
        {
            cout << endl;
            cout << "Member Not Present" << endl;
            return;
        }

        int i;
        for (i = 0; i < members.size(); i++)
        {
            if (members[i]->getId() == member_id)
            {
                cout << endl;
                cout << "Member Exist in System.." << endl;
                break;
            }
        }

        if (!members[i]->getPayementStatus())
        {
            cout << "Member Has Not Taken Membership!!" << endl;
            return;
        }

        // Assign Copy to Member

        // Display Unique Books
        booksFuncn::displayBooksTitleandId(books);

        int book_id;
        cout << "Enter Book id: ";
        cin >> book_id;

        bool book_assigned = 0;

        int j;
        for (j = 0; j < bookCopys.size(); j++)
        {
            if (bookCopys[j]->getId() == book_id && bookCopys[j]->isAvailable())
            {
                bookCopys[j]->setCopyasAssigned();
                book_assigned = 1;
                break;
            }
        }
        if (!book_assigned)
        {
            cout << "Book cannot be Assigned!!!" << endl;
            return;
        }
        cout << "Book Assigned!!!" << endl;
        cout << endl;

        time_t now = time(0); // current date

        tm temp = *localtime(&now); // convert to tm (copy)
        temp.tm_mday += 7;          // add 7 days

        time_t return_dueDate = mktime(&temp); // convert back

        // int id, int copy_id, int member_id, time_t issue_date, time_t return_dueDate, float fine_amount
        issueRecords *ptr_fun = new issueRecords(bookCopys[j]->getCopy_id(), member_id, now, return_dueDate, 0.0);

        issueRecordsv.push_back(ptr_fun);

        return;
    }
}

void displayIssueRecords(vector<issueRecords *> &issueRecordsv)
{
    for (int i = 0; i < issueRecordsv.size(); i++)
    {
        issueRecordsv[i]->displayIssueRecords();
    }
}

//(bookCopys, members, books, issueRecordsv)
void return_Copy(vector<Copys *> &bookCopys, vector<Members *> &members, vector<Books *> &books, vector<issueRecords *> &issueRecordsv)
{
    int copy_id;
    cout << "Enter Copy_id:";
    cin >> copy_id;

    time_t now = time(0);

    for (int i = 0; i < bookCopys.size(); i++)
    {
        if (bookCopys[i]->getCopy_id() == copy_id)
        {
            bookCopys[i]->setCopyAsUnassigned();
            break;
        }
    }
    bool recordFound = 0;
    int i;
    for (i = 0; i < issueRecordsv.size(); i++)
    {
        if (issueRecordsv[i]->getCopy_id() == copy_id)
        {
            recordFound = 1;
            break;
        }
    }
    if (!recordFound)
    {
        cout << "No Record Found" << endl;
        return;
    }
    issueRecordsv[i]->setReturn_date(now);

    float total_fine = 0.0;

    if (!issueRecordsv[i]->isFine())
    {
        issueRecordsv[i]->setfine_amount(total_fine);
        return;
    }

    int days = issueRecordsv[i]->datediff();
    cout << days << endl;
    total_fine = days * 5;

    issueRecordsv[i]->setfine_amount(total_fine);
    return;
}

// bookCopys, members, books, issueRecordsv
void makeReports(vector<Copys *> &bookCopysv, vector<Members *> &members, vector<Books *> &books, vector<issueRecords *> &issueRecordsv)
{
    ofstream fout("Member_Reports.txt", ios::app);
    fout << "Members Which Have Taken Membership" << endl;

    for (int i = 0; i < members.size(); i++)
    {
        if (members[i]->getPayementStatus())
        {
            fout << members[i]->getId() << "," << members[i]->getName() << "," << members[i]->getemail() << endl;
        }
    }
    fout.close();

    ofstream fout2("Book_Reports.txt", ios::app);
    fout2 << "Copies Which Are Already Assigned" << endl;

    for (int i = 0; i < bookCopysv.size(); i++)
    {
        if (!bookCopysv[i]->isAvailable())
        {
            fout2 << "Copy_id: " << bookCopysv[i]->getCopy_id() << "," << "Book_Title:" << bookCopysv[i]->getTitle() << "," << "Book_id: " << bookCopysv[i]->getId() << endl;
        }
    }
    fout2.close();

    ofstream fout3("Fine_Reports.txt", ios::app);
    fout3 << "Total Fine Collected" << endl;
    float fine = 0;
    for (int i = 0; i < issueRecordsv.size(); i++)
    {
        fine += issueRecordsv[i]->getFine();
    }
    fout3 << "Total Fine: " << fine;
    fout3.close();
    return;
}

void makePayments(vector<Payments *> &payments, vector<Members *> &members)
{

    Payments *ptr = new Payments();
    ptr->accept_records();
    payments.push_back(ptr);

    for (int i = 0; i < members.size(); i++)
    {
        if (ptr->getpayment_id() == members[i]->getId())
        {
            members[i]->setPaymentStatus();
            break;
        }
    }
    ptr->display_records();
    return;
}

int MenuDrive()

{
    int ch;
    cout << endl;
    cout << "1.Add Members" << endl;
    cout << "2.Display Members" << endl;
    cout << "3.Add Book" << endl;
    cout << "4.Display Books" << endl;
    cout << "5.Make Copyies of Book " << endl;
    cout << "6.Display Copy Records" << endl;
    cout << "7.Assign Copies To Member" << endl;
    cout << "8.Display Issue Records" << endl;
    cout << "9.Return Copy" << endl;
    cout << "10.Reports" << endl;
    cout << "11.Payments" << endl;
    cout << endl;
    cout << "Enter Choice: ";
    cin >> ch;
    return ch;
}

int main()
{
    int ch;

    vector<Books *> books;
    vector<Copys *> bookCopys;
    vector<Members *> members;
    vector<issueRecords *> issueRecordsv;
    vector<Payments *> payments;

    // vector<issueRecords *> issueRecordsv;

    // dummyData(bookCopys);

    while ((ch = MenuDrive()) != 0)
    {
        switch (ch)
        {
        case 1:
        {
            MemberFuncn::addMember(members);
            break;
        }
        case 2:
        {
            MemberFuncn::displayMembers(members);
            break;
        }
        case 3:
        {
            booksFuncn::addBooks(books);
            break;
        }
        case 4:
        {
            booksFuncn::displayBooks(books);
            break;
        }
        case 5:
        {
            CopyFuncn::addCopy(books, bookCopys);
            break;
        }
        case 6:
        {
            CopyFuncn::displayCopyBooks(bookCopys);
            break;
        }
        case 7:
        {
            AssignCopiesFuncn::assignCopyToMember(bookCopys, members, books, issueRecordsv);
            break;
        }
        case 8:
        {
            displayIssueRecords(issueRecordsv);
            break;
        }
        case 9:
        {
            return_Copy(bookCopys, members, books, issueRecordsv);
            break;
        }
        case 10:
        {
            makeReports(bookCopys, members, books, issueRecordsv);
            break;
        }
        case 11:
        {
            makePayments(payments, members);
            break;
        }
        default:
        {
            break;
        }
        }
    }
}