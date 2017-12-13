//CryptoPals Set 1 Challenge 1
#include "crypto.h"

int main()
{
	CryptoLib crypt;

	//Test case provided from the site
	// string str = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
	// cout << crypt.con_hex_2_b64(str) << endl;

	string str = crypt.con_ascii_2_hex("Hello World");
	string enc = crypt.b64_encode(str); 
	cout << "ENCODED: " << enc << endl;

	string dec = crypt.con_hex_2_ascii(crypt.b64_decode(enc));
	cout << "DECODED: " << dec << endl;
	return 0;
}