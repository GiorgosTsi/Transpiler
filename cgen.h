#ifndef CGEN_H
#define CGEN_H


#define GREEN   "\033[32m"      /* Green */
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */

/*
	String streams are handy for using standard C-library
	functions to produce formatted strings.
*/
typedef struct sstream
{
	char *buffer;
	size_t bufsize;
	FILE* stream;
} sstream;

void ssopen(sstream* S);
char* ssvalue(sstream* S);
void ssclose(sstream* S);

char *replaceChar(char* const source,  char toBeReplaced, char replacer);

char* replace_str(const char *str, const char *old, const char *new);

/*
        This function takes the same arguments as printf,
        but returns a new string with the output value in it.
 */
char* template(const char* pat, ...);

/*
	This is the function used to report errors in the translation.
*/
void yyerror(char const* pat, ...);

/*
	This is set to the number of calls to yyerror
 */
extern int yyerror_count;


/* This is output at the head of a c program. */
extern const char* c_prologue;


#endif
