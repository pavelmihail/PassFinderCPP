# PassFinderCPP

 You have breached the adversary database and got its password hashvalue. The hash value is given in the attached file (check the table for your name).
 You know that your adversary is using one of the most 10 million used passwords available here https://weakpass.com/wordlist/1935 (download file ignis-10M.txt).
 You also know that they are using a technique that will make your rainbow tables useless because they add “ismsap” as a prefix to all user passwords and after that they hash them 2 times using MD5 (1st run) and SHA-256 (2nd run). The output from the MD5 step is hashed again with SHA-256.
 Write a simple C/C++ application that will brute force the adversary password by using the 3rd party development library OpenSSL. The C/C++ implementation should contain one single .c or .cpp file. The source code file name must contain your name. The C/C++ implementation must print out the corresponding password at the console.
 Please, fill up the response box with the password when you upload the implementation.

# run comand
$ g++ <filename>.cpp -lcrypto  -o <filename>

# useful documentation

 install openSSL in ubuntu
https://linuxpip.org/install-openssl-linux/

 for the libry to be seen
$ sudo apt-get install libpcap-dev libssl-dev
