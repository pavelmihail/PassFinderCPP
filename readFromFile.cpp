#include <iostream>
#include <fstream>
#include <string>
#include <openssl/md5.h>

using namespace std;

int main()
{

    //define the file object and open the file in binary mode
    ifstream infile;
    infile.open("ignis-10M.txt", ios::binary | ios::in);
    cout << infile.is_open();

    //chech if the file is open
    if (infile.is_open())
    {
        //read the file line by line
        string line;
        while (getline(infile, line))
        {
            //do something with the red line
            printf("%s\n", line.c_str());
        }
    }

    infile.close();
    return 0;
}

/////////////////////////////////////write in file////////////////////////////////////////////////////

// newfile.open("tpoint.txt",ios::out);  // open a file to perform write operation using file object
//     if(newfile.is_open()) //checking whether the file is open
//     {
//         newfile<<"Tutorials point";   //inserting text
//         newfile.close();    //close the file object
//     }