#include"AESalgorithm.h"
#include<memory>

#include <bitset>

void main()
{
	std::string to_encryp = "isac";
	std::vector<uint8_t> test;
	int b = (int)to_encryp.at(1);
	 uint8_t c = 116;
	//test.push_back((int)to_encryp.at(1));

	std::vector<unsigned char>        key{ 0xB,0xC,13,12,11,10,15,14,13,12,11,10,9,8,7,6 };

	//std::vector<std::vector<uint8_t> > fog{ 
	//	{ 0x63,0x7c,0x77,0x7b },
	//	{ 0xca,0x82,0xc9,0x7d} 
	//};

	//for(auto i: test)
	//std::cout << b << std::endl;

	//c = (uint8_t) b;
	//std::cout << unsigned(c) << std::endl;
	//std::bitset<8> x(c&0b00001111);
	//std::cout << x << std::endl;

	//std::cout << c << std::endl;


	std::vector<unsigned char> encrypted;

	std::unique_ptr<AES> message;

	//encrypted = message->Encrypt(to_encrypt, key);
	

}