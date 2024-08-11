#ifndef UNISTD_H
#define UNISTD_H
 
// Определение стандартных размеров
#define _POSIX_VERSION 200809L
 
// Типы для использования в системных вызовах
typedef unsigned long size_t;
 
// Объявления стандартных функций
int access(const char *pathname, int mode);
unsigned int alarm(unsigned int seconds);
int close(int fd);
char *ctermid(char *s);
int fork(void);
long fpathconf(int fd, int name);
//pid_t getpid(void);
//pid_t getppid(void);
int isatty(int fd);
int link(const char *oldpath, const char *newpath);
//off_t lseek(int fd, off_t offset, int whence);
int read(int fd, void *buf, size_t count);
int write(int fd, const void *buf, size_t count);
 
#endif // UNISTD_H
