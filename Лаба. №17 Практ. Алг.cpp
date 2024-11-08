#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cwctype>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Student { // Завдання 1
	string name;
	string surname;
	int age;
};

void writeToFile1(const string& filename) { // Завдання 1
	ofstream outfile(filename);

	if (!outfile) {
		cerr << "Помилка відкриття файлу для запису!" << endl;
		return;
	}

	srand(time(0));
	vector<Student> students = { {"Іван", "Петренко", rand() % 8 + 18},
								 {"Марія", "Шевченко", rand() % 8 + 18},
								 {"Олег", "Бондаренко", rand() % 8 + 18}
							   };

	for (const auto& student : students) {
		outfile << student.surname << " " << student.name << " " << student.age << endl;
	}

	//outfile << "Петренко Іван 20\n";
	//outfile << "Шевченко Марія 21\n";
	//outfile << "Бондаренко Олег 19\n";
	outfile.close();
}

bool isLetter1(wchar_t c) { // Завдання 1

	//return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
		//(c >= 'А' && c <= 'Я') || (c >= 'а' && c <= 'я') || (c == 'Є' || c == 'є' || c == 'І' || c == 'і' || c == 'Ї' || c == 'ї' || c == 'Ґ' || c == 'ґ');
	return iswalpha(c);
}

vector <Student> readFromFile1(const string& filename, int& letter_count) { // Завданя 1
	ifstream infile(filename);
	if (!infile) {
		cerr << "Помилка відкриття файлу для читання!" << endl;
		return {};
	}

	vector <Student> students;
	string name, surname;
	int age;
	letter_count = 0;

	while (infile >> surname >> name >> age) {
		students.push_back({ name, surname, age });

		for (auto c : surname + name) {
			if (isLetter1(static_cast<wchar_t>(c))) {
				letter_count++;
			}
		}
	}

	infile.close();
	return students;
}

void displayAge1(const vector <Student>& students) { // Завдання 1
	cout << "Вік студентів:" << endl;
	for (const auto& student : students) {
		cout << student.surname << " " << student.age << endl;
	}
}

void displayNames1(const vector <Student>& students) { // Завдання 1
	cout << "Прізвище та ім'я студентів:" << endl;
	for (const auto& student : students) {
		cout << student.surname << " " << student.name << endl;
	}
}

void displayStudents1(const vector<Student>& students) { // Завдання 1
	cout << "Інформація про студентів:\n";
	for (const auto& student : students) {
		cout << student.age << " " << student.surname << " " << student.name << endl;
	}
}

void writeToFile2(const string& filename, int number) { // Завдання 2
	ofstream outfile(filename, ios::app);

	if (!outfile) {
		cerr << "Помилка відкриття файлу для запису!" << endl;
		return;
	}

	outfile << number << endl;
	outfile.close();
}

int readFromFile2(const string& filename) { // Завдання 2
	ifstream infile(filename);
	if (!infile) {
		cerr << "Помилка відкриття файлу для читання!" << endl;
		return -1;
	}

	int number;
	infile >> number;
	infile.close();
	return number;
}

void writeToFile2Rand(const string& filename) { // Завдання 2
	ofstream outfile(filename);

	if (!outfile) {
		cerr << "Помилка відкриття файлу для запису!" << endl;
		return;
	}

	srand(time(0));
	int number = rand() % 900 + 100;
	cout << "Згенероване трицифрове число: " << number << endl;
	outfile << number << endl;
	outfile.close();
}


void swapFirstAndLastDigits(string& numberStr) { // Завдання 2
	if (numberStr.length() == 3) {
		swap(numberStr[0], numberStr[2]);
	}
}

void writeToFile3(const string& filename) { // Завдання 3
	ofstream outfile(filename, ios::app);

	if (!outfile) {
		cerr << "Помилка відкриття файлу для запису!" << endl;
		return;
	}

	srand(time(0));
	for (int i = 0; i < 5; i++) {
		int number = rand() % 900 + 100;
		outfile << number << endl;
	}

	outfile.close();
}

int countEvenDigitsInFile(const string& filename) { // Завдання 3
	ifstream infile(filename);
	if (!infile) {
		cerr << "Помилка відкриття файлу для читання!" << endl;
		return -1;
	}

	int count = 0;
	string numberStr;

	while (infile >> numberStr) {
		for (char digit : numberStr) {
			if (isdigit(digit) && (digit - '0') % 2 == 0) {
				count++;
			}
		}
	}

	infile.close();
	return count;
}

