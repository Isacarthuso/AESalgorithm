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

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
