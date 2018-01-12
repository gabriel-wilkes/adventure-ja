#include <stdio.h>
#include <string.h>
#include <stdarg.h>

struct Jdic {
	const char *jp;
	int i;
};
struct Edic {
	const char *en;
	int i;
	const char *wh;
};
#include "trans.h"

#if defined(_WIN32)

void err(int eval, const char *fmt, ...)
{
	va_list v;
	char buf[80];

	if(fmt == NULL)
		perror(NULL);
	else {
		va_start(v, fmt);
		vsprintf(buf, fmt, v);
		va_end(v);
		perror(buf);
	}

	exit(eval);
}

void errx(int eval, const char *fmt, ...)
{
	va_list v;
	char buf[80];

	if(fmt == NULL)
		perror(NULL);
	else {
		va_start(v, fmt);
		vsprintf(buf, fmt, v);
		va_end(v);
		perror(buf);
	}

	exit(eval);
}

void warn(const char *fmt, ...)
{
	va_list v;
	char buf[80];

	if(fmt == NULL)
		perror(NULL);
	else {
		va_start(v, fmt);
		vsprintf(buf, fmt, v);
		va_end(v);
		perror(buf);
	}
}

#endif

static int is_jp(void)
{
	char c = getchar();

	ungetc(c, stdin);
	return c & 0x80;
}

static int getl(char *buf)
{
	char *p = buf;

	while(p < buf + MAXSTR && (*p = getchar()) != '\n')
		p++;
	if(p == buf + MAXSTR) {
		FLUSHLINE;
		return 0;
	}
	*p = 0;

	return (int )(p - buf);
}

static const struct Jdic *findjp(const char *jp)
{
	const struct Jdic *d;
	int len, n;

	if((len = strlen(jp)) == 0)
		return NULL;

	for(d = j_dic; d->jp != NULL ; d++) {
		n = strlen(d->jp);
		if(n <= len && strncmp(jp, d->jp, n) == 0)
			return d;
	}
	return NULL;
}

int jtoe(char *wrd1, char *wrd2)
{
	const struct Jdic *j1, *j2 = NULL;
	char buf[MAXSTR], *p;

	if(!is_jp())
		return 0;
	getl(buf);

	strcpy(wrd1, "");
	strcpy(wrd2, "");

	p = buf;
	while((j1 = findjp(p)) != NULL && j1->i < 0)
		p += strlen(j1->jp);
	if(j1 == NULL)
		return 1;

	p += strlen(j1->jp);
	while((j2 = findjp(p)) != NULL && j2->i < 0)
		p += strlen(j2->jp);
	if(j2 == NULL) {
		strcpy(wrd1, e_dic[j1->i].en);
		return 1;
	}

	strcpy(wrd1, e_dic[j2->i].en);
	strcpy(wrd2, e_dic[j1->i].en);
	return 1;
}

int jtoe_yn(void)
{
	int i, len;
	char buf[MAXSTR];
	const char *y[] = { "はい", "ハイ", "ｙｅｓ", "ＹＥＳ" };
	const char *n[] = { "いいえ", "イイエ", "ｎｏ", "ＮＯ" };

	if(!is_jp())
		return 0;
	getl(buf);

	ungetc('\n', stdin);
	for(i = 0; i < (int )(sizeof(y) / sizeof(y[0])); i++) {
		len = strlen(buf);
		if(strncmp(buf, y[i], len) == 0) {
			ungetc('y', stdin);
			return 1;
		} else if(strncmp(buf, n[i], len) == 0) {
			ungetc('n', stdin);
			return 1;
		}
	}

	ungetc(' ', stdin);
	return 1;
}

const static struct Edic *finden(const char *en)
{
	size_t len;
	const struct Edic *d;

	len = strlen(en); len = (len < 5 ? len: 5);

	for(d = e_dic; d->en != NULL; d++) {
		if(len != strlen(d->en))
			continue;
		if(d->i >= 0 && strncmp(en, d->en, len) == 0)
			return d;
	}
	return NULL;
}

const char *etoj(const char *en)
{
	const struct Edic *e;

	if((e = finden(en)) == NULL)
		return " what";
	else
		return j_dic[e->i].jp;
}

const char *etoj_wh(const char *en)
{
	const struct Edic *e;

	if((e = finden(en)) == NULL)
		return en;
	else if(e->wh == NULL)
		return "何を";
	else
		return e->wh;
}
