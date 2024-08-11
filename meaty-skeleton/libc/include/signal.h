#ifndef SIGNAL_H
#define SIGNAL_H
 
// Определения сигналов
#define SIGINT     2  // Interrupt from keyboard
#define SIGTERM    15 // Termination signal
#define SIGKILL    9  // Kill signal
 
// Структура для обработки сигнала
typedef void (*sighandler_t)(int);
 
// Объявление функции для установки обработчика сигнала
sighandler_t signal(int signum, sighandler_t handler);
 
// Вызов сигнала
void raise(int sig);
 
#endif // SIGNAL_H
