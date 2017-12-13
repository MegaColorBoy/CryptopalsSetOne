//Cryptopals Set 1 Challenge 4
#include "crypto.h"

int main()
{
	CryptoLib crypt;

	ifstream infile;
	string str;
	int maxCount = 0;
	string maxString = "";
	vector<int> maxV;

	infile.open("enctext.txt");

	//if the file is not there
	if(!infile)
	{
		cout << "Unable to open the file";
		exit(1);
	}

	while(infile >> str)
	{
		//Only look for strings with 60 char length
		if(str.size() == 60)
		{
			str = crypt.add_spaces(crypt.con_hex_2_bin(str), 8);
			vector<int> v1 = crypt.con_bin_2_dec(str, 7.0);
			string newStr = crypt.con_dec_2_ascii(v1);

			//1. Select the string that has the most english letters
			int count = crypt.high_frequency_count(crypt.frequency_table(newStr));
			if(count > maxCount)
			{
				maxCount = count;
				maxString = newStr;
				maxV = v1;
			} 
		}
	}

	//2. Pass the list of decimals to the function
	cout << crypt.detectSingleByteXOR(maxV) << endl;
	return 0;
}