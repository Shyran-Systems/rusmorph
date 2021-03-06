# if !defined( _mlma1049_h_ )
# define _mlma1049_h_

# if defined( WIN32 )
#   include <pshpack1.h>
# endif

# include <limits.h>
# include <stdint.h>
# include <stddef.h>

# if !defined( __widechar_defined__ )
# define  __widechar_defined__
#   if defined(WCHAR_MAX) && (WCHAR_MAX >> 16) == 0
    typedef wchar_t         widechar;
#   else
    typedef unsigned short  widechar;
#   endif  // size
# endif  // __widechar_defined__

# if !defined( __lexeme_t_defined__ )
#   define  __lexeme_t_defined__
#   if    UINT_MAX  == 0xffffffff       // check if 32-bit platform
      typedef unsigned int  lexeme_t;
#   elif  ULONG_MAX == 0xffffffffUL
      typedef unsigned long lexeme_t;
#   else
#     error Cannot resolve the 32-bit unsigned int type!
#   endif
# endif

# if !defined( __formid_t_defined__ )
#   define  __formid_t_defined__
    typedef unsigned char   formid_t;
# endif // __formid_t_defined__

# if !defined( lemmatize_errors_defined )
#   define lemmatize_errors_defined
#   define LEMMBUFF_FAILED -1
#   define LIDSBUFF_FAILED -2
#   define GRAMBUFF_FAILED -3
#   define WORDBUFF_FAILED -4
# endif

# if !defined( mlma_search_flags_defined )
#   define mlma_search_flags_defined
#   define sfStopAfterFirst  0x0001    // ���������� ������ ��������������
#   define sfIgnoreCapitals  0x0002    // ������� �� ����� �������������
# endif

# if !defined( mlmaru_search_flags_defined )
#   define mlmaru_search_flags_defined
#   define sfHardForms       0x0004    // ������������ ����������
#   define sfDefisWordTails  0x0008    // ������������ ����. �������
#   define nfAdjVerbs        0x0100    // ������������ �� ���������
# endif

# if !defined( mlma_grammarecord_defined )
#   define mlma_grammarecord_defined

  typedef struct
  {
    uint16_t  wdInfo;
    formid_t  idForm;
    uint16_t  grInfo;
    uint8_t   bFlags;
  } SGramInfo;

# endif  /* mlma_grammarecord_defined */

# if !defined( mlma_lexemerecord_defined )
# define  mlma_lexemerecord_defined

  typedef struct
  {
    lexeme_t        nlexid;
    const char*     plemma;
    SGramInfo*      pgrams;
    unsigned        ngrams;
  } SLemmInfoA;

  typedef struct
  {
    lexeme_t        nlexid;
    const widechar* plemma;
    SGramInfo*      pgrams;
    unsigned        ngrams;
  } SLemmInfoW;

# endif  // ! mlma_lexemerecord_defined

/**************************************************************************/
/*            �������������� ���������� �� ������ ���������               */
/*                                                                        */
/*                                *******                                 */
/*                                                                        */
/* ������������ �����, ������� 2 �����. �������������� ����������.        */
/*                                                                        */
/* @+++++++ ++++++++ - ���������� ����� (������� � ��������������)        */
/* +@@@++++ ++++++++ - �����                                              */
/* ++++@+++ ++++++++ - �����                                              */
/* +++++@@+ ++++++++ - ���                                                */
/* +++++++@ ++++++++ - ������� ����� (��� ����. � ����.)                  */
/* ++++++++ @+++++++ - ������������� �������                              */
/* ++++++++ +@@+++++ - ���������, ������������, ������������� ���������   */
/* ++++++++ +++@@+++ - ���� (��� �������� � �� ����)                      */
/* ++++++++ +++++@@@ - �������'�� �������������� ���������� �����         */
/*                                                                        */
/* ���� �������������� �������������� "��������������" ����, ���������-   */
/* ���� ������� �������� ������ ���������:                                */
/*                                                                        */
/*          +++++++@ - ��������� ��� ������������� �����                  */
/*          ++++++@+ - ��������� ��� ��������������� �����                */
/**************************************************************************/

# if !defined( russian_gram_info_defined )
#   define russian_gram_info_defined

#   define wfMultiple     0x40          /* ������������� �����   */

#   define afAnimated     0x01          /*                       */
#   define afNotAlive     0x02          /*                       */
#   define afHardForm     0x04          /* ������������ �����    */
#   define afJoiningC     0x08          /* ����. �������         */

