/*
Contains a function to return the current system date and time (in a particular format as required by the RPi Package of Project 5G/LTE).
Writted by Arunangshu Pal.
Tested OK. Wednesday 05 November 2025 05:07:57 PM 
*/

#include <cstdlib>
#include <fstream>
#include <cstring>
#define MAX 100

using namespace std;

char *getDate(char *, int);

char *getDate(char *datestring, int datestrlen)
{
    char *tempfile = new char[MAX];
	char *datestr = new char[MAX];
	char *cmd = new char[MAX];

	strcpy(tempfile, "date.temp");

	ofstream opf;
	opf.open(tempfile, ios::out);
	opf.close();

	strcpy(cmd, "date '+%Y-%m-%d %H:%M:%S' >");
	strcat(cmd, tempfile);
	system(cmd);

	ifstream ipf;
	ipf.open(tempfile, ios::in);
	ipf.read(datestr, MAX);
	ipf.close();

	*cmd = '\0';
	strcpy(cmd, "rm -f ");
	strcat(cmd, tempfile);
	system(cmd);

    char *i; int j;
    for(i = datestr, j = 0; j < MAX-1 && *i != '\n' && *i != '\0'; i++, j++);
    if(*i != '\0')
        *i = '\0';
    strcpy(datestring, datestr);

    delete[] tempfile;
    delete[] datestr;
    delete[] cmd;

    return datestring;
}