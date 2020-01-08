/******************************************************************************

Copyright (c) 2020 Thomas Cort

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

******************************************************************************/

#ifndef __TCSTRING_H
#define __TCSTRING_H

#include <stddef.h>

struct string {
	char *cstring;	/* storage buffer is a regular NUL terminated string */
	size_t len;	/* length of the string in cstring */
	size_t cap;	/* allocated size (capacity) of cstring */
	size_t inc;	/* amount to increment capacity when growing cstring */
};

typedef struct string string_t;

string_t *string_alloc(size_t cap, size_t inc);
void string_append_char(string_t *str, char ch);
void string_append_cstring(string_t *str, char *s);
string_t *string_from_cstring(char *s);
char *string_to_cstring(string_t *str);
size_t string_strlen(string_t *str);
int string_strcmp(string_t *left, string_t *right);
int string_strcastcmp(string_t *left, string_t *right);
int string_strcoll(string_t *left, string_t *right);
string_t *string_strcpy(string_t *dst, string_t *src);
string_t *string_strcat(string_t *dst, string_t *src);
void string_chomp(string_t *str);
void string_trim(string_t *str);
void string_free(string_t *str);

#endif
