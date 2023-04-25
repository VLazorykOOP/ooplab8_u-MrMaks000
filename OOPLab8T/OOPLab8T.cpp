// OOPLab8T.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "example.h"
#include "Tasks.h"

int main()
{   
    char n;

	while (true)
	{
		system("cls");
		std::cout << "Lab 8 \n";
		std::cout << "e - example.\n";
		std::cout << "1 - Task 1.\n";
		std::cout << "2 - Task 2.\n";
		std::cout << "3 - Task 3.\n";
		std::cout << "4 - Task 4.\n";
		std::cout << "r - exit.\n";
		std::cin >> n;
		switch (n)
		{
		case '1':
			Task1();
			break;
		case '2':
			Task2();
			break;
		case '3':
			Task3();
			break;
		case '4':
			Task4();
			break;
		case 'e':
			example();
			break;
		case 'r':
			return 0;
		}	

		std::cout << "\nPrass 'r' for exit.\n";
		std::cout << "Prass random key for starting now.\n";
		std::cin >> n;
		if (n == 'r') return 0;
	}
     
}

