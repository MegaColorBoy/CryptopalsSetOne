//CryptoPals Crypto Library
//Abstract Class for the CryptoPals library
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <fstream>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

class CryptoLib
{
	public:
		//Constructor
		CryptoLib();

		//Hashmap that contains hex key and binary values
		map<char, string> gen_hex_table();

		//Convert hex to string
		string con_hex_2_bin(string hexStr);

		//Add spaces between strings
		string add_spaces(string str, int spaces);

		//Reverse string
		string reverse_string(string str);

		//Convert binary to decimal
		vector<int> con_bin_2_dec(string str, double power);

		//Convert decimal to binary
		string con_dec_2_bin(int decimal);

		//Convert decimal to ASCII
		string con_dec_2_ascii(vector<int> v);

		//Convert ASCII to HEX
		string con_ascii_2_hex(string str);

		//Convert HEX to ASCII
		string con_hex_2_ascii(string str);

		//Convert Hex to Base64
		string con_hex_2_b64(string str);

		//Convert Base64 to Hex
		string con_b64_2_hex(string str);

		//Base64 Encoder - Version 2
		string b64_encode(string str);

		//Base64 Decoder - Version 2
		string b64_decode(string str);

		//Single Byte XOR
		string singleByteXOR(string str);

		//Detect Single Byte XOR
		string detectSingleByteXOR(vector<int> maxV);

		//Fixed XOR
		string fixedXOR(string str1, string str2);

		//Repeating Key XOR
		string repeatingKeyXOR(string str, string key);

		//Return Character frequency of a string
		map<char, int> frequency_table(string str);

		//Return character with the highest frequency
		char ret_high_freq_char(map<char, int> m);

		//Return integer with the highest frequency of alphabets
		int high_frequency_count(map<char,int> m);

		//Print vector
		void print_vector(vector<int> v);

		//Print Hashmap
		void print_map(map <char,string> m);
		void print_map(map <char,int> m);
		void print_map(map <string,char> m);
};