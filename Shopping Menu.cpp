#include<iostream>
#include<fstream>

using namespace std;

class shopping{
	private:
		int pcode;
		float price;
		float dis;
		string pname;
	
	public:
		void menu();
		void administrator();
		void buyer();
		void add();
		void edit();
		void rem();
		void list();
		void receipt();
};

void shopping :: menu(){
	m:
	int choice;
	string email;
	string password;
	cout<<"\t\t\t\t_____________________________\n";
    cout<<"\t\t\t\t                             \n";
    cout<<"\t\t\t\t     supermarket Main Menu   \n";
    cout<<"\t\t\t\t                             \n";
    cout<<"\t\t\t\t_____________________________\n";
    cout<<"\t\t\t\t                             \n";
    
    cout<<"\t\t\t\t|   1) Administrator   |\n";
    cout<<"\t\t\t\t|                      |\n";
    cout<<"\t\t\t\t|   2) Buyer           |\n";
    cout<<"\t\t\t\t|                      |\n";
    cout<<"\t\t\t\t|   3) Exit            |\n";
    cout<<"\t\t\t\t|                      |\n";
    cout<<"\n\t\t\t Please select! ";
    cin>>choice;
    
    switch(choice){
    	case 1:
    		cout<<"\t\t\t Please login \n";
    		cout<<"\t\t\t Enter Email   \n";
    		cin>>email;
    		cout<<"\t\t\t    password     \n";
    		cin>>password;
    		
    		if (email=="gaurav@gmail.com" && password=="gaurav@123")
			{
    			administrator();
			}
			else
			{
				cout<<"invalid email/password";
				break;
	    	}
    	case 2:
    		buyer();
    
   		case 3:
    		exit(0);
    
    	default :
    		cout<<"please select from given options";
 }
		goto m;    	
}

void shopping :: administrator(){
	m:
	int choice;
	cout<<"\n\n\n\t\t\t administrator menu";
	cout<<"\n\t\t\t| ____1) Add the product ____|";
	cout<<"\n\t\t\t|                             ";
	cout<<"\n\t\t\t| ____2) Modify the product _|";
	cout<<"\n\t\t\t|                             ";
	cout<<"\n\t\t\t| ____3) Delete the product _|";
	cout<<"\n\t\t\t|                             ";
	cout<<"\n\t\t\t| ____4) Back to main menu __|";
	cout<<"\n\t\t\t|                             ";
	
	cout<<"Please enter your choice ";
	cin>>choice;
	
	switch(choice){
		case 1:
			add();
			break;
		case 2:
			edit();
			break;
		case 3:
			rem();
			break;
		case 4:
			menu();
			break;
		
		default:
			cout<<"Invalid choice";
	}
 	goto m;
	
}

void shopping :: buyer(){
	m:
	int choice;
	cout<<"\t\t\t       Buyer       \n";
	cout<<"\t\t\t__________________ \n";  
	cout<<"                         \n"; 
	cout<<"\t\t\t1) Buy product     \n";
	cout<<"                         \n";
	cout<<"\t\t\t2) Go back         \n";
	cout<<"\t\t\t  Enter your choice : ";
	cin>>choice;
	
	switch(choice){
		case 1:
			receipt();
			break;
		
		case 2:
			menu();
		
		default :
			
			cout<<"Invalid choice";
	}
	goto m;
}

