#include"AESalgorithm.h"


std::vector<unsigned char> AES::SubBytes(std::string plaintext, std::string key)
{

	////Xor add RoundKey
	//auto xorcalc = [=]()->void { for (int i = 0; i < 15; i++) { plaintextXORkey.push_back((int)plaintext[i] ^ key[i]);} };


	////SubBytes
	// std::vector<uint8_t> map_sbox;
	// uint8_t column;
	// uint8_t line;

	// for (auto itr : plaintextXORkey) {

	//	 column = itr & 0b00001111;
	//	 line   = itr & 0b11110000;
	//	 map_sbox.push_back(sBox[line][column]);
	// }

	// //Shift Rows


	return  std::vector<unsigned char>();
}

char buffer[20];
std::string str("Test string...");
std::size_t length = str.copy(buffer, 6, 5);

std::vector<unsigned char> AES::Encrypt(std::string to_encrypt, std::string key)
{
	// pack creation 
	char  pack[15], keyL[15];
	to_encrypt.copy(pack, 15, 0);
	key.copy(keyL, 15, 0);

	//std::cout << to_encrypt << std::endl;
	//for (int j = 0; j < 15; j++) {
	//	std::cout << pack[j] ;
	//}
	//std::cout<<   "\n";
	//
	//for (int j = 0; j < 15; j++) {
	//	std::cout << keyL[j] ;
	//}

	//std::cout << "\n";

	//Xor add RoundKey
	char XorAddRoundKey[15];
	auto xorcalc = [&]()->void { for (int i = 0; i < 15; i++) { XorAddRoundKey[i] = pack[i] ^ keyL[i]; } };
	xorcalc();

	//Sub-Bytes:
	unsigned char mapSbox[16];

	for (int i = 0; i < 15; i++) {

		std::bitset<8> RowColumn(XorAddRoundKey[i]);
		//row , column
		mapSbox[i] = sBox[postsBox[((RowColumn.to_ulong() & 0b11110000) >> 4)][(RowColumn.to_ulong() & 0b00001111)]];

	}
	//std::bitset<8> RowColumn(XorAddRoundKey[0]);
	//std::cout << XorAddRoundKey[2] << '\n';
	//std::cout << RowColumn << std::endl;
	//uint8_t t = RowColumn.to_ulong();
	//uint8_t column = (( RowColumn.to_ulong()&0b11110000 ) >> 4 );
	//uint8_t row = ( RowColumn.to_ulong() & 0b00001111 );
	//printf("\n%d", column);
	//printf("\n%d", row);

	//Shift Rows

	//2nd row
	unsigned char memory1 = mapSbox[4];
	unsigned char memory2 = mapSbox[5];
	unsigned char memory3 = mapSbox[6];
	unsigned char memory4 = mapSbox[7];

	mapSbox[4] = memory4;
	mapSbox[5] = memory3;
	mapSbox[6] = memory2;
	mapSbox[7] = memory1;

	//3rd row
	memory1 = mapSbox[8];
	memory2 = mapSbox[9];
	memory3 = mapSbox[10];
	memory4 = mapSbox[11];

	mapSbox[8]  = memory3;
	mapSbox[9]  = memory4;
	mapSbox[10] = memory1;
	mapSbox[11] = memory2;

	//4th row
	memory1 = mapSbox[12];
	memory2 = mapSbox[13];
	memory3 = mapSbox[14];
	memory4 = mapSbox[15];

	mapSbox[12] = memory4;
	mapSbox[13] = memory1;
	mapSbox[14] = memory2;
	mapSbox[15] = memory3;



	





	//uint row = (4 >> RowColumn);
	//uint8_t column = (RowColumn << 4);

	 //std::cout << (x & 0b00001111)<< '\n';

		//	 column = itr & 0b00001111;
		 //line   = itr & 0b11110000;


	/*for (int j = 0; j < 15; j++) {
		std::cout << XorAddRoundKey[j] << std::endl;
	}*/

	//auto xorcalc = [=]()->void { for (int i = 0; i < 15; i++) { plaintextXORkey.push_back((int)to_encrypt[i] ^ key[i]); } };

	//std::cout << plaintextXORkey << std::endl;

	//std::vector<std::vector<std::string>> plaintext;

	//uint8_t flow_to_encrypt = 0;
	//for (int i = 0; i < 2; i++)
	//{
	//	for(int j = 0; j <2; j++)
	//	{
	//		
	//		flow_to_encrypt++;
	//	
	//	}
	//}
	//const char* str = to_encrypt.c_str();


	//std::cout << str << std::endl;

	//plaintext[1][1] = "1";
	//std::vector<unsigned char> AddRoundKey;

	//AddRoundKey = AES::SubBytes(to_encrypt, key);

	return std::vector<unsigned char>();
}