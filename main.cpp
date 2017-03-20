#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
using namespace std;

struct MOT
{
	char mnemonics[4];
	char opcode;
	char instruction[2];
	char format[3];

};
struct POT
{
	char pseudo_op[5];
	char address;
};
struct SYMBOL
{
		char symbol[8];
		char value[4];
		char length;
		bool relocation;
};
struct LITERAL
{
		char symbol[8];
		char value[4];
		char length;
		bool relocation;
};
class Assembler
{
	public:
	 void addMOT();
	 void addPOT();
	 void view();
	 void convert();
	 
};
 void Assembler::addMOT()
{
	ofstream out;
	out.open("MOT.txt",ios::app);
	if(!out)
	{
		cout<<"Program self Error Handle: Unable to open MOT\n";
		exit(29);
	}
	MOT m;
	cout<<"Mnemonic: ";
	cin>>m.mnemonics;
	out<<m.mnemonics;
	cout<<"\nBinary Op Code :";
	cin>>m.opcode;
	out<<m.opcode;
	cout<<"\nInstruction Length :";
	cin>>m.instruction;
	out<<m.instruction;
	cout<<"\n Format :";
	cin>>m.format;
	out<<m.format;
	out<<endl;
	out.close();

	
}
 void Assembler::addPOT()
{
	ofstream out;
	out.open("POT.txt",ios::app);
	if(!out)
	{
		cout<<"Program self Error Handle: Unable to open POT\n";
		exit(29);
	}
	POT m;
	cout<<"\nEnter Pseudo-Op :";
	cin>>m.pseudo_op;
	out<<m.pseudo_op;
	cout<<"\nAddress of subroutine :";
	cin>>m.address;
	out<<m.address;
	out<<endl;
	cout<<"\nSuccesfully written to POT\n";

	
}
 void Assembler::view()
{
}
 void Assembler::convert()
{
	ofstream out;
	ifstream in;
	in.open("source.txt");
	char SYMBOL[8];
	char INSTRUCTION[5];
	char OPERAND[8];
	
	while(1)
	{
		char line[25];
		if(!in.getline(line,25))
			break;
		
		cout<<endl;
		string s=line;
		string n=s.substr(0,s.find_first_of(' '));
		cout<<endl<<n;

		getch();
	}
	

	
	out.open("I.txt",ios::app);

}
int main()
{
	cout<<"Menu \n"<<"1- Add Instructions to MOT\n"<<"2- Add Instructions to POT"<<"3- View Instructions\n"<<"4- Convert \n";
	int  c;
	cin>>c;
	Assembler a;
	switch(c)
	{
		case 1: 
			a.addMOT();
			break;
		case 2:
			a.addPOT();
			break;
		case 3: 
			a.view();
			break;
		case 4:
			a.convert();
		default:
			cout<<"Wrong input exit\n";
			exit(0);
	}
}