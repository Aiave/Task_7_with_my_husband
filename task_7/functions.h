#ifndef TASK
#define TASK

#include <stdio.h>
#include <stdbool.h>

int get_digit_count(int number);
int get_digit(int number, int index);
bool has_needed_times(int number, int digit, int needed_count);

#endif

// "пы сы в начале" от мужа
// digit - цифра
// need - быть необходимым
// сount - количество, counter - счетчик
// number - число
// has - иметь, hasNumber - есть ли число
// is - быть, isNumber - является ли это числом?
// get - получить
// set - сделать, setLocale - поставить язык окружения