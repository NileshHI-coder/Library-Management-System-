#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

class Book {
	private:
		int bookId;
		string title;
		string author;
		bool issued;
		
	public:
		// Function to add Book;
		void addBook() {
			
			cout<<"\n Enter the Book ID :";
			cin>>bookId;
			
			cin.ignore();
			
			cout<<"\n Enter the title of the Book :";
			getline(cin,title);
			
			cout<<"\n Enter the Author of the Book :";
			getline(cin,author);
			
			issued = false;
		}
		
		//Function to Display Book;
		
		void displayBook() {
			
			cout<<"\n----------------------------------------\n";
			cout<<"\n Book Id : " << bookId;
			cout<<"\n Book Title : " << title;
			cout<<"\n Book Author : " << author;
			cout<<"\n Status : ";
			
			if(issued) {
				cout<<" Issued ";
			}
			else {
				cout<<" Available ";
			}
			
		}
		
		//Function to issued Books;
		
		void issueBook() {
			
			if(issued) {
				cout<< " Book is already issued.";
			}
			else {
				issued = true;
				cout<< " Book issued successfully.";
			}
		}
		
		//function to return book;
		
		void returnBook() {
			
			if(issued) {
				cout<<"Book was not Issued.";
			}
			else {
				issued = false;
				cout<<"Book was return successfully.";
			}
		}
		
		bool searchtitle (string s) {
			return title == s ;	
	    }
	 
	    bool searchauthor (string a) {
	    	return author == a;
		}
		
		// Save to File
    void writeToFile()
    {
        ofstream file("library.txt", ios::app);

        file << bookId << endl;
        file << title << endl;
        file << author << endl;
        file << issued << endl;

        file.close();
    }

    // Read From File
    void readFromFile()
    {
        ifstream file("library.txt");

        int id;
        string t, a;
        bool isIssued;

        cout << "\n====== LIBRARY RECORDS ======\n";

        while(file >> id)
        {
            file.ignore();

            getline(file, t);
            getline(file, a);

            file >> isIssued;

            cout << "\nBook ID   : " << id;
            cout << "\nTitle     : " << t;
            cout << "\nAuthor    : " << a;
            cout << "\nStatus    : ";

            if(isIssued)
                cout << "Issued";
            else
                cout << "Available";

            cout << "\n-----------------------------";
        }

        file.close();
    }
};

int main()
{
    Book b;

    int choice;
    string search;

    do
    {
        cout << "\n========== LIBRARY MANAGEMENT SYSTEM ==========";
        cout << "\n1. Add Book";
        cout << "\n2. Display Book";
        cout << "\n3. Issue Book";
        cout << "\n4. Return Book";
        cout << "\n5. Search by Title";
        cout << "\n6. Search by Author";
        cout << "\n7. Show All Records";
        cout << "\n8. Exit";

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        cin.ignore();

        switch(choice)
        {
            case 1:
                b.addBook();
                b.writeToFile();
                break;

            case 2:
                b.displayBook();
                break;

            case 3:
                b.issueBook();
                break;

            case 4:
                b.returnBook();
                break;

            case 5:
                cout << "\nEnter Title to Search: ";
                getline(cin, search);

                if(b.searchtitle(search))
                    b.displayBook();
                else
                    cout << "Book Not Found!";
                break;

            case 6:
                cout << "\nEnter Author Name to Search: ";
                getline(cin, search);

                if(b.searchauthor(search))
                    b.displayBook();
                else
                    cout << "Book Not Found!";
                break;

            case 7:
                b.readFromFile();
                break;

            case 8:
                cout << "\nThank You!";
                break;

            default:
                cout << "\nInvalid Choice!";
        }

    } while(choice != 8);

    return 0;
}
