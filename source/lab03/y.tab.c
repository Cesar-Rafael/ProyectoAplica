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

#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>

// Prototipos de funcion
int yylex();
void yyerror(char *s);

// Se hizo la corrección de errores, ahora compila y corre
// Comando: yacc grupo5_ER.y && gcc y.tab.c -lm -lfl && ./a.out

char lexema[100];
FILE* arch;

#line 89 "y.tab.c"

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
    BUCLE_SALIDA = 260,
    CARACTER_RARO = 261,
    TIPO_CARACTER = 262,
    BUCLE_CONTINUACION = 263,
    TIPO_DOUBLE = 264,
    CONDICION_SINO = 265,
    FIN = 266,
    FALSO = 267,
    BUCLE_FOR = 268,
    FUNCION_INICIO = 269,
    CONDICION_INICIO = 270,
    ENTRADA = 271,
    TIPO_ENTERO = 272,
    OPERACION_MODULAR = 273,
    NEGACION_LOGICA = 274,
    O_LOGICO = 275,
    SALIDA = 276,
    FUNCION_RETORNO = 277,
    TIPO_CADENA = 278,
    VERDADERO = 279,
    VARIABLE = 280,
    BUCLE_WHILE = 281,
    OPERACION_SUMA = 282,
    OPERACION_RESTA = 283,
    OPERACION_MULTIPLICACION = 284,
    OPERACION_DIVISION = 285,
    OPERACION_POTENCIA = 286,
    DISYUNCION_BINARIA = 287,
    NEGACION_BINARIA = 288,
    CONJUNCION_BINARIA = 289,
    NEGACION_LOGICA_2 = 290,
    LEFT_SHIFT = 291,
    RIGHT_SHIFT = 292,
    DISYUNCION_EXCLUSIVA_BINARIA = 293,
    FIN_DE_INSTRUCCION = 294,
    SEPARACION_VARIABLES = 295,
    INICIO = 296,
    INICIO_FIN_CADENA = 297,
    INICIO_FIN_CARACTER = 298,
    PARENTESIS_IZQUIERDA = 299,
    PARENTESIS_DERECHA = 300,
    CORCHETE_IZQUIERDA = 301,
    CORCHETE_DERECHA = 302,
    MENOR_QUE = 303,
    MAYOR_QUE = 304,
    MENOR_O_IGUAL_QUE = 305,
    MAYOR_O_IGUAL_QUE = 306,
    COMENTARIO = 307,
    ASIGNACION = 308,
    ASIGNACION_PROFUNDA = 309,
    IGUALDAD = 310,
    DESIGUALDAD = 311,
    INCREMENTO_EN_UNIDAD = 312,
    DECREMENTO_EN_UNIDAD = 313,
    CONDICION_UNICA = 314,
    INCREMENTO_DIRECTO = 315,
    DECREMENTO_DIRECTO = 316,
    MULTIPLICACION_DIRECTA = 317,
    DIVISION_DIRECTA = 318,
    NUMERO_ENTERO = 319,
    NUMERO_REAL = 320,
    IDENTIFICADOR = 321,
    SALTO_LINEA = 322,
    TERNARIO_SI = 323,
    TERNARIO_SINO = 324
  };
