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

void AES::EncryptForward(int a)
{
	std::cout << "Thread: " << a << std::endl;
}

char buffer[20];
std::string str("Test string...");
std::size_t length = str.copy(buffer, 6, 5);

std::vector<unsigned char> AES::XorAddRoundKey(std::string* PlainText, std::string* Userkey) {

	char* ptr_char_plain_text;
	char* ptr_char_key;
	std::string plain_text, cp_key;

	plain_text = *PlainText;

	cp_key = *Userkey;

	ptr_char_plain_text = &plain_text[0];

	ptr_char_key = &cp_key[0];
	
	std::vector<unsigned char> xorResult;

	for (int i = 0; i < Userkey->size(); i++)
	{
		xorResult.push_back(ptr_char_plain_text[i] ^ ptr_char_key[i]);

	}


	return xorResult;

}


std::vector<unsigned char> AES::Encrypt(std::string to_encrypt, std::string key)
{




	////Sub-Bytes:
	//unsigned char mapSbox[16];

	//for (int i = 0; i < 15; i++) {

	//	std::bitset<8> RowColumn(XorAddRoundKey[i]);
	//	//row , column
	//	mapSbox[i] = sBox[postsBox[((RowColumn.to_ulong() & 0b11110000) >> 4)][(RowColumn.to_ulong() & 0b00001111)]];

	//}

	////Shift Rows

	////2nd row
	//unsigned char memory1 = mapSbox[4];
	//unsigned char memory2 = mapSbox[5];
	//unsigned char memory3 = mapSbox[6];
	//unsigned char memory4 = mapSbox[7];

	//mapSbox[4] = memory4;
	//mapSbox[5] = memory3;
	//mapSbox[6] = memory2;
	//mapSbox[7] = memory1;

	////3rd row
	//memory1 = mapSbox[8];
	//memory2 = mapSbox[9];
	//memory3 = mapSbox[10];
	//memory4 = mapSbox[11];

	//mapSbox[8]  = memory3;
	//mapSbox[9]  = memory4;
	//mapSbox[10] = memory1;
	//mapSbox[11] = memory2;

	////4th row
	//memory1 = mapSbox[12];
	//memory2 = mapSbox[13];
	//memory3 = mapSbox[14];
	//memory4 = mapSbox[15];

	//mapSbox[12] = memory4;
	//mapSbox[13] = memory1;
	//mapSbox[14] = memory2;
	//mapSbox[15] = memory3;

	////Mix-Columns

	//auto mult = [&mapSbox](int pline, int pcolumn) -> char {return MixColumnConstMatrix[pline] * mapSbox[pcolumn]; };


	//unsigned char MixColumntMatrix[16]
	//{/* 0    1    2    3 */
	//  mult(0,0) + mult(0,4) + mult(0,8)  + mult(0,12),
	//  mult(0,1) + mult(0,5) + mult(0,9)  + mult(0,13),
	//  mult(0,2) + mult(0,6) + mult(0,10) + mult(0,14),
	//  mult(0,3) + mult(0,7) + mult(0,11) + mult(0,15),

	//  mult(4,0) + mult(4,4) + mult(4,8)  + mult(4,12),
	//  mult(4,1) + mult(4,5) + mult(4,9)  + mult(4,13),
	//  mult(4,2) + mult(4,6) + mult(4,10) + mult(4,14),
	//  mult(4,3) + mult(4,7) + mult(4,11) + mult(4,15),
	//
	//  mult(8,0) + mult(8,4) + mult(8,8)  + mult(8,12),
	//  mult(8,1) + mult(8,5) + mult(8,9)  + mult(8,13),
	//  mult(8,2) + mult(8,6) + mult(8,10) + mult(8,14),
	//  mult(8,3) + mult(8,7) + mult(8,11) + mult(8,15),
	// 
	//  mult(12,0) + mult(12,4) + mult(12,8)  + mult(12,12),
	//  mult(12,1) + mult(12,5) + mult(12,9)  + mult(12,13),
	//  mult(12,2) + mult(12,6) + mult(12,10) + mult(12,14),
	//  mult(12,3) + mult(12,7) + mult(12,11) + mult(12,15),

	//};

	return std::vector<unsigned char>();
}

//Set how many bit will be used to encrypt
bool AES::SetKeyBits(uint16_t keybitsnumb)
{
	

	if (keybitsnumb == 128 || keybitsnumb == 192 || keybitsnumb == 256) {
		key_bits_numb = keybitsnumb;
		return true;
	}
		
	else
		return false;
}

/*Set and check the key to be used in encryptation process
	return:
	0 - key has the number of bit size as expected.
	Dif

*/

int16_t AES::Setkey(std::string key)
{
	
	if (key.size() * bits8 == key_bits_numb) {

		key_ = key;
	}
	
	return ((key.size() * bits8) - key_bits_numb)/ bits8;
}

int8_t AES::SetPlainText(std::string plaintext)
{
	uint8_t rest;
	uint8_t numbers_packs = 0;
	
	if(key_bits_numb == 0)
		return -1;

	else {

		rest = plaintext.size() % 16;
		std::cout <<"size"<< plaintext.size() << std::endl;
		if (rest == 0) {

			numbers_packs = plaintext.size() / 16;
		}

		else {

			numbers_packs = ((plaintext.size() / 16) + 1 );

		}
		size_t pintial = 0, pfinal = 0;

		for (uint8_t i = 0; i < numbers_packs; i++) {

				pintial = i * 16;
				str_pack.push_back(plaintext.substr(pintial, 16));
		}

		std::string lastPack;
		lastPack = str_pack.back();
		uint8_t number_element = lastPack.size();
		if (lastPack.size() < 16) {
			for(uint8_t i = 0; i < (16 - number_element); i++) {
				lastPack.append("#");
			}
		}

		str_pack.pop_back();
		str_pack.push_back(lastPack);
		return numbers_packs;
	}
}

std::vector<std::string> AES::GetPack(void)
{
	return str_pack;
}

void AES::CleanPacks(void)
{
	str_pack.clear();
}
