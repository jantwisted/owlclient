/* 
   <Conf Manager is a library to read/write configuration files.>
   Copyright (C) <2013>  <Janith Perera>

   This file is part of Conf Manager.

   Conf Manager is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Conf Manager is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Conf Manager.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#define SIZE 1000
/* define the separator symbol as a string */
#define CONF_SYMBOL "="

#define MAX_FILE_SIZE 1000

#ifndef __ATTR_P__
# define __ATTR_P__ __attribute__((__pure__))
# define __ATTR_N__ __attribute__((noreturn))

#endif
 
extern char * get_prop(char *) __ATTR_P__;
extern int get_count(char *, FILE*, int *) __ATTR_P__;
extern char* trim_string(char*) __ATTR_P__;
extern void read_file(FILE*,char**);
extern void conf_save(FILE*, char*, char*);
extern char* get_value(char* ) __ATTR_P__;
extern char* conf_read(FILE*, char *) __ATTR_P__;
