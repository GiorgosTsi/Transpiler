#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cgen.h"

extern int line_num;

void ssopen(sstream *S) { S->stream = open_memstream(&S->buffer, &S->bufsize); }

char *ssvalue(sstream *S) {
  fflush(S->stream);
  return S->buffer;
}

void ssclose(sstream *S) { fclose(S->stream); }

char *replaceChar(char* const source, char toBeReplaced, char replacer) {
	for (int i = 0; i < strlen(source); ++i) {
		if (source[i] == toBeReplaced) {
			source[i] = replacer;
		}
	}
	return source;
}

char *template(const char *pat, ...) {
  sstream S;
  ssopen(&S);

  va_list arg;
  va_start(arg, pat);
  vfprintf(S.stream, pat, arg);
  va_end(arg);

  char *ret = ssvalue(&S);
  ssclose(&S);
  return ret;
}

/*
        Report errors
*/
void yyerror(char const *pat, ...) {
  va_list arg;
  fprintf(stderr, "line %d: ", line_num);

  va_start(arg, pat);
  vfprintf(stderr, pat, arg);
  va_end(arg);

  fprintf(stderr, "\n");

  yyerror_count++;
}

int yyerror_count = 0;

const char *c_prologue =
    "#include \"lambdalib.h\"\n"
    "\n";
    
    
///////////////////////////////////My section:
// Function to replace occurrences of 'old' with 'new' in 'str'

/*Used in array comprehension , to get the new expression with replaced elm->array[array_i] */
char* replace_str(const char *str, const char *old, const char *new) {
    char *result;
    int i, cnt = 0;
    int newlen = strlen(new);
    int oldlen = strlen(old);

    // Count the number of times old word occur in the string
    for (i = 0; str[i] != '\0'; i++) {
        if (strstr(&str[i], old) == &str[i]) {
            cnt++;
            i += oldlen - 1;
        }
    }

    // Allocate memory for the new result string
    result = (char *)malloc(i + cnt * (newlen - oldlen) + 1);

    i = 0;
    while (*str) {
        if (strstr(str, old) == str) {
            strcpy(&result[i], new);
            i += newlen;
            str += oldlen;
        } else
            result[i++] = *str++;
    }

    result[i] = '\0';
    return result;
}
