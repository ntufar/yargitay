#include <syslog.h>
int refreshtime();
char *strip(char* str);
char *dress(char* str, int len);
int ntlog(int fac, char *msg);
int ntlog2(int fac, char *function, char *msg);
int ntchanges(char *fmt, ... );
int nthareket(char *fmt, ... );
int aux(char *message);
char *striso2dos(char *str);
char *quote(char *str);

#define LOG_CEZA	LOG_LOCAL0
#define LOG_HUKUK	LOG_LOCAL1
#define LOG_EMSAL	LOG_LOCAL2
#define LOG_SORGU	LOG_LOCAL3
