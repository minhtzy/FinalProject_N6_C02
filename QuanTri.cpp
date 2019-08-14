#include<QuanTri.h>
#include<iostream>
using namespace std;
QuanTri::QuanTri(){
	username ='\0';
	password ='\0';
}
//void QuanTri::Input(){
//	cout<<"Nhap vao ten nguoi dung: ";
//	cin>>username;
//	cout<<"Nhap vao mat khau: ";
//	cin>>password;
//}
int QuanTri::docfile(ifstream &doc){
	if(!doc){
		cout<<"Cannot open file!";
	}
	getline(doc,username);
	getline(doc,password);
}
bool QuanTri::checklogin(string name, string pass){
	if(name=username&&pass=password){
		return true;
	}else return false;
}
void DSQuanTri::doc(){
	ifstream f;
	f.open("quantri.dat",ios::in);
	if(!f){
		cout<<"Cannot open file!";
	}
	f>>num;
	for(int i=0;i<num;i++){
		f.ignore();
		ds[i].docfile(f);
	}
}
void menu(){
	int opt;
	do{
		
		cout<<"LOGIN"<<endl;
		cout<<"1.Login"<<endl;
		cout<<"2.Register"<<endl;
		cout<<"3.Exit"<<endl;
		cout<<"Your option: ";
		cin>>opt;
		cin.ignore();
		switch(opt){
			case 1:{
				doc();
				string name;
				string pass;
				cout<<"Input name: ";
				cin>>name;
				cout<<"Input pass: ";
				cin>>pass;
//				input();
				int ok=0;
				for(int i=0;i<num;i++){
					if(ds[i].checklogin(name,pass)==true){
						ok=1;
						break;
					}
				}
				if(ok){
					int opt2;
					do{
						cout<<"Option: ";
						cout<<"1.Update status nguoi dung"<<endl;
						cout<<"2.Thong ke khieu nai"<<endl;
						cout<<"3.Xu ly khieu nai"<<endl;
						cout<<"4.Logout";
						cout<<"Your option: ";
						cin>>opt2;
						cin.ignore();
						switch(opt2){
							case 1:{
								break;
							}
							case 2:{
								break;
							}
							case 3:{
								break;
							}
						}
					}while(opt2!=4);
				}
				break;
			}
		}
	}while(opt!=3);
}