void writeToFile4(const string& filename) { // Завдання 4
	ofstream outfile(filename);
	if (!outfile) {
		cerr << "Помилка відкриття файлу для запису!" << endl;
		return;
	}
	
	srand(time(0));

	vector<pair <string, int>> students = { 
		{"Іванов", rand() % 101},
		{"Петров", rand() % 101},
		{"Сидоров", rand() % 101},
		{"Козлов", rand() % 101},
		{"Михайлов", rand() % 101}
	};

	for (const auto& student : students) {
		outfile << student.first << " " << student.second << endl;
	}

	outfile.close();
}

string getECTSGrade(int averageScore) {  // Завдання 4
	if (averageScore >= 90) return "A";
	else if (averageScore >= 80) return "B";
	else if (averageScore >= 70) return "C";
	else if (averageScore >= 60) return "D";
	else if (averageScore >= 50) return "E";
	else return "F";
}

void calculateAverageScoreECTS(const string& filename) {  // Завдання 4
	ifstream infile(filename);
	if (!infile) {
		cerr << "Помилка відкриття файлу для читання!" << endl;
		return;
	}

	string surname;
	int score;
	int totalScore = 0;
	int count = 0;

	while (infile >> surname >> score) {
		totalScore += score;
		count++;
	}
	infile.close();

	if (count == 0) {
		cerr << "Файл не містить даних для обчислення!" << endl;
		return;
	}

	int averageScore = totalScore / count;
	string ectsGrade = getECTSGrade(averageScore);

	cout << "Середній бал: " << averageScore << endl;
	cout << "Оцінка за шкалою ECTS: " << ectsGrade << endl;

	ofstream outfile(filename, ios::app);
	outfile << "Середній бал за шкалою ECTS: " << ectsGrade << endl;
	outfile.close();
}

bool isVowel(wchar_t c) { // Завдання 5
	wchar_t vowels[] = L"AEIOUYaeiouyАЕЄИІЇОУЮЯаеєиіїоуюя";
	for (wchar_t v : vowels) {
		if (c == v) {
			return true;
		}
	}
	return false;
}

void writeToFile5(const string& filename) { // Завдання 5
	ofstream outfile(filename);
	if (!outfile) {
		cerr << "Помилка відкриття файлу для запису!" << endl;
		return;
	}

	string text = "The modern world has transformed significantly due to advancements in technology. Digital devices have become indispensable tools for communication, work, and entertainment. With the rise of artificial intelligence, many industries are witnessing unprecedented changes in productivity and innovation. Education systems worldwide are also adapting, incorporating online resources and interactive platforms to engage students. Despite these benefits, there are concerns regarding data privacy and the ethical use of AI. Governments and organizations are now focusing on establishing regulations to safeguard users' rights. Meanwhile, the rapid pace of technological growth continues to create both new opportunities and challenges. As society navigates this digital age, the importance of balancing progress with ethical responsibility becomes clearer every day.";
	outfile << text << endl;
	outfile.close();
}

int countVowelsInFile(const string& filename) { // Завдання 5
	wifstream infile(filename);
	if (!infile) {
		cerr << "Помилка відкриття файлу для читання!" << endl;
		return -1;
	}

	int vowe_count = 0;
	wchar_t c;

	while (infile >> noskipws >> c) {
		if (isVowel(c)) {
			vowe_count++;
		}
	}

	infile.close();
	return vowe_count;
}

void appendVowelsCountToFile(const string& filename, int vowel_count) { // Завдання 5
	ofstream outfile(filename, ios::app);
	if (!outfile) {
		cerr << "Помилка відкриття файлу для запису!" << endl;
		return;
	}

	outfile << "Кількість голосних букв у тексті: " << vowel_count << endl;
	outfile.close();
}

