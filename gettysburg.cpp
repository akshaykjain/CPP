#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip> 
using namespace std;

int main()
{
   string file1, line;
   ifstream ipfile;
   ofstream opfile;
   int i = 0;
   int c = 1;
   int amountLine    = 0;
   int amountWord    = 0;
   int amountCh      = 0;
   int amountPunct   = 0;
   int amountSpaces  = 0;
   int amountUcase   = 0;
   int amountLcase   = 0;
     
  // cout <<  " Please enter the name of the file you wish to check" << endl ;
  // cin >> file1;
   file1 = "GettysburgAddress.txt";
   ipfile.open(file1.c_str());
  
   while (getline(ipfile,line)) 
   {
      amountLine++;
      for(i=0; i < line.size(); i++)
  	   {
  	      amountCh++;
  	      
  	      if (islower(line[i]))
  	      {   
  	         amountLcase++;
  	      }  
  	      
  	      else if (isupper(line[i]))
     	   {   
  	         amountUcase++;
  	      }
  	      
  	      else if (ispunct(line[i]))
     	   {
     	      amountPunct++;
  	      }
  	      
  	      else if (isspace(line[i]))
  	      {
  	         amountSpaces++;
  	      }
  	    
         if ((isalpha(line[i])) && (!isalpha(line[i+1])))  	      
  	         amountWord++;
  	   }
   }
   
   cout  << "Statistics for file GettysburgAddress.txt:" << endl << endl
         << "Lines: "               <<  amountLine    << endl
         << "Characters: "          << amountCh       << endl
         << "Words: "               <<   amountWord   << endl
         << "Lower-case letters: "  << amountLcase    << endl
         << "Upper-case letters: "  << amountUcase    << endl
         << "Spaces: "              << amountSpaces   << endl
         << "Punctuation marks: "  << amountPunct    << endl;
         
         
   return 0;
}
     