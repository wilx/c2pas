%{
#include "csynan.hxx"
%}

int		{ return TOK_INT }
char		{ return TOK_CHAR }
long		{ return TOK_LONG }
unsigned	{ return TOK_UNSIGNED }
float		{ return TOK_FLOAT }
double		{ return TOK_DOUBLE }
const		{ return TOK_CONST }
while		{ return TOK_WHILE }
if		{ return TOK_IF }
goto		{ return TOK_GOTO }
struct		{ return TOK_STRUCT }
typedef		{ return TOK_TYPEDEF }
enum		{ return TOK_ENUM }
union		{ return TOK_UNION }
