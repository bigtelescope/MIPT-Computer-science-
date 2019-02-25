#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

//	Struct includind word and amount of such
//	words in a text
typedef struct statistics
{
	int amount;
	string word;
}Statistics;

//	Changes letters to lowercase and
//	deletes punctuation marks
string prepare(const string & s)
{
	string result;

	transform(s.begin(), s.end(), back_inserter(result), ::tolower);

	if(!isalpha(*(--result.end())))
		result.pop_back();
	if(!isalpha(*(result.begin())))
		result = result.erase(0, 1);

	return result;
}

// For std::sort() function
static bool CompareV(Statistics & s1, Statistics & s2)
{
	return (s1.amount < s2.amount);
}

int main()
{
	ifstream file("lyrics.txt");
	
	if(file.is_open())
	{
		if(file.peek() == EOF)
		{
			cout << "File is empty" << endl;
			return 0;
		}

		int counter = 0;
		string word;
		vector<Statistics> V;
		map< string, int > mymap;

		while(file >> word)
		{
			word = prepare(word);
			mymap[word]++;
		}
/*
		Why does it led to segmentation fault?

		for(auto item = mymap.begin(); item != mymap.end(); ++item)
			V[0].word = item->first;
*/
		for(auto item = mymap.begin(); item != mymap.end(); ++item)
		{
			Statistics temp = {item->second, item->first};
			V.push_back(temp);
		}

		sort(V.begin(), V.end(), CompareV);

		for(auto temp : V)
			cout << temp.word << "  :  " << temp.amount << endl;
	}
	else
		cout << "File hasn't opened:(" << endl;

	file.close();
	
  	return 0;
}
