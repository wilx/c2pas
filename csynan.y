%{
#define YYPARSE_PARAM ptr 
#define YYERROR_VERBOSE 1
#define YYDEBUG 1

char* filename = "";
extern int yylex (void);
void yyerror (char *s);

union yystype {
    int x;
    char * str;
};
#define YYSTYPE yystype

#include <iostream>
#include "lexan.hxx"

%}

%token TOK_INT TOK_CHAR TOK_LONG TOK_UNSIGNED TOK_FLOAT TOK_DOUBLE TOK_SIGNED TOK_SHORT
%token TOK_CONST TOK_WHILE TOK_IF TOK_GOTO TOK_STRUCT TOK_TYPEDEF TOK_ENUM
%token TOK_UNION TOK_STRUCT TOK_STATIC TOK_REGISTER TOK_AUTO TOK_SWITCH TOK_CASE
%token TOK_BREAK TOK_CONTINUE TOK_DEFAULT TOK_RETURN TOK_EXTERN TOK_VOID TOK_ELSE
%token TOK_IDENT TOK_FPNUM TOK_INTNUM TOK_UINTNUM TOK_STRING TOK_CHARVAL
%token TOK_EQ TOK_GE TOK_MINUSEQ TOK_MINMIN TOK_LAND TOK_LOR TOK_PLUSEQ TOK_MULTEQ
%token TOK_DIVEQ TOK_LSHIFT TOK_RSHIFT TOK_ARROW TOK_LISHIFTEQ TOK_XOREQ
%token TOK_LE TOK_PLUSPLUS TOK_OREQ TOK_ANDEQ TOK_ELLIPSIS TOK_FOR TOK_NE
%token TOK_LSHIFTEQ TOK_VOLATILE TOK_MODEQ TOK_RSHIFTEQ TOK_DO TOK_SIZEOF
%token TYPE_NAME

%start translation_unit
%%

primary_expression
        : TOK_IDENT
        | constant
        | TOK_STRING
        | '(' expression ')'
        ;

constant
        : TOK_FPNUM
        | TOK_INTNUM
        | TOK_UINTNUM
        | TOK_CHARVAL
        ;
        
postfix_expression
        : primary_expression
        | postfix_expression '[' expression ']'
        | postfix_expression '(' ')'
        | postfix_expression '(' argument_expression_list ')'
        | postfix_expression '.' TOK_IDENT
        | postfix_expression TOK_ARROW TOK_IDENT
        | postfix_expression TOK_PLUSPLUS
        | postfix_expression TOK_MINMIN
        ;

argument_expression_list
        : assignment_expression
        | argument_expression_list ',' assignment_expression
        ;

unary_expression
        : postfix_expression
        | TOK_PLUSPLUS unary_expression
        | TOK_MINMIN unary_expression
        | unary_operator cast_expression
        | TOK_SIZEOF unary_expression
        | TOK_SIZEOF '(' type_name ')'
        ;

unary_operator
        : '&'
        | '*'
        | '+'
        | '-'
        | '~'
        | '!'
        ;

cast_expression
        : unary_expression
        | '(' type_name ')' cast_expression
        ;

multiplicative_expression
        : cast_expression
        | multiplicative_expression '*' cast_expression
        | multiplicative_expression '/' cast_expression
        | multiplicative_expression '%' cast_expression
        ;

additive_expression
        : multiplicative_expression
        | additive_expression '+' multiplicative_expression
        | additive_expression '-' multiplicative_expression
        ;

shift_expression
        : additive_expression
        | shift_expression TOK_LSHIFT additive_expression
        | shift_expression TOK_RSHIFT additive_expression
        ;

relational_expression
        : shift_expression
        | relational_expression '<' shift_expression
        | relational_expression '>' shift_expression
        | relational_expression TOK_LE shift_expression
        | relational_expression TOK_GE shift_expression
        ;

equality_expression
        : relational_expression
        | equality_expression TOK_EQ relational_expression
        | equality_expression TOK_NE relational_expression
        ;

and_expression
        : equality_expression
        | and_expression '&' equality_expression
        ;

exclusive_or_expression
        : and_expression
        | exclusive_or_expression '^' and_expression
        ;

inclusive_or_expression
        : exclusive_or_expression
        | inclusive_or_expression '|' exclusive_or_expression
        ;

logical_and_expression
        : inclusive_or_expression
        | logical_and_expression TOK_LAND inclusive_or_expression
        ;

logical_or_expression
        : logical_and_expression
        | logical_or_expression TOK_LOR logical_and_expression
        ;

conditional_expression
        : logical_or_expression
        | logical_or_expression '?' expression ':' conditional_expression
        ;

assignment_expression
        : conditional_expression
        | unary_expression assignment_operator assignment_expression
        ;

assignment_operator
        : '='
        | TOK_MULTEQ
        | TOK_DIVEQ
        | TOK_MODEQ
        | TOK_PLUSEQ
        | TOK_MINUSEQ
        | TOK_LSHIFTEQ
        | TOK_RSHIFTEQ
        | TOK_ANDEQ
        | TOK_XOREQ
        | TOK_OREQ
        ;

expression
        : assignment_expression
        | expression ',' assignment_expression
        ;

constant_expression
        : conditional_expression
        ;

declaration
        : declaration_specifiers ';'
        | declaration_specifiers init_declarator_list ';'
        ;

declaration_specifiers
        : storage_class_specifier
        | storage_class_specifier declaration_specifiers
        | type_specifier
        | type_specifier declaration_specifiers
        | type_qualifier
        | type_qualifier declaration_specifiers
        ;

init_declarator_list
        : init_declarator
        | init_declarator_list ',' init_declarator
        ;

