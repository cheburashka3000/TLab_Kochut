#include <unittest++/UnitTest++.h>
#include </home/user/TLab2_Kochut/zadanie2/TableCipher.h>
#include </home/user/TLab2_Kochut/zadanie2/TableCipher.cpp>
struct KeyB_fixture {
	TableCipher * p;
	TableCipher * b;
	KeyB_fixture() {
		p = new TableCipher(3);
		b = new TableCipher(25);
	}
	~KeyB_fixture() {
		delete p;
		delete b;
	}
};
SUITE(KeyTest)
{
	TEST(ValidSimpleKey) {
		CHECK_EQUAL("BDACE",TableCipher(3).encrypt("ABCDE"));
	}
	TEST(ValidMultipleKey) {
		CHECK_EQUAL("BDAC",TableCipher(2).encrypt("ABCD"));
	}
	TEST(WeakKey) {
		CHECK_THROW(TableCipher cp(1),cipher_error);
	}
	TEST(NegativeKey) {
		CHECK_THROW(TableCipher cp(-7),cipher_error);
	}
	TEST(ZeroKey) {
		CHECK_THROW(TableCipher cp(0),cipher_error);
	}
};
SUITE(EncryptTest)
{
	TEST_FIXTURE(KeyB_fixture, UpCaseString) {
		CHECK_EQUAL("EIBWOUSEHADHUKOFJPVTLYGTQCRNXMOREZO",
		            p->encrypt("THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG"));
	}
	TEST_FIXTURE(KeyB_fixture, LowCaseString) {
		CHECK_EQUAL("eibwousehadhukofjpvtlygtqcrnxmorezo",
		            p->encrypt("thequickbrownfoxjumpsoverthelazydog"));
	}
	TEST_FIXTURE(KeyB_fixture, StringWithWhitspaceAndPunct) {
		CHECK_EQUAL("eukrnoJpOrhLyo!hQcBwF m eT zD!T i o xusv ea g!",
		            p->encrypt("The Quick Brown Fox Jumps Over The Lazy Dog!!!"));
	}
	TEST_FIXTURE(KeyB_fixture, StringWithNumbers) {
		CHECK_EQUAL("he3ai v3rbsIa  bt", p->encrypt("I have 33 rabbits"));
	}
	TEST_FIXTURE(KeyB_fixture, NoAlphaString) {
		CHECK_EQUAL("38592+699147=9", p->encrypt("1234+8765=9999"));
	}
	TEST_FIXTURE(KeyB_fixture, EmptyString) {
		CHECK_THROW(p->encrypt(""),cipher_error);
	}
	TEST_FIXTURE(KeyB_fixture, LongKey) {
		CHECK_THROW(b->encrypt("ABCDE"),cipher_error);
	}
};
SUITE(DecryptText)
{
	TEST_FIXTURE(KeyB_fixture, UpCaseString) {
		CHECK_EQUAL("THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG",
		            p->decrypt("EIBWOUSEHADHUKOFJPVTLYGTQCRNXMOREZO"));
	}
	TEST_FIXTURE(KeyB_fixture, LowCaseString) {
		CHECK_EQUAL("thequickbrownfoxjumpsoverthelazydog",
		            p->decrypt("eibwousehadhukofjpvtlygtqcrnxmorezo"));
	}
	TEST_FIXTURE(KeyB_fixture, StringWithWhitspaceAndPunct) {
		CHECK_EQUAL("The Quick Brown Fox Jumps Over The Lazy Dog!!!",
		            p->decrypt("eukrnoJpOrhLyo!hQcBwF m eT zD!T i o xusv ea g!"));
	}
	TEST_FIXTURE(KeyB_fixture, StringWithNumbers) {
		CHECK_EQUAL("I have 33 rabbits", p->decrypt("he3ai v3rbsIa  bt"));
	}
	TEST_FIXTURE(KeyB_fixture, NoAlphaString) {
		CHECK_EQUAL("1234+8765=9999", p->decrypt("38592+699147=9"));
	}
	TEST_FIXTURE(KeyB_fixture, EmptyString) {
		CHECK_THROW(p->decrypt(""),cipher_error);
	}
	TEST_FIXTURE(KeyB_fixture, LongKey) {
		CHECK_THROW(b->encrypt("ABCDE"),cipher_error);
	}
};
int main(int argc, char **argv)
{
	return UnitTest::RunAllTests();
}
