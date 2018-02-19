/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/16 17:19:15 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 17:30:12 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAXFILENAMELEN 100

Prototype for function
void is_symlink(const char *filename);

int main()
{
int len;
char filename[MAXFILENAMELEN];

printf("Enter a file name: ");
fgets(filename, MAXFILENAMELEN, stdin);

Remove the newline from the end if it' there
len = strlen(filename);
if (filename[len-1] == '\n') {
filename[len-1] = '\0';
}

Call function to test if it is a symlink
is_symlink(filename);

return 0;
}

void is_symlink(const char *filename)
{
struct stat p_statbuf;

if (lstat(filename, &p_statbuf) < 0) {   if error occured */
//perror("calling stat()");
//exit(1);  /* end progam here
/*

   if (S_ISLNK(p_statbuf.st_mode) == 1) {
   printf("%s is a symbolic link\n", filename);
   } else {
   printf("%s is NOT a symbolic link\n", filename);
   }*/


#include <stdio.h>
#include "libft/libft.h"
void red () {
	printf("\033[1;31m");
}

void yellow() {
	printf("\033[1;33m");
}

void reset () {
	printf("\033[0m");
}

int main () {
	red();
	ft_putstr("Hello ");
	yellow();
	printf("world\n");
	reset();
	return 0;
}
