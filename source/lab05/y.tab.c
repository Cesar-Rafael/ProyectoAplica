/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "base.y"

#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 100

// Prototipos de funcion
int yylex(void);
void yyerror(char* s);

int GenerarCodigo(int op, int a1, int a2, int a3);
int GenerarTemporal(void);
void ImprimirTablaCodigos(void);
void ImprimirTablaSimbolos(void);
void InterpretarCodigo(void);
int LocalizarSimbolo(char* lexema, int token);

int cantidad_simbolos = 0;
int posicion_ultimo_codigo = -1;
int cantidad_variables_temporales = 1;
char lexema[MAX_SIZE];
FILE* arch;

typedef struct{
	int op;
	int a1;
	int a2;
	int a3;
} Codigo;

typedef struct{
	char nombre[MAX_SIZE];
	int token;
	int valor;
} Simbolo;

Codigo tabla_codigos[MAX_SIZE];
Simbolo tabla_simbolos[MAX_SIZE];

// Se hizo la corrección de errores, ahora compila y corre
// Comando: yacc grupo5_ER.y && gcc y.tab.c -lm -lfl && ./a.out


#line 119 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    Y_LOGICO = 258,
    TIPO_BOOLEAN = 259,
    CARACTER_RARO = 260,
    TIPO_CARACTER = 261,
    TIPO_DOUBLE = 262,
    CONDICION_SINO = 263,
    FIN = 264,
    FALSO = 265,
    BUCLE_FOR = 266,
    FUNCION_INICIO = 267,
    CONDICION_INICIO = 268,
    ENTRADA = 269,
    TIPO_ENTERO = 270,
    OPERACION_MODULAR = 271,
    NEGACION_LOGICA = 272,
    O_LOGICO = 273,
    SALIDA = 274,
    FUNCION_RETORNO = 275,
    TIPO_CADENA = 276,
    VERDADERO = 277,
    VARIABLE = 278,
    BUCLE_WHILE = 279,
    OPERACION_SUMA = 280,
    OPERACION_RESTA = 281,
    OPERACION_MULTIPLICACION = 282,
    OPERACION_DIVISION = 283,
    OPERACION_POTENCIA = 284,
    DISYUNCION_BINARIA = 285,
    NEGACION_BINARIA = 286,
    CONJUNCION_BINARIA = 287,
    LEFT_SHIFT = 288,
    RIGHT_SHIFT = 289,
    DISYUNCION_EXCLUSIVA_BINARIA = 290,
    FIN_DE_INSTRUCCION = 291,
    SEPARACION_VARIABLES = 292,
    INICIO = 293,
    INICIO_FIN_CADENA = 294,
    INICIO_FIN_CARACTER = 295,
    PARENTESIS_IZQUIERDA = 296,
    PARENTESIS_DERECHA = 297,
    CORCHETE_IZQUIERDA = 298,
    CORCHETE_DERECHA = 299,
    MENOR_QUE = 300,
    MAYOR_QUE = 301,
    MENOR_O_IGUAL_QUE = 302,
    MAYOR_O_IGUAL_QUE = 303,
    COMENTARIO = 304,
    ASIGNACION = 305,
    ASIGNACION_PROFUNDA = 306,
    IGUALDAD = 307,
    DESIGUALDAD = 308,
    INCREMENTO_EN_UNIDAD = 309,
    DECREMENTO_EN_UNIDAD = 310,
    CONDICION_UNICA = 311,
    INCREMENTO_DIRECTO = 312,
    DECREMENTO_DIRECTO = 313,
    MULTIPLICACION_DIRECTA = 314,
    DIVISION_DIRECTA = 315,
    NUMERO_ENTERO = 316,
    NUMERO_REAL = 317,
    IDENTIFICADOR = 318,
    SALTO_LINEA = 319,
    TERNARIO_SI = 320,
    TERNARIO_SINO = 321,
    NEUTRO = 322,
    SALTAR_FALSO = 323,
    SALTAR_VERDADERO = 324,
    SALTAR_CONDICIONADO = 325,
    OPERACION_TERNARIA = 326
  };
#endif
/* Tokens.  */
#define Y_LOGICO 258
#define TIPO_BOOLEAN 259
#define CARACTER_RARO 260
#define TIPO_CARACTER 261
#define TIPO_DOUBLE 262
#define CONDICION_SINO 263
#define FIN 264
#define FALSO 265
#define BUCLE_FOR 266
#define FUNCION_INICIO 267
#define CONDICION_INICIO 268
#define ENTRADA 269
#define TIPO_ENTERO 270
#define OPERACION_MODULAR 271
#define NEGACION_LOGICA 272
#define O_LOGICO 273
#define SALIDA 274
#define FUNCION_RETORNO 275
#define TIPO_CADENA 276
#define VERDADERO 277
#define VARIABLE 278
#define BUCLE_WHILE 279
#define OPERACION_SUMA 280
#define OPERACION_RESTA 281
#define OPERACION_MULTIPLICACION 282
#define OPERACION_DIVISION 283
#define OPERACION_POTENCIA 284
#define DISYUNCION_BINARIA 285
#define NEGACION_BINARIA 286
#define CONJUNCION_BINARIA 287
#define LEFT_SHIFT 288
#define RIGHT_SHIFT 289
#define DISYUNCION_EXCLUSIVA_BINARIA 290
#define FIN_DE_INSTRUCCION 291
#define SEPARACION_VARIABLES 292
#define INICIO 293
#define INICIO_FIN_CADENA 294
#define INICIO_FIN_CARACTER 295
#define PARENTESIS_IZQUIERDA 296
#define PARENTESIS_DERECHA 297
#define CORCHETE_IZQUIERDA 298
#define CORCHETE_DERECHA 299
#define MENOR_QUE 300
#define MAYOR_QUE 301
#define MENOR_O_IGUAL_QUE 302
#define MAYOR_O_IGUAL_QUE 303
#define COMENTARIO 304
#define ASIGNACION 305
#define ASIGNACION_PROFUNDA 306
#define IGUALDAD 307
#define DESIGUALDAD 308
#define INCREMENTO_EN_UNIDAD 309
#define DECREMENTO_EN_UNIDAD 310
#define CONDICION_UNICA 311
#define INCREMENTO_DIRECTO 312
#define DECREMENTO_DIRECTO 313
#define MULTIPLICACION_DIRECTA 314
#define DIVISION_DIRECTA 315
#define NUMERO_ENTERO 316
#define NUMERO_REAL 317
#define IDENTIFICADOR 318
#define SALTO_LINEA 319
#define TERNARIO_SI 320
#define TERNARIO_SINO 321
#define NEUTRO 322
#define SALTAR_FALSO 323
#define SALTAR_VERDADERO 324
#define SALTAR_CONDICIONADO 325
#define OPERACION_TERNARIA 326

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);





#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  125
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   278

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  72
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  161
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  239

