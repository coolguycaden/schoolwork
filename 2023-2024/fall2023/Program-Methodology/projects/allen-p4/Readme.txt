Caden Allen
C27114928
caden3@clemson.edu

The necessary steps to run and compile this project is pretty simple. Use the make command to compile the code. 
Then, run ./PhoneNum.exe -h to understand more indepth on what to do. You can pass in input files to decode or encode,
and output files to store the encoded/decoded info. There is an issue with my code, one well-known by Henry and Jack. 
For some reason, the code breaks when I free the memory allocated to decodedWord in my toWord function. I commented out
the free statement, please be lenient with point loss.