#endif
/* Tokens.  */
#define Y_LOGICO 258
#define TIPO_BOOLEAN 259
#define BUCLE_SALIDA 260
#define CARACTER_RARO 261
#define TIPO_CARACTER 262
#define BUCLE_CONTINUACION 263
#define TIPO_DOUBLE 264
#define CONDICION_SINO 265
#define FIN 266
#define FALSO 267
#define BUCLE_FOR 268
#define FUNCION_INICIO 269
#define CONDICION_INICIO 270
#define ENTRADA 271
#define TIPO_ENTERO 272
#define OPERACION_MODULAR 273
#define NEGACION_LOGICA 274
#define O_LOGICO 275
#define SALIDA 276
#define FUNCION_RETORNO 277
#define TIPO_CADENA 278
#define VERDADERO 279
#define VARIABLE 280
#define BUCLE_WHILE 281
#define OPERACION_SUMA 282
#define OPERACION_RESTA 283
#define OPERACION_MULTIPLICACION 284
#define OPERACION_DIVISION 285
#define OPERACION_POTENCIA 286
#define DISYUNCION_BINARIA 287
#define NEGACION_BINARIA 288
#define CONJUNCION_BINARIA 289
#define NEGACION_LOGICA_2 290
#define LEFT_SHIFT 291
#define RIGHT_SHIFT 292
#define DISYUNCION_EXCLUSIVA_BINARIA 293
#define FIN_DE_INSTRUCCION 294
#define SEPARACION_VARIABLES 295
#define INICIO 296
#define INICIO_FIN_CADENA 297
#define INICIO_FIN_CARACTER 298
#define PARENTESIS_IZQUIERDA 299
#define PARENTESIS_DERECHA 300
#define CORCHETE_IZQUIERDA 301
#define CORCHETE_DERECHA 302
#define MENOR_QUE 303
#define MAYOR_QUE 304
#define MENOR_O_IGUAL_QUE 305
#define MAYOR_O_IGUAL_QUE 306
#define COMENTARIO 307
#define ASIGNACION 308
#define ASIGNACION_PROFUNDA 309
#define IGUALDAD 310
#define DESIGUALDAD 311
#define INCREMENTO_EN_UNIDAD 312
#define DECREMENTO_EN_UNIDAD 313
#define CONDICION_UNICA 314
#define INCREMENTO_DIRECTO 315
#define DECREMENTO_DIRECTO 316
#define MULTIPLICACION_DIRECTA 317
#define DIVISION_DIRECTA 318
#define NUMERO_ENTERO 319
#define NUMERO_REAL 320
#define IDENTIFICADOR 321
#define SALTO_LINEA 322
#define TERNARIO_SI 323
#define TERNARIO_SINO 324

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
#define YYFINAL  115
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   481

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  131
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  206

#define YYUNDEFTOK  2
#define YYMAXUTOK   324


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
      65,    66,    67,    68,    69
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   231,   231,   233,   234,   236,   237,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   319,   320,   322,   324,   326,   327,
     329,   330,   332,   333,   335,   337,   338,   340,   341,   342,
     343,   345,   346,   347,   348,   350,   352,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   373,   374,   376,   377,   378,
     379,   380
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "Y_LOGICO", "TIPO_BOOLEAN",
  "BUCLE_SALIDA", "CARACTER_RARO", "TIPO_CARACTER", "BUCLE_CONTINUACION",
  "TIPO_DOUBLE", "CONDICION_SINO", "FIN", "FALSO", "BUCLE_FOR",
  "FUNCION_INICIO", "CONDICION_INICIO", "ENTRADA", "TIPO_ENTERO",
  "OPERACION_MODULAR", "NEGACION_LOGICA", "O_LOGICO", "SALIDA",
  "FUNCION_RETORNO", "TIPO_CADENA", "VERDADERO", "VARIABLE", "BUCLE_WHILE",
  "OPERACION_SUMA", "OPERACION_RESTA", "OPERACION_MULTIPLICACION",
  "OPERACION_DIVISION", "OPERACION_POTENCIA", "DISYUNCION_BINARIA",
  "NEGACION_BINARIA", "CONJUNCION_BINARIA", "NEGACION_LOGICA_2",
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
  "TERNARIO_SINO", "$accept", "programa", "lista_sentencias",
  "lista_generica", "elemento_generico", "sentencia", "impresion",
  "lectura", "iteracion", "seleccion", "bloque", "declaracion",
  "asignacion", "operacion_unaria", "asignacion_operativa", "expresion",
  "sentencia_condicional", "comentario", "termino", "factor", "terminal", YY_NULLPTR
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
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324
};
# endif

