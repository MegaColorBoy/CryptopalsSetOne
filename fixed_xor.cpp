//Matasano Crypto Challenges: Set 1
//Problem 2:  Fixed XOR
#include <iostream>
#include <string.h>
#include <map>
#include <sstream>
#include <math.h>
#include <vector>
using namespace std;

//Print the hashmap
void print_map(map<char,string> m)
{
	cout << "{";
	for(auto p: m)
	{
		cout << p.first << ":" << p.second << " ";
	}
	cout << "}" << endl;
}

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

void mainFunction(string str1, string str2)
{
	//step 1. convert hex to binary
	str1 = add_spaces(con_hex_2_bin(str1));
	str2 = add_spaces(con_hex_2_bin(str2));

	//step 2. convert binary to decimal
	vector<int> v1 = con_bin_2_dec(str1);
	vector<int> v2 = con_bin_2_dec(str2);

	string newStr = "";
	
	//step 3. XOR str1 decimals with str2 decimals
	for(int i=0; i<v1.size(); i++)
	{
		unsigned char a = v1[i];
		unsigned char b = v2[i];
		unsigned char c = a ^ b;
		newStr += c;
	}

	stringstream ss;
	for(int i=0; i<newStr.size();i++)
	{
		ss << std::hex << (int)newStr[i];
	}
	cout << "RESULT: " << ss.str() << endl;
}

int main()
{
	string str1 = "1c0111001f010100061a024b53535009181c";
	string str2 = "686974207468652062756c6c277320657965";

	mainFunction(str1, str2);
	return 0;
}