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
#include "common.h"

void xhelp()
{
  Fputs("\nAvailable Commands\n\n",stdout);
  Fputs("CONNECT <ip> <port> : connect to a server\n",stdout);
  Fputs("CONNECTR <ip> <port>: connect & read server\n",stdout);
  Fputs("WRITE: write a default message\n",stdout);
  Fputs("HELP : more information\n",stdout);
  Fputs("QUIT : exit from OwlClient\n",stdout);
  
}