#define YYUNDEFTOK  2
#define YYMAXUTOK   326


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   267,   267,   269,   270,   272,   274,   275,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   353,   358,   366,   371,   376,   364,   386,   392,   398,
     404,   410,   415,   383,   437,   442,   448,   432,   458,   459,
     462,   461,   468,   472,   467,   478,   482,   477,   488,   487,
     495,   494,   504,   503,   513,   512,   522,   521,   531,   530,
     540,   544,   548,   552,   557,   563,   570,   575,   582,   587,
     594,   599,   605,   611,   617,   623,   629,   635,   640,   646,
     652,   658,   664,   669,   675,   681,   687,   693,   699,   705,
     710,   716,   722,   727,   731,   736,   740,   744,   748,   752,
     758,   757
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "Y_LOGICO", "TIPO_BOOLEAN",
  "CARACTER_RARO", "TIPO_CARACTER", "TIPO_DOUBLE", "CONDICION_SINO", "FIN",
  "FALSO", "BUCLE_FOR", "FUNCION_INICIO", "CONDICION_INICIO", "ENTRADA",
  "TIPO_ENTERO", "OPERACION_MODULAR", "NEGACION_LOGICA", "O_LOGICO",
  "SALIDA", "FUNCION_RETORNO", "TIPO_CADENA", "VERDADERO", "VARIABLE",
  "BUCLE_WHILE", "OPERACION_SUMA", "OPERACION_RESTA",
  "OPERACION_MULTIPLICACION", "OPERACION_DIVISION", "OPERACION_POTENCIA",
  "DISYUNCION_BINARIA", "NEGACION_BINARIA", "CONJUNCION_BINARIA",
  "LEFT_SHIFT", "RIGHT_SHIFT", "DISYUNCION_EXCLUSIVA_BINARIA",
  "FIN_DE_INSTRUCCION", "SEPARACION_VARIABLES", "INICIO",
  "INICIO_FIN_CADENA", "INICIO_FIN_CARACTER", "PARENTESIS_IZQUIERDA",
  "PARENTESIS_DERECHA", "CORCHETE_IZQUIERDA", "CORCHETE_DERECHA",
  "MENOR_QUE", "MAYOR_QUE", "MENOR_O_IGUAL_QUE", "MAYOR_O_IGUAL_QUE",
  "COMENTARIO", "ASIGNACION", "ASIGNACION_PROFUNDA", "IGUALDAD",
  "DESIGUALDAD", "INCREMENTO_EN_UNIDAD", "DECREMENTO_EN_UNIDAD",
  "CONDICION_UNICA", "INCREMENTO_DIRECTO", "DECREMENTO_DIRECTO",
  "MULTIPLICACION_DIRECTA", "DIVISION_DIRECTA", "NUMERO_ENTERO",
  "NUMERO_REAL", "IDENTIFICADOR", "SALTO_LINEA", "TERNARIO_SI",
  "TERNARIO_SINO", "NEUTRO", "SALTAR_FALSO", "SALTAR_VERDADERO",
  "SALTAR_CONDICIONADO", "OPERACION_TERNARIA", "$accept", "programa",
  "lista_sentencias", "comentario", "lista_generica", "elemento_generico",
  "sentencia", "impresion", "lectura", "iteracion", "@1", "@2", "$@3",
  "@4", "@5", "@6", "@7", "@8", "$@9", "seleccion", "@10", "@11", "$@12",
  "bloque", "declaracion", "@13", "@14", "$@15", "asignacion", "@16",
  "$@17", "operacion_unaria", "@18", "@19", "asignacion_operativa", "@20",
  "@21", "@22", "@23", "expresion", "expresion_ternaria", "expresion_0",
  "expresion_1", "expresion_2", "expresion_3", "expresion_4",
  "expresion_5", "expresion_6", "factor", "terminal",
  "sentencia_condicional", "@24", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326
};
# endif

#define YYPACT_NINF (-145)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-121)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      33,  -145,   -32,   -25,   -16,    50,   -11,  -145,   -41,     7,
      75,    58,   212,  -145,  -145,    97,    49,  -145,  -145,    33,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,    22,    23,  -145,
     -14,    59,  -145,   113,    -6,    98,    32,  -145,  -145,  -145,
      47,    58,    10,    58,  -145,   113,    58,    27,  -145,  -145,
     -47,  -145,    37,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,    35,   212,    36,    34,
      38,    30,    40,    42,    55,  -145,  -145,  -145,    61,    61,
      61,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    75,  -145,    67,
      68,    76,    85,    64,    78,    58,    73,  -145,  -145,    58,
    -145,  -145,    61,    61,    61,    61,    59,   -12,  -145,    -6,
      -6,    -6,    -6,    -6,    -6,    98,    98,    98,    98,    32,
      32,    32,    32,    32,    32,  -145,    58,    79,    99,  -145,
     103,  -145,    58,    91,  -145,  -145,   116,   116,   116,   116,
      61,   105,  -145,  -145,  -145,  -145,  -145,    33,   106,   116,
    -145,    33,   107,     4,  -145,  -145,  -145,  -145,  -145,    33,
    -145,  -145,    81,   140,   144,  -145,   108,   120,   126,  -145,
    -145,  -145,  -145,    33,     4,   164,  -145,  -145,  -145
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,   159,     0,     0,     0,     0,     0,   158,     0,     0,
       0,     0,     7,   155,   156,   157,     0,     2,    80,     4,
      73,    75,    74,    76,    71,    77,   122,    78,     0,   121,
     123,   126,   128,   130,   137,   142,   149,   152,   153,    79,
       0,     0,     0,     0,   157,   129,     0,   100,    83,   151,
     157,   120,     0,     8,     9,    70,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,     0,     7,     0,     0,
       0,     0,     0,     0,     0,     1,     3,    72,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    87,     0,
       0,     0,     0,     0,     0,     0,   154,     5,     6,     0,
     109,   111,     0,     0,     0,     0,   125,     0,   127,   132,
     131,   134,   133,   135,   136,   138,   139,   140,   141,   145,
     143,   144,   148,   146,   147,   150,     0,     0,     0,   154,
       0,   101,     0,     0,   160,   106,   113,   115,   117,   119,
       0,     0,    94,    82,    81,   103,    84,     0,     0,   124,
      88,     4,     0,     0,   161,   107,    89,    95,   104,     4,
      99,    85,     0,     0,     0,    86,   108,     0,     0,    98,
      90,    96,    91,     4,     0,     0,    92,    97,    93
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -145,  -145,   -19,  -145,    57,  -145,  -144,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,   -59,   145,  -145,  -145,  -145,  -145,  -145,
    -145,   -38,  -145,  -145,   -10,  -145,  -145,  -145,  -145,    -9,
    -145,  -124,    60,    56,   182,   -28,    41,    26,    -7,  -145,
    -145,  -145
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    16,    17,    18,   116,   117,    19,    20,    21,    22,
     155,   213,   225,   186,   216,   222,   232,   234,   238,    23,
     211,   223,   233,   221,    24,   153,   154,   212,    25,   118,
     208,    26,   119,   120,    27,   121,   122,   123,   124,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,   207
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     126,    51,    52,    49,   128,   167,   128,  -108,  -110,    40,
    -112,  -114,  -116,  -118,     1,     2,    41,     3,     4,   137,
     138,     5,    47,     6,   139,    42,     7,     8,     9,   140,
      46,    51,   149,    51,   151,    10,    51,   152,   196,   197,
     198,   199,   219,     1,     2,    11,     3,     4,    48,   125,
       5,   129,     6,    12,   200,     7,     8,     9,  -120,   127,
       1,   147,   130,   214,    10,    13,    14,    15,     1,   220,
       8,     1,     7,   150,    11,     5,   209,  -102,     5,   156,
       7,    10,    12,     7,   157,     1,   159,   162,   160,    10,
     220,    43,    10,   161,    13,    14,    15,     7,   163,    43,
     191,   164,    43,   169,   170,   171,   172,   173,   174,   187,
     188,    13,    14,    44,   141,   165,    43,   202,   189,    13,
      14,    50,    13,    14,    44,   142,   143,   190,   192,   194,
     144,   145,   146,   206,   128,   203,    13,    14,    44,   204,
     185,   210,   215,   218,   226,    51,   193,  -105,   228,    51,
     195,  -108,  -110,   229,  -112,  -114,  -116,  -118,   131,   132,
     133,   134,   230,  -110,   231,   135,   136,   179,   180,   181,
     182,   183,   184,   237,   158,   236,    51,   201,   175,   176,
     177,   178,    51,   205,   227,   148,   168,    45,   166,     0,
       0,     0,   217,     0,     0,     0,     0,     0,     0,     0,
     224,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   235,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,     0,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115
};

