#include "crypto.h"

int main()
{
	CryptoLib crypt;
	string message;
	string binary;
	string key;

	//if this returns 37, then the function is working correct!
	// cout << crypt.hamming_distance("this is a test", "wokka wokka!!!") << endl;

	//Read the file content
	ifstream infile;

	//Converted the B64 text to Hexadecimals through an online converter
	//as it wasn't accurate with b64 decoder that I'd built
	infile.open("message.txt");
	getline(infile, message, '\0');
	infile.close();

	//Convert the hexadecimal string to ASCII
	message = crypt.con_hex_2_ascii(message);

	//Guess the length of the key
	int keyLength = crypt.guess_key_length(message);

	//Transpose the message based on keysize length
	int blocks = message.size() / keyLength;

	for(int i=0; i<keyLength; ++i)
	{
		string block;
		char indexKey='\0';
 
 		//scan the encrypted text to build the block with char at index i
		for(int j=0; j<blocks; j++){
			block += message.substr((j*keyLength) + i,1);
		}

		//Concatenate the selected characters, which will become the predicted key
		key += crypt.singleByteXOR_Bruteforce_key(block);
	}

	cout << "KEY: " << key << endl;
	cout << "DECODED: " << crypt.con_hex_2_ascii(crypt.repeatingKeyXOR(message, key)) << endl;

	return 0;	
}