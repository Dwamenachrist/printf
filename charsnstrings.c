#include "main.h"
/**
 * _printf - prints strings, chars and % sign
 * @format: text
 *
 * Return: n
 */
int _printf(const char *format, ...)
{
        va_list args;

        va_start(args, format);

        int n;
        char c;
        char str[BUFFER_SIZE];

        n = 0;
        while (*format)
        {
                if (*format == '%')
                {
                        format++;
                        switch (*format)
                        {
                                case 'c':
                                        {
                                                c = (char)va_arg(args, int);
                                                n += write(1, &c, 1);
                                                break;
                                        }
                                case 's':
                                        {
                                                const char *arg_str = va_arg(args, const char *);
                                                strncpy(str, arg_str, BUFFER_SIZE - 1);
                                                str[BUFFER_SIZE - 1] = '\0';
                                                n += write(1, str, strlen(str));
                                                break;
                                        }
                                case '%':
                                        n += write(1, "%", 1);
                                        break;
                                default:
                                        break;
                        }
                }
                else
                {
                        n += write(1, format, 1);
                }

                format++;
        }

        va_end(args);
        return (n);
}
/**
 * main - print
 *
 * Return: Always 0.
 */
int main(void)
{
        char test = 'v';

        _printf("Hello %s! The answer is %c%%\n", "world", test);
        return (0);
}

