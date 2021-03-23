#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

//please if this work i will eat all the vegetables and will not bite my mother when she tries to wash me

using namespace std;

unsigned hash(string s) {
	unsigned h = 0;
	for (int i = 0; i < s.size(); i++) 
		h = h * 101 + (unsigned) s[i];
	return h; 
}


struct Student {
	string login;
	string password;
	string mail;
	string group;
	bool logged_in = false;
	
	void readData(bool All);
	void createAccount();
	void signUp();
	void getWeek();
	void getMarks();
};


void Student::readData(bool All) {
	cin >> login;
	cin >> password;
	if(All) {
	cin >> mail;
	cin >> group;
	}
}

void Student::createAccount() {
	ofstream of("acc.txt", ios_base::app);
	
	string hLogin, hPassword;
	hLogin = hash(login);
	hPassword = hash(password);
	
	of << hLogin << " " << hPassword << " " << mail << " " << group << endl;
	of.close();
	
	cout << "successfully signed up" << endl;
	logged_in = true;
}

void Student::signUp() {
	ifstream Acc("acc.txt");
	
	string hLogin, hPassword, cLogin, cPassword, pass_string;
	bool NLI = true;
	hLogin = hash(login);
	hPassword = hash(password);
	
	while (NLI && !Acc.eof()) {
		Acc >> cLogin;
		Acc >> cPassword;
		Acc >> mail;
		Acc >> group;
		if (cLogin == hLogin && cPassword == hPassword) {
			NLI = !NLI;
			cout << "successfully logged in" << endl;
			logged_in = true;
		}
	}
	if(NLI) {
		cout << "wrong login/password" << endl;
		logged_in = false;
	} 
	Acc.close();
}


void Student::getWeek() {
	cout << endl << "LESSONS:" << endl;
	ifstream Table("table.txt");
	string t_group, week;
	bool cont = true;
	while(cont && !Table.eof()) {
		Table >> t_group;
		Table >> week;
		if (t_group == group) cont = !cont;
		while (week != "fin") {
			if (t_group == group) cout << week << endl;
			Table >> week;
		}
		
	}
	Table.close();
}

void Student::getMarks() {
	cout << endl << "MARKS:" << endl;
	ifstream Marks("marks.txt");
	string t_login, lesson;
	bool cont = true;
	while(cont && !Marks.eof()) {
		Marks >> t_login;
		Marks >> lesson;
		if (t_login == login) cont = !cont;
		while (lesson != "fin") {
			if (t_login == login) cout << lesson << endl;
			Marks >> lesson;
		}
	}
	Marks.close();
}


int main() {
	cout << "create account? (y/n)" << endl;
	char n;
	cin >> n;
	bool New = n == 'y';
		 
	if(New) cout << "login, password, email, class" << endl;
	else cout << "login, password" << endl;
	Student me;
		 
	me.readData(New);
	if(New) me.createAccount();
	else me.signUp();
	if (me.logged_in) { 
		me.getWeek();
		me.getMarks();
	}
	return 0;
 }
