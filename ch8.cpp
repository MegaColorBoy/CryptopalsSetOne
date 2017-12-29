//The Cryptopals Crypto Challenges - Set 1 Challenge 8
#include "crypto.h"

int main()
{
	CryptoLib crypt;

	string str;

	ifstream infile;
	infile.open("8.txt");

	int count = 0;
	while(!infile.eof())
	{
		getline(infile, str);

		//Check if this string has ECB mode
		if(crypt.detect_ecb_mode(str, 16) == true)
		{
			cout << "FOUND AT LINE " << count << " => " << str << endl;
			break;
		}
		count++;
	}
}