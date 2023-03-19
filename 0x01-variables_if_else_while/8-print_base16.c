#include <stdio.h>

/**
 * main - prints all the numbers of base 16 in lowercase,
 * follewed by a new line
 * Return: Always 0 (success)
 */
int main(void)
{
        char ch;

        for (ch = '0'; ch <= '9'; ch++)
        {
                putchar(ch);
        }
        for (ch = 'a'; ch <= 'f'; ch++)
        {
                putchar(ch);
        }
        putchar('\n');
        return (0);
}
