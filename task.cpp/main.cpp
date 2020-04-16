// name: Alaa Adel Mohamed Soliman  ID:20180050  G:1
// name: Eman Salah ELdin Abdelfatah ID:20180063  G:1

#include <iostream>
#include<cctype>
#include<cstring>
using namespace std;

struct  trans
{
	int tran;
	char DW;
	int ntran;
};

double transaction(struct trans *cust, int  x, int i, double* balance,double *p_balance) {
	double c = 0, f = 0;
	cout<< "How many transaction do you want to enter\n" << "Max you can enter 10 transactions\n";
    cin >> cust[i].ntran;
    x = cust[i].ntran;
    cout<<"\n";
    while (x <= 0 || x > 10) {
        cout << "reenter again\n"; cin >> cust[i].ntran;
        x = cust[i].ntran;
		}
	cout << "First enter D for Deposit or W for withdraw\n" << "Then enter the value of transaction\n";
    for (int j = 0; j < x; j++) {
            cin >> cust[j].DW>>cust[j].tran;
            double z = cust[j].tran;
		    while ((cust[j].DW != 'D'&&cust[j].DW != 'd') &&(cust[j].DW != 'W'&&cust[j].DW != 'w')||(z<0)) {
			cout << "reenter again\n" << "enter valid transaction\n"; cin >> cust[j].DW>> cust[j].tran;
                z=cust[i].tran;
			}
		if (cust[j].DW == 'd' || cust[j].DW == 'D') {
			c += (1 * z);
		}
		if (cust[j].DW == 'w' || cust[j].DW == 'W') {
			f += (-1 * z);
		}
		balance[i] =p_balance[i]+c + f;
	}
    cout << "\n";
	return balance[i];
}

void name( char*fname,char *lname) {
	cout << "Enter the name of the client:first and last name\n";
	cin >> fname>> lname;
}

void adress(char*nstreet,char*address,char*neighborhood ,char* city) {
    cout << "\n" << "Enter address in these form \n" << "number of street, name of street, neighborhood, city\n";
	cin >> nstreet >> address >> neighborhood >> city;
  int len1=strlen(nstreet),len2=strlen(address),len3=strlen(neighborhood);
	for(int i=len1-1;i>=0;i--){
   if(nstreet[i]<'0' || nstreet[i]>'9'){
            cout<<"enter number not char\n ";
            cin>>nstreet;}
    }
  if(int(address[len2-1])!=44 ) {
            cout<<"enter , after name of street \n";
            cin>>address;}
  if(int(neighborhood[len3-1])!= 44) {
            cout<<"enter , after name of name of neighborhood \n";
            cin>>neighborhood;}
}