init_declarator
        : declarator
        | declarator '=' initializer
        ;

storage_class_specifier
        : TOK_TYPEDEF
        | TOK_EXTERN
        | TOK_STATIC
        | TOK_AUTO
        | TOK_REGISTER
        ;

type_specifier
        : TOK_VOID
        | TOK_CHAR
        | TOK_SHORT
        | TOK_INT
        | TOK_LONG
        | TOK_FLOAT
        | TOK_DOUBLE
        | TOK_SIGNED
        | TOK_UNSIGNED
        | struct_or_union_specifier
        | enum_specifier
        | TYPE_NAME
        ;

struct_or_union_specifier
        : struct_or_union TOK_IDENT '{' struct_declaration_list '}'
        | struct_or_union '{' struct_declaration_list '}'
        | struct_or_union TOK_IDENT
        ;

struct_or_union
        : TOK_STRUCT
        | TOK_UNION
        ;

struct_declaration_list
        : struct_declaration
        | struct_declaration_list struct_declaration
        ;

struct_declaration
        : specifier_qualifier_list struct_declarator_list ';'
        ;

specifier_qualifier_list
        : type_specifier specifier_qualifier_list
        | type_specifier
        | type_qualifier specifier_qualifier_list
        | type_qualifier
        ;

struct_declarator_list
        : struct_declarator
        | struct_declarator_list ',' struct_declarator
        ;

struct_declarator
        : declarator
        | ':' constant_expression
        | declarator ':' constant_expression
        ;

enum_specifier
        : TOK_ENUM '{' enumerator_list '}'
        | TOK_ENUM TOK_IDENT '{' enumerator_list '}'
        | TOK_ENUM TOK_IDENT
        ;

enumerator_list
        : enumerator
        | enumerator_list ',' enumerator
        ;

enumerator
        : TOK_IDENT
        | TOK_IDENT '=' constant_expression
        ;

type_qualifier
        : TOK_CONST
        | TOK_VOLATILE
        ;

declarator
        : pointer direct_declarator /*bez ukazatelu*/
        | direct_declarator
        ;

direct_declarator
        : TOK_IDENT
        | '(' declarator ')'
        | direct_declarator '[' constant_expression ']'
        | direct_declarator '[' ']'
        | direct_declarator '(' parameter_type_list ')'
        | direct_declarator '(' identifier_list ')'
        | direct_declarator '(' ')'
        ;

pointer
        : '*'
        | '*' type_qualifier_list
        | '*' pointer
        | '*' type_qualifier_list pointer
        ;

type_qualifier_list
        : type_qualifier
        | type_qualifier_list type_qualifier
        ;

parameter_type_list
        : parameter_list
        | parameter_list ',' TOK_ELLIPSIS
        ;

parameter_list
        : parameter_declaration
        | parameter_list ',' parameter_declaration
        ;

parameter_declaration
        : declaration_specifiers declarator
        | declaration_specifiers abstract_declarator
        | declaration_specifiers
        ;

identifier_list
        : TOK_IDENT
        | identifier_list ',' TOK_IDENT
        ;

type_name
        : specifier_qualifier_list
        | specifier_qualifier_list abstract_declarator
        ;

abstract_declarator
        : pointer
        | direct_abstract_declarator
        | pointer direct_abstract_declarator
        ;

direct_abstract_declarator
        : '(' abstract_declarator ')'
        | '[' ']'
        | '[' constant_expression ']'
        | direct_abstract_declarator '[' ']'
        | direct_abstract_declarator '[' constant_expression ']'
        | '(' ')'
        | '(' parameter_type_list ')'
        | direct_abstract_declarator '(' ')'
        | direct_abstract_declarator '(' parameter_type_list ')'
        ;

initializer
        : assignment_expression
        | '{' initializer_list '}'
        | '{' initializer_list ',' '}'
        ;

initializer_list
        : initializer
        | initializer_list ',' initializer
        ;

statement
        : labeled_statement
        | compound_statement
        | expression_statement
        | selection_statement
        | iteration_statement
        | jump_statement
        ;

labeled_statement
        : TOK_IDENT ':' statement
        | TOK_CASE constant_expression ':' statement
        | TOK_DEFAULT ':' statement
        ;

compound_statement
        : '{' '}'
        | '{' statement_list '}'
        | '{' declaration_list '}'
        | '{' declaration_list statement_list '}'
        ;

declaration_list
        : declaration
        | declaration_list declaration
        ;

statement_list
        : statement
        | statement_list statement
        ;

expression_statement
        : ';'
        | expression ';'
        ;

selection_statement
        : TOK_IF '(' expression ')' statement
        | TOK_IF '(' expression ')' statement TOK_ELSE statement
        | TOK_SWITCH '(' expression ')' statement
        ;

iteration_statement
        : TOK_WHILE '(' expression ')' statement
        | TOK_DO statement TOK_WHILE '(' expression ')' ';'
        | TOK_FOR '(' expression_statement expression_statement ')' statement
        | TOK_FOR '(' expression_statement expression_statement expression ')' statement
        ;

jump_statement
        : TOK_GOTO TOK_IDENT ';'
        | TOK_CONTINUE ';'
        | TOK_BREAK ';'
        | TOK_RETURN ';'
        | TOK_RETURN expression ';'
        ;

translation_unit
        : external_declaration
        | translation_unit external_declaration
        ;

external_declaration
        : function_definition
        | declaration
        ;

function_definition
        : declaration_specifiers declarator declaration_list compound_statement
        | declaration_specifiers declarator compound_statement
        | declarator declaration_list compound_statement
        | declarator compound_statement
        ;

%%

void yyerror (char *s)
{		
    std::cerr << filename << ": " << s << std::endl;
}
