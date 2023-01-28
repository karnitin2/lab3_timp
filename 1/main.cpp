#include <UnitTest++/UnitTest++.h>
#include "/media/Общедоступные/Для ТИМПА 3/Task_1/modAlphaCipher.h"
#include "/media/Общедоступные/Для ТИМПА 3/Task_1/modAlphaCipher.cpp"
SUITE(KeyTest)
{
    TEST(ValidKey) {
        CHECK_EQUAL("АМЦГЖИУ", modAlphaCipher("АЛФАВИТ").encrypt("АБВГД"));
    }
    TEST(LowCaseKey) {
        CHECK_EQUAL("ПАВНЕБ", modAlphaCipher("ывиорт").encrypt("ГКИН"));
    }
    TEST(WhitespaceInKey) {
        CHECK_THROW(modAlphaCipher key("Р Т"), cipher_error);
    }
    TEST(EmptyKey) {
        CHECK_THROW(modAlphaCipher key(""), cipher_error);
    }
}
struct KeyB_fixture {
    modAlphaCipher* p;
    KeyB_fixture()
    {
        p = new modAlphaCipher("Б");
    }
    ~KeyB_fixture()
    {
        delete p;
    }
};
SUITE(EncryptTest)
{
    TEST_FIXTURE(KeyB_fixture, UpCaseString) {
        CHECK_EQUAL("НБНЬМБСБНФ", p->encrypt("ЕРКЛЕЙДЖ"));
    }
    TEST_FIXTURE(KeyB_fixture, LowCaseString) {
        CHECK_EQUAL("НБНЬМБСБНФ", p->encrypt("ердилейдж"));
    }
    TEST_FIXTURE(KeyB_fixture, NoAlphaString) {
        CHECK_THROW(p->encrypt("1243"), cipher_error);
    }
}
SUITE(DecryptText)
{
    TEST_FIXTURE(KeyB_fixture, LowCaseString) {
        CHECK_THROW(p -> decrypt("нПРОБСБНФ"), cipher_error);
    }
    TEST_FIXTURE(KeyB_fixture, EmptyString) {
        CHECK_THROW(p->decrypt(""), cipher_error);
    }
}
int main(int argc, char **argv)
{
    return UnitTest::RunAllTests();
}
struct KeyAB_fixture {
    modAlphaCipher * pointer;
    KeyAB_fixture()
    {
        pointer = new modAlphaCipher(L"АВ");
    }
    ~KeyAB_fixture()
    {
    delete pointer;
    }
};
int main()
{
    return UnitTest::RunAllTests();
}
