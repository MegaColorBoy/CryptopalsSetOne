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

string add_spaces(string str, int spaces)
{
	string newStr = "";
	for(int i=0; i<str.size(); i+=spaces)
	{
		newStr += str[i];
		newStr += str[i+1];
		newStr += str[i+2];
		newStr += str[i+3];
		newStr += str[i+4];
		newStr += str[i+5];
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
		double power = 5.0;
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

void mainFunction(string str)
{
	string b64 = "";

	//step 1. convert hex to binary
	string binary = con_hex_2_bin(str);
	// cout << binary << endl;

	//Step 2. add spaces for every 6 bits
	binary = add_spaces(binary, 6);

	//Step 3. convert the binary to decimals
	vector<int> v = con_bin_2_dec(binary);

	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));

	//Step 4. convert the decimals to b64 using the reference string
	string ref = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	for(int i=0; i<v.size(); i++)
	{
		b64 += ref[v[i]];
	}
	cout << b64 << endl;
}

int main()
{
	// string str = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
	string str = "1c0111001f010100061a024b53535009181c";
	mainFunction(str);
	// print_map(gen_table());
	return 0;
}