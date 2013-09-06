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
#include "cnfm.h"

#ifdef CONF_SYMBOL
# define SPACE " "
# define APPENDER SPACE CONF_SYMBOL SPACE
#else
#define APPENDER " = "
#define CONF_SYMBOL "="
#endif

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
  char * top_buffer=NULL;
  char * low_buffer=NULL;
  char  file_prop[SIZE];
  int nline;
  top_buffer = (char*) malloc(SIZE*sizeof(char));
  low_buffer = (char*) malloc(SIZE*sizeof(char));
  read_file(pFile,&top_buffer);
  strcpy(file_prop,prop);
  int loc = get_count(file_prop,pFile,&nline);
  strncpy(low_buffer, &top_buffer[nline], strlen(top_buffer)-nline);
  fseek ( pFile , loc , SEEK_SET );
  fputs (APPENDER, pFile );
  fputs (value, pFile );
  fseek (pFile, 0, SEEK_CUR);
  fputs(low_buffer, pFile);
  int nzero = nline - (loc+strlen(value)+3);
  for(;nzero>0;nzero--)
     fputs(" ",pFile);
  free(top_buffer);
  free(low_buffer);
  if (fclose(pFile) == EOF) {
    fputs("Error closing input file.",stderr);
  }
  fputs("saved successfully\n",stdout);
}

char* get_prop(char* buff)
{
  char *buff2 = strdup(buff);
  char* prop = strtok(buff2, CONF_SYMBOL);
  return prop;
}

char* get_value(char* buff)
{
  char *buff2 = strdup(buff);
   char* prop = strtok(buff2, CONF_SYMBOL);
  strtok(buff2, "=");
  char* value = strtok(NULL,CONF_SYMBOL);
  char value2[200];
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
  char *buffer = (char*)malloc(MAX_FILE_SIZE*sizeof(char));
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

