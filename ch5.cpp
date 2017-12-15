//Cryptopals Set 1 Challenge 5
#include "crypto.h"

int main()
{
	CryptoLib crypt;

	//Test cases provided
	string str = "Burning 'em, if you ain't quick and nimble I go crazy when I hear a cymbal";
	string key = "ICE";

	cout << "ENCODED: " << crypt.repeatingKeyXOR(str, key) << endl;
	return 0;
}