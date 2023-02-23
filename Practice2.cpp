#include <iostream>
#include <locale.h>
#include <ctime>

using namespace std;

//функция преобразования символа в целое число
int char_to_int(char c) {
	return c - '0';
}

//функция преобразования целого числа в символ
char int_to_char(int i) {
	return i + '0';
}

//функция генерирования числа
//f = true - двоичное
//f = false - десятичное
char* new_value(bool f) {
	srand(time(NULL));
	int n_digits, digit;
	char* s_value;
	if (f) {
		n_digits = rand() % 14 + 2;
		s_value = new char[n_digits];
		s_value[n_digits - 1] = '\0';
		s_value[0] = '1';
		for (int i = 1; i < n_digits - 1; i++) {
			digit = rand() % 2;
			s_value[i] = int_to_char(digit);
		}
	}
	else {
		n_digits = rand() % 4 + 2;
		s_value = new char[n_digits];
		s_value[n_digits - 1] = '\0';
		digit = rand() % 9 + 1;
		s_value[0] = int_to_char(digit);
		for (int i = 1; i < n_digits - 1; i++) {
			digit = rand() % 10;
			s_value[i] = int_to_char(digit);
		}
	}
	return s_value;
}

//функция перевода из десят. СС в двоичную
char* bin(int n) {
	char* s_bin = new char[16]; //указ. на строку, содерж. возращ. результат
	itoa(n, s_bin, 2);
	return s_bin;
}

//функция перевода из двоичной СС в десятичную
namespace decimal {
	char* dec(char s_bin[]) {
		int digit, value = 0, p = strlen(s_bin) - 1;
		char* s_dec = new char[6];
		for (int i = 0; i < strlen(s_bin); i++) {
			digit = char_to_int(s_bin[i]);
			value = value + digit * pow(2, p);
			p = p - 1;
		}
		itoa(value, s_dec, 10);
		return s_dec;
	}
}

//функция проверки СС числа
//f = true - двоичное
//f = false - десятичное
bool check_value(char s_value[]) {
	bool f_check = true;
	for (int i = 0; i < strlen(s_value); i++)
		if ((s_value[i] != '0') && (s_value[i] != '1')) {
			f_check = false;
			break;
		}
	return f_check;
}

//процедура комментирования ответов
void reaction(bool f) {
	srand(time(NULL));
	int answer = rand() % 6;
	if (f)
		switch (answer) {
		case 0: puts(" Верно!\n");
			break;
		case 1: puts(" Отличный результат!\n");
			break;
		case 2: puts(" Абсолютно точно!\n");
			break;
		case 3: puts(" Верно! Так держать!\n");
			break;
		case 4: puts(" Впечатляющий результат!\n");
			break;
		case 5: puts(" Молодец!\n");
			break;
		}
	else
		switch (answer) {
		case 0: puts(" Не совсем так...\n");
			break;
		case 1: puts(" Давай-ка ещё раз!\n");
			break;
		case 2: puts(" Ну почти!\n");
			break;
		case 3: puts(" Близко, но давай-ка подумаем ещё\n");
			break;
		case 4: puts(" Ну-ка ещё разок!\n");
			break;
		}
}