#define YYPACT_NINF (-186)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     369,  -186,   -29,   -28,   -27,  -186,   -46,   -23,    87,   344,
     187,  -186,  -186,   -49,    22,   369,  -186,  -186,  -186,  -186,
    -186,  -186,  -186,  -186,  -186,    74,  -186,  -186,   394,  -186,
    -186,   344,   -42,   354,   -34,   344,   344,  -186,  -186,   105,
    -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,
    -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,
    -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,
    -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,
    -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,
    -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,
    -186,  -186,  -186,  -186,  -186,  -186,    26,  -186,   344,   -13,
      59,   344,   344,   344,   344,  -186,  -186,   344,   344,  -186,
     344,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,   112,    62,    65,
     118,  -186,   344,   120,   238,    55,  -186,  -186,   242,  -186,
    -186,   343,   388,   409,   411,   394,   394,    69,  -186,  -186,
    -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,
    -186,  -186,  -186,  -186,   309,    96,    97,   102,   413,   339,
    -186,   369,  -186,  -186,  -186,  -186,  -186,   344,   369,  -186,
    -186,  -186,  -186,  -186,  -186,   369,  -186,  -186,    81,   247,
     263,   103,  -186,   369,   293,  -186
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   131,     0,     0,     0,   130,     0,     0,     0,     0,
       0,   127,   128,   129,     0,     2,     4,    75,    77,    76,
      78,    73,    79,    80,    81,     0,    82,    83,   104,   116,
     125,     0,     0,     0,     0,     0,     0,   129,   117,     0,
       7,     8,     9,    72,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,     6,     0,     0,
       0,     0,     0,     0,     0,     1,     3,     0,     0,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   129,
       0,    92,     0,     0,     0,   126,   106,     5,     0,    95,
      96,     0,     0,     0,     0,   101,   102,     0,   124,   110,
     123,   107,   108,   109,   115,   113,   111,   112,   114,   120,
     119,   122,   121,   118,     0,     0,     0,     0,     0,     0,
     126,     0,    94,    97,    98,    99,   100,     0,     0,    91,
      88,    86,    84,    85,    93,     0,    87,   105,   103,     0,
       0,     0,    90,     0,     0,    89
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -186,  -186,  -185,  -186,    37,   -15,  -186,  -186,  -186,  -186,
     -25,  -186,  -186,  -186,  -186,    -8,  -186,  -186,  -111,    -6,
    -186
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    14,    15,   106,   107,    16,    17,    18,    19,    20,
     190,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
     116,    39,    38,   199,   108,   141,   155,   156,   109,   110,
     200,   111,   112,   113,   114,    31,    32,    33,   204,   142,
      34,    35,   115,   137,   138,   140,   149,   143,   144,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,   146,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   117,   118,   150,     1,
     148,   117,   118,   151,   152,   153,   154,   175,   117,   118,
     176,     5,   157,   119,   181,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,    36,   117,   118,   178,   191,   192,   120,   187,   117,
     118,   193,   120,   147,   203,   117,   118,   117,   118,   120,
     145,    11,    12,    37,   196,     0,     0,   174,     0,   189,
       0,     0,     0,   177,   189,   179,   197,     0,     0,     0,
       0,     0,     0,   120,     0,     0,     0,     0,     0,   198,
     120,     0,     0,     0,   116,   116,   120,     0,   120,   116,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,     0,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   201,   202,     1,
       0,     0,     2,     3,     0,   117,   118,     0,     4,   117,
     118,     5,     6,     7,   202,     1,     0,     0,     2,     3,
       8,   182,     0,   180,     4,     0,     0,     5,     6,     7,
       0,     9,     0,     0,     0,     0,     8,     0,     0,    10,
       0,     0,     0,     0,   205,     1,   120,     9,     2,     3,
     120,    11,    12,    13,     4,    10,     0,     5,     6,     7,
       0,     1,     0,     0,     2,     3,     8,    11,    12,    13,
       4,     0,     0,     5,     6,     7,     0,     9,     0,     0,
       0,     0,     8,     0,     0,    10,     0,     0,     0,     0,
     188,     1,     0,     9,     2,     3,     1,    11,    12,    13,
       4,    10,     0,     5,     6,     7,     1,     0,     5,     0,
     117,   118,     8,    11,    12,    13,     0,     8,     5,     0,
     195,     1,   183,     9,     2,     3,     0,     8,    36,     0,
       4,    10,     0,     5,     6,     7,     0,   121,    36,     0,
       0,     0,     8,    11,    12,    13,     0,     0,    11,    12,
      37,   120,   122,     9,   123,   117,   118,     0,    11,    12,
     139,    10,     0,   124,   125,   126,   127,   184,   128,     0,
     129,   130,   131,    11,    12,    13,   117,   118,   117,   118,
     117,   118,   132,   133,   134,   135,     0,   136,   185,     0,
     186,     0,   194,     0,     0,     0,   120,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   120,     0,   120,
       0,   120
};