int main()
{
    char  fname[20], lname[20], address[20], neighborhood[20], city[20],nstreet[10];
	int n, m, x, i, j, z, k, choice, option;
	double balance[20], f = 0, c = 0,p_balance[20];
	string name1, name2, city_1;


	struct trans cust[20];

	cout << "How many clients do you want to enter their data\n" << "Max you can enter 20 clients\n"; cin >> n;
	while (cin.fail()){
    cin.clear();
    cin.ignore();
    cout<<"you enter invalid input. re enter again\n";
    cin>>n;
	}
	cout << "\n";
	while (n < 0 || n>20) {
		cout << "reenter again\n"; cin >> n;
		while (cin.fail()){
    cin.clear();
    cin.ignore();
    cout<<"you enter invalid input. re enter again\n";
    cin>>n;
	}
	}
	for (i = 0; i < n; i++)
	{
		cout << "Enter data of client " << i + 1 << ":\n-------------------------------\n";
		name(fname,lname);
		adress(nstreet,address,neighborhood ,city);
        cout<<"\nenter primary balance of client "<<i+1<<"\n";cin>>p_balance[i];
        while(p_balance[i]<0){
            cout<<"enter positive balance\n";cin>>p_balance[i];
         }
        cout << "\n";
		cout << "the balance is " << transaction(cust, x, i, balance,p_balance) << endl;
		cout << "\n\n";
	}

        do{
		cout << "\nHello in bank management system please enter your choice\n" << " 1)To print all name and account balances\n" << " 2)To print specific customer's account balance\n"
			<< " 3)To edit customer transactions\n" << " 4)To show customer with highest balance\n" << " 5)To change customer name, transactions, balance, or address\n"
			<< " 6)To show how many customers in one city\n\n ";
		cout << "enter your option\n"; cin >> m;

		if (m == 1) {
			for (int i = 0; i < n; i++)
			{
				cout << "\nname of client" << i + 1 << ":" <<fname << " " << lname << "\n";
				cout << "balance = " << balance[i] << "\n";
			}
		}

        if (m == 2)
		{
			cout << "enter the first  the second name you want to find it\n";
			cin >> name1 >> name2;
			cout<<"\n";
			for (int i = 0; i < n; i++)
			{
				if (name1 == fname&& name2 == lname) {
					cout << "account balance of " << fname << " " <<lname << ":" << balance[i];
				}
			}
		}

		if (m == 3) {
			char w;
			int q;
			cout << "enter the first,second name you want to edit his transaction \n";
			cin >> name1 >> name2;
			cout<<"\n";
			for (int i = 0; i < n; i++)
			{
				if (name1 == fname&& name2 ==lname) {
					cout << "enter the transaction you want to change d or w and value of transaction \n";
					cin >> w >> q;
					for (int i = 0; i < n; i++)
					{
						if ( w==cust[i].DW && q== cust[i].tran)
						{
							cout << "enter the new transaction \n";
							cin >> cust[i].DW>>cust[i].tran;
						}
					}
				}
			}
		}

		if (m == 4) {
		int max = 0, g = 0,y;
		y=n;
		while (y>= 0) {
             if (balance[g] > max) max = balance[g];
            g += 1;
			y -= 1;
		}
		for(int i=0 ; i<n ; i++)
        {
            if(max==balance[i])
            {
                cout<<"\nclient with highest balance is "<<fname<<" "<<lname<<"\n balance:"<<max;
            }
        }
	}

		if (m == 5) {
			int t;
			do {
				cout << "\nEnter choice\n" << " 1)for change customer's name\n" << " 2)for change transactions and balance\n" << " 3)for change address\n";
				cin >> t;
				while (t < 0 && t>3) {
					cout << "these non valid choice\n" << "enter another one\n"; cin >> t;
				}
				switch (t) {

                case 1: do {
                    cout << "\nenter name of client you want to change his name\n";
                    cin >> name1 >> name2;
                    for (int i = 0; i < n; i++) {
                        if (name1 == fname&& name2 == lname) {
							name(fname,lname);
							cout << "\nnew name of client " << i + 1 << "is: " << fname << "  " << lname;
						}
					}
					cout << "\ndo you want to change another client's name\n" << "enter 1 for yes or 0 for no\n"; cin >> k;
					while (k != 1 && k != 0) {
						cout << "reenter valid choice\n"; cin >> k;
					}
				} while (k == 1);
				break;

				case 2: do {
					cout << "\nenter name of client you want to change his transactions\n";
					cin >> name1 >> name2;
					for (int i = 0; i < n; i++) {
						if (name1 == fname&& name2 == lname) {
                            transaction(cust, x, i, balance,p_balance);
							cout << "\nnew balance of client " << fname << " " << lname << ":" << balance[i];
						}
					}
					cout << "\ndo you want to change another client's transactions\n" << "enter 1 or yes and 0 for no\n"; cin >> k;
					while (k != 1 && k != 0) {
						cout << "reenter valid choice\n"; cin >> k;
					}
				}
                while (k == 1);
				break;

				default:do {
					cout << "\nenter name of client you want to change his address\n";
					cin >> name1 >> name2;
					for (int i = 0; i < n; i++) {
						if (name1 == fname&& name2 == lname) {
							adress(nstreet,address,neighborhood , city);
							cout << "\nnew address of the client" << fname << " " << lname << " is: " << nstreet << address << "," <<neighborhood << "," << city;
						}
					}
					cout << "\ndo you want to change another client's address\n" << "enter 1 or yes or 0 for no\n"; cin >> k;
					while (k != 1 && k != 0) {
						cout << "reenter valid choice\n"; cin >> k;
					}
				} while (k == 1);
				}

				cout << "\n do you want to choose another option enter 1 for yes or 0 for no\n"; cin >> choice;
				while ((choice != 0) && (choice != 1)) {
					cout << "reenter valid choice\n"; cin >> choice;
				}
			}   while (choice == 1);
		}

		if (m == 6) {
			do {
				cout << "\nenter name of city you want to calculate its clients\n";
				cin >> city_1;
				int count = 0;
				for (i = 0; i < n; i++) {
					if (city_1 == city) {
						count += 1;

					}
				}
				cout << "numbers of client in \n" << city_1 << "= " << count;
				cout << "\ndo you want to enter another city to calculate its clients\n" << "enter 1 for yes or 0 for no\n"; cin >> option;
				while (option != 1 && option != 0) {
					cout << "enter valid choice\n"; cin >> option;
				}
			} while (option == 1);
			cout<<"\n";
		}

		cout << "\ndo you want to enter another option enter 1 for yes or 0 for no\n"; cin >> option;
		while (option != 1 && option != 1) {
			cout << "enter valid choice\n"; cin >> option;
		}
        }

      	while (option == 1);

	return 0;
}













