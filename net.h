/* net.h -- 
 * Created: Sat Feb 22 00:39:54 1997 by faith@cs.unc.edu
 * Revised: Wed Apr 16 09:35:43 1997 by faith@cs.unc.edu
 * Copyright 1997 Rickard E. Faith (faith@cs.unc.edu)
 * 
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 1, or (at your option) any
 * later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 675 Mass Ave, Cambridge, MA 02139, USA.
 * 
 * $Id: net.h,v 1.5 1997/04/30 12:03:53 faith Exp $
 * 
 */


extern const char *net_hostname( void );
extern int        net_connect_tcp( const char *host, const char *service );
extern int        net_open_tcp( const char *service, int queueLength );
extern void       net_detach( void );
extern int        net_read( int s, char *buf, int maxlen );
extern int        net_write( int s, const char *buf, int len );