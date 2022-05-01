#include"AESalgorithm.h"


void main()
{
	std::string to_encryp = "isac Newton Artuso Fernandes";
	std::string key = "rtyuioplkjhgtre";

	std::vector<uint8_t> test;
	int b = (int)to_encryp.at(1);
	 uint8_t c = 116;
	//test.push_back((int)to_encryp.at(1));

	//std::vector<unsigned char> key{ 0xB,0xC,13,12,11,10,15,14,13,12,11,10,9,8,7,6 };

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


	 char ch1 = 'I', ch2 = 'S', ch3;
	 ch3 = ch1 ^ ch2;
	 std::bitset<8> x(ch1);
	// std::cout << x << '\n';;
	 //std::cout << (x & 0b00001111)<< '\n';

	 	//	 column = itr & 0b00001111;
		 //line   = itr & 0b11110000;

	 //printf("char %d\n", ch3);
	 //printf("char move 4 bits %d\n", ch3<<4);
	 //printf("%c\n", ch1 - ch2 - 4);


	 std::string s1, s2, s3;

	 s1 = 'I';
	 s2 = 'S';

	 const char* c1 = s1.c_str();
	 const char* c2 = s2.c_str();

	 //printf("String to char %d\n", *c1^*c2);



	std::vector<unsigned char> encrypted;

	std::unique_ptr<AES> message;

	encrypted = message->Encrypt(to_encryp, key);
	

}