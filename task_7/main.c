#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include "functions.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	
	int number, needed_count;
	printf("Введите число: ");
	scanf_s("%d", &number);
	printf("Сколько раз цифра должна повторяться в числе?\n");
	scanf_s("%d", &needed_count);

	int digit_count = get_digit_count(number);	//узнаём, сколько цифр в числе, и записываем в переменную digit_count

	// needed_count - 1 = количество цифр, меньше которых проверка бессмысленна
	// digit_count - (needed_count - 1) = сколько максимально цифр нужно проверить
	// index - позиция цифры в числе (с конца)
	for (int index = 0; index < digit_count - (needed_count - 1); index++)
	{
		//проверяем, встретилось ли цифра нужное количество раз
		//передаём число, функцию для перебора цифр (в неё число и индексы), нужное количество повторений
		if (has_needed_times(number, get_digit(number, index), needed_count))
		{
			printf("Да");
			return 0;
		}
	}

	printf("Нет");
	return 0;
}