void displayAndReplaceMultipleSpaces(const string& filename) { // Завдання 6
	ifstream infile(filename);
	if (!infile) {
		cerr << "Помилка відкриття файлу для читання!" << endl;
		return;
	}

	string originalContent;
	string line;
	cout << "Початковий вміст файлу:\n";
	while (getline(infile, line)) {
		cout << line << '\n';
		originalContent += line + '\n';
	}
	infile.close();

	string modifiedContent;
	bool in_space = false;

	for (char c : originalContent) {
		if (c == ' ') {
			if (!in_space) {
				modifiedContent += c;
				in_space = true;
			}
		}
		else {
			modifiedContent += c;
			in_space = false;
		}
	}

	if (originalContent == modifiedContent) {
		cout << "\nПробілів, які йдуть підряд, не знайдено." << endl;
	} else {
		cout << "\nВміст файлу після видалення зайвих пробілів:\n";
		cout << modifiedContent << endl;

		ofstream outfile(filename);
		if (!outfile) {
			cerr << "Помилка відкриття файлу для запису!" << endl;
			return;
		}

		outfile << modifiedContent;
		outfile.close();
		cout << "Пробіли, які йдуть підряд, замінено на один." << endl;
	}
}

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);
	srand(time(0));

	int in, in_2, in_3;

	string filename1 = "./Zavd1.txt";
	int letter_count1 = 0;
	vector <Student> students1;

	string filename2 = "./Zavd2.txt";
	int number2;
	string numberStr;
	ofstream outfile2(filename2);

	string filename3 = "./Zavd3.txt";
	int evenCount;

	string filename4 = "./Zavd4.txt";

	string filename5 = "./Zavd5.txt";
	int vowel_count;

	string filename6 = "./Zavd6.txt";

	while (true) {

		cout << "1. Текстовий файл Zavd1.txt" << endl; // 3 тудента з ім'ям, прізвищем та віком
		cout << "2. Текстовий файл Zavd2.txt" << endl; // трицифрове число, поміняти місцями першу та останню цифру
		cout << "3. Текстовий файл Zavd3.txt" << endl; // Знайти кількість входжень парних цифр у всі числа
		cout << "4. Текстовий файл Zavd4.txt" << endl; // З прізвищами п’яти студентів та їх оцінками з програмування (по 100-бальній системі). Знайти середній бал для 5-ти студентів та перевести його за шкалою ECTS. Записати в кінець файлу це значення
		cout << "5. Текстовий файл Zavd5.txt" << endl; // текст (не менше 40 символів). Знайти кількість голосних букв у ньому. Дописати результат в кінець файлу.
		cout << "6. Текстовий файл Zavd6.txt" << endl; // Замінити в ньому всі пробіли, які йдуть підряд на один. Перезаписати даний файл.
		cout << "0. Вихід" << endl;

		cout << "\nВиберіть завдання: ";
		cin >> in;

		if (in == 0) {
			break;
		}

		switch (in) {
		case 1:
			writeToFile1(filename1);

			students1 = readFromFile1(filename1, letter_count1);

			cout << "Кількість літер у прізвищах та іменах студентів: " << letter_count1 << endl;

			while (true) {
				cout << "\nВивести інформацію про студентів (введіть 1 або 2 по різному виводиться. 0 для виходу)" << endl;

				cin >> in_2;

				if (in_2 == 0) {
					break;
				}

				switch (in_2) {
				case 1:
					displayAge1(students1);
					cout << endl;
					displayNames1(students1);
					break;
				case 2:
					displayStudents1(students1);
					break;

				default:
					cout << "Невірний вибір!" << endl;
					break;
				}
			}
			cout << endl;
			break;
		case 2:
			outfile2;
			outfile2.close();

			cout << "1. Згенерувати випадкове трицифрове число" << endl;
			cout << "2. Ввести трицифрове число" << endl;

			cin >> in_3;

			switch (in_3) {
			case 1:
				writeToFile2Rand(filename2);
				break;
			case 2:
				cout << "Введіть трицифрове число: ";
				cin >> number2;

				writeToFile2(filename2, number2);
				break;
			}

			number2 = readFromFile2(filename2);

			if (number2 != -1) {
				numberStr = to_string(number2);
				swapFirstAndLastDigits(numberStr);
				writeToFile2(filename2, stoi(numberStr));
				cout << "Число після заміни першої та останньої цифри: " << numberStr << endl;
			}
			cout << endl;
			break;
		case 3:
			{
			writeToFile3(filename3);
			evenCount = countEvenDigitsInFile(filename3);
			if (evenCount != -1) {
				cout << "Кількість входжень парних цифр у всі числа: " << evenCount << endl;
			}
			cout << endl;
			break;
			}
		case 4:
			writeToFile4(filename4);
			calculateAverageScoreECTS(filename4);
			cout << endl;
			break;
		case 5:
			writeToFile5(filename5);
			vowel_count = countVowelsInFile(filename5);
			if (vowel_count != -1) {
				appendVowelsCountToFile(filename5, vowel_count);
				cout << "Кількість голосних букв у тексті: " << vowel_count << endl;
			}
			cout << endl;
			break;
		case 6:
			displayAndReplaceMultipleSpaces(filename6);
			cout << endl;
			break;
		default:
			cout << "Невірний вибір!" << endl;
			break;
		}
	}
}