static const yytype_int16 yycheck[] =
{
      19,    11,    11,    10,    18,   129,    18,    54,    55,    41,
      57,    58,    59,    60,    10,    11,    41,    13,    14,    25,
      26,    17,    63,    19,    30,    41,    22,    23,    24,    35,
      41,    41,    41,    43,    43,    31,    46,    46,   162,   163,
     164,   165,    38,    10,    11,    41,    13,    14,    41,     0,
      17,    65,    19,    49,    66,    22,    23,    24,    36,    36,
      10,    29,     3,   207,    31,    61,    62,    63,    10,   213,
      23,    10,    22,    63,    41,    17,   200,    50,    17,    42,
      22,    31,    49,    22,    49,    10,    50,    57,    54,    31,
     234,    41,    31,    55,    61,    62,    63,    22,    58,    41,
      36,    59,    41,   131,   132,   133,   134,   135,   136,    42,
      42,    61,    62,    63,    16,    60,    41,    38,    42,    61,
      62,    63,    61,    62,    63,    27,    28,    42,    50,    56,
      32,    33,    34,    42,    18,    36,    61,    62,    63,    36,
     147,    36,    36,    36,    63,   155,   155,    50,     8,   159,
     159,    54,    55,     9,    57,    58,    59,    60,    45,    46,
      47,    48,    42,    55,    38,    52,    53,   141,   142,   143,
     144,   145,   146,     9,   117,   234,   186,   186,   137,   138,
     139,   140,   192,   192,   222,    40,   130,     5,   128,    -1,
      -1,    -1,   211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   233,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    10,    11,    13,    14,    17,    19,    22,    23,    24,
      31,    41,    49,    61,    62,    63,    73,    74,    75,    78,
      79,    80,    81,    91,    96,   100,   103,   106,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
      41,    41,    41,    41,    63,   116,    41,    63,    41,   120,
      63,   106,   111,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    76,    77,   101,   104,
     105,   107,   108,   109,   110,     0,    74,    36,    18,    65,
       3,    45,    46,    47,    48,    52,    53,    25,    26,    30,
      35,    16,    27,    28,    32,    33,    34,    29,    96,   111,
      63,   111,   111,    97,    98,    82,    42,    49,    76,    50,
      54,    55,    57,    58,    59,    60,   114,   113,   115,   117,
     117,   117,   117,   117,   117,   118,   118,   118,   118,   119,
     119,   119,   119,   119,   119,   120,    85,    42,    42,    42,
      42,    36,    50,   111,    56,   111,   113,   113,   113,   113,
      66,   111,    38,    36,    36,   111,    42,   123,   102,   113,
      36,    92,    99,    83,    78,    36,    86,    74,    36,    38,
      78,    95,    87,    93,    74,    84,    63,   103,     8,     9,
      42,    38,    88,    94,    89,    74,    95,     9,    90
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    72,    73,    74,    74,    75,    76,    76,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    79,    80,    82,    83,    84,    81,    85,    86,    87,
      88,    89,    90,    81,    92,    93,    94,    91,    95,    95,
      97,    96,    98,    99,    96,   101,   102,   100,   104,   103,
     105,   103,   107,   106,   108,   106,   109,   106,   110,   106,
     111,   111,   111,   111,   112,   113,   113,   114,   114,   115,
     115,   116,   116,   116,   116,   116,   116,   116,   117,   117,
     117,   117,   117,   118,   118,   118,   118,   118,   118,   118,
     119,   119,   119,   120,   120,   121,   121,   121,   121,   121,
     123,   122
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     2,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     5,     0,     0,     0,     8,     0,     0,     0,
       0,     0,     0,    14,     0,     0,     0,    13,     3,     1,
       0,     4,     0,     0,     7,     0,     0,     6,     0,     3,
       0,     3,     0,     4,     0,     4,     0,     4,     0,     4,
       1,     1,     1,     1,     5,     3,     1,     3,     1,     2,
       1,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     3,     3,     3,     3,     1,
       3,     2,     1,     1,     3,     1,     1,     1,     1,     1,
       0,     6
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 81:
#line 354 "base.y"
{
	GenerarCodigo(SALIDA, yyvsp[-2], NEUTRO, NEUTRO);
}
#line 1691 "y.tab.c"
    break;

  case 82:
#line 359 "base.y"
{
	GenerarCodigo(ENTRADA, yyvsp[-2], NEUTRO, NEUTRO);
}
#line 1699 "y.tab.c"
    break;

  case 83:
#line 366 "base.y"
{
	yyval = posicion_ultimo_codigo + 1;
}
#line 1707 "y.tab.c"
    break;

  case 84:
#line 371 "base.y"
{
	GenerarCodigo(SALTAR_FALSO, yyvsp[-1], NEUTRO, NEUTRO);
	yyval = posicion_ultimo_codigo;
}
#line 1716 "y.tab.c"
    break;

  case 85:
#line 376 "base.y"
{
	GenerarCodigo(SALTAR_VERDADERO, yyvsp[-4], NEUTRO, NEUTRO);
}
#line 1724 "y.tab.c"
    break;

  case 86:
#line 379 "base.y"
{
	tabla_codigos[yyvsp[-2]].a2 = posicion_ultimo_codigo + 1;
}
#line 1732 "y.tab.c"
    break;

  case 87:
#line 386 "base.y"
{
  // Dejamos un primer punto de control para la condicion de detencion
  yyval = posicion_ultimo_codigo + 1;
}
#line 1741 "y.tab.c"
    break;

  case 88:
#line 392 "base.y"
{
  // Si la expresion en $6 es verdadera, nos dirigimos hacia el bloque interno.
  // En otro caso, nos dirigimos al exterior del bucle
  GenerarCodigo(SALTAR_CONDICIONADO, yyvsp[-1], NEUTRO, NEUTRO); 
  yyval = posicion_ultimo_codigo;
}
#line 1752 "y.tab.c"
    break;

  case 89:
#line 398 "base.y"
{
  // Dejamos un punto de control para la actualizacion
  yyval = posicion_ultimo_codigo + 1;
}
#line 1761 "y.tab.c"
    break;

  case 90:
#line 404 "base.y"
{
  // Tras la actualizacion, nos dirigimos de nuevo hacia la condicion
  // que controla si continuamos o no en el bucle
  GenerarCodigo(SALTAR_VERDADERO, yyvsp[-6], NEUTRO, NEUTRO);
  yyval = posicion_ultimo_codigo;
}
#line 1772 "y.tab.c"
    break;

  case 91:
#line 410 "base.y"
{
  // Dejamos un punto de control para el bloque interno
  yyval = posicion_ultimo_codigo + 1;
}
#line 1781 "y.tab.c"
    break;

  case 92:
#line 415 "base.y"
{
  // Al concluir el bloque, nos dirigimos a la expresion de actualizacion
  GenerarCodigo(SALTAR_VERDADERO, yyvsp[-5], NEUTRO, NEUTRO);
}
#line 1790 "y.tab.c"
    break;

  case 93:
#line 419 "base.y"
{
  // En este punto ya conocemos los codigos intermedios, por lo que podemos
  // especificar a donde se tiene que dirigir la condicion de detencion en
  // cada caso

  // Cuando la condicion es falsa, salimos del bucle
  tabla_codigos[yyvsp[-7]].a2 = posicion_ultimo_codigo + 1;
  // Cuando la condicion es verdadera, nos dirigimos hacia el bloque interno
  tabla_codigos[yyvsp[-7]].a3 = yyvsp[-2];
}
#line 1805 "y.tab.c"
    break;

  case 94:
#line 437 "base.y"
{
  GenerarCodigo(SALTAR_FALSO, yyvsp[-2], NEUTRO, NEUTRO);
  yyval = posicion_ultimo_codigo;
}
#line 1814 "y.tab.c"
    break;

  case 95:
#line 442 "base.y"
{
  GenerarCodigo(SALTAR_VERDADERO, NEUTRO, NEUTRO, NEUTRO);
  yyval = posicion_ultimo_codigo;
}
#line 1823 "y.tab.c"
    break;

  case 96:
#line 448 "base.y"
{
  tabla_codigos[yyvsp[-4]].a2 = posicion_ultimo_codigo + 1;
}
#line 1831 "y.tab.c"
    break;

  case 97:
#line 453 "base.y"
{
  tabla_codigos[yyvsp[-5]].a1 = posicion_ultimo_codigo + 1;
}
#line 1839 "y.tab.c"
    break;

  case 100:
#line 462 "base.y"
{
	yyval = LocalizarSimbolo(lexema, IDENTIFICADOR);
}
#line 1847 "y.tab.c"
    break;

  case 102:
#line 468 "base.y"
{
	yyval = LocalizarSimbolo(lexema, IDENTIFICADOR);
}
#line 1855 "y.tab.c"
    break;

  case 103:
#line 472 "base.y"
{
	GenerarCodigo(ASIGNACION, yyvsp[-2], yyvsp[0], NEUTRO);
}
#line 1863 "y.tab.c"
    break;

  case 105:
#line 478 "base.y"
{
	yyval = LocalizarSimbolo(lexema, IDENTIFICADOR);
}
#line 1871 "y.tab.c"
    break;

  case 106:
#line 482 "base.y"
{
	GenerarCodigo(ASIGNACION, yyvsp[-2], yyvsp[0], NEUTRO);
}
#line 1879 "y.tab.c"
    break;

  case 108:
#line 488 "base.y"
{
	yyval = LocalizarSimbolo(lexema, IDENTIFICADOR);
}
#line 1887 "y.tab.c"
    break;

  case 109:
#line 491 "base.y"
{
	GenerarCodigo(INCREMENTO_EN_UNIDAD, yyvsp[-1], NEUTRO, NEUTRO);
}
#line 1895 "y.tab.c"
    break;

  case 110:
#line 495 "base.y"
{
	yyval = LocalizarSimbolo(lexema, IDENTIFICADOR);
}
#line 1903 "y.tab.c"
    break;

  case 111:
#line 498 "base.y"
{
	GenerarCodigo(DECREMENTO_EN_UNIDAD, yyvsp[-1], NEUTRO, NEUTRO);
}
#line 1911 "y.tab.c"
    break;

  case 112:
#line 504 "base.y"
{
	yyval = LocalizarSimbolo(lexema, IDENTIFICADOR);
}
#line 1919 "y.tab.c"
    break;

  case 113:
#line 508 "base.y"
{
	GenerarCodigo(INCREMENTO_DIRECTO, yyvsp[-2], yyvsp[0], NEUTRO);
	yyval = yyvsp[-2];
}
#line 1928 "y.tab.c"
    break;

  case 114:
#line 513 "base.y"
{
	yyval = LocalizarSimbolo(lexema, IDENTIFICADOR);
}
#line 1936 "y.tab.c"
    break;

  case 115:
#line 517 "base.y"
{
	GenerarCodigo(DECREMENTO_DIRECTO, yyvsp[-2], yyvsp[0], NEUTRO);
	yyval = yyvsp[-2];
}
#line 1945 "y.tab.c"
    break;

  case 116:
#line 522 "base.y"
{
	yyval = LocalizarSimbolo(lexema, IDENTIFICADOR);
}
#line 1953 "y.tab.c"
    break;

  case 117:
#line 526 "base.y"
{
	GenerarCodigo(MULTIPLICACION_DIRECTA, yyvsp[-2], yyvsp[0], NEUTRO);
	yyval = yyvsp[-2];
}
#line 1962 "y.tab.c"
    break;

  case 118:
#line 531 "base.y"
{
	yyval = LocalizarSimbolo(lexema, IDENTIFICADOR);
}
#line 1970 "y.tab.c"
    break;

  case 119:
#line 535 "base.y"
{
	GenerarCodigo(DIVISION_DIRECTA, yyvsp[-2], yyvsp[0], NEUTRO);
	yyval = yyvsp[-2];
}
#line 1979 "y.tab.c"
    break;

  case 120:
#line 541 "base.y"
{
	yyval = yyvsp[0];
}
#line 1987 "y.tab.c"
    break;

  case 121:
#line 545 "base.y"
{
	yyval = yyvsp[0];
}
#line 1995 "y.tab.c"
    break;

  case 122:
#line 549 "base.y"
{
	yyval = yyvsp[0];
}
#line 2003 "y.tab.c"
    break;

  case 123:
#line 553 "base.y"
{
	yyval = yyvsp[0];
}
#line 2011 "y.tab.c"
    break;

  case 124:
#line 558 "base.y"
{
	GenerarCodigo(OPERACION_TERNARIA, yyvsp[-4], yyvsp[-2], yyvsp[0]);
	yyval = yyvsp[-4];
}
#line 2020 "y.tab.c"
    break;

  case 125:
#line 564 "base.y"
{
	int posicion_temporal = GenerarTemporal();
	GenerarCodigo(O_LOGICO, posicion_temporal, yyvsp[-2], yyvsp[0]);
	yyval = posicion_temporal;
}
#line 2030 "y.tab.c"
    break;

  case 126:
#line 571 "base.y"
{
	yyval = yyvsp[0];
}
#line 2038 "y.tab.c"
    break;

  case 127:
#line 576 "base.y"
{
	int posicion_temporal = GenerarTemporal();
	GenerarCodigo(Y_LOGICO, posicion_temporal, yyvsp[-2], yyvsp[0]);
	yyval = posicion_temporal;
}
#line 2048 "y.tab.c"
    break;

  case 128:
#line 583 "base.y"
{
	yyval = yyvsp[0];
}
#line 2056 "y.tab.c"
    break;

  case 129:
#line 588 "base.y"
{
	int posicion_temporal = GenerarTemporal();
	GenerarCodigo(NEGACION_LOGICA, posicion_temporal, yyvsp[0], NEUTRO);
	yyval = posicion_temporal;
}
#line 2066 "y.tab.c"
    break;

  case 130:
#line 595 "base.y"
{
	yyval = yyvsp[0];
}
#line 2074 "y.tab.c"
    break;

  case 131:
#line 600 "base.y"
{
	int posicion_temporal = GenerarTemporal();
	GenerarCodigo(MAYOR_QUE, posicion_temporal, yyvsp[-2], yyvsp[0]);
	yyval = posicion_temporal;
}
#line 2084 "y.tab.c"
    break;

  case 132:
#line 606 "base.y"
{
	int posicion_temporal = GenerarTemporal();
	GenerarCodigo(MENOR_QUE, posicion_temporal, yyvsp[-2], yyvsp[0]);
	yyval = posicion_temporal;
}
#line 2094 "y.tab.c"
    break;

  case 133:
#line 612 "base.y"
{
	int posicion_temporal = GenerarTemporal();
	GenerarCodigo(MAYOR_O_IGUAL_QUE, posicion_temporal, yyvsp[-2], yyvsp[0]);
	yyval = posicion_temporal;
}
#line 2104 "y.tab.c"
    break;

  case 134:
#line 618 "base.y"
{
	int posicion_temporal = GenerarTemporal();
	GenerarCodigo(MENOR_O_IGUAL_QUE, posicion_temporal, yyvsp[-2], yyvsp[0]);
	yyval = posicion_temporal;
}
#line 2114 "y.tab.c"
    break;

  case 135:
#line 624 "base.y"
{
	int posicion_temporal = GenerarTemporal();
	GenerarCodigo(IGUALDAD, posicion_temporal, yyvsp[-2], yyvsp[0]);
	yyval = posicion_temporal;
}
#line 2124 "y.tab.c"
    break;

  case 136:
#line 630 "base.y"
{
	int posicion_temporal = GenerarTemporal();
	GenerarCodigo(DESIGUALDAD, posicion_temporal, yyvsp[-2], yyvsp[0]);
	yyval = posicion_temporal;
}
#line 2134 "y.tab.c"
    break;

  case 137:
#line 636 "base.y"
{
	yyval = yyvsp[0];
}
#line 2142 "y.tab.c"
    break;

  case 138:
#line 641 "base.y"
{
	int posicion_temporal = GenerarTemporal();
	GenerarCodigo(OPERACION_SUMA, posicion_temporal, yyvsp[-2], yyvsp[0]);
	yyval = posicion_temporal;
}
#line 2152 "y.tab.c"
    break;

  case 139:
#line 647 "base.y"
{
	int posicion_temporal = GenerarTemporal();
	GenerarCodigo(OPERACION_RESTA, posicion_temporal, yyvsp[-2], yyvsp[0]);
	yyval = posicion_temporal;
}
#line 2162 "y.tab.c"
    break;

  case 140:
#line 653 "base.y"
{
	int posicion_temporal = GenerarTemporal();
	GenerarCodigo(DISYUNCION_BINARIA, posicion_temporal, yyvsp[-2], yyvsp[0]);
	yyval = posicion_temporal;
}
#line 2172 "y.tab.c"
    break;

  case 141:
#line 659 "base.y"
{
	int posicion_temporal = GenerarTemporal();
	GenerarCodigo(DISYUNCION_EXCLUSIVA_BINARIA, posicion_temporal, yyvsp[-2], yyvsp[0]);
	yyval = posicion_temporal;
}
#line 2182 "y.tab.c"
    break;

  case 142:
#line 665 "base.y"
{
	yyval = yyvsp[0];
}
#line 2190 "y.tab.c"
    break;

  case 143:
#line 670 "base.y"
{
	int posicion_temporal = GenerarTemporal();
 	GenerarCodigo(OPERACION_MULTIPLICACION, posicion_temporal, yyvsp[-2], yyvsp[0]);
 	yyval = posicion_temporal;
}
#line 2200 "y.tab.c"
    break;

  case 144:
#line 676 "base.y"
{
	int posicion_temporal = GenerarTemporal();
	GenerarCodigo(OPERACION_DIVISION, posicion_temporal, yyvsp[-2], yyvsp[0]);
	yyval = posicion_temporal;
}
#line 2210 "y.tab.c"
    break;

  case 145:
#line 682 "base.y"
{
	int posicion_temporal = GenerarTemporal();
	GenerarCodigo(OPERACION_MODULAR, posicion_temporal, yyvsp[-2], yyvsp[0]);
	yyval = posicion_temporal;
}
#line 2220 "y.tab.c"
    break;

  case 146:
#line 688 "base.y"
{
	int posicion_temporal = GenerarTemporal();
	GenerarCodigo(LEFT_SHIFT, posicion_temporal, yyvsp[-2], yyvsp[0]);
	yyval = posicion_temporal;
}
#line 2230 "y.tab.c"
    break;

  case 147:
#line 694 "base.y"
{
	int posicion_temporal = GenerarTemporal();
	GenerarCodigo(RIGHT_SHIFT, posicion_temporal, yyvsp[-2], yyvsp[0]);
	yyval = posicion_temporal;
}
#line 2240 "y.tab.c"
    break;

  case 148:
#line 700 "base.y"
{
	int posicion_temporal = GenerarTemporal();
	GenerarCodigo(CONJUNCION_BINARIA, posicion_temporal, yyvsp[-2], yyvsp[0]);
	yyval = posicion_temporal;
}
#line 2250 "y.tab.c"
    break;

  case 149:
#line 706 "base.y"
{
	yyval = yyvsp[0];
}
#line 2258 "y.tab.c"
    break;

  case 150:
#line 711 "base.y"
{
	int posicion_temporal = GenerarTemporal();
	GenerarCodigo(OPERACION_POTENCIA, posicion_temporal, yyvsp[-2], yyvsp[0]);
	yyval = posicion_temporal;
}
#line 2268 "y.tab.c"
    break;

  case 151:
#line 717 "base.y"
{
	int posicion_temporal = GenerarTemporal();
  	GenerarCodigo(NEGACION_BINARIA, posicion_temporal, yyvsp[0], NEUTRO);
  	yyval = posicion_temporal;
}
#line 2278 "y.tab.c"
    break;

  case 152:
#line 723 "base.y"
{
	yyval = yyvsp[0];
}
#line 2286 "y.tab.c"
    break;

  case 153:
#line 728 "base.y"
{
	yyval = yyvsp[0];
}
#line 2294 "y.tab.c"
    break;

  case 154:
#line 732 "base.y"
{
	yyval = yyvsp[-1];
}
#line 2302 "y.tab.c"
    break;

  case 155:
#line 737 "base.y"
{
	yyval = LocalizarSimbolo(lexema, NUMERO_ENTERO);
}
#line 2310 "y.tab.c"
    break;

  case 156:
#line 741 "base.y"
{
	yyval = LocalizarSimbolo(lexema, NUMERO_REAL);
}
#line 2318 "y.tab.c"
    break;

  case 157:
#line 745 "base.y"
{
	yyval = LocalizarSimbolo(lexema, IDENTIFICADOR);
}
#line 2326 "y.tab.c"
    break;

  case 158:
#line 749 "base.y"
{
	yyval = LocalizarSimbolo(lexema, VERDADERO);
}
#line 2334 "y.tab.c"
    break;

  case 159:
#line 753 "base.y"
{
	yyval = LocalizarSimbolo(lexema, FALSO);
}
#line 2342 "y.tab.c"
    break;

  case 160:
#line 758 "base.y"
{
	GenerarCodigo(SALTAR_FALSO, yyvsp[-2], NEUTRO, NEUTRO);
	yyval = posicion_ultimo_codigo;
}
#line 2351 "y.tab.c"
    break;

  case 161:
#line 762 "base.y"
{
	tabla_codigos[yyvsp[-1]].a2 = posicion_ultimo_codigo + 1;
}
#line 2359 "y.tab.c"
    break;


#line 2363 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 766 "base.y"


void InterpretarCodigo(void) {
	int op, a1, a2, a3;
	for (int i = 0; i <= posicion_ultimo_codigo; i++) {
		op = tabla_codigos[i].op;
		a1 = tabla_codigos[i].a1;
		a2 = tabla_codigos[i].a2;
		a3 = tabla_codigos[i].a3;

		if (op == ASIGNACION) {
			tabla_simbolos[a1].valor = tabla_simbolos[a2].valor;
		}
		if (op == CONJUNCION_BINARIA) {
			tabla_simbolos[a1].valor = tabla_simbolos[a2].valor & tabla_simbolos[a3].valor;
		}
		if (op == DECREMENTO_DIRECTO) {
			tabla_simbolos[a1].valor -= tabla_simbolos[a2].valor;
		}
		if (op == DECREMENTO_EN_UNIDAD) {
			tabla_simbolos[a1].valor--;
		}
		if (op == DESIGUALDAD) {
			tabla_simbolos[a1].valor = tabla_simbolos[a2].valor != tabla_simbolos[a3].valor;
		}
		if (op == DISYUNCION_BINARIA) {
			tabla_simbolos[a1].valor = tabla_simbolos[a2].valor | tabla_simbolos[a3].valor;
		}
		if (op == DISYUNCION_EXCLUSIVA_BINARIA) {
			tabla_simbolos[a1].valor = tabla_simbolos[a2].valor ^ tabla_simbolos[a3].valor;
		}
		if (op == DIVISION_DIRECTA) {
			tabla_simbolos[a1].valor /= tabla_simbolos[a2].valor;
		}
		if (op == ENTRADA) {
			scanf("%d", &tabla_simbolos[a1].valor);
		}
		if (op == IGUALDAD) {
			tabla_simbolos[a1].valor = tabla_simbolos[a2].valor == tabla_simbolos[a3].valor;
		}
		if (op == INCREMENTO_DIRECTO) {
			tabla_simbolos[a1].valor += tabla_simbolos[a2].valor;
		}
		if (op == INCREMENTO_EN_UNIDAD) {
			tabla_simbolos[a1].valor++;
		}
		if (op == LEFT_SHIFT) {
			tabla_simbolos[a1].valor = tabla_simbolos[a2].valor << tabla_simbolos[a3].valor;
		}
		if (op == MAYOR_O_IGUAL_QUE) {
			tabla_simbolos[a1].valor = tabla_simbolos[a2].valor >= tabla_simbolos[a3].valor;
		}
		if (op == MAYOR_QUE) {
			tabla_simbolos[a1].valor = tabla_simbolos[a2].valor > tabla_simbolos[a3].valor;
		}
		if (op == MENOR_O_IGUAL_QUE) {
			tabla_simbolos[a1].valor = tabla_simbolos[a2].valor <= tabla_simbolos[a3].valor;
		}
		if (op == MENOR_QUE) {
			tabla_simbolos[a1].valor = tabla_simbolos[a2].valor < tabla_simbolos[a3].valor;
		}
		if (op == MULTIPLICACION_DIRECTA) {
			tabla_simbolos[a1].valor *= tabla_simbolos[a2].valor;
		}
		if (op == NEGACION_BINARIA) {
			tabla_simbolos[a1].valor = ~tabla_simbolos[a2].valor;
		}
		if (op == NEGACION_LOGICA) {
			tabla_simbolos[a1].valor = !tabla_simbolos[a2].valor;
		}
		if (op == O_LOGICO) {
			tabla_simbolos[a1].valor = tabla_simbolos[a2].valor || tabla_simbolos[a3].valor;
		}
		if (op == OPERACION_DIVISION) {
			tabla_simbolos[a1].valor = tabla_simbolos[a2].valor / tabla_simbolos[a3].valor;
		}
		if (op == OPERACION_MODULAR) {
			tabla_simbolos[a1].valor = tabla_simbolos[a2].valor % tabla_simbolos[a3].valor;
		}
		if (op == OPERACION_MULTIPLICACION) {
			tabla_simbolos[a1].valor = tabla_simbolos[a2].valor * tabla_simbolos[a3].valor;
		}
		if (op == OPERACION_POTENCIA) {
			// En caso utilizar double, cambiamos el siguiente algoritmo por la funcion pow de math.h
			int base = tabla_simbolos[a2].valor;
			int exponente = tabla_simbolos[a3].valor;
			int resultado = 1;
			while (exponente > 0) {
				if (exponente & 1) resultado *= base;
				exponente >>= 1;
				base *= base;
			}
			tabla_simbolos[a1].valor = resultado;
		}
		if (op == OPERACION_RESTA) {
			tabla_simbolos[a1].valor = tabla_simbolos[a2].valor - tabla_simbolos[a3].valor;
		}
		if (op == OPERACION_SUMA) {
			tabla_simbolos[a1].valor = tabla_simbolos[a2].valor + tabla_simbolos[a3].valor;
		}
		if (op == RIGHT_SHIFT) {
			tabla_simbolos[a1].valor = tabla_simbolos[a2].valor >> tabla_simbolos[a3].valor;
		}
		if (op == SALIDA) {
			printf("%d\n",tabla_simbolos[a1].valor);
		}
    if (op == SALTAR_CONDICIONADO) {
      if (tabla_simbolos[a1].valor == 0) {
        i = a2 - 1;
      } else {
        i = a3 - 1;
      }
    }
		if (op == SALTAR_FALSO) {
			if (tabla_simbolos[a1].valor == 0) {
        i = a2 - 1;
      }
		}
		if (op == SALTAR_VERDADERO) {
			i = a1 - 1;
		}
		if (op == Y_LOGICO) {
			// TODO: Darle precedencia adecuada
			tabla_simbolos[a1].valor = tabla_simbolos[a2].valor && tabla_simbolos[a3].valor;
		}
		if (op == OPERACION_TERNARIA) {
			tabla_simbolos[a1].valor = tabla_simbolos[a1].valor ? tabla_simbolos[a2].valor : tabla_simbolos[a3].valor;
		}
	}
}

int GenerarTemporal(void) {
	char t[10];
	sprintf(t, "tmp_%d", cantidad_variables_temporales++);
	return LocalizarSimbolo(t, IDENTIFICADOR);
}

int GenerarCodigo(int op, int a1, int a2, int a3) {
	posicion_ultimo_codigo++;
	tabla_codigos[posicion_ultimo_codigo].op = op;
	tabla_codigos[posicion_ultimo_codigo].a1 = a1;
	tabla_codigos[posicion_ultimo_codigo].a2 = a2;
	tabla_codigos[posicion_ultimo_codigo].a3 = a3;
}

void ImprimirTablaCodigos(void) {
	printf("Tabla Codigo:\n");
	printf("cod_op\tpos_sim\tpos_x\tpos_y\n");
	for (int pos = 0; pos <= posicion_ultimo_codigo; pos++) {
		printf("%d\t%d\t%d\t%d\n",
		tabla_codigos[pos].op,
		tabla_codigos[pos].a1,
		tabla_codigos[pos].a2,
		tabla_codigos[pos].a3);
	}
}

void ImprimirTablaSimbolos(void) {
	printf("Tabla Simbolos:\n");
	printf("pos \tnombre \ttoken \tvalor\n");
	for (int pos = 0; pos < cantidad_simbolos; pos++) {
		printf("%d\t%s\t%d\t%d\n",
		pos,
		tabla_simbolos[pos].nombre,
		tabla_simbolos[pos].token,
		tabla_simbolos[pos].valor);
	}
}

// Retorna la posicion del codigo buscado en caso exista, o del ultimo elemento en la tabla de simbolos pues este sera
// anadido en dicha posicion.

int LocalizarSimbolo(char* lexema, int token) {

	// Si el simbolo ya existe, retornamos su posicion en la tabla

  	for (int i = 0; i < cantidad_simbolos; i++) {
  		if (strcmp(tabla_simbolos[i].nombre, lexema) == 0) {
  			return i;
  		}
  	}

	// Asignamos un espacio en la tabla de simbolos al nuevo simbolo

	strcpy(tabla_simbolos[cantidad_simbolos].nombre, lexema);
	tabla_simbolos[cantidad_simbolos].token = token;
	if (token == NUMERO_ENTERO) {
		tabla_simbolos[cantidad_simbolos].valor = atoi(lexema);
	} else if (token == NUMERO_REAL) {
		tabla_simbolos[cantidad_simbolos].valor = atof(lexema);
	} else if (token == IDENTIFICADOR) {
		tabla_simbolos[cantidad_simbolos].valor = 0;
	} else if (token == VERDADERO) {
		tabla_simbolos[cantidad_simbolos].valor = 1;
	} else if (token == FALSO) {
		tabla_simbolos[cantidad_simbolos].valor = 0;
	}
	return cantidad_simbolos++;
}

int main(int argc, char* argv[]) {
	clock_t tiempo = clock();
	char nombre_archivo[100];
	if (argc == 1) {
		printf("ERROR: Por favor ingrese el nombre de test\n");
		exit(1);
	}
	sprintf(nombre_archivo, "../../tests/lab05/%s", argv[1]);
	arch = fopen(nombre_archivo, "r");

    if (arch == NULL) {
    	printf("ERROR: No se ha abierto el archivo %s correctamente.\n", nombre_archivo);
        exit(1);
    }
    if (!yyparse()) {
        printf("Programa correcto.\n");
        //Si desea ver la impresión de las tablas de simbolos y codigos, por favor descomente las siguientes lineas:
        //ImprimirTablaSimbolos();
        //ImprimirTablaCodigos();
        InterpretarCodigo();
        //ImprimirTablaSimbolos();
    } else {
        printf("Error de sintaxis.\n");
    }
    tiempo = clock() - tiempo;
    double tiempo_ejecucion = ((double) tiempo) / CLOCKS_PER_SEC * 1000000;
    printf("Tiempo de ejecucion: %f ms\n", tiempo_ejecucion);
}

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

int yylex() {
    char c;
    int pos;
    while (isspace((c = fgetc(arch))));
    if (c == EOF) return 0;

    /*
     * Caso 1:
     * Si el token comienza con una letra del alfabeto o guion bajo tenemos las siguientes posibilidades:
     * Todas son letras del alfabeto. Verifico si es que es palabra reservada para retornarla.
     * En otro caso, necesariamente es un identificador
     */

    if (isalpha(c) || c == '_') {
        pos = 0;
        do {
            lexema[pos++] = c;
            c = fgetc(arch);
            //printf("%c\n", c);
        } while ('a' <= c && c <= 'z' || 'A' <= c && c <= 'Z' || '0' <= c && c <= '9' || c == '_');
        ungetc(c, arch);
        lexema[pos++] = '\0';
        //printf("%s\n", lexema);
        int solo_alfabeto = 1;
        for (int i = 0; i < pos - 1; i++) {
            if (!isalpha(lexema[i])) {
                solo_alfabeto = 0;
                break;
            }
        }
        if (solo_alfabeto) {
            if (strcmp(lexema, "and") == 0) return Y_LOGICO;
            if (strcmp(lexema, "bool") == 0) return TIPO_BOOLEAN;
            if (strcmp(lexema, "char") == 0) return TIPO_CARACTER;
            if (strcmp(lexema, "double") == 0) return TIPO_DOUBLE;
            if (strcmp(lexema, "else") == 0) return CONDICION_SINO;
            if (strcmp(lexema, "end") == 0) return FIN;
            if (strcmp(lexema, "false") == 0) return FALSO;
            if (strcmp(lexema, "for") == 0) return BUCLE_FOR;
            if (strcmp(lexema, "function") == 0) return FUNCION_INICIO;
            if (strcmp(lexema, "if") == 0) return CONDICION_INICIO;
            if (strcmp(lexema, "input") == 0) return ENTRADA;
            if (strcmp(lexema, "int") == 0) return TIPO_ENTERO;
            if (strcmp(lexema, "mod") == 0) return OPERACION_MODULAR;
            if (strcmp(lexema, "not") == 0) return NEGACION_LOGICA;
            if (strcmp(lexema, "or") == 0) return O_LOGICO;
            if (strcmp(lexema, "output") == 0) return SALIDA;
            if (strcmp(lexema, "return") == 0) return FUNCION_RETORNO;
            if (strcmp(lexema, "string") == 0) return TIPO_CADENA;
            if (strcmp(lexema, "true") == 0) return VERDADERO;
            if (strcmp(lexema, "var") == 0) return VARIABLE;
            if (strcmp(lexema, "while") == 0) return BUCLE_WHILE;
        }
        return IDENTIFICADOR;
    }

    /*
     * Caso 2:
     * Si el token comienza con un numero analizo lo siguiente:
     * Obtengo todos los digitos consecutivos posibles.
     * Si es que el caracter siguiente es un punto y lo que le sigue un numero, entonces obtengo el siguiente
     * numero entero posible y a esto lo convierto en mi numero real.
     * Sino retorno un numero entero.
     */

    if (isdigit(c)) {
        // Obtengo la parte entera
        pos = 0;
        do {
            lexema[pos++] = c;
            c = fgetc(arch);
        } while (isdigit(c));

        // Si es que tenemos un punto flotante analizamos dos casos
        if (c == '.') {
            int longitud_parte_entera = pos;
            do {
                lexema[pos++] = c;
                c = fgetc(arch);
            } while (isdigit(c));
            ungetc(c, arch);

            // Si es que no hemos encontrado ningun digito valido luego del punto, solo retornamos la parte entera
            if (pos == longitud_parte_entera + 1) {
                ungetc('.', arch);
                lexema[longitud_parte_entera] = '\0';
                return NUMERO_ENTERO;
            } else {
                // En otro caso, retorno el numero real que ha sido escaneado
                lexema[pos] = '\0';
                return NUMERO_REAL;
            }
        } else {
            // Si lo que sigue al punto no es lo suficiente como para formar la parte decimal
            // devuelvo el punto al buffer y retorno el numero entero
            ungetc(c, arch);
            lexema[pos] = '\0';
            return NUMERO_ENTERO;
        }
    }

    //En esta ultima parte, solo nos falta analizar simbolos.
    pos = 0;

    // Multiplicacion, potencia e multiplicacion directa
    if (c == '*') {
        c = fgetc(arch);
        if (c == '*') return OPERACION_POTENCIA;
        if (c == '=') return MULTIPLICACION_DIRECTA;
        /*
         * En caso no coincida con ninguna de las anteriores, unicamente estamos multiplicando y devolvemos
         * el ultimo caracter analizado al buffer del archivo.
         */
        ungetc(c, arch);
        return OPERACION_MULTIPLICACION;
    }

    // Menor que, menor o igual que y left shift
    if (c == '<') {
        c = fgetc(arch);
        if (c == '<') return LEFT_SHIFT;
        if (c == '=') return MENOR_O_IGUAL_QUE;
        ungetc(c, arch);
        return MENOR_QUE;
    }

    // Mayor que, mayor o igual que y right shift
    if (c == '>') {
        c = fgetc(arch);
        if (c == '>') return RIGHT_SHIFT;
        if (c == '=') return MAYOR_O_IGUAL_QUE;
        ungetc(c, arch);
        return MAYOR_QUE;
    }

    // Asignación, comparación de igualdad
    if (c == '=') {
        c = fgetc(arch);
        if (c == '=') return IGUALDAD;
        ungetc(c, arch);
        return ASIGNACION;
    }

    if (c == '+') {
        c = fgetc(arch);
        if (c == '=') return INCREMENTO_DIRECTO;
        if (c == '+') return INCREMENTO_EN_UNIDAD;
        ungetc(c, arch);
        return OPERACION_SUMA;
    }

    if (c == '-') {
        c = fgetc(arch);
        if (c == '=') return DECREMENTO_DIRECTO;
        if (c == '-') return DECREMENTO_EN_UNIDAD;
        if (c == '>') return TERNARIO_SI;
        ungetc(c, arch);
        return OPERACION_RESTA;
    }

    if (c == '/') {
        c = fgetc(arch);
        if (c == '=') return DIVISION_DIRECTA;
        ungetc(c, arch);
        return OPERACION_DIVISION;
    }

    if (c == '!') {
        c = fgetc(arch);
        if (c == '=') return DESIGUALDAD;
        ungetc(c, arch);
        return NEGACION_LOGICA;
    }

    if (c == '&') {
			c = fgetc(arch);
			if (c == '&') return CONDICION_UNICA;
			ungetc(c, arch);
			return CONJUNCION_BINARIA;
    }

    if (c == '%'){
    	c = fgetc(arch);
    	if (c == '%') return COMENTARIO;
    	ungetc(c, arch);
    }

    if (c == ';') return FIN_DE_INSTRUCCION;
    if (c == ',') return SEPARACION_VARIABLES;
    if (c == ':') return INICIO;
    if (c == '"') return INICIO_FIN_CADENA;
    if (c == '\'') return INICIO_FIN_CARACTER;
    if (c == '(') return PARENTESIS_IZQUIERDA;
    if (c == ')') return PARENTESIS_DERECHA;
    if (c == '[') return CORCHETE_IZQUIERDA;
    if (c == ']') return CORCHETE_DERECHA;
    if (c == '~') return NEGACION_BINARIA;
    if (c == '|') return DISYUNCION_BINARIA;
    if (c == '^') return DISYUNCION_EXCLUSIVA_BINARIA;
    if (c == '?') return TERNARIO_SINO;

    return CARACTER_RARO;
}