static const yytype_int16 yycheck[] =
{
      15,     9,     8,   188,    53,    39,   117,   118,    57,    58,
     195,    60,    61,    62,    63,    44,    44,    44,   203,    53,
      66,    44,     0,    31,    66,    33,    39,    35,    36,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    27,    28,    39,    12,
     108,    27,    28,   111,   112,   113,   114,    45,    27,    28,
      45,    24,   120,    39,    59,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,    44,    27,    28,   142,    39,    39,    68,    69,    27,
      28,    39,    68,   106,    41,    27,    28,    27,    28,    68,
      45,    64,    65,    66,   179,    -1,    -1,    45,    -1,   174,
      -1,    -1,    -1,    45,   179,    45,   181,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,   187,
      68,    -1,    -1,    -1,   199,   200,    68,    -1,    68,   204,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    10,    11,    12,
      -1,    -1,    15,    16,    -1,    27,    28,    -1,    21,    27,
      28,    24,    25,    26,    11,    12,    -1,    -1,    15,    16,
      33,    39,    -1,    45,    21,    -1,    -1,    24,    25,    26,
      -1,    44,    -1,    -1,    -1,    -1,    33,    -1,    -1,    52,
      -1,    -1,    -1,    -1,    11,    12,    68,    44,    15,    16,
      68,    64,    65,    66,    21,    52,    -1,    24,    25,    26,
      -1,    12,    -1,    -1,    15,    16,    33,    64,    65,    66,
      21,    -1,    -1,    24,    25,    26,    -1,    44,    -1,    -1,
      -1,    -1,    33,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      41,    12,    -1,    44,    15,    16,    12,    64,    65,    66,
      21,    52,    -1,    24,    25,    26,    12,    -1,    24,    -1,
      27,    28,    33,    64,    65,    66,    -1,    33,    24,    -1,
      41,    12,    39,    44,    15,    16,    -1,    33,    44,    -1,
      21,    52,    -1,    24,    25,    26,    -1,     3,    44,    -1,
      -1,    -1,    33,    64,    65,    66,    -1,    -1,    64,    65,
      66,    68,    18,    44,    20,    27,    28,    -1,    64,    65,
      66,    52,    -1,    29,    30,    31,    32,    39,    34,    -1,
      36,    37,    38,    64,    65,    66,    27,    28,    27,    28,
      27,    28,    48,    49,    50,    51,    -1,    53,    39,    -1,
      39,    -1,    39,    -1,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    68,
      -1,    68
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    12,    15,    16,    21,    24,    25,    26,    33,    44,
      52,    64,    65,    66,    71,    72,    75,    76,    77,    78,
      79,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    44,    44,    44,    66,    44,    44,    66,    89,    85,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    73,    74,    53,    57,
      58,    60,    61,    62,    63,     0,    75,    27,    28,    39,
      68,     3,    18,    20,    29,    30,    31,    32,    34,    36,
      37,    38,    48,    49,    50,    51,    53,    85,    66,    66,
      85,    39,    53,    85,    85,    45,    52,    74,    85,    39,
      39,    85,    85,    85,    85,    88,    88,    85,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    45,    45,    45,    45,    85,    45,
      45,    59,    39,    39,    39,    39,    39,    69,    41,    75,
      80,    39,    39,    39,    39,    41,    80,    75,    85,    72,
      72,    10,    11,    41,    72,    11
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    70,    71,    72,    72,    73,    73,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    76,    76,    77,    78,    79,    79,
      80,    80,    81,    81,    82,    83,    83,    84,    84,    84,
      84,    85,    85,    85,    85,    86,    87,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    89,    89,    90,    90,    90,
      90,    90
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     5,     5,     5,     5,    10,
       3,     1,     3,     5,     4,     3,     3,     4,     4,     4,
       4,     3,     3,     5,     1,     5,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     2,     3,     3,
       3,     3,     3,     3,     3,     1,     3,     1,     1,     1,
       1,     1
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
  case 101:
#line 345 "base.y"
                                            { yyval = yyvsp[-2] + yyvsp[0]; }
#line 1667 "y.tab.c"
    break;

  case 102:
#line 346 "base.y"
                                             { yyval = yyvsp[-2] - yyvsp[0]; }
#line 1673 "y.tab.c"
    break;

  case 104:
#line 348 "base.y"
                   { yyval = yyvsp[0];}
#line 1679 "y.tab.c"
    break;

  case 107:
#line 354 "base.y"
                                                 { yyval = yyvsp[-2] * yyvsp[0]; }
#line 1685 "y.tab.c"
    break;

  case 109:
#line 356 "base.y"
                                           { yyval = pow(yyvsp[-2], yyvsp[0]); }
#line 1691 "y.tab.c"
    break;

  case 111:
#line 358 "base.y"
                                   { yyval = yyvsp[-2] << yyvsp[0]; }
#line 1697 "y.tab.c"
    break;

  case 112:
#line 359 "base.y"
                                    { yyval = yyvsp[-2] >> yyvsp[0]; }
#line 1703 "y.tab.c"
    break;

  case 113:
#line 360 "base.y"
                                           { yyval = yyvsp[-2] & yyvsp[0]; }
#line 1709 "y.tab.c"
    break;

  case 114:
#line 361 "base.y"
                                                     { yyval = yyvsp[-2] ^ yyvsp[0]; }
#line 1715 "y.tab.c"
    break;

  case 115:
#line 362 "base.y"
                                           { yyval = yyvsp[-2] | yyvsp[0]; }
#line 1721 "y.tab.c"
    break;

  case 116:
#line 363 "base.y"
                { yyval = yyvsp[0]; }
#line 1727 "y.tab.c"
    break;

  case 117:
#line 364 "base.y"
                                 { yyval = ~yyvsp[0]; }
#line 1733 "y.tab.c"
    break;

  case 118:
#line 365 "base.y"
                                   { yyvsp[-2] = yyvsp[0]; }
#line 1739 "y.tab.c"
    break;

  case 125:
#line 373 "base.y"
                 { yyval = yyvsp[0]; }
#line 1745 "y.tab.c"
    break;

  case 126:
#line 374 "base.y"
                                                          { yyval = yyvsp[-1]; }
#line 1751 "y.tab.c"
    break;


#line 1755 "y.tab.c"

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
#line 382 "base.y"


int main(void) {
    // arch = fopen("../../tests/lab03/asignacion.raa", "r");
    // arch = fopen("../../tests/lab03/bucle_while.raa", "r");
    arch = fopen("../../tests/lab03/comentarios.raa", "r");
    // arch = fopen("../../tests/lab03/entrada.raa", "r");
    // arch = fopen("../../tests/lab03/operaciones_aritmeticas.raa", "r");
    // arch = fopen("../../tests/lab03/operaciones_aritmeticas_no_triviales.raa", "r");
    // arch = fopen("../../tests/lab03/operaciones_binarias.raa", "r");
    // arch = fopen("../../tests/lab03/salida.raa", "r");
    // arch = fopen("../../tests/lab03/selectiva_if_else.raa", "r");
    // arch = fopen("../../tests/lab03/operaciones_unarias.raa", "r");
    // arch = fopen("../../tests/lab03/asignacion_operativa.raa", "r");
    // arch = fopen("../../tests/lab03/operadores_condicionales.raa", "r");
    // arch = fopen("../../tests/lab03/operaciones_booleanas.raa", "r");
    // arch = fopen("../../tests/lab03/sentencia_condicional.raa", "r");
    // arch = fopen("../../tests/lab03/operacion_ternaria.raa", "r");

    if (arch == NULL) {
    	printf("ERROR: No se ha abierto el archivo test01.raa correctamente.\n");
        exit(1);
    }
    if (!yyparse()) {
        printf("Es buen programa\n");
    } else {
        printf("Es mal programa\n");
    }
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
            if (strcmp(lexema, "break") == 0) return BUCLE_SALIDA;
            if (strcmp(lexema, "char") == 0) return TIPO_CARACTER;
            if (strcmp(lexema, "continue") == 0) return BUCLE_CONTINUACION;
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
        return '!';
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
