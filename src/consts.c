/* consts.c - Common config constants & handling
   Copyright (C) 2000, 2001 Thomas Moestl

This file is part of the pdnsd package.

pdnsd is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

pdnsd is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with pdsnd; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

/* $Id: consts.c,v 1.1 2001/04/03 19:10:30 tmm Exp $ */

#include "../config.h"
#include <stdlib.h>
#include "consts.h"
#include "rr_types.h"

typedef struct {
	int      c;
	char     *name;
} const_t;

/* Order alphabetically!! */
static const_t consts[]={
	{C_AUTH,    "auth"},
	{C_DEV,     "dev"},
	{C_DIALD,   "diald"},
	{C_EXCLUDED,"excluded"},
	{C_EXEC,    "exec"},
	{C_IF,      "if"},
	{C_INCLUDED,"included"},
	{C_NONE,    "none"},
	{C_OFF,     "off"},
	{C_ON,      "on"},
	{C_ONQUERY, "onquery"},
	{C_PING,    "ping"},
	{TCP_ONLY,  "tcp_only"},
	{TCP_UDP,   "tcp_udp"},
	{UDP_ONLY,  "udp_only"}};
	 
static int cmp_const(const void *key, const void *el)
{
	return strcmp((char *)key, ((const_t *)el)->name);
}

int lookup_const(char *name)
{
	const_t *c=(const_t *)bsearch(name, consts, sizeof(consts)/sizeof(const_t), sizeof(const_t),cmp_const);
	if (c)
		return c->c;
	return C_ERR;
}
