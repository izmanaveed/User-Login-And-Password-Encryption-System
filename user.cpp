//USER LOGIN AND PASSWORD ENCRYPTION SYSTEM
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int set_hint();
int use_hint();
void encrypt_login (char x[]);
void encrypt_password (char x1[]);
void decrypt_login (char y[]);
void decrypt_password (char y1[]);
void R();
char login_id[10];
char password[8];
float E[3][1], a[3][3], message[3][1], key[3][3]= {6,24,1,13,16,10,20,17,15};		
void encrypt();   
void enter_key_and_message();   

using namespace std;

class ENCRYPTION
{
	private:
		int choice;
	public:
	int choose_type();
};


class Access: protected ENCRYPTION
{
	private:
		int age;
		char name[30];
		char gender[8];
	public:
		int n,m;
		void set();	
		void enter_data();
};

class User:public Access
{
	protected:
		char login_id1[10];
		char password1[8];
		int flag=1;
		int flag1=1;
	public:
		int compare_login();
		int compare_password();	
};

class CEASER_CIPHER: public User
{
	private:
		int r;
	public:
		void R();
		void encrypt_login(char x[]);
		void encrypt_password (char x1[]);
		void decrypt_login (char y[]);
		void decrypt_password (char y1[]);
};


class HILL_CIPHER: public User
{
	private:
		int i, j, k;
    char msg[3];
	public:
	void encrypt();
	void enter_key_and_message();
};



main()
{
	CEASER_CIPHER CC;
	HILL_CIPHER HC;
	ENCRYPTION e1;
	int L,P,X,SH,UH;
	char choose;
	char a[100];
	Access a1;
	User u1;
	cout<<"			USER LOGIN AND PASSWORD ENCRYPTION SYSTEM "<<endl;
	a1.enter_data();
	u1.set();
	cout<<"YOU HAVE SUCCESSFULLY SET YOUR LOGIN ID AND PASSWORD!"<<endl;
	SH=set_hint();
	L= u1.compare_login();
	P= u1.compare_password();
	if (L==1&&P==1)
	{
		X=e1.choose_type();
		if (X==1)
		{
			cout<<"Key used for encryption will be: "<<endl;
			CC.R();
			cout<<"The encrypted login is: "<<endl;
			CC.encrypt_login(login_id);
			cout<<login_id<<endl;
			cout<<"The encrypted password is: "<<endl;
			CC.encrypt_password(password);
			cout<<password<<endl;
			cout<<"The decrypted login is:"<<endl;
			CC.decrypt_login(login_id);	
			cout<<login_id<<endl;
			cout<<"The decrypted password is:"<<endl;
			CC.decrypt_password(password);	
			cout<<password<<endl;			
		}
	
		else if (X==2)
		{
			HC.enter_key_and_message();  
    		HC.encrypt();
		}

	}
	
	else if (L!=1||P!=1)
{
	cout<<"Invalid login or password."<<endl;

	cout<<"Need a hint? Press Y for yes or N for no"<<endl;
	cin>>choose;
	if (choose=='Y')
	{
	UH=use_hint();
    }
	if (SH==UH)
	{
	u1.set();
	cout<<"YOU HAVE SUCCESSFULLY RESET YOUR LOGIN ID AND PASSWORD!"<<endl;
	}
	else 
	{
		cout<<"Please try again next time"<<endl;
	}
}
}


//function definitions
int set_hint()
{
	int set_number;
	cout<<"In case of forgetting login or password, answer the following question so that you may reset login id and password if needed "<<endl;
	cout<<"Enter your favourite number"<<endl;
	cin>>set_number;
	return set_number;

}
int use_hint()
{
	int use_number;
	cout<<"What is your favourite number?"<<endl;
	cin>>use_number;
	return use_number;
}
int ENCRYPTION::choose_type()
{
	cout<<"DO YOU WISH TO ENCRYPT CURRENT LOGIN ID AND PASSWORD? IF YES, PRESS 1."<<endl;
	cout<<"IF YOU WISH TO CREATE AN ENCRYPTED LOGIN ID PASSWORD, press 2."<<endl;
	cin>>choice;
	return choice;
}
void Access::set()
{
	cout<<"enter number of characters you wish to set for your login id"<<endl;
	cin>>n;
	cout<<"enter number of characters you wish to set for your login password"<<endl;
	cin>>m;
	cout<<"set user login id (must be less than "<<n<<" characters): "<<endl;
	for (int i=0; i<n; i++)
	{
		cin>>login_id[i];
	}
	cout<<"set user login password (must be less than "<<m<<" characters): "<<endl;
	for (int i=0; i<m; i++)
	{
		cin>>password[i];	
	}
}
void Access::enter_data()
{
	cout<<"Please enter your name:"<<endl;
	cin>>name;
	cout<<"Please enter age:"<<endl;
	cin>>age;
	cout<<"Please specify gender:"<<endl;
	cin>>gender;
}
int User::compare_login()
{
	cout<<"enter login id : "<<endl;
	for (int i=0; i<n; i++)
	{
		cin>>login_id1[i];
	}	
	for (int i=0; i<n; i++)
	{
		if (login_id[i]==login_id1[i])
		{
			return flag;
		}
		else if (login_id[i]!=login_id1[i])
		{
			break;
		}
	}
}
int User::compare_password()
{
	cout<<"enter user login password : "<<endl;
	for (int i=0; i<m; i++)
	{
		cin>>password1[i];	
	}
	for (int i=0; i<m; i++)
	{
		if (password[i]==password1[i])
		{
			return flag1;
		}
		else if (password[i]!=password1[i])
		{
			break;
		}
	}
	
}
void CEASER_CIPHER::R()		
{
	srand (time(NULL));
	r=rand() %26+1;
	cout<<r<<endl;
}	
void CEASER_CIPHER::encrypt_login(char x[])
{
	for (int i=0; x[i]!='\0'; i++)
	{
		x[i]=x[i]+r;
	}
}
void CEASER_CIPHER::encrypt_password (char x1[])
{
	for (int i=0; x1[i]!='\0'; i++)
	{
		x1[i]=x1[i]+r;
	}	
}
void CEASER_CIPHER::decrypt_login (char y[])
{
	for (int j=0; y[j]!='\0'; j++)
	{
		y[j]=y[j]-r;
	}
}
void CEASER_CIPHER::decrypt_password (char y1[])
{
	for (int j=0; y1[j]!='\0'; j++)
	{
		y1[j]=y1[j]-r;
	}
}
void HILL_CIPHER::encrypt()
{
	for(i = 0; i < 3; i++)
    {
		for(j = 0; j < 1; j++)
        {		
			for(k = 0; k < 3; k++)
               {   
			    E[i][j] = E[i][j] + key[i][k] * message[k][j];
				}
		}
	}
    cout<<"Encrypted message is: "<<endl;
    for(i = 0; i < 3; i++)
        {
		cout<<(char)(fmod(E[i][0], 26) + 65);
		}	
}
void HILL_CIPHER::enter_key_and_message()
{
	cout<<"Enter message for encryption (must be of 3 charcters only): "<<endl;
    cin>>msg;    
    for(i = 0; i < 3; i++)
{
   message[i][0] = msg[i] - 65;
}
}

