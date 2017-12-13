//Detect Single Byte XOR
//Answer: Now that the party is jumping
#include <iostream>
#include <string.h>
#include <map>
#include <sstream>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

//Hashmap contains hex key and binary values
map<char, string> gen_table()
{
	map<char, string> map;

	map['0'] = "0000";
	map['1'] = "0001";
	map['2'] = "0010";
	map['3'] = "0011";
	map['4'] = "0100";
	map['5'] = "0101";
	map['6'] = "0110";
	map['7'] = "0111";
	map['8'] = "1000";
	map['9'] = "1001";
	map['a'] = "1010";
	map['b'] = "1011";
	map['c'] = "1100";
	map['d'] = "1101";
	map['e'] = "1110";
	map['f'] = "1111";

	return map;
}

string con_hex_2_bin(string hexStr)
{
	map<char,string> m = gen_table();

	string newStr = "";
	for(int i=0; i<hexStr.size(); i++)
	{
		if(isdigit(hexStr[i]))
		{
			newStr += m.find(hexStr[i])->second;
		}
		else
		{
			newStr += m.find(hexStr[i])->second;
		}
		// newStr += m.find(hexStr[i])->second;
	}
	return newStr;
}

vector<int> con_bin_2_dec(string str)
{
	vector<int> v;
	string newStr = "";

	istringstream iss(str);
	string x;

	while(iss >> x)
	{
		double power = 7.0;
		double decimal = 0.0;
		for(int i=0; i<x.size(); i++)
		{
			if(x[i] == '1')
			{
				decimal += pow(2.0,power);
			}
			power--;
		}
		v.push_back((int)decimal);
	}
	return v;
}

string add_spaces(string str)
{
	string newStr = "";
	for(int i=0; i<str.size(); i+=8)
	{
		newStr += str[i];
		newStr += str[i+1];
		newStr += str[i+2];
		newStr += str[i+3];
		newStr += str[i+4];
		newStr += str[i+5];
		newStr += str[i+6];
		newStr += str[i+7];
		newStr += " ";
	}
	return newStr;
}

//Return the char frequency of the string
map<char, int> frequencyTable(string str)
{
	map<char, int> m;
	map<char, int>::iterator it;

	for(int i=0; i<str.size(); i++)
	{
		char ch = str[i];
		it = m.find(ch);

		if(it == m.end())
		{
			m.insert(make_pair(ch, 1));
		}
		else
		{
			it->second++;
		}
	}

	return m;
}

//dec to ascii
string con_dec_2_ascii(vector<int> v)
{
	string newStr = "";
	for(int i=0; i<v.size(); i++)
	{
		newStr += (char) v[i];
	}
	return newStr;
}

//Map Frequency
map<char, int> getFrequency(string str)
{
	map<char, int> m;
	map<char, int>::iterator it;

	for(int i=0; i<str.size(); i++)
	{
		char ch = str[i];
		it = m.find(ch);

		if(it == m.end())
		{
			m.insert(make_pair(ch,1));
		}
		else
		{
			it->second++;
		}
	}

	return m;
}

//Print the hashmap
void print_map(map<char,int> m)
{
	// int count = 0;
	cout << "{";
	for(auto p: m)
	{
		if(isalpha(p.first))
		{
			cout << p.first << ":" << p.second << " ";
			// count += p.second;
		}
	}
	cout << "}" << endl;
}

//High frequency for strings with more alphabets
int high_frequency(map<char,int> m)
{
	int count = 0;
	for(auto p: m)
	{
		if(isalpha(p.first))
		{
			// cout << p.first << ":" << p.second << " ";
			count += p.second;
		}
	}
	return count;
}
void mainFunction(string str)
{
	str = add_spaces(con_hex_2_bin(str));
	vector<int> v1 = con_bin_2_dec(str);

	//cout << con_bin_2_dec(v1) << endl;



	// unsigned char a = 88; //because 'X' has the largest score
	// for(int j=0; j<v1.size(); j++)
	// {
	// 	unsigned char b = v1[j];
	// 	unsigned char c = b ^ a;
	// 	cout << c << ""; 
	// }
	// cout << endl;
	// std::copy(v1.begin(), v1.end(), std::ostream_iterator<int>(std::cout, " "));
}

int main()
{
	ifstream infile;
	string str;
	int maxCount = 0;
	string maxString = "";
	vector<int> maxV;

	infile.open("enctext.txt");

	if(!infile)
	{
		cout << "Unable to open file" << endl;
		exit(1);
	}

	while(infile >> str)
	{
		if(str.size() == 60)
		{
			str = add_spaces(con_hex_2_bin(str));
			vector<int> v1 = con_bin_2_dec(str);
			string newStr = con_dec_2_ascii(v1);
			int count = high_frequency(getFrequency(newStr));
			if(count > maxCount)
			{
				maxCount = count;
				maxString = newStr;
				maxV = v1;
			}
		}
	}
	cout << maxString << " " << maxCount << endl;

	for(int i=0; i<256; i++)
	{
		unsigned char a = i;
		cout << "CHAR " << a <<" : ";
		for(int j=0; j<maxV.size(); j++)
		{
			unsigned char b = maxV[j];
			unsigned char c = b ^ a;
			cout << c << ""; 
		}
		cout<<endl;	
	}
	
	cout << endl;


	return 0;
}