#   define gfRetForms     0x8000        /* ���������� �����      */
#   define gfFormMask     0x7000        /* ����� ��� �������     */
#   define gfMultiple     0x0800        /* ������������� �����   */
#   define gfGendMask     0x0600        /* ���                   */
#   define gfShortOne     0x0100        /* ������� �����         */
#   define gfCompared     0x0080        /* ������������� ������� */
#   define gfVerbForm     0x0060        /* ���������� ���������� */
#   define gfAdverb       0x0040        /* ������� �� ����.      */
#   define gfVerbFace     0x0018        /* ����                  */
#   define gfVerbTime     0x0007        /* �����                 */

#   define vtInfinitiv    0x0001        /* ���������             */
#   define vtImperativ    0x0002        /* �������. ����������   */
#   define vtFuture       0x0003        /* ������� �����         */
#   define vtPresent      0x0004        /* ��������� �����       */
#   define vtPast         0x0005        /* ��������� �����       */

#   define vbFirstFace    0x0008        /* ������ ����           */
#   define vbSecondFace   0x0010        /* ������ ����           */
#   define vbThirdFace    0x0018        /* ������ ����           */

#   define vfVerb         0x0000        /* ���������� �����      */
#   define vfVerbActive   0x0020        /* ��������. ���������   */
#   define vfVerbPassiv   0x0040        /* �����. ���������      */
#   define vfVerbDoing    0x0060        /* ������������          */

# endif  /* russian_gram_info_defined */

# if !defined( EXPORT )
#   if defined( WIN16 )
#     define EXPORT __export
#   else
#     define EXPORT
#   endif /* WIN16 */
# endif /* EXPORT */

# if !defined( MLMA_API )
#   if defined( WIN16 )
#     define MLMA_API __far __pascal
#   elif defined( _WIN32 )
#     define MLMA_API __stdcall
#   else
#     define MLMA_API
#   endif
# endif /* MLMA_API definition */

# if !defined( MLMAPROC )
#   if defined( WIN16 )
#     define MLMAPROC __far __pascal __export
#   elif defined( _WIN32 )
#     define MLMAPROC __stdcall
#   else
#     if defined( __GNUC__ ) && !defined( __LP64__ )
#       define MLMAPROC __attribute__((stdcall))
#     else
#       define MLMAPROC
#     endif
#   endif
# endif /* MLMA_API definition */

/*================ The new API for the morphological analyser ================*/
/* uses common a-la-COM API which would look in the same way on both C && C++ */
/* compilers.                                                                 */
/*============================================================================*/

# if !defined( MLMA_INTERFACE )

#   if defined( __cplusplus )

