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

#include <stdlib.h>
#include <string.h>

#include "tcstring.h"

string_t *string_alloc(size_t cap, size_t inc) {
	string_t *str;

	str = (string_t *) reallocarray(NULL, sizeof(string_t), 1);
	if (str == NULL) {
		return NULL;
	}
	memset(str, '\0', sizeof(string_t));

	str->cstring = (char *) reallocarray(NULL, sizeof(char), cap);
	if (str->cstring == NULL) {
		string_free(str);
		str = NULL;
		return NULL;
	}
	memset(str->cstring, '\0', sizeof(char) * cap);

	str->len = 0;
	str->cap = cap;
	str->inc = inc;

	return str;
}

void string_append_char(string_t *str, char ch) {
	if (str->len + 1 == str->cap) { /* always leave +1 for '\0' byte */
		char *newcstring;

		str->cap += str->inc;

		newcstring = (char *) reallocarray(str->cstring, sizeof(char),
								str->cap);
		if (newcstring == NULL) {
			return;
		}
		str->cstring = newcstring;
		memset(str->cstring + str->cap - str->inc, '\0',
						sizeof(char) * str->inc);
	}

	
	str->cstring[str->len] = ch;
	str->len++;
}

void string_append_cstring(string_t *str, char *s) {
	size_t i;
	for (i = 0; i < strlen(s); i++) {
		string_append_char(str, s[i]);
	}
}

string_t *string_from_cstring(char *s) {
	string_t *str;

	str = string_alloc(256, 256);
	if (str == NULL) {
		return NULL;
	}

	string_append_cstring(str, s);

	return str;
}

char *string_to_cstring(string_t *str) {
	return strdup(str->cstring);
}

size_t string_strlen(string_t *str) {
	return str->len;
}

int string_strcmp(string_t *left, string_t *right) {
	return strcmp(left->cstring, right->cstring);
}

int string_strcastcmp(string_t *left, string_t *right) {
	return strcasecmp(left->cstring, right->cstring);
}

string_t *string_strcpy(string_t *dst, string_t *src) {
	dst->len=0;
	string_append_cstring(dst, src->cstring);
	return dst;
}

string_t *string_strcat(string_t *dst, string_t *src) {
	string_append_cstring(dst, src->cstring);
	return dst;
}

void string_free(string_t *str) {
	if (str != NULL) {
		if (str->cstring != NULL) {
			memset(str->cstring, '\0', str->cap);
			free(str->cstring);
			str->cstring = NULL;
		}
		memset(str, '\0', sizeof(string_t));
		free(str);
	}
}

