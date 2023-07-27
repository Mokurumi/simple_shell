#define MAIN_H

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;

char *_strpbrk(char *s, char *accept);
int _strlen(char *s);
char *_strtok(char *str, char *delim);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *_getenv(const char *name);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *str1, const char *str2, size_t n);
int _strcmpdir(const char *str1, const char *str2);
char *_strcpy(char *dest, char *src);

char *find_executable_path(char **path, char *command);
char *find_path(void);
char **tokenize(char *line);
void free_buf(char **buffer);
int handle_command(char **command, char *line);
void handle_signal(int m);

void _change_directory(char **tokenArray);
int execute_builtin(char **tokenArray);
int _setenv(char **tokenArray);
int _unsetenv(char **tokenArray);
int cd_builtin(char **command);

int _wait(void);
int _stat(int ac, char **av);
int _ppid(void);
int _pid(void);
int _fork(char *command, char **fullCommand);
int env_main(void);
int env_environ(int argc, char *argv[], char *env[]);

#endif
