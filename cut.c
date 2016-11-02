/*****************************************************************************
 * Copyright (C) Shubham A. Devkate     shubham.devkate1998@gmail.com
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main(int argc, char *argv[])
{
	int c, sflag = 0, flag = 0, fflag = 0, cflag = 0, dflag = 0, bflag = 0, mflag = 0, i, j;
	int val, val1, val2, val3, val4;
	char *d;
	if(argc == 2){
		if(strcmp(argv[1], "--help") == 0){
			help();
		}
	}
	// ./a.out -b 4
	// ./a.out -c 7
	else if(argc == 3){
		stdinput(atoi(argv[2]));
	}
	// ./a.out -b 3 --complement file
	// ./a.out -c 3 --complement file
	else if(argc == 5){
		flag = 1;
		if(strcmp(argv[3], "--complement") == 0)
			complement(atoi(argv[2]), argv[4]);
	}
	if(flag != 1){
		while((c = getopt(argc, argv, "sfcdb")) != -1) {
			switch(c){
				case 's':
					sflag = 1;
					break;
				case 'f': 
					fflag = 1;
					break;
				case 'c':
					cflag = 1;
					d = argv[2];
					if(argc == 4){
						if(strcmp(argv[1], "-c") == 0){
							if(d[1] == ',' || d[3] == ','){
								if(d[1] == ',' && d[3] == '\0'){	// ./a.out -c 2,5 file
									store(1);
									cut_char(atoi(d + 0), argv[3]);		
									store(2);
									cut_char(atoi(d + 2), argv[3]);
								}

							}
							else if(d[0] == '-'){
								val = atoi(argv[2]);
								if(val < 0){
									val = val * -1;
									cut_to(val, argv[3]);           // ./a.out -c -8 file
								}
							}
							else if(d[1] == '-' || d[2] == '-' || d[3] == '-'){
								val = atoi(argv[2]);
								if(val > 0 && (d[1] == '-' && d[2] == '\0') || (d[2] == '-' && d[3] == '\0')) {
									cut_from(val, argv[3]);         // ./a.out -c 3- file
								}

							}
							if(d[1] == '-' || d[2] == '-'){
								if(d[1] == '-'){
									val1 = atoi(d + 0);
									val2 = atoi(d + 2);
									cut_btw(val1, val2, argv[3]);   // ./a.out -c 3-7 file
								}
								else if(d[2] == '-'){
									val1 = atoi(d + 0);
									val2 = atoi(d + 3);
									cut_btw(val1, val2, argv[3]);   // ./a.out -c 10-21 file
								}

							}
							else
								cutchar(atoi(argv[2]), argv[3]);        // ./a.out -c 3 file    
						}      

					}
					break;
				case 'd':
					dflag = 1;
					break;
				case 'b':
					bflag = 1;
					if(argc == 4){
						if(strcmp(argv[1], "-b") == 0){
							d = argv[2];
							if(d[1] == ',' && d[3] == '\0'){		// ./a.out -b 1,3 file
								store(1);
								cut_char(atoi(d + 0), argv[3]);
								store(2);
								cut_char(atoi(d + 2), argv[3]);
							}
							else if(d[0] == '-'){				
								val = atoi(argv[2]);
								if(val < 0){
									val = val * -1;
									cut_to(val, argv[3]);		// ./a.out -b -4 file
								}
							}
							else if(d[1] == '-' || d[2] == '-' || d[3] == '-'){			
								val = atoi(argv[2]);			
								if(val > 0 && (d[1] == '-' && d[2] == '\0') || (d[2] == '-' && d[3] == '\0')) {
									cut_from(val, argv[3]);		// ./a.out -b 7- file
								}

							}
							if(d[1] == '-' || d[2] == '-'){
								if(d[1] == '-'){
									val1 = atoi(d + 0);
									val2 = atoi(d + 2);
									cut_btw(val1, val2, argv[3]);	// ./a.out -b 3-9 file
								}
								else if(d[2] == '-'){
									val1 = atoi(d + 0);
									val2 = atoi(d + 3);
									cut_btw(val1, val2, argv[3]);	// ./a.out -b 12-22 file
								}

							}
							else
								cutchar(atoi(argv[2]), argv[3]);	// ./a.out -b 5 file	
						}			
					}
					break;
				default :
					fprintf(stderr, "getopt");
			}
		}
	} 


	//	printf("sflag = %d, fflag = %d, cflag = %d, dflag = %d, bflag = %d", sflag, fflag, cflag, dflag, bflag);

	return 0;
} 