void shopping ::add(){
    m:
	fstream data;
	int c;
	int token=0;
	float p;
	float d;
	string n;
	
	cout<<"\n\n\t\t\t Add new product ";
	cout<<"\n\n\t Code of the product ";
	cin>>pcode;
	cout<<"\n\n  Name of the product ";
	cin>>pname;
	cout<<"\n\n\t Price of the product";
	cin>>price;
	cout<<"\n\n\t Discount on the product ";
	cin>>dis;
	
	data.open("database.txt",ios::in);
	if(!data){
		data.open("database.txt", ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();
	}
	else{
		data>>c>>n>>p>>d;
		
		while(!data.eof()){
			if(c==pcode){
				token++;
			}
			data>>c>>n>>p>>d;
		}
		data.close();
	}
	
	if(token==1)
	{
	cout<<"\t\t\t\t|    Already exist               !\n";
	goto m;
	}
	else {
		data.open("database.txt", ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();
	}
	cout<<"\n\n\t\t Record inserted  !";
}


void shopping::edit(){
	fstream data,data1;
		int pkey;
		int token=0;
		int c;
		int p;
		int d;
		string n;
		
		cout<<"\n\t\t\t Modify the record " ;
		cout<<"\n\t\t\t  product code : ";
		cin>>pkey;
		
		data.open("database.txt" , ios::in);
		if(!data){
			cout<<"\n\n    File doesn't exist ! ";
		}
		else{
			data1.open("database1.txt", ios::app|ios::out);
			data>>pcode>>pname>>price>>dis;
			while(!data.eof()){
				if(pkey==pcode){
					cout<<"\n\t\t Product of new code :";
					cin>>c;
					cout<<"\n\t\t Name of the product :";
					cin>>n;
					cout<<"\n\t\t Price  :";
					cin>>p;
					cout<<"\n\t\t Discount :";
					cin>>d;
					data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
					cout<<"\n\n\t\t Record edited ";
					token++;
				}
				else{
					data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
				}
				data>>pcode>>pname>>price>>dis;
			}
			data.close();
			data1.close();
			
			remove("database.txt");
			rename("database1.txt","database.txt");
			
			if(token==0){
				cout<<"\n\n Record not found sorry! ";
			}
		}
}

void shopping::rem(){
	fstream data,data1;
	int pkey;
	int token=0;
	cout<<"\n\n\t Delete product";
	cout<<"\n\n\t Product code : ";
	cin>>pkey;
	data.open("database.txt", ios::in);
	if(!data)
	{
		cout<<"     File doesn't exist";
	}
	else
	{
		data1.open("database1.txt", ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof()){
			if(pcode==pkey){                                     //if found skip the copy else for each data there copy in else
				cout<<"\n\n\t Product deleted successfully";        
				token++;
			}
			else{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			data >>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt","database.txt");
		
		if(token==0){
			cout<<"\n\n Record not found";
		}
	}
}

void shopping:: list(){
	fstream data;
	data.open("database.txt", ios::in);
	cout<<"\n\n|____________________________________________\n";
	cout<<"Pro.code \t\t Name\t\t Price\t\t Discount        \n";
	cout<<"\n\n|_____________________________________________\n";
	data>>pcode>>pname>>price>>dis;
	while(!data.eof())
	{
		cout<<pcode<<"\t\t\t"<<pname<<"\t\t"<<price<<"\t\t"<<dis<<"\n";
		data>>pcode>>pname>>price>>dis;
	}
	data.close();
}

void shopping::receipt(){
	fstream data;
	int arrc[100];
	int arrq[100];
	string choice;
	int c=0;
	float amount=0;
	float dis=0;
	float total=0;
	
	cout<<"\n\n\t\t\t\t          RECEIPT                   ! ";
	data.open("database.txt", ios::in);
	if(!data)
	{
		cout<<"\n\n           Empty database                 ! ";
	}
	else{
		data.close();
		list();
		cout<<"\n___________________________________\n";
		cout<<"\n|                                  \n";
		cout<<"\n      Please place the order       \n";
		cout<<"\n|                                  \n";
		cout<<"\n___________________________________\n";
		
		do{
			m:
			cout<<"\n\n Enter product code : ";
			cin>>arrc[c];
			cout<<"\n\n Enter the product quantity : ";
			cin>>arrq[c];
			for(int i=0;i<c;i++)
			{
				if(arrc[c]==arrc[i])
				{
					cout<<"\n\n Duplicate product code. Please try again!   \n ";
					cout<<"\t\t\t Add new product \t\t\t      !";
					goto m;
				}
			}
			c++;
			cout<<"\n\n Do you want to buy another product? if yes then press yes else no  ";
			cin>>choice;
		}
	while(choice =="yes");
	
	cout<<" "<<c<<"\n";
	cout<<"\n\n\t\t\t________________RECEIPT________________\n";
	cout<<"\nPro. code \t Pro. Name \t Pro. quantity \t price \t Amount \t  Amount with discount \n";
	for(int i=0;i<c;i++)
	{
		data.open("database.txt" ,ios::in);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
			if(pcode==arrc[i])
			{
				amount=price*arrq[i];
				dis=amount-(amount*dis/100);
				total=total+dis;
				cout<<pcode<<"\t\t     "<<pname<<"\t      "<<arrq[i]<<"\t         "<<price<<"\t   "<<amount<<"\t\t          "<<dis<<"\n";
				
			}
			data>>pcode>>pname>>price>>dis;
		}
		//cout<<"       "<<arrc[i]<<"\n";
			data.close();
		}	
	
	}
	cout<<"\n\n_____________________________________";
	cout<<"\n Total Amount : "<<total;
}
int main(){
	shopping s;
	s.menu();

}
