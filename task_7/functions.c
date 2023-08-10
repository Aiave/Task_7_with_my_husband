#include <stdio.h>
#include <stdbool.h>

//узнаём, сколько цифр в числе
int get_digit_count(int number)
{
	int count = 0;
	while (number != 0)
	{
		number /= 10;	//убираем последнюю цифру (number = number / 10)
		count++;		//увеличиваем счётчик на убранный разряд
	}
	return count;
}

//перебираем цифры в числе
int get_digit(int number, int index)
{
	int powered = 1;				//порядок: для 0 - 1, для 1 - 10, для 2 - 100 и т. п.
	for (int i = 0; i < index; i++)	//делаем index раз (index - количество нулей в порядке)
		powered *= 10;				//добавляем 0 в порядок, умножая на 10 (powered = powered * 10)

	return number / powered % 10;	//получаем цифру: делим на порядок и берём последнюю цифру полученного числа

	//пример алгоритма:
	//124754	->	124754 / 100	->	1247 % 10	->	7
	//   210	1 * 10 * 10 (2 раза)
}

//проверяем, встречается ли цифра в числе нужное количество раз
bool has_needed_times(int number, int digit, int needed_count)
{
	int counter = 0;
	while (number != 0)							//пока в числе есть цифры
	{
		int localDigit = number % 10;			//получаем последнюю цифру
		if (localDigit == digit)				//если последняя цифра равна той, с которой мы сравниваем
			counter++;							//увеличиваем счётчик
		number = (number - localDigit) / 10;	//отрезаем последнюю цифру

		//к примеру, 43215 / 5 -> 43215 - 5 -> 43210 / 10 -> 4321 - убрали последнюю цифру
		//а можно просто / 10
	}

	return counter >= needed_count;	//возвращаем, встретилось ли цифра нужное количество раз
}