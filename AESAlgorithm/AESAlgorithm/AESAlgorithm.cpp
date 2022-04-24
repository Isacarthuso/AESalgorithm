#include"AESalgorithm.h"


std::vector<unsigned char> AES::SubBytes(std::string plaintext, std::string key)
{
	 auto xorcalc = [=]()->void { for (int i = 0; i < 15; i++) { plaintextXORkey.push_back((int)plaintext[i] ^ key[i]);} };


	 std::vector<uint8_t> map_sbox;
	 uint8_t column;
	 uint8_t line;

	 for (auto itr : plaintextXORkey) {

		 column = itr & 0b00001111;
		 line   = itr & 0b11110000;
		 map_sbox.push_back(sBox[line][column]);
	 }

	return  std::vector<unsigned char>();
}

std::vector<unsigned char> AES::Encrypt(std::string to_encrypt, std::string key)
{
	std::vector<unsigned char> AddRoundKey;

	AddRoundKey = AES::SubBytes(to_encrypt, key);

	return std::vector<unsigned char>();
}