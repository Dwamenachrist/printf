#include "main.h"

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int char_count = 0;

    while (*format) {
        if (*format == '%' && *(format + 1) != '\0') {
            format++; // Move past '%'

            // Handle conversion specifiers
            switch (*format) {
                case 'c': {
                    char c = (char) va_arg(args, int);
                    write(1, &c, 1);
                    char_count++;
                    break;
                }
                case 's': {
                    char *str = va_arg(args, char*);
                    write(1, str, strlen(str));
                    char_count += strlen(str);
                    break;
                }
                case 'u': {
                    unsigned int u = va_arg(args, unsigned int);
                    char buffer[20];  // Assuming a reasonable size
                    int len = snprintf(buffer, sizeof(buffer), "%u", u);
                    write(1, buffer, len);
                    char_count += len;
                    break;
                }
                case 'o': {
                    unsigned int o = va_arg(args, unsigned int);
                    char buffer[20];  // Assuming a reasonable size
                    int len = snprintf(buffer, sizeof(buffer), "%o", o);
                    write(1, buffer, len);
                    char_count += len;
                    break;
                }
                case 'x':
                case 'X': {
                    unsigned int x = va_arg(args, unsigned int);
                    char buffer[20];  // Assuming a reasonable size
                    int len = snprintf(buffer, sizeof(buffer), (*format == 'x') ? "%x" : "%X", x);
                    write(1, buffer, len);
                    char_count += len;
                    break;
                }
                case 'd':
                case 'i': {
                    int num = va_arg(args, int);
                    char buffer[20];  // Assuming a reasonable size
                    int len = snprintf(buffer, sizeof(buffer), "%d", num);
                    write(1, buffer, len);
                    char_count += len;
                    break;
                }
                case 'p': {
                    void *ptr = va_arg(args, void*);
                    char buffer[20];  // Assuming a reasonable size
                    int len = snprintf(buffer, sizeof(buffer), "%p", ptr);
                    write(1, buffer, len);
                    char_count += len;
                    break;
                }
                case '%': {
                    write(1, "%", 1);
                    char_count++;
                    break;
                }
                default:
                    // Ignore unsupported specifiers
                    break;
            }
        } else {
            // Regular character, not a specifier
            write(1, format, 1);
            char_count++;
        }

        format++;
    }

    va_end(args);
    return char_count;
}

int main() {
    // Example usage
    int value = 42;
    _printf("Pointer: %p\n", (void*)&value);
    return 0;
}

