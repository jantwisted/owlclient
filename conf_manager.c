/* 
   <OwlClient is a simple program which can send and receive messages from a server. This is specially designed to xml and json.>
   Copyright (C) <2013>  <Janith Perera>

   This file is part of OwlClient.

   OwlClient is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   OwlClient is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with OwlClient.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#define SIZE 1000
#define POS 11
#define MAX_FILE_SIZE 1000
char * get_prop(char *);
int get_count(char *, FILE*, int *);
char* trim_string(char*);
void read_file(FILE*,char**);
void conf_save(FILE*, char*, char*);
char* get_value(char* );
char* conf_read(FILE*, char *);

char* conf_read(FILE* file, char *param)
{
  char *buffer;
  buffer = (char*) malloc(SIZE);
  char *line = NULL;
  size_t len;
  size_t read;
  while((read=getline(&line, &len, file))!=-1)
    {
      if (strcmp(trim_string(get_prop(line)), param)==0)
	{
	  return line;
	}
    }
  return NULL;

}


void conf_save (FILE* pFile, char* value, char* prop)
{
  char * buff1=NULL;
  char * buff2=NULL;
  char  buff3[1000];
  int nline;
  buff1 = (char*) malloc(SIZE*sizeof(char));
  buff2 = (char*) malloc(SIZE*sizeof(char));
  read_file(pFile,&buff1);
  strcpy(buff3,prop);
  int loc = get_count(buff3,pFile,&nline);
  strncpy(buff2, &buff1[nline], strlen(buff1)-nline);
  fseek ( pFile , loc , SEEK_SET );
  fputs (" = ", pFile );
  fputs (value, pFile );
  fseek (pFile, 0, SEEK_CUR);
  fputs(buff2, pFile);
  free(buff1);
  free(buff2);
  fclose ( pFile );
}

char* get_prop(char* buff)
{
  char *buff2 = strdup(buff);
  char* prop = strtok(buff2, "=");
  return prop;
}

char* get_value(char* buff)
{
  char *buff2 = strdup(buff);
  char* prop = strtok(buff2, "=");
  char* value = strtok(NULL,"=");
  unsigned char value2[200];
  strncpy(value2, value, 200);
  return trim_string(value);
}


int get_count(char* buff, FILE* fp, int *line_size)
{
  char* str = trim_string(buff);
  char* line = NULL;
  size_t len;
  size_t read;
  int count=0;
  while((read=getline(&line, &len, fp))!=-1)
    {
      count += strlen(line);
      if (strcmp(trim_string(get_prop(line)), str)==0)
	{
	  *line_size = count;
	  count = count-strlen(line)+strlen(str);
	  break;
	}
    }
  return count;
}

char* trim_string(char* str)
{
  char* c = NULL;
  c = str;
  int i = 0;
  while(isspace(*c)){
    str++;
    c++;
  }
  if(*c==0)
    fputs(str,stdout);

  c = str+strlen(str)-1;
  while(c>str && isspace(*c))
    {
      i++;
      c--;
    }
  str[strlen(str)-i] = '\0';
  return str;
}

void read_file(FILE* fp, char** string)
{
  unsigned char *buffer = (char*)malloc(MAX_FILE_SIZE*sizeof(char));
  int n;
  if(fp){
    n = fread(buffer, MAX_FILE_SIZE, 1, fp);
  }else{
    fputs("Error reading file", stderr);
  }
  strcpy(*string,buffer); 
  rewind(fp);
  free(buffer);
}