int main()
{
	char* s_num = new char[16], * s_check = new char[16], * result, choice[20];
	int dec, item;
	bool f;
	setlocale(0, "russian");
	puts("Вас приветствует калькулятор систем счисления");
menu: puts("Выберите интересующий вариант (1-3):");  //метка menu
	printf(" 1.Перевод в системы счисления\n 2.Обучение переводу\n");
	printf(" 3.Выход\n");
again1: cin.getline(choice, 20);
	item = atoi(choice);
	if (item != 3) {
		switch (item) {
		case 1:  //обработка пункта меню 1 (Перевод в системы счисления)
			system("cls"); //очистка консоли
		prev1: printf("Перевод в системы счисления\n");
			printf(" 1.Перевод из 10 в 2\n 2.Перевод из 2 в 10\n");
			printf(" 3.Назад\n");
		again2: cin.getline(choice, 20);
			item = atoi(choice);
			switch (item) {
			case 1:  //обработка пункта меню 1->1 (Перевевод из 10 в 2)
				system("cls"); //очистка консоли
				printf("Перевод из 10 в 2");
				printf("(введите для выхода '00')\n");
			more1: printf(" Введите десятичное число: ");
				cin.getline(s_num, 16);
				if ((strcmp(s_num, "00") == 0)) {
					system("cls"); //очистка консоли
					goto prev1;
				}
				dec = atoi(s_num);
				result = bin(dec);
				printf(" Двоичное представление числа: %s\n\n", result);
				goto more1;
			case 2:  //обработка пункта меню 1->2 (Перевевод из 2 в 10)
				system("cls"); //очистка консоли
				printf("Перевод из 2 в 10");
				printf("(введите для выхода '00')\n");
			more2: printf(" Введите двоичное число: ");
				cin.getline(s_num, 16);
				f = check_value(s_num);
				if (not f) {
					puts(" Не очень похоже на двоичное число...");
					puts(" Давай попробуем снова\n");
					goto more2;
				}
				if ((strcmp(s_num, "00") == 0)) {
					system("cls"); //очистка консоли
					goto prev1;
				}
				result = decimal::dec(s_num);
				printf(" Десятичное представление числа: %s\n\n", result);
				goto more2;
			case 3:  //обработка пункта меню 1->3 (Назад)
				system("cls"); //очистка консоли
				goto menu;
			default:
				puts("\nПовторите выбор");
				goto again2;
			}
		case 2: //обработка пункта меню 2 (Обучение переводу)
			system("cls"); //очистка консоли
		prev2: printf("Обучение переводу\n");
			printf(" 1.Перевод из 10 в 2\n 2.Перевод из 2 в 10\n");
			printf(" 3.Назад\n");
		again3:cin.getline(choice, 20);
			item = atoi(choice);
			switch (item) {
			case 1:  //обработка пункта меню 2->1 (Перевевод из 10 в 2)
				system("cls"); //очистка консоли
				printf("Перевод из 10 в 2 ");
				printf("(введите для выхода '00', для просмотра ответа '01')\n");
			more3: s_num = new_value(false);
				dec = atoi(s_num);
				result = bin(dec);
				printf(" Десятичное число: %s\n", s_num);
			retry1: printf(" Введите двоичное представление: ");
				scanf("%s", s_num);
				if ((strcmp(s_num, "00") == 0)) {
					system("cls"); //очистка консоли
					cin.ignore();
					goto prev2;
				}	
				if ((strcmp(s_num, "01") == 0)) {
					printf(" Верный ответ: %s\n\n", result);
					goto more3;
				}
				if (strcmp(result, s_num) == 0) {
					reaction(true);
					cin.ignore();
					goto more3;
				}
				else {
					reaction(false);
					goto retry1;
				}
			case 2:  //обработка пункта меню 2->2 (Перевевод из 2 в 10)
				system("cls"); //очистка консоли
				printf("Перевод из 2 в 10\n");
				printf("(введите для выхода '00', для просмотра ответа '01')\n");
			more4:s_num = new_value(true);
				result = decimal::dec(s_num);
				printf(" Двоичное число: %s\n", s_num);
			retry2: printf(" Введите десятичное представление: ");
				scanf("%s", s_num);
				if ((strcmp(s_num, "00") == 0)) {
					system("cls"); //очистка консоли
					cin.ignore();
					goto prev2;
				}
				if ((strcmp(s_num, "01") == 0)) {
					printf(" Верный ответ: %s\n\n", result);
					goto more4;
				}
				if (strcmp(result, s_num) == 0) {
					reaction(true);
					cin.ignore();
					goto more4;
				}
				else {
					reaction(false);
					goto retry2;
				}
			case 3:  //обработка пункта меню 1->3 (Назад)
				system("cls"); //очистка консоли
				goto menu;
			default:
				puts("\nПовторите выбор");
				goto again3;
			}
		default:
			puts("\nПовторите выбор");
			goto again1;
		}
	}
	else
	{
		system("cls"); //очистка консоли
		puts("Работа с программой завершена\nЖелаем успехов!");
	}
}