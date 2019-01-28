/* 
 * (c) Schlothauer & Wauer
 * Bearbeiter : Bernd Barthel
 * $Id: omtcBas.h 10851 2010-07-20 14:15:40Z bernd $ 
 */

#ifndef OMTCBAS_INCLUDED
#define OMTCBAS_INCLUDED


#ifndef NULL
#  if defined(__cplusplus) || defined(_Windows)
#    define NULL 0
#  else
#    define NULL ((void *)0)
#  endif
#endif

/* Konstanten */

/* Zyklusdauer 1 Sekunde */
#define zyklDauer 1
/* maximale Anzahl der Durchlaeufe der Hauptlogik */
#define maxLogikLoops  10


#define PACKED

#define false 0
#define true 1

#define boolean lsa_bool


/* Einfache Datentypen */
typedef char lsa_char;
typedef char* lsa_string;
typedef unsigned char lsa_bool;
typedef char lsa_byte;
#define LISA_BYTE_MIN -128
#define LISA_BYTE_MAX 127
typedef unsigned char lsa_ubyte;
#define LISA_UBYTE_MIN 0
#define LISA_UBYTE_MAX 255
typedef short lsa_short;
#define LISA_SHORT_MIN -32768
#define LISA_SHORT_MAX 32767
typedef unsigned short lsa_ushort;
#define LISA_USHORT_MIN 0
#define LISA_USHORT_MAX 65535
typedef int lsa_int;
#define LISA_INT_MIN -32768
#define LISA_INT_MAX 32767
typedef unsigned int lsa_uint;
#define LISA_UINT_MIN 0
#define LISA_UINT_MAX 65535
typedef float lsa_float;
#define LISA_FLOAT_MIN -1E37
#define LISA_FLOAT_MAX 1E37

/* Werte fuer state der Variablen */
/* Persistent */
#define VARPERSISTENT 0x01
/* aenderbar */
#define VARWRITE 0x02
/* Nicht aenderbar, auch nicht von der Logik */
#define VARCONST 0x08
/* Public, von auszen sichtbar */
#define VARPUBLIC 0x04
/* wird von Log-System erfasst */
#define VARLOG 0x10

/* UUID ("Universally Unique IDentifiers" definiert von der Open Software Foundation) */
/* dient zur eindeutigen Kennzeichnung der Parameterstructur */
typedef PACKED struct
{
  unsigned long  D1;
  unsigned short D2;
  unsigned short D3;
  unsigned char  D4[8];
} TUUID;

/* Parameter-Header */
typedef PACKED struct
{
  char Bearbeiter[20];
  unsigned long Datum;
  TUUID UUID;
  unsigned long  Laenge;
  unsigned short SatzNr;
  unsigned long  Check;
} ParaKennung;

#endif
