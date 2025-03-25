#include <iostream>
#include <fstream>
using namespace std;
//Работа с файлами

void WriteAndRead(const char* filename) {
	int number[5];
	cout << "Введите 5 чисел";
	for (int i = 0; i < 5; i++)
	{
		cin >> number[i];
	}
	ofstream outFile(filename);
	if (outFile.is_open())
	{
		for (int i = 0; i < 5; i++)
		{
			outFile << number[i] << endl;
		}
		outFile.close();
	}
	ifstream inFile(filename);
	int newNumber[5];
	if (inFile.is_open())
	{
		int sum = 0;
		for (int i = 0; i < 5; i++)
		{
			inFile >> newNumber[i];
			sum += newNumber[i];
		}
		inFile.close();
		cout << sum;
	}

}

void CopyFile(const char* input,const char* output) {
	ifstream inFile(input);
	ofstream outFile(output);

	if (!inFile.is_open() && !outFile.is_open())
	{
		cout << "Не удалось открыть файл";
		return;
	}

	char buffer[20];
		inFile.read(buffer, sizeof(buffer));
		outFile.write(buffer, sizeof(buffer));
	
	inFile.close();
	outFile.close();
	cout << "Файлы скопированы";

}

int main() {
	setlocale(LC_ALL, "ru");
	system("chcp 1251");
	//ifstream inFile("File.txt");
	//char buffer[1024];
	//int countSymbol = 0;
	//while (!inFile.eof())
	//{
	//	inFile.read(buffer, sizeof(buffer));
	//	countSymbol = inFile.gcount();
	//}
	//buffer[countSymbol] = '\0';
	//inFile.close();
	///*cout << buffer<<endl;*/


	//ofstream outFile("output.txt");
	//cout << "Введите строку";
	//char str[50];
	//cin.getline(str, 50);

	//cout << str;

	//if (outFile.is_open())
	//{
	//	outFile << str<<endl;
	//	outFile.close();
	//}
	//else
	//{
	//	cout << "Не удалось открыть файл";
	//}
	////while (!outFile.eof())
	////{
	////	outFile.write(str,50);
	////}
	//outFile.close();

	//char str2[] = "I Love c++";
	//ofstream OutFile2("output.txt",std::ios::app);
	//if (OutFile2.is_open())
	//{
	//	OutFile2 << str2 << endl;
	//	OutFile2.close();
	//}
	
	/*WriteAndRead("number.txt");*/

	CopyFile("output.txt", "newFile.txt");
}

//cammit