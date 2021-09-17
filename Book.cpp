#include<iostream>
#include<fstream>
using namespace std;
struct book{
	int id,no;
	string name;
	};
void view();
void request_Book(int);
void returnBook();
void exitLib(){exit(0);}
void view()
              {
	                 fstream f;
                      book Stu;
						int x;
                      f.open("books_database.txt",ios::in);

                      cout<<"\n\t#no_of_copies_available\tbook_id\tname_of_the_book\n";

                      while( (f.read((char*)&Stu,sizeof(Stu))) != NULL )
                      		cout<<"\n\t"<<id<<"\t"<<no<<"\t"<<name;
						cout<<"Enter id of the book you want to borrow";
						cin>>x;
						request_Book(x);
                     f.close();
              }
void returnBook()
              {

  ofstream temp;
  temp.open("temp.txt");
                      fstream f;
                      book Stu;
						int x;
						cout<<"Enter book id ";
						cin>>x;
                     f.open("books_database.txt",ios::in );
						while( (f.read((char*)&Stu,sizeof(Stu))) != NULL )
					  {
						  if(x==Stu.id)
						  {
						cout<<"Thankyou customer.Please place the book back on the shelf";
						 Stu.no++;
						 
							  
						  
                      		//Stu.putdata();
					  }
					  if(flag==0)
					  cout<<"Book id is not correct.Please try again";
					  temp.write( (char *) &Stu, sizeof(Stu) );
					  }
                      
                      f.close();
					  temp.close();
  remove("books_database.txt");
  rename("temp.txt", "books_database.txt");
              }

void request_Book(int xid)
              {
			  

  ofstream temp;
  temp.open("temp.txt");
                    fstream f;
                      book Stu;
					   int flag=0;
                      f.open("books_database.txt",ios::in );

                      //cout<<"\n\t#no_of_copies_available\tbook_id\tname_of_the_book\n";

                      while( (f.read((char*)&Stu,sizeof(Stu))) != NULL )
					  {
						  
						  if(xid==Stu.id)
						  {
							  flag=1;
							  if(Stu.no<1)
						cout<<"This book is presently not on our shelf.Pls try later";
						else{
							  cout<<"Congratulations customer your book is alloted.Pls collect it from the shelf";
							   Stu.no--;
							   
							  
						  }
                      		//Stu.putdata();
					  }
					  if(flag==0)
					  cout<<"Book id is not correct.Please try again";
					  temp.write( (char *) &Stu, sizeof(Stu) );
					  }
					  
                      f.close();
  temp.close();
  remove("books_database.txt");
  rename("temp.txt", "books_database.txt");
              }

int main()
{
  int ch,;
  fstream myFile;
  myFile.open ("books_database.txt", ios::in | ios::out);
  cout << "Hello Customer, Welcome to Good Will Library"<< endl ;
  cout << "select one of the options below"<< endl ;
  cout << "1. View list of books on our shelves"<< endl ;
  cout << "2.Request for a new book"<< endl ;
  cout << "3.Return a book"<< endl ;
  cout << "4.Exit"<< endl ;
  cin>>ch;
  do{
	  switch(ch)
  {
	  case 1:view();break;
	  case 2:request_Book();break;
	  case 3:returnBook();break;
	  case 4:exitLib();break;
	  default:cout<<"Wrong Choice";
	  
  }} while(ch!=4);
 
  
 myFile.close();
  return 0;
}
