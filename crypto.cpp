//Implementation of the CryptoPals Library
//This library is for Set 1 Challenges
#include "crypto.h"

//Constructor
CryptoLib::CryptoLib(){}

//Hashmap that contain hex key and binary values
map<char, string> CryptoLib::gen_hex_table()
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

//Convert hex to string
string CryptoLib::con_hex_2_bin(string hexStr)
{
	map<char,string> m = gen_hex_table();

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

//Add spaces between strings
string CryptoLib::add_spaces(string str, int spaces)
{
	string newStr = "";
	int count = 0;

	for(int i=0; i<str.size(); i++)
	{

		// newStr += str[i];
		if(count == spaces)
		{
			newStr += " ";
			i--;
			count = 0;
		}
		else
		{
			newStr += str[i];
			count++;
		}
	}

	return newStr;
}

//Reverse string
string CryptoLib::reverse_string(string str)
{
	string newStr = "";
	for(int i=str.size()-1; i>=0; i--)
	{
		newStr += str[i];
	}
	return newStr;
}

//Convert binary to decimal
vector<int> CryptoLib::con_bin_2_dec(string str, double power)
{
	vector<int> v;
	string newStr = "";
	istringstream iss(str);
	string x;

	while(iss >> x)
	{
		double p = power;
		double decimal = 0.0;

		for(int i=0; i<x.size(); i++)
		{
			if(x[i] == '1')
			{
				decimal += pow(2.0, p);
			}
			p--;
		}
		v.push_back((int)decimal);
	}
	return v;
}

//Convert decimal to binary
string CryptoLib::con_dec_2_bin(int decimal)
{
	string newStr = "";
	int value = decimal;
	while(value != 0)
	{
		int rem = value % 2;
		value = value / 2;
		char c = rem + '0';
		newStr += c;
	}
	
	return reverse_string(newStr);
}

//Convert Decimal to ASCII
string CryptoLib::con_dec_2_ascii(vector<int> v)
{
	string newStr = "";
	for(int i=0; i<v.size(); i++)
	{
		newStr += (char)v[i];
	}
	return newStr;
}

//Convert ASCII to HEX
string CryptoLib::con_ascii_2_hex(string str)
{
	stringstream ss;
	for(int i=0; i<str.size(); i++)
	{
		ss << std::hex << (int)str[i];
	}
	return ss.str();
}

//Convert HEX to ASCII
string CryptoLib::con_hex_2_ascii(string str)
{
	string newStr = "";
	str = add_spaces(con_hex_2_bin(str), 8);
	vector<int> v = con_bin_2_dec(str, 7.0);

	for(int i=0; i<v.size(); i++)
	{
		newStr += (char)v[i];
	}
	return newStr;
}

//Convert HEX to Base 64
string CryptoLib::con_hex_2_b64(string str)
{
	string b64 = "";
	string ref = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	string newStr = add_spaces(con_hex_2_bin(str), 6);

	vector<int> v = con_bin_2_dec(newStr, 5.0);

	for(int i=0; i<v.size(); i++)
	{
		b64 += ref[v[i]];
	}

	return b64;
}

//Convert Base64 to Hex
string CryptoLib::con_b64_2_hex(string str)
{
	string hex = "";
	string ref = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	string binary = "";

	for(int i=0; i<str.size(); i++)
	{
		int pos = ref.find(str[i]);
		string bits = con_dec_2_bin(pos);
		binary += bits;
	}
	binary = add_spaces(binary, 4);

	istringstream iss(binary);
	string x;

	map<char, string> m = gen_hex_table();
	map<char, string>::iterator it;

	while(iss >> x)
	{
		for(it = m.begin(); it!= m.end(); it++)
		{
			if(it->second == x)
			{
				hex += it->first;
			}
		}
	}

	return hex;
}

//Hamming Distance
int CryptoLib::hamming_distance(string str1, string str2)
{
	int count=0;
	for(int i=0; i<str1.size(); i++)
	{
		int partial = (str1[i]&0xFF) ^ (str2[i]&0xFF);
		while(partial)
		{
			count += partial & 1;
			partial = partial >>1;
		}
	}
	return count;
}

//Base64 Encoder - Version 2
string CryptoLib::b64_encode(string str)
{
	string newStr = "";
	string ref = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	
	//Number of bytes per 12 bits
	int bytes = str.size() / 3;
	int padding = str.size() % 3;

	//Padding must be either 0 or 1
	if(padding > 1)
	{
		return newStr;
	}

	//Number of characters to be encoded is 3
	int count = bytes * 3;

	unsigned long long h = 0;

	int i = 0;
	for(i=0; i<count; i+=3) //iterate every 3 chars
	{
		//Get every 3 chars
		char a[2] = {str[i], 0};
		char b[2] = {str[i+1], 0};
		char c[2] = {str[i+2], 0};

		//Now, convert each hex character (base 16) to it's equivalent decimal number
		//and merge them into one variable
		h = strtoull(a, nullptr, 16) << 8; //shift left by 8 bits
		h |= strtoull(b, nullptr, 16) << 4; //shift left by 4 bits
		h |= strtoull(c, nullptr, 16); //no shift required only the first 2 characters need
	
		//HEX: 0x3F -> DEC: 63 -> ASCII: ?

		newStr += ref[0x3F & (h >> 6)]; //first b64 char; shift to right by 6 bits
		newStr += ref[0x3F & h]; //second b64 char
	}

	//if padding is required
	//Follows the same pattern as the above.
	if(padding == 1)
	{
		char a[2] = {str[i], 0};
		h = strtoull(a, nullptr, 16) << 8; // shift left by 8 bits
		newStr += ref[0x3F & (h >> 6)];
		newStr += '='; //add this towards the end of the encoded string
	}

	return newStr;
}

//Base64 Decoder - Version 2
string CryptoLib::b64_decode(string str)
{
	string newStr = "";
	string ref = "0123456789abcdef";

	//Check if this is a valid b64 string
	if(str.size() % 2 != 0)
	{
		return newStr;
	}

	//Number of bytes for hexadecimals
	int bytes = str.size() / 2;
	int count = bytes * 2;

	unsigned long long h = 0;
	for(int i=0; i<count; i+=2) //iterate every 2 chars
	{
		for(int j=0; j<2; j++)
		{
			h <<= 6; //shift 6 bits to the left

			//Check if the value is in the range of A-Z
			if(str[i+j] >= 0x41 && str[i+j] <= 0x5a)
			{
				h |= str[i+j] - 0x41;
			}
			//Check if the value is in the range of a-z
			else if(str[i+j] >= 0x61 && str[i+j] <= 0x7a)
			{
				h |= str[i+j] - 0x47;
			}
			//Check if the value is in the range of 0-9
			else if(str[i+j] >= 0x30 && str[i+j] <= 0x39)
			{
				h |= str[i+j] + 0x04;
			}
			//Check if the value is a '+'
			else if(str[i+j] == 0x2b)
			{
				h |= 0x3e;
			}
			//Check if the value is a '/'
			else if(str[i+j] == 0x2f)
			{
				h |= 0x3f;
			}
			//Check if the value is a '='
			else if(str[i+j] == 0x3d)
			{
				if(count - (i+j) == 1)
				{
					newStr += ref[0xf & (h >> 8)];
				}
			}
		}
		//Shift to the right by 8 bits
		newStr += ref[0xf & (h >> 8)];
		//Shift to the right by 4 bits
		newStr += ref[0xf & (h >> 4)];
		newStr += ref[0xf & h];
	}

	return newStr;
}

//Single Byte XOR
string CryptoLib::singleByteXOR(string str)
{
	string newStr = "";

	//1. Convert Hexadecimal to Binary
	str = add_spaces(con_hex_2_bin(str), 8);

	//2. Convert Binary to Decimals
	vector<int> v = con_bin_2_dec(str, 7.0);

	/*
		What's happening here?
		4. Generate a frequency table using the characters from the ASCII string
		5. Look for characters that are English and also has the highest frequency
		6. The character that has the highest frequency is the KEY!
	*/

	//The key
	unsigned char a = toupper(ret_high_freq_char(frequency_table(con_dec_2_ascii(v))));

	//7. Perform XOR with the KEY against each character
	for(int i=0; i<v.size(); i++)
	{
		unsigned char b = v[i];
		unsigned char c = b ^ a;
		newStr += c;
	}

	//8. Decoded message
	return newStr;
}

//Single Byte XOR V2 - a better version
string CryptoLib::singleByteXOR_V2(string str, char key)
{
	//Don't forget to add a NULL character to the string, it broke when I didn't add it previously.
	string newStr(str.size(),'\0'); 
	
	for(int i=0; i<str.size(); ++i){
		newStr[i] = str[i] ^ key;
	}
	return newStr;
}

//Return the Single Byte XOR key via Bruteforce
char CryptoLib::singleByteXOR_Bruteforce_key(string cipherBlock)
{
	char key = 0;
	int maxCount=0;
	string decodedMessage;

	//Brute force all 256 possibilities
	for(int i=0; i<=256; i++)
	{
		char ch = (char) i;

		//Perform Single Byte XOR -- modified version
		string attempt = singleByteXOR_V2(cipherBlock, ch);

		// cout << "Message: " << attempt << endl;

		int count = 0;
		/*
			Look for characters that are alphabetic and the space character,
			if it finds, increment the counter
		*/
		for(int j=0; j<attempt.size(); j++)
		{
			if((attempt[j] >= 65 && attempt[j] <= 122) || attempt[j] == ' ')
			{
				count++;
			}
		}

		//The one with the highest count, has the predicted key
		if(count > maxCount)
		{
			maxCount = count;
			key = ch;
			// decrypted = attempt;
		}
	}

	// cout << "KEY: " << key << endl;
	// cout << "MESSAGE: " << decrypted << endl;

	return key;
}

//Guess Key length of the cipher
int CryptoLib::guess_key_length(string cipherText)
{
	int KEYSIZE = -1;
	double leastNormalized = INT_MAX;
	
	//Guess a keysize from 2 to 40
	for(int i=2; i<=40; i++)
	{
		double normalize = 0.0f;

		//Number of bytes per key size
		int bytes = cipherText.size()/i;

		for(int j=0; j<bytes; j++)
		{
			string blockA = cipherText.substr((j*i), i);
			string blockB = cipherText.substr(((j+1)*i), i);
		
			//Calculate Hamming Distance between 2 strings
			int edit_distance = hamming_distance(blockA, blockB);

			normalize += ((double)edit_distance)/((double)blockA.size());
		}

		//Now, take an average 
		normalize /= bytes;

		//The key size that has the least edit distance is the key size required
		if(normalize > 0 && normalize < leastNormalized)
		{
			leastNormalized = normalize;
			KEYSIZE = i;
		}
	}

	//Return the key size
	return KEYSIZE;
}

//Detect string with Single Byte XOR
string CryptoLib::detectSingleByteXOR(vector<int> maxV)
{
	string final = "";
	int maxCount = 0;

	/*
		2. Perform a Brute-force XOR on the string that has
		the most english letters in which each character is XOR'd against
		every character from the ASCII table (256 characters)
	*/
	for(int i=0; i<256; i++)
	{
		string temp = "";
		unsigned char a = i;
		for(int j=0; j<maxV.size(); j++)
		{
			unsigned char b = maxV[j];
			unsigned char c = b ^ a;
			temp += tolower(c);
		}

		//3. Select the string that has the most english letters. again.
		int count = high_frequency_count(frequency_table(temp));
		if(count > maxCount)
		{
			maxCount = count;
			final = temp;
		}
	}
	
	//4. Display the most "english" text as the final result
	return final;
}

//Fixed XOR implementation
string CryptoLib::fixedXOR(string str1, string str2)
{
	if(str1.size() != str2.size())
	{
		return "The strings are not of equal length.";
	}
	else
	{
		string newStr = "";

		//Step 1. convert hex to binary of 8 bits
		str1 = add_spaces(con_hex_2_bin(str1), 8);
		str2 = add_spaces(con_hex_2_bin(str2), 8);

		//Step 2. convert binary to decimal
		vector<int> v1 = con_bin_2_dec(str1, 7.0);
		vector<int> v2 = con_bin_2_dec(str2, 7.0);

		//Step 3. XOR the decimals of v1 with decimals of v2
		for(int i=0; i<v1.size(); i++)
		{
			unsigned char a = v1[i];
			unsigned char b = v2[i];
			unsigned char c = a ^ b;
			newStr += c;
		}

		//Final result
		return con_ascii_2_hex(newStr);	
	}
}

//Repeating Key XOR implementation
string CryptoLib::repeatingKeyXOR(string str, string key)
{
	string newStr = "";
	int count = 0;

	/*
		1. Perform XOR against each character of the message 
		against each character of the key. 
		So if the key was "ICE" and the message is "abcdefg",
		it would be "a" against "I", then "b" against "C" and "c" against "E"
		but once it reaches the key's limit, you start again from the beginning
		of the key, which should be like: "d" against "I", "e" against "C" and so on.
	*/
	for(int i=0; i<str.size(); i++)
	{
		unsigned char a = key[count];
		unsigned char b = str[i];
		unsigned char c = b ^ a;

		newStr += c;

		if(count == key.size()-1)
		{
			count = 0;
		}
		else
		{
			count++;
		}
	}

	//2. Convert the ASCII message to Hexadecimal
	string final = "0";
	final += con_ascii_2_hex(newStr);
	return final;
}

//Return Character frequency of a string
map<char, int> CryptoLib::frequency_table(string str)
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

//Return character with the highest frequency
char CryptoLib::ret_high_freq_char(map<char, int> m)
{
	int max_count = 0;
	char max_char;

	for(auto p: m)
	{
		if(isalpha(p.first))
		{
			if(p.second > max_count)
			{
				max_char = p.first;
				max_count = p.second;
			}
		}
	}
	return max_char;
}

//Return integer with the highest frequency of alphabets
int CryptoLib::high_frequency_count(map<char,int>m)
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

//Print vector
void CryptoLib::print_vector(vector<int> v)
{
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
}

//Print Hashmap - v1
void CryptoLib::print_map(map <char,string> m)
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

//Print Hashmap - v2
void CryptoLib::print_map(map<char,int> m)
{
	// int count = 0;
	cout << "{";
	for(auto p: m)
	{
		//Show the frequency of the characters that are in English
		if(isalpha(p.first))
		{
			cout << p.first << ":" << p.second << " ";
			// count += p.second;
		}
	}
	cout << "}" << endl;
}

//Print Hashmap - v3
void CryptoLib::print_map(map <string, char> m)
{
	// int count = 0;
	cout << "{";
	for(auto p: m)
	{
		cout << p.first << ":" << p.second << " ";
	}
	cout << "}" << endl;
}