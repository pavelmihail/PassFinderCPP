#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <openssl/md5.h>
#include <openssl/sha.h>

using namespace std;

// predifiend values
const string PASSWORD_TO_FIND = "fb6c6ebe761e4e79f07c715b380826544117b7a68e66af639313401e56271028";
const string SALT = "ismsap";

//encryption with md5 and sha combined
string md5_sha256(const string str)
{
    //MD5 digenstion
    unsigned char hashMd5[MD5_DIGEST_LENGTH];
    MD5_CTX md5;

    MD5_Init(&md5);
    MD5_Update(&md5, str.c_str(), str.size());
    MD5_Final(hashMd5, &md5);

    //SHA256 digest of the MD5 output
    unsigned char hashSha[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;

    SHA256_Init(&sha256);
    SHA256_Update(&sha256, hashMd5, MD5_DIGEST_LENGTH);
    SHA256_Final(hashSha, &sha256);

    //manage the output into a string
    stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        ss << hex << setw(2) << setfill('0') << (int)hashSha[i];
    }

    return ss.str();
}

int main()
{
    //read from file line by line binary
    ifstream infile;
    infile.open("ignis-10M.txt", ios::binary | ios::in);

    if (infile.is_open())
    {
        string line = "";
        while (getline(infile, line))
        {
            //apply the salt
            string saltedValue = SALT + line;

            //check the password hash
            if(md5_sha256(saltedValue) == PASSWORD_TO_FIND){
                cout << "Parola gasita este: " << line << endl;
                break;
            }
        }
    }

    //close the file
    infile.close();

    return 0;
}