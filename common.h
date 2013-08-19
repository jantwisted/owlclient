#include <stdio.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/uio.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <pthread.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

#ifdef	HAVE_PTHREAD_H
#include	<pthread.h>
#endif

#define SERV_PORT 9000

#define	MAXLINE	4096
#define	LISTENQ	2
#define	SERV_TCP_PORT	52001
#define	OK	52001
#define	SA	struct sockaddr


#ifndef		__unp_pthread_h
#define		__unp_pthread_h


void	Pthread_create(pthread_t *, const pthread_attr_t *, void * (*)(void *), void *);
void	Pthread_join(pthread_t, void **);
void	Pthread_detach(pthread_t);
void	Pthread_kill(pthread_t, int);

void	Pthread_mutexattr_init(pthread_mutexattr_t *);
void	Pthread_mutexattr_setpshared(pthread_mutexattr_t *, int);
void	Pthread_mutex_init(pthread_mutex_t *, pthread_mutexattr_t *);
void	Pthread_mutex_lock(pthread_mutex_t *);
void	Pthread_mutex_unlock(pthread_mutex_t *);

void	Pthread_cond_broadcast(pthread_cond_t *);
void	Pthread_cond_signal(pthread_cond_t *);
void	Pthread_cond_wait(pthread_cond_t *, pthread_mutex_t *);
void	Pthread_cond_timedwait(pthread_cond_t *, pthread_mutex_t *,
							   const struct timespec *);

void	Pthread_key_create(pthread_key_t *, void (*)(void *));
void	Pthread_setspecific(pthread_key_t, const void *);
void	Pthread_once(pthread_once_t *, void (*)(void));

#endif	

char* conf_read(FILE*, char *);
void xcommand(char*, int *);
void xread(int);
void Connect(int, const struct sockaddr *, socklen_t);
int Socket(int, int, int);
void Inet_pton(int, const char *, void *);
void xhelp();
void xterm(int *);
const char* xfile_read();
int xconnect(char*, char*);
void conf_save (FILE* , char* , char* );
char* get_prop(char*);
char* get_value(char*);
int get_count(char* , FILE* , int *);
char* trim_string(char*);
void read_file(FILE*, char** );
