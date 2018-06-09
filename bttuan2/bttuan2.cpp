// bttuan2.cpp : Defines the entry point for the console application.
//
#include<stdc++.h>
#include<conio.h>
using namespace std;
fstream data_file;
string fileName;
ofstream myfile;

ifstream fi ("BRACKET.INP");
ofstream fo ("BRACKET.OUT");
string a;
/*******************************************
				bai 1
********************************************/

void kiemtradayngoac() {
	
	int mongoac=0;
	vector<int> b, c;
	fi >> a;
	int n = a.size();
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] == '(') {
			b.push_back(i);
		}
		else {
			if (b.size() == 0) {
				c.push_back(i);
			}
			else {
				b.pop_back();
			}
		}
	}
	
	if (b.size() + c.size() == 0) {
		fo << "0";
	}
	else {
		fo << b.size() + c.size() << endl;
		for (int i = 0; i < c.size(); ++i) fo << '(' << " " << mongoac++ << endl;
		for (int i = 0; i < b.size(); ++i) fo << ')' << " " << n++ << endl;
	}
}
void fileb1()
{
	system("cls");
	kiemtradayngoac();
	_getch();
}

/*******************************************
               bai 2
********************************************/
void Search()
{
	system("cls");
	fflush(stdin);
	int count = 0;
	int pos;
	int index = 0;
	string ch, c;
	string tk;
	data_file.open(fileName, ios::in);
	myfile.open("OUTPUT.TXT", ios::out);

	cout << "1.search 2.edit 3.exit\n\n";
	cout << "Enter word to search: ";
	cin >> c;
	//c = c + " ";
	myfile << "Enter word to search: ";
	myfile << c << endl;
	if (c[0] >= 97 && c[0] <= 122)
	{
		tk = c;
		tk[0] -= 32;
	}
	else if (c[0] >= 65 && c[0] <= 90) {
		tk = c;
		tk[0] += 32;
	}
	while (!data_file.eof())
	{
		index++;
		pos = 0;
		getline(data_file, ch);
		while ((pos = ch.find(c, pos)) != string::npos) {
			cout << "line: " << index << " col: " << pos << endl;
			myfile << "\tline: " << index << " col: " << pos << endl;
			pos++;
			count++;
		}
		pos = 0;
		while ((pos = ch.find(tk, pos)) != string::npos) {
			cout << "line: " << index << " col: " << pos << endl;
			myfile << "\tline: " << index << " col: " << pos << endl;
			pos++;
			count++;
		}
	}
	cout << "\nOccurrence=" << count;
	data_file.close(); //closing file
	myfile.close();
	cout << "\r\n>> Chon (1->3) tuong ung voi menu: ";
	_getch();
}
void replace()
{
	system("cls");
	fflush(stdin);
	myfile.open("OUTPUT.TXT", ios::out);
	data_file.open(fileName, ios::in);

	int pos;
	int index = 0;
	string line = " ";
	string text, text2;
	string data;
	cout << "1.search 2.edit 3.exit\n\n";
	cout << "Enter word to replace: ";
	cin >> text;
	//text = text + " ";
	myfile << "Enter word to replace: ";
	myfile << text << endl;

	cout << "Replace with the word: ";
	cin >> text2;
	//text2 = text2 + " ";
	myfile << "Replace with the word: ";
	myfile << text2 << endl;

	while (!data_file.eof())
	{
		int tg = 0;
		index++;
		pos = 0;
		getline(data_file, line);
		while ((pos = line.find(text, pos)) != string::npos) {
			tg = 1;
			line.replace(pos, text.length(), text2);
			myfile << "\tline: " << index << " col: " << pos << endl;
			pos++;
		}
		if (tg == 0) {
			data += line + "\n";
		}
		else {
			data += line + '\n';
		}

	}
	data_file.close();
	data_file.open(fileName, ios::out);
	data_file << data;
	myfile << "Replace " <<"'"<<text <<"'" <<" by " <<"'"<<text2 <<"'";
	data_file.close(); //closing file
	myfile.close();
	cout << "\r\n>> Chon (1->3) tuong ung voi menu: ";
	_getch();
}
void nhapfile()
{
	system("cls");
loop:
	cout << "Enter file name: ";
	cin >> fileName;
	data_file.open(fileName, ios::in);
	bool ret = data_file.fail();
	if (ret == true) {
		cout << "File don't exist\n";
		goto loop;
	}
	else
	{
		cout << "File exist\n";
		cout << "Danh sach cac bai tap:\r\n";
		cout << "\t1. Search\r\n";
		cout << "\t2. Replace \r\n";
		cout << "\t3. exit 3\r\n";
		cout << "\r\n>> Chon (1->3) tuong ung voi bai tap: ";
	}
	data_file.close();
}
void fileb2() {
	system("cls");
	nhapfile();
	int choice = 0;
	do {
		fflush(stdin);
		cin >> choice;
		switch (choice) {
		case 1:
			Search();
			break;
		case 2:
			replace();
			break;
		case 3:break;
		default:
			cout << "\r\n>> Ban chon sai, an phim bat ki de chon lai..";
			_getch();
		}
		if (choice == 3)
		{
			break;
		}
	} while (1);
	_getch();
}
void mainfile()
{
	system("cls");
	// 2. Mở file
	fstream data_file;
	data_file.open("input.txt", ios::out);

	// 3. Ghi dữ liệu vào file, trường hợp này ta có data là dữ liệu
	string data =
		"Now we will talk about Exception Handling.\n\nHere in this program, we have kept it simple so nothing much to worry about here, however, we do\ntake the name from the user\nThe array we use to store the name is of size 30. What will happen if user enters a string that is more\nthan 30 in length? This would result in a buffer overflow. This may crash your program right away or\nproduce unexpected results.\n\nTo avoid this either we can write a function that would get a string from the stdin one by one and stops if\nEnter is pressed or if string is more than 30 OR we can use the inbuilt function known as fgets.\nThanks!";
	data_file << data;

	// 4. Đóng file
	data_file.close();
	printf("\r\n\r\n>> An phim bat ki de quay lai chuong trinh chinh...");
	_getch();
}
/*******************************************
				MAIN
********************************************/
void print_menu() {
	cout << "Danh sach cac bai tap:\r\n";
	cout << "\t1. Exercise 1\r\n";
	cout << "\t2. Exercise 2\r\n";
	cout << "\t3. Exercise 3\r\n";
	cout << "\t4. Exit program\r\n";
	cout << "\r\n>> Chon (1->4) tuong ung voi bai tap: ";
}
int main()
{
	int choice = 0;
	do {
		// Clear screen
		system("cls");
		// Print intro
		print_menu();
		fflush(stdin);
		scanf_s("%d", &choice);
		switch (choice) {
		case 1:
			fileb1();
			break;
		case 2:
			fileb2();
			break;
		case 3:
			mainfile();
			break;
		case 4:
			break;
		default:
			printf("\r\n>> Ban chon sai, an phim bat ki de chon lai..");
			_getch();
		}
		if (choice == 4)
		{
			break;
		}
	} while (1);
	// Stop to view
	printf("\r\n>> Nhap phim bat ki de ket thuc chuong trinh...");
	_getch();
	return 0;
}
