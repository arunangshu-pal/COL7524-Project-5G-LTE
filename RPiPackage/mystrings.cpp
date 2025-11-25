/*
Collection of functions for operations on strings, required to read json files of Project 5G/LTE.
Writted by Arunangshu Pal.
All functions tested, and working correctly.
Wednesday 15 October 2025 11:17:01 PM IST
*/

char *cleanNewline(char *);				// Tested OK. Working correctly. Wednesday 15 October 2025 01:29:50 PM IST
char *cleanWhites(char *);				// Tested OK. Working correctly. Wednesday 15 October 2025 01:29:50 PM IST
char *strAppendCh(char *, char, int);	// Tested OK. Working correctly. Wednesday 15 October 2025 01:29:50 PM IST
bool findSubstr(char *, char *);		// Tested OK. Working correctly. Wednesday 15 October 2025 01:29:50 PM IST
char *extractCSV(char *, char *, int);	// Tested OK. Working correctly. Wednesday 15 October 2025 11:14:22 PM IST

char *cleanNewline(char *s)
{
	char *i;
	for(i = s; *i != '\n' && *i != '\0'; i++);
	*i = '\0';
	return s;
}

char *cleanWhites(char *s)
{
	char *ii, *jj;
	for(ii = s; *ii != '\0';)
	{
		if(*ii == ' ' || *ii == '\n')
		{
			for(jj = ii; *jj != '\0'; jj++)
				*jj = *(jj+1);
		}
		else
			ii++;
	}
	return s;
}

char *strAppendCh(char *s, char c, int max)
{
	char *ii;
	int i;
	for(ii = s, i = 0; *ii != '\0' && i < max-1; ii++, i++);
	if(i < max-1)
	{
		*ii = c;
		*(ii+1) = '\0';
	}
	return s;
}

bool findSubstr(char *sen, char *word)
{
	char *ii, *j, *k;
	bool found = false;
	for(ii = sen; *ii != '\0'; ii++)
	{
		if(*ii == *word)
		{
			found = true;
			for(j = ii, k = word;;j++, k++)
			{
				if(*k == '\0')
					break;
				else if(*j != *k)
				{
					found = false;
					break;
				}
			}
		}
		if(found == true)
			break;
	}
	return found;
}

char *extractCSV(char *jsonLine, char *csvLine, int max)
{
	int i;
	for(i = 0; jsonLine[i] != 0; i++)
	{
		if(jsonLine[i] == ' ' || jsonLine[i] == '\n')
		{
			jsonLine = cleanWhites(jsonLine);
			break;
		}
	}
	csvLine[0] = '\0';

	int modeVarVal = 0, extractMode = 0;
	for(i = 0; jsonLine[i] != '\0'; i++)
	{
		if(modeVarVal == 2)
		{
			if(extractMode == 0)
			{
				if(jsonLine[i] == '{')
					modeVarVal = 1;
				else
				{
					extractMode = 1;
					if(jsonLine[i] == ',')
					{
						strAppendCh(csvLine, ',', max);
						extractMode = 0;
						modeVarVal = 1;
					}
					else if(jsonLine[i] == '}')
						extractMode = 0;
					else
						strAppendCh(csvLine, jsonLine[i], max);
				}
			}
			else
			{
				if(jsonLine[i] == ',')
				{
					strAppendCh(csvLine, ',', max);
					extractMode = 0;
					modeVarVal = 1;
				}
				else if(jsonLine[i] == '}')
					extractMode = 0;
				else
					strAppendCh(csvLine, jsonLine[i], max);
			}
		}
		else
		{
			if(jsonLine[i] == '{')
				modeVarVal = 1;
			else if(jsonLine[i] == ':')
				modeVarVal = 2;
		}
	}
	strAppendCh(csvLine, '\0', max);
	return csvLine;
}