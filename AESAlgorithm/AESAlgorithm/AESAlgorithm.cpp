#include"AESalgorithm.h"


unsigned char AES::AddRoundKey(unsigned char plaintext[], unsigned char key[]) {

	for (int i = 0; i < 15; i++)
	{
		AES::round_key_output.push_back(plaintext[i] ^ key[i]);

	}
	return 0;
}