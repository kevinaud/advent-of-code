#define ARROW 257
#define COMMA 258
#define OPEN_PEREN 259
#define CLOSE_PEREN 260
#define NEWLINE 261
#define STRING 262
#define INTEGER 263
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
    char* str;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
