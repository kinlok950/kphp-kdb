/*
    This file is part of VK/KittenPHP-DB-Engine Library.

    VK/KittenPHP-DB-Engine Library is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    VK/KittenPHP-DB-Engine Library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with VK/KittenPHP-DB-Engine Library.  If not, see <http://www.gnu.org/licenses/>.

    Copyright 2009-2010 Vkontakte Ltd
              2009-2010 Nikolai Durov
              2009-2010 Andrei Lopatin
*/

#include <string.h>
#include <assert.h>
#include "translit.h"

static inline char *trans_letter (char *str, int *len) {
  *len = 1;
   
  switch (*str) {
  case 0:  *len = 0;  return 0;
  case '�': return "A";
  case '�': return "B"; 
  case '�': return "V"; 
  case '�': return "G"; 
  case (char) 0xa5: return "G"; 
  case '�': return "D"; 
  case '�': return "Ye"; 
  case '�': return "Ye"; 
  case '�': return "Yo"; 
  case '�': return "Zh"; 
  case '�': return "Z"; 
  case '�': return "I"; 
  case '�': return "Yi"; 
  case (char) 0xb2: return "I"; 
  case '�': return "J"; 
  case '�': if (str[1] == '�') { *len = 2;  return "X"; }
            else { return "K"; } 
  case '�': return "L"; 
  case '�': return "M"; 
  case '�': return "N"; 
  case '�': return "O"; 
  case '�': return "P"; 
  case '�': return "R"; 
  case '�': return "S"; 
  case '�': return "T"; 
  case '�': return "U"; 
  case '�': return "F"; 
  case '�': return "H"; 
  case '�': return "Ts"; 
  case '�': return "Ch"; 
  case '�': return "Sh"; 
  case '�': return "Sh"; 
  case '�': return "E"; 
  case '�': return "Yu"; 
  case '�': return "Ya"; 
  case '�': return "a"; 
  case '�': return "b"; 
  case '�': return "v"; 
  case '�': return "g"; 
  case (char) 0xb4: return "g"; 
  case '�': return "d"; 
  case '�': return "e"; 
  case '�': return "ye"; 
  case '�': return "yo"; 
  case '�': return "zh"; 
  case '�': return "z"; 
  case '�': if (str[1] == '�') { 
	      *len = 2;  
	      return "ia"; 
	    } else if (str[1] == '�') {
	      *len = 2;
	      return "y"; 
	    } else { 
	      return "i"; 
	    } 
  case '�': return "y"; 
  case '�': return "yi"; 
  case (char) 0xb3: return "i"; 
  case '�': if (str[1] == '�') { *len = 2;  return "x"; }
            else { return "k"; } 
  case '�': return "l"; 
  case '�': return "m"; 
  case '�': return "n"; 
  case '�': return "o"; 
  case '�': return "p"; 
  case '�': return "r"; 
  case '�': return "s"; 
  case '�': return "t"; 
  case '�': return "u"; 
  case '�': return "f"; 
  case '�': return "h"; 
  case '�': return "ts"; 
  case '�': return "ch"; 
  case '�': return "sh"; 
  case '�': return "sh"; 
  case '�': return ""; 
  case '�': return "y"; 
  case '�': if (str[1] == '�') { *len = 2;  return "ye"; }
            else { return ""; } 
  case '�': return "e"; 
  case '�': return "yu"; 
  case '�': return "ya"; 
  default: return 0;
  }
}

char *translit_str (char *buffer, int buff_size, char *str, int len) {
  char *ptr = str, *out = buffer, *str_e = str + len, *out_e = buffer + buff_size;
  while (ptr < str_e && *ptr) {
    int a = 0, b;
    char *tr = trans_letter (ptr, &a);
    if (tr) {
      b = strlen (tr);
    } else {
      b = 1;
      tr = ptr;
    }
    assert (a > 0 && b >= 0);
    if (out + b > out_e) {
      *out = 0;
      return buffer;
    }
    memcpy (out, tr, b);
    out += b;
    ptr += a;
  }
  *out = 0;
  return buffer;    
}

