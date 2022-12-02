#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <openssl/md5.h>
#include <openssl/sha.h>

using namespace std;

//md5 function from documentation plus string output
string md5(const string str)
{
    unsigned char hash[MD5_DIGEST_LENGTH];
    MD5_CTX md5;

    MD5_Init(&md5);
    MD5_Update(&md5, str.c_str(), str.size());
    MD5_Final(hash, &md5);

    stringstream ss;
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++)
    {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str();
}

//sha256 function from documentation plus string output
string sha256(const string str)
{

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;

    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);

    stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str();
}

int main()
{
    string messages = "message";

    //display the md5 and sha encryption for "message"
    cout << md5(messages) << endl;
    cout << sha256(messages) << endl;

    return 0;
}
