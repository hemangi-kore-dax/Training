#include<iostream>
#include<fstream>
#include<vector>
#include<String>
#include<sstream>
#include<iomanip>

using namespace std;

string removeSpaces(string &str){
	// n is length of the original string
	int n = str.length();

	// i points to next position to be filled in
	// output string/ j points to next character
	// in the original string
	int i = 0, j = -1;

	// flag that sets to true is space is found
	bool spaceFound = false;

	// Handles leading spaces
	while (++j < n && str[j] == ' ');

	// read all characters of original string
	while (j < n)
	{
		// if current characters is non-space
		if (str[j] != ' ')
		{
			// remove preceding spaces before dot,
			// comma & question mark
			if ((str[j] == '.' || str[j] == ',' ||
				str[j] == '?') && i - 1 >= 0 &&
				str[i - 1] == ' ')
				str[i - 1] = str[j++];

			else
				// copy current character at index i
				// and increment both i and j
				str[i++] = str[j++];

			// set space flag to false when any
			// non-space character is found
			spaceFound = false;
		}
		// if current character is a space
		else if (str[j++] == ' ')
		{
			// If space is encountered for the first
			// time after a word, put one space in the
			// output and set space flag to true
			if (!spaceFound)
			{
				str[i++] = ' ';
				spaceFound = true;
			}
		}
	}

	// Remove trailing spaces
	if (i <= 1)
		str.erase(str.begin() + i, str.end());
	else
		str.erase(str.begin() + i - 1, str.end());

	return str;
}

vector<string> printWords(string str)
{
    // word variable to store word
    string word;
	vector<string> res;
 
    // making a string stream
    stringstream iss(str);
 
    // Read and print each word.
    while (iss >> word)
        res.push_back(word);

	return res; 
		
}
string format_name(string ip1, string ip2)
{
	int fix=30;
	string final_name;
	string concat_name=ip1+" "+ip2;
	int len=concat_name.length();
	int pad_len=fix-len;
	// cout<<concat_name<<setw(pad_len);
	string sp=" ";
	final_name=concat_name;
	for(int i=0;i<pad_len;i++)
	{
		final_name=final_name+sp ;
	}
	return final_name;
}

string format_address1(string ip1, string ip2)
{
	int fix=25;
	string concat_addr=ip1+" "+ip2;
	int len=concat_addr.length();
	int pad_len=fix-len;
	string final_add1=concat_addr;
	for(int i=0;i<pad_len;i++)
	{
		final_add1=final_add1+" " ;
	}
	return final_add1;
	
}



int main(int argc, char *argv[])
{
	ifstream my_file;
	vector<string> g1;
	vector<string> newvect;
	vector<vector<string>> wordvect;
	my_file.open(argv[1]);
	if (my_file.is_open())
	{	
		string ch;
		while (getline(my_file, ch)) 
		{
			g1.push_back(ch);
			// for (string i : g1)
			// {
			// 	cout << i <<endl;
			// }

		}
		my_file.close();
	}
	
	else {
		cout << "No such file";
	}

	for(int i=0; i<g1.size(); i++)
		{
			string tmp=removeSpaces(g1[i]);
			newvect.push_back(tmp);
		}
		// cout<<endl;
		// for (string i : newvect) 
		// {
		// 	cout << i <<endl;
		// }
		for(int i=0; i<newvect.size(); i++)
		{
			vector<string> temp = printWords(newvect[i]);
			wordvect.push_back(temp);
		}
        // for(int i=0; i<wordvect.size(); i++)
        // {
        //     for(int j=0;j<wordvect[i].size();j++)
        //     {
        //         cout<<wordvect[i][j]<<endl;
        //     }
        // }
		
		cout<<"Envelope:"<<endl;
        for(int i=0; i<wordvect.size(); i++)
        {
            cout<<wordvect[i][1]<<" "<<wordvect[i][0]<<","<<endl;
            cout<<wordvect[i][4]<<" "<<wordvect[i][5]<<","<<endl;
            cout<<wordvect[i][6]<<" "<<wordvect[i][7]<<wordvect[i][8]<<endl;
            cout<<endl;
        }	
		cout<<"Fixed format:"<<endl;
		
        for(int i=0; i<wordvect.size(); i++)
        {	
			cout<<format_name(string(wordvect[i][1]), string(wordvect[i][0]));
			cout<<format_address1(string(wordvect[i][4]),string(wordvect[i][5]));
			// cout<<wordvect[i][1]<<" "<<wordvect[i][0]<<" ";
            // cout<<wordvect[i][4]<<" "<<wordvect[i][5]<<" ";
            cout<<wordvect[i][6]<<" "<<wordvect[i][7]<<" "<<wordvect[i][8]<<endl;
            cout<<endl;
        }
       cout<<"Fixed format with CSV:"<<endl;
	   
        for(int i=0; i<wordvect.size();i++)
        {
            cout<<'"'<<wordvect[i][1]<<" "<<wordvect[i][0]<<'"'<<",";
            cout<<'"'<<wordvect[i][4]<<" "<<wordvect[i][5]<<'"'<<",";
            cout<<'"'<<wordvect[i][6]<<", "<<wordvect[i][7]<<" "<<wordvect[i][8]<<'"'<<endl;
            cout<<endl;
        }
        

	return 0;
}