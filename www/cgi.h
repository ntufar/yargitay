/*34567890123456789012345678901234567890123456789012345678901234567890123456789
**
** File      cgi.h
**
** Desc      A CGI library for C programmers. Automatically handles GET, POST
**           and ISINDEX requests, with lots of useful routines to simplify
**           CGI development. Applications can even be debugged from the
**           commandline!
**
** Limits    Cannot yet handle form file uploads.
**
** Copyright 1996 JemTek Pty Ltd, Jerome Munchenberg
**           http://www.jemtek.com.au/jemtek
**           jerome@jemtek.com.au
**
** History   Ver  Date     Author Modification
**           1.0  06-03-96 JEM    First Draft
**                29-07-96 JEM    Fixed error messages in main
**	          31-08-96 JEM    Swapped LFs for NLs
**
******************************************************************************/

/* Library structures
******************************************************************************/

struct {
  char *authType;
  int   contentLength;
  char *contentType;
  char *gatewayInterface;
  char *httpAccept;
  char *httpHost;
  char *httpReferer;
  char *httpUserAgent;
  char *pathInfo;
  char *pathTranslated;
  char *queryString;
  char *remoteAddr;
  char *remoteHost;
  char *remoteIdent;
  char *remoteUser;
  char *requestMethod;
  char *scriptName;
  char *serverName;
  char *serverPort;
  char *serverProtocol;
  char *serverSoftware;
} cgiEnv;

/* Library functions
******************************************************************************/

/* --- debug functions --- */

void  cgiDisplayEnv();
void  cgiDisplayPairs();

/* --- data encode/decode functions --- */

char *cgiEncodeSys(char *data);
char *cgiEncodeUrl(char *data);

/* --- form query functions --- */

int   cgiFormCmpVal(char *var, char *val);
int   cgiFormCmpValMulti(char *var, char len, char **vals);

int   cgiFormCntVar(char *var);

char *cgiFormGetVal(char *var);
int   cgiFormGetValMulti(char *var, char ***vals);

/* --- html header functions --- */

int   cgiHeaderContent(char *mimeType);
int   cgiHeaderLocation(char *redirectUrl);
int   cgiHeaderStatus(int statusCode, char *statusReason, char *statusMesg);
int   cgiHeaderNonParse(int statusCode, char *statusMesg, char *mimeType);

/* --- html body functions --- */

int   cgiHtmlHead(char *title);
int   cgiHtmlTail();

/* --- misc utility functions --- */

int   cgiImageOk();

int   cgiLoad(char *file);

int   cgiPrintf(char *fmt, ...);

/* Externally defined variables
******************************************************************************/

extern char *cgiDebug;

/* Externally defined functions
******************************************************************************/

extern int cgiMain();

/* The End
******************************************************************************/