#     define  MLMA_INTERFACE( iface ) \
      struct  iface {

#     define  MLMA_METHOD( method )   \
      virtual int MLMAPROC  method

#     define  MLMA_THIS
#     define  MLMA_VOID
#     define  MLMA_PURE = 0

#     define  MLMA_END  }

#   else

#     define  MLMA_INTERFACE( iface )     \
      struct  iface##_vtbl;               \
                                          \
      typedef struct iface                \
      {                                   \
        const struct iface##_vtbl* vtbl;  \
      } iface;                            \
                                          \
      struct  iface##_vtbl                \
      {

#     define  MLMA_METHOD( method )   \
      int (MLMAPROC *method)

#     define  MLMA_THIS   void*,
#     define  MLMA_VOID   void*
#     define  MLMA_PURE

#     define  MLMA_END  }

#   endif  // __cplusplus

# endif  // MLMA_INTERFACE

# if !defined( mlma_interface_defined )
# define  mlma_interface_defined

  MLMA_INTERFACE( IMlmaEnum )
    MLMA_METHOD( Attach )( MLMA_VOID ) MLMA_PURE;
    MLMA_METHOD( Detach )( MLMA_VOID ) MLMA_PURE;

    MLMA_METHOD( RegisterLexeme )( MLMA_THIS
                                   lexeme_t     nlexid,
                                   int          nforms, const formid_t* pforms ) MLMA_PURE;
  MLMA_END;

  MLMA_INTERFACE( IMlmaMb )
    MLMA_METHOD( Attach )( MLMA_VOID ) MLMA_PURE;
    MLMA_METHOD( Detach )( MLMA_VOID ) MLMA_PURE;

    MLMA_METHOD( CheckWord )( MLMA_THIS
                              const char*     pszstr, size_t  cchstr,
                              unsigned        dwsets ) MLMA_PURE;
    MLMA_METHOD( Lemmatize )( MLMA_THIS
                              const char*     pszstr, size_t  cchstr,
                              SLemmInfoA*     plexid, size_t  clexid,
                              char*           plemma, size_t  clemma,
                              SGramInfo*      pgrams, size_t  ngrams,
                              unsigned        dwsets                 ) MLMA_PURE;
    MLMA_METHOD( BuildForm )( MLMA_THIS
                              char*           output, size_t    cchout,
                              lexeme_t        nlexid, formid_t  idform ) MLMA_PURE;
    MLMA_METHOD( FindForms )( MLMA_THIS
                              char*           output, size_t    cchout,
                              const char*     pszstr, size_t    cchstr,
                                                      formid_t  idform ) MLMA_PURE;
    MLMA_METHOD( CheckHelp )( MLMA_THIS
                              char*           output, size_t    cchout,
                              const char*     pszstr, size_t    cchstr ) MLMA_PURE;
    MLMA_METHOD( GetWdInfo )( MLMA_THIS
                              unsigned char*  pwinfo, lexeme_t  nlexid ) MLMA_PURE;
  MLMA_END;

  MLMA_INTERFACE( IMlmaWc )
    MLMA_METHOD( Attach )( MLMA_VOID ) MLMA_PURE;
    MLMA_METHOD( Detach )( MLMA_VOID ) MLMA_PURE;

    MLMA_METHOD( SetLoCase )( MLMA_THIS
                              widechar*       pszstr, size_t    cchstr )  MLMA_PURE;
    MLMA_METHOD( SetUpCase )( MLMA_THIS
                              widechar*       pwsstr, size_t    cchstr )  MLMA_PURE;
    MLMA_METHOD( CheckWord )( MLMA_THIS
                              const widechar* pszstr, size_t    cchstr,
                              unsigned        dwsets ) MLMA_PURE;
    MLMA_METHOD( Lemmatize )( MLMA_THIS
                              const widechar* pszstr, size_t    cchstr,
                              SLemmInfoW*     plexid, size_t    clexid,
                              widechar*       plemma, size_t    clemma,
                              SGramInfo*      pgrams, size_t    ngrams,
                              unsigned        dwsets ) MLMA_PURE;
    MLMA_METHOD( BuildForm )( MLMA_THIS
                              widechar*       output, size_t    cchout,
                              lexeme_t        nlexid, formid_t  idform ) MLMA_PURE;
    MLMA_METHOD( FindForms )( MLMA_THIS
                              widechar*       output, size_t    cchout,
                              const widechar* pszstr, size_t    cchstr,
                                                      formid_t  idform ) MLMA_PURE;
    MLMA_METHOD( CheckHelp )( MLMA_THIS
                              widechar*       output, size_t    cchout,
                              const widechar* pwsstr, size_t    cchstr ) MLMA_PURE;
    MLMA_METHOD( GetWdInfo )( MLMA_THIS
                              unsigned char*  pwinfo, lexeme_t  nlexid ) MLMA_PURE;
    MLMA_METHOD( EnumWords )( MLMA_THIS
                              IMlmaEnum*      pienum,
                              const widechar* pszstr, size_t    cchstr ) MLMA_PURE;
  MLMA_END;

# if !defined( __cplusplus )

#   define  mlma_CheckWord( module, pszstr, cchstr, dwsets )    \
      module->vtbl->CheckWord( (module), (pszstr), (cchstr), (dwsets) )

#   define  mlma_Lemmatize( module, pszstr, cchstr, plexid,     \
            clexid, plemma, clemma, pgrams, ngrams, dwsets )    \
      module->vtbl->Lemmatize( (module), (pszstr), (cchstr),    \
                                         (plexid), (clexid),    \
                                         (plemma), (clemma),    \
                                         (pgrams), (ngrams), (dwsets) )

#   define  mlma_BuildForm( module, output, cchout, nlexid, idform )  \
      module->vtbl->BuildForm( (module), (output), (cchout),          \
                                         (nlexid), (idform) )

#   define  mlma_FindForms( module, output, cchout, pszstr, cchstr, idform )  \
      module->vtbl->FindForms( (module), (output), (cchout),                  \
                                         (pszstr), (cchstr), (idform) )

#   define  mlma_CheckHelp( module, output, cchout, pszstr, cchstr )  \
      module->vtbl->CheckHelp( (module), (output), (cchout),          \
                                         (pszstr), (cchstr) )

# endif  // !__cplusplus

# endif  /* !mlma_interface_defined */

# if defined( __cplusplus )
extern "C" {
# endif /* __cplusplus */

# if !defined( __TEnumWords_prototype_defined__ )
#   define  __TEnumWords_prototype_defined__
      typedef short (MLMA_API* TEnumWords)( lexeme_t lid, void* lpv );
# endif

  int   MLMAPROC        mlmaruLoadMbAPI( IMlmaMb** );
  int   MLMAPROC        mlmaruLoadCpAPI( IMlmaMb**, const char* codepage );
  int   MLMAPROC        mlmaruLoadWcAPI( IMlmaWc** );

size_t client2win(char* dst, size_t dst_size, char const* src, size_t src_size);
size_t win2client(char* dst, size_t dst_size, char const* src, size_t src_size);

# if defined( __cplusplus )
}
# endif /* __cplusplus */

# if defined( WIN32 )
#   include <poppack.h>
# endif

# endif /* _mlma1049_h_ */
