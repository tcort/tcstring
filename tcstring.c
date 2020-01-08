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

int main(void) {
	return 0;
}
