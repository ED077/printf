#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdi  io.h>
#include <unistd.h>

#define UNUSED_ARG(x) (void)(x)
#define BUFFER_SIZE 1024

/* FLAGS */
#define FLAG_MINUS 1
#define FLAG_PLUS 2
#define FLAG_ZERO 4
#define FLAG_HASH 8
#define FLAG_SPACE 16

/* SIZES */
#define SIZE_LONG 2
#define SIZE_SHORT 1
i
/**
 * struct print_format - Structure for print operation
 *
 * @format: The format.
 * @function: The associated function.
 */
struct print_format
{
	char format;
	int (*function)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct print_format print_format_t - Typedef for print operation str
 *
 * @format: The format.
 * @function: The associated function.
 */
typedef struct print_format print_format_t;

int custom_printf(const char *format, ...);
int handle_print(const char *format, int *i, va_list list,
char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/
/* Functions for character and string printing */
int print_character(va_list types, char buffer[], int flags,
int width, int precision, int size);
int print_custom_string(va_list types, char buffer[], int flags,
int width, int precision, int size);
int print_percent_symbol(va_list types, char buffer[], int flags,
int width, int precision, int size);

/* Functions for number printing */
int print_integer(va_list types, char buffer[], int flags,
int width, int precision, int size);
int print_binary_number(va_list types, char buffer[], int flags,
int width, int precision, int size);
int print_unsigned_integer(va_list types, char buffer[], int flags,
int width, int precision, int size);
int print_octal_number(va_list types, char buffer[], int flags,
int width, int precision, int size);
int print_hexadecimal_number(va_list types, char buffer[], int flags,
int width, int precision, int size);
int print_uppercase_hexadecimal(va_list types, char buffer[], int flags,
int width, int precision, int size);

int print_hexadecimal(va_list types, char map_to[], char buffer[], int flags,
char flag_ch, int width, int precision, int size);

/* Function for non-printable characters */
int print_non_printable_characters(va_list types, char buffer[], int flags,
int width, int precision, int size);

/* Function for printing memory address */
int print_memory_pointer(va_list types, char buffer[], int flags,
int width, int precision, int size);

/* Functions for handling other specifiers */
int extract_flags(const char *format, int *i);
int extract_width(const char *format, int *i, va_list list);
int extract_precision(const char *format, int *i, va_list list);
int extract_size(const char *format, int *i);

/* Function for reversing a string */
int print_reversed_string(va_list types, char buffer[], int flags,
int width, int precision, int size);

/* Function for printing a string in ROT13 */
int print_rot13_encoded_string(va_list types, char buffer[], int flags,
int width, int precision, int size);

/* Width handler functions */
int write_char(char c, char buffer[], int flags, int width, int precision,
int size);
int write_number(int is_positive, int index, char buffer[], int flags,
int width, int precision, int size);
int write_numeric_value(int index, char bff[], int flags,
int width, int precision, int length, char padd, char extra_c);
int write_memory_address(char buffer[], int index, int length, int width,
int flags, char padd, char extra_c, int padd_start);
int write_unsigned_value(int is_negative, int index, char buffer[], int flags,
int width, int precision, int size);

/****************** UTILITIES ******************/
int is_printable_char(char character);
int append_hexadecimal_code(char character, char[], int);
int is_digit_char(char character);

long int convert_sized_number(long int num, int size);
long int convert_sized_unsigned(unsigned long int num, int size);

#endif /* MAIN_H */
