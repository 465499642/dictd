/* dict.h -- Header file for dict program
 * Created: Fri Dec  2 20:01:18 1994 by faith@cs.unc.edu
 * Revised: Thu Aug 24 03:23:49 1995 by r.faith@ieee.org
 * Copyright 1994 Rickard E. Faith (faith@cs.unc.edu)
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
 * NOTE: This program is not distributed with any data.  This program
 * operates on many different data types.  You are responsible for
 * obtaining any data upon which this program operates.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#ifdef __linux__
#include <getopt.h>
#else
extern int  optind;
extern char *optarg;
#endif

#define DEFAULT_NAME "jargon"
#define DEFAULT_PATH "/usr/dict/jarg310.txt"
#define DEFAULT_DESC "The Jargon File"

#define DEFAULT_USER ".dictrc"
#define DEFAULT_SYST "/etc/dictrc"

#define BUFFER_SIZE    10240

#define MAXWORDS 144210		/* Do _not_ change this. */

#define ACTION_FIRST       0
#define ACTION_NAMED       1
#define ACTION_ALL         2
#define ACTION_EXHAUST     3

#define MATCH_NONE         0
#define MATCH_EXACT        1
#define MATCH_SUBSTRING    2

#define SEARCH_SUBSTRINGS  1
#define SEARCH_LEVENSHTEIN 2
#define SEARCH_SOUNDEX     4

#define STYLE_NORMAL       1
#define STYLE_SERVER       2
#define STYLE_QUIET        4

typedef struct {
   char          *name;		/* database name                     */
   char          *filename;	/* path to database                  */
   char          *index;	/* path to database index            */
   char          *indexalt;	/* alternate path to database index  */
   char          *listname;	/* path to compression dictionary    */
   char          *description;	/* database description              */
   char          **wordlist;	/* compression dictionary            */
   char          *ascii[128];	/* compression dictionary            */
   char          space;		/* special space char for compresion */
   int           fd;		/* index file descriptor             */
   unsigned long size;		/* index size                        */
   char          *front;	/* mmap'd front of index             */
   char          *back;		/* mmap'd end of index               */
   FILE          *str;		/* database file pointer             */
   unsigned long used;		/* lru timestamp for fd cache        */
} Entry;

extern int  Debug;
extern char buffer[BUFFER_SIZE];

#ifdef __ultrix__
extern char *strdup( char *src );
#endif

extern char *look( char *string, char *front, char *back );
extern int  compare( char *s1, char *s2, char *back );

extern void list_entries( FILE *str );
extern void add_entry( char *name, char *file, char *index, char *description);
extern void find( char *word, int action, int match, int search, int style,
		  char *name, FILE* str );

extern void print_entry( char *pos, Entry *entry, int style, FILE *str );
extern void print_possibilities( char *target, char *folded, Entry *entry,
				 int search, int style, FILE *str );
extern int  exact( char *target, char *pos, char *back );
extern int  read_list( int fd,
		       char ***wordlist, char *ascii[128], char *space );
extern char *decode_line( const char *line, char **wordlist,
			  char *ascii[128], char space );
