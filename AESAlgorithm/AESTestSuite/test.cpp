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
	
	EXPECT_EQ(0,Encryption.Setkey("ABCDEFGHIJLMNOPQ"));

	EXPECT_EQ(1, Encryption.Setkey("ABCDEFGHIJL MNOPQ"));

	EXPECT_EQ(-1, Encryption.Setkey("ABCDEFGHIJL MNO"));

	EXPECT_EQ(10, Encryption.Setkey("ABCDEFGHIJLMNOPQPOJIUYTRDF"));

}
TEST(SetUpEncryption, checkPacks) {
	AES Encryption;
	Encryption.SetKeyBits(128);

	std::vector<std::string> packs; 
	std::string pack;
	std::string key;
	

	//key = "1234567891011121314151617181920";
	//EXPECT_EQ(2, Encryption.SetPlainText(key));
	//packs = Encryption.GetPack();
	//pack = packs.at(0);
	//EXPECT_TRUE("1234567891011121" == pack);
	//pack = packs.at(1);
	//EXPECT_TRUE("314151617181920#" == pack);

	Encryption.CleanPacks();

	key = "oplmh6ygvcfhkpoi314151617181920wyterstyuiokmnbsdftu";
	EXPECT_EQ(4, Encryption.SetPlainText(key));
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

	key = "trtyuioplknbvfgd";
	EXPECT_EQ(1, Encryption.SetPlainText(key));
	packs = Encryption.GetPack();
	pack = packs.at(0);
	EXPECT_TRUE("trtyuioplknbvfgd" == pack);

}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
