#include "monty.h"
#include <stdlib.h>

/**
 * swap_val - function to swap values in two values
 *
 * @a: value one
 * @b: value two
 */

void swap_val(char *a, char *b)
{
	char tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * reverse- function to reverse a string
 *
 * @s: string to reverse
 * @start: start index
 * @end: end index
 *
 * Return: pointer to reversed string
 */

char *reverse(char *s, int start, int end)
{
	while (start < end)
	{
		swap_val(&s[start++], &s[end--]);
	}

	return (s);
}

/**
 * _itoa - function to convert integer to string
 *
 * @value: integer to convert.
 * @s: string to hold new integer.
 * @base: base to convert value to
 *
 * Return: pointer to new string
 */

char *_itoa(int value, char *s, int base)
{
	int n, i = 0, r;
	/** invalid input */

	if (base < 2 || base > 32)
		return (s);

	/** consider the absolute value of the number */
	n = abs(value);
	while (n)
	{
		r = n % base;
		if (r >= 10)
		{
			s[i++] = 65 + (r - 10);
		}
		else
		{
			s[i++] = 48 + r;
		}
		n = n / base;
	}
	/** if the number is 0 */
	if (i == 0)
		s[i++] = '0';
	/** If the base is 10 and the value is negative, the resulting string */
	/** is preceded with a minus sign (-) */
	/** With any other base, value is always considered unsigned */
	if (value < 0 && base == 10)
		s[i++] = '-';
	s[i] = '\0'; /** null terminate string */

	/** reverse the string */
	return (reverse(s, 0, i - 1));
}
