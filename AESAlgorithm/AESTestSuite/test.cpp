#include "pch.h"
#include"gtest/gtest.h"
#include"AESalgorithm.h"
#include"AESalgorithm.cpp"

TEST(SetUpEncryption, Setbitsnumber) {

	AES Encryption;
	Encryption.SetKeyBits(128);

	EXPECT_TRUE(Encryption.SetKeyBits(128));

	EXPECT_FALSE(Encryption.SetKeyBits(1));

	EXPECT_TRUE(Encryption.SetKeyBits(192));

	EXPECT_FALSE(Encryption.SetKeyBits(30));

	EXPECT_TRUE(Encryption.SetKeyBits(256));

	EXPECT_FALSE(Encryption.SetKeyBits(-1));
}
TEST(SetUpEncryption, SetKey)
{
	AES Encryption;
	Encryption.SetKeyBits(128);
	Encryption.Setkey("ABCDEFGHIJLMNOPQ");
	//key set is accordind to the SetKeyBits
	EXPECT_EQ(0,Encryption.Setkey("ABCDEFGHIJLMNOPQ"));

	//key set there is +1 char according to the SetKeyBits
	EXPECT_EQ(1, Encryption.Setkey("ABCDEFGHIJL MNOPQ"));

	//key set there is -1 char according to the SetKeyBits
	EXPECT_EQ(-1, Encryption.Setkey("ABCDEFGHIJL MNO"));

	//key set there is +10 chars according to the SetKeyBits
	EXPECT_EQ(10, Encryption.Setkey("ABCDEFGHIJLMNOPQPOJIUYTRDF"));

}
TEST(SetUpEncryption, checkPacks) {
	AES Encryption;
	Encryption.SetKeyBits(128);

	std::vector<std::string> packs; 
	std::string pack;
	std::string PlainText;
	

	PlainText = "1234567891011121314151617181920";
	EXPECT_EQ(2, Encryption.SetPlainText(PlainText));
	packs = Encryption.GetPack();
	pack = packs.at(0);
	EXPECT_TRUE("1234567891011121" == pack);
	pack = packs.at(1);
	EXPECT_TRUE("314151617181920#" == pack);

	Encryption.CleanPacks();

	PlainText = "oplmh6ygvcfhkpoi314151617181920wyterstyuiokmnbsdftu";
	EXPECT_EQ(4, Encryption.SetPlainText(PlainText));
	packs = Encryption.GetPack();
	pack = packs.at(0);
	EXPECT_TRUE("oplmh6ygvcfhkpoi" == pack);
	pack = packs.at(1);
	EXPECT_TRUE("314151617181920w" == pack);
	pack = packs.at(2);
	EXPECT_TRUE("yterstyuiokmnbsd" == pack);
	pack = packs.at(3);
	EXPECT_TRUE("ftu#############" == pack);

	Encryption.CleanPacks();

	PlainText = "trtyuioplknbvfgd";
	EXPECT_EQ(1, Encryption.SetPlainText(PlainText));
	packs = Encryption.GetPack();
	pack = packs.at(0);
	EXPECT_TRUE("trtyuioplknbvfgd" == pack);

	Encryption.CleanPacks();

	PlainText = "trtyuioplknbv";
	EXPECT_EQ(1, Encryption.SetPlainText(PlainText));
	packs = Encryption.GetPack();
	pack = packs.at(0);
	EXPECT_TRUE("trtyuioplknbv###" == pack);

}

TEST(SetUpEncryption, roundKey) {

	AES Encryption;

	std::vector<unsigned char> xorResult;

	std::string key       = "f&rLum11111111A";

	std::string PlainText = "2#0rp511111111b";

	xorResult = Encryption.XorAddRoundKey(&PlainText, &key);

	EXPECT_TRUE(+xorResult.at(0) == 84);

	EXPECT_TRUE(+xorResult.at(1) == 5);

	EXPECT_TRUE(+xorResult.at(2) == 66);

	EXPECT_TRUE(+xorResult.at(3) == 62);

	EXPECT_TRUE(+xorResult.at(14) == 35);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
