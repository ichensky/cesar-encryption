# Copyright (c) 2016-.. #John
#
# Author: #John <pocolab.com@gmail.com>
# URL: http://www.pocolab.com
# Version: 1.0.0

# Commentary:

# Decode any cesar cipher 

# License:

# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 3
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with GNU Emacs; see the file COPYING.  If not, write to the
# Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
# Boston, MA 02110-1301, USA.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CHUNK 2048

void print_str(char *str, size_t len,size_t i);
void print_char(int c, int i);
int main(){
	char *buf=malloc(CHUNK*sizeof(char));
	
	char *command="cat x.txt | xxd -r -p";
	FILE *fp;

	fp = popen(command, "r");
	if (!fp) {
		fprintf(stderr,"Failed to run command\n");
		exit(EXIT_FAILURE);
	}

	fgets(buf, CHUNK, fp);
	pclose(fp);

	size_t len=strlen(buf);
	char *str=malloc((len+1)*sizeof(char));
	memcpy(str,buf,(len+1));

	size_t i;
	for (i = 0; i < 255; i++) {
		print_str(str,len,i);
		fprintf(stdout,"\n");
	}

	return(0);
}

void print_str(char *str, size_t len, size_t i){
	size_t j;
	for (j = 0; j < len; j++) {
		print_char(str[j],i);	
	}
	
}
void print_char(int c, int i){
	fprintf(stdout,"%c",c+i);
}
