#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

//string prepare()

int main()
{
	ifstream file("lyrics.txt");
	if(!file.is_open())
	{
		cout << "oh shit\n";
		return -1;
	}
	for(int i = 0; i < 10; i++)
	{
		string s;
		file >> s;
		//cout << "old is " << s << " word" << endl;
		if(!isalpha(*(--s.end())))
			s.pop_back();
		if(isupper(*(s.begin()))) // possible to optimmize as *(s.begin())) ==> s[0]
			*(s.begin()) = tolower(s[0]);
		cout << "new is " << s << " word\n";
	}
  	return 0;
}