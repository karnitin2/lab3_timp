#include <UnitTest++/UnitTest++.h>
#include "/home/stud/C++Projects/2lab/2/Cipher.h"
#include "/home/stud/C++Projects/2lab/2/Cipher.cpp"
SUITE(KeyTest)
{

    TEST(ValidKey) {
        CHECK_EQUAL("OWOLLDELHR", Cipher().cipher("HELLOWORLD",7));
    }
    TEST(EmptyKey) {
        CHECK_THROW(Cipher().cipher("HELLOWORLD", 0),cipher_error);
    }
    TEST(InvalidKey1) {
        CHECK_THROW(Cipher().cipher("HELLOWORLD", 1),cipher_error);
    }
    TEST(InvalidKey2) {
        CHECK_THROW(Cipher().cipher("HELLOWORLD", -5),cipher_error);
    }

}

SUITE(CipherTest)
{
    TEST(ValidText1) {
        CHECK_EQUAL("LRLOEWDHOL", Cipher().cipher("HELLOWORLD",4));
    }
    TEST(ValidText2) {
        CHECK_EQUAL("lrloewdHol", Cipher().cipher("Helloworld",4));
    }
    TEST(EmptyText) {
        CHECK_THROW(Cipher().cipher("",4),cipher_error);
    }
    TEST(ValidText3) {
        CHECK_EQUAL("EDLLORWHOL", Cipher().cipher("OWOLLDELHR",7));
    }
}

SUITE(DecipherText)
{
    TEST(UpCaseString) {
        CHECK_EQUAL("HELLOWORLD", Cipher().decipher("LRLOEWDHOL", 4));
    }
    TEST(LowCaseString) {
        CHECK_THROW(Cipher().decipher("lrloeWDHOL", 4),cipher_error);
    }
    TEST(EmptyString) {
        CHECK_THROW(Cipher().decipher("", 4),cipher_error);
    }
    TEST(SpaceString) {
        CHECK_THROW(Cipher().decipher("LRL OEW DHOL", 4),cipher_error);
    }
    TEST(DigitsString) {
        CHECK_THROW(Cipher().decipher("LRL1OEW9DHOL", 4),cipher_error);
    }

}
int main(int argc, char **argv)
{
    return UnitTest::RunAllTests();
}
