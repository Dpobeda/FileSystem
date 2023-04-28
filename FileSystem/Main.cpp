#include <iostream>
#include <string>
#include <fstream> // file stream - библиотека позволяющая взаимодействовать с файловой системой компьютера.

// Задача 1.
bool statictic(std::string word);
bool print_file(std::string file_path) {
	std::ifstream in;
	in.open(file_path);

	if (in.is_open()) {
		char sym;
		while (in.get(sym))
			std::cout << sym;
		in.close();
		std::cout << std::endl;
		return true;
	}
	return false;
}

// Задача 2.
bool clear_file(std::string file_path) {
	std::ofstream clear;
	clear.open(file_path);

	if (clear.is_open()) {
		clear.close();
		return true;
	}
	return false;
}



int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	std::string path = "file.txt";

	// Ofstream - Запись данных в файл.
	// ifstream - Чтение данных из файла.
	// fstream - Запись данных в файл и чтение данных ищ файла.

	// Класс ofstream. 
	
	// Первый способ.
	std::ofstream out; // Объект класса ofstream для записи данных в файл.
	out.open(path, std::ios::app); // Открытие файла в режиме app.

	// Второй способ.
	// std::ofstream out(path);

	if (out.is_open()) { // Проверка файла на открытие.
		std::cout << "Файл открыт для записи.\n";
		std::string str;
		std::cout << "Введите строку -> ";
		std::getline(std::cin, str);
		out << str << '\n'; // Добавление информации в файл.
		std::cout << "Запись добавлена в файл. \n";
	}
	else
		std::cout << "Ошибка открытия файла.\n";

	// Возможные причины ошибок при открытии файла;
	// 1. Неправильный синтаксис указания пути к файлу;
	// 2. Нет доступа к файлу;
	// 3. Файл открыт другим объектом или приложением.


	out.close(); // Закрытие файла и очистка объекта out.

	std::cout << std::endl;
	

	// Клаcс ifstream.
	
	std::ifstream in;
	in.open(path);

	if (in.is_open()) {
		std::cout << "Файл открыт для чтения.\n";
		std::cout << "Содержимое файла: \n";
		std::string file_text;

		// Первый способ: Посимвольное считывание.
		// char sym;
		//while (in.get(sym))
			// std::cout << sym; // ТОЛЬКО ВЫВОД.
		//	file_text += sym; // ВЫВОД И СОХРАНЕНИЕ В СТРОК.
		//std::cout << file_text << std::endl;

		// Второй способ: Пословное считывание.
		//while (!in.eof()) {
			//std::string tmp;
			//in >> tmp;
			//file_text += tmp + '\n';
		//}
		//std::cout << file_text << std::endl;

		// Третий способ: Построчное считывание.
		std::string line;
		while (std::getline(in, line))
			file_text += line + "\n";
		std::cout << file_text << std::endl;
	}
	else
		std::cout << "Ошибка откртыия файла.\n";

	in.close();
	

	// Удаление файла.
	
	if (remove(path.c_str()) == 0)
		std::cout << "Файл \"" << path << "\" удалён.\n";
	else
		std::cout << "Ошибка удаления файла.\n";

	// Возможные причины ошибок при удаление файла.
	// 1. Неправильный синтаксис указание к пути файлу;
	// 2. Нет доступа к файлу;
	// 3. Файла не существует.
	// 4. Файл открыт.

	// Задача 1 - 2. Слова в файл.

	std::cout << "Задача 1.\n";
	int action;

	do {
		std::cout << "\nВыберите действие:\n";
		std::cout << "1. Добавление статистики в файл;\n";
		std::cout << "2. Вывод файла;\n";
		std::cout << "3. Очистка файла;\n";
		std::cout << "4. Завершение работы;\n";
		std::cout << "Введите номер действия -> ";
		std::cin >> action;

		std::string str1;

		switch (action) {
		case 1:
			std::cout << "Введите строку -> ";
			std::cin.ignore();
			std::getline(std::cin, str1);

			if (statictic(str1))
				std::cout << "\nЗапись добавлена в файл.\n\n";
			else
				std::cout << "Ошибка выполнения функции.\n\n";
			break;
		
		case 2:
			std::cout << "\nСодержимое файла:\n";
			print_file("Stats.txt");
			break;

		case 3:
			clear_file("Stats.txt");
			std::cout << "\nФайл очищен.\n\n";
			break;
		case 4:
			std::cout << "\nПрограмма завершена.\n\n";
			break;
		default:
			std::cout << "Ошибка ввода.\n\n";
		}
	} while (action != 4);
	

	return 0;
}

bool statictic(std::string word) {
	std::ofstream out1;
	out1.open("Stats.txt", std::ios::app);

	if (out1.is_open()) {
		out1 << word << ' ' << word.length() << "\n";
		out1.close();
		return true;
	}
	return false;
}