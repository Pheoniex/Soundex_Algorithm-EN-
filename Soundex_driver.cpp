//This Algorithm is made as an assignment project under the guidance of Dr. Rakesh Chandra Balabantaray Sir 

//including header files
#include <cstring>
#include <cstdio>
#include <cctype>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//declaration for grouping of the letters with their respective group as per soundex algorithm.
char numch[] = {'a','e','i','o','u','w','h','y','b','f','p','v','c','g','j','k','q','s','x','z','d','t','l','m','n','r'};
int numint[] = {8,8,8,8,8,9,9,9,1,1,1,1,2,2,2,2,2,2,2,2,3,3,4,5,5,6};

//for reading file
void readFile(FILE * fPtr)
{
    char ch;

    do
    {
        ch = fgetc(fPtr);

        putchar(ch);

    } while (ch != EOF);
}

//grouping the letters with their numeric group as per soundex rules
int groupnum (char s)
{
    for (int i=0; i<26 ; i++)
    {
        if(s==numch[i])
        {
           return numint[i];
        }
    }return -1;
}

//to convert all the letters to lower case
char convertToChar(int nch)
{
    char ch;
    ch = nch + '0';

    return ch;
}

//to search for the words with similar soundex code in the data base and display them
void display(char token[4])
{

             ifstream input;
		size_t pos;
              string line;
    int counter=0;
		input.open("Lexicon.txt");
		if(input.is_open())
		{
			while(getline(input,line))
			{
			  if (line.find(token) != string::npos) {
          if(counter == 0)
          {
            cout<<"the user may mean: \n";
            counter++;
          }

          for(pos=5 ; pos<line.length();pos++){
              cout<<line[pos];
            }cout<<endl;



        }
    }


}

}

//for converting the user query word into a soundex code
void soundex_user(char* testword){

    char code[5]={};
    //lower case all alphabets
    for (int i=0; i<strlen(testword); i++)
    {
        testword[i] = tolower(testword[i]);
    }

    //first letter in always kept
    code[0]=testword[0];

    int prev = groupnum(code[0]);
    int c=0;

    for(int i =1; i<strlen(testword); i++)
    {
        //if empty or invalid testword
        if (prev==-1)
        {
            cout<<"invalid input\n";
            exit;
        }
        int nch = groupnum(testword[i]);//Getting numeric Value

        if (nch==8)
        {
            c = 1;
        }
        if((nch!=9 && nch!=prev && nch!=8)||(c==1 && nch!=9 && nch!=8)) //to keep or exclude
        {
            if(strlen(code)<4)//only 4 chars
            {   c=0;
                code[strlen(code)] = convertToChar(nch);
                prev = nch;
            }else
            {
                break;
            }
        }
    }
    while(strlen(code)<4)
    {
        code[strlen(code)] = '0';
    }
    cout<<code;
    display(code);

}

//for converting the words from a file into soundex code and then writing into another file the soundex code and word pair
void soundex(char* testword){

    char code[5]={};
    
    //lower case all alphabets
    for (int i=0; i<strlen(testword); i++)
    {
        testword[i] = tolower(testword[i]);
    }

    //first letter in always kept
    code[0]=testword[0];

    int prev = groupnum(code[0]);
    int c=0;
    for(int i =1; i<strlen(testword); i++)
    {
        //if empty or invalid testword
        if (prev==-1)
        {
            cout<<"invalid input\n";
            exit;
        }
        int nch = groupnum(testword[i]);//Getting numeric Value
        if (nch==8)
        {
            c = 1;
        }
        if((nch!=9 && nch!=prev && nch!=8)||(c==1 && nch!=9 && nch!=8)) //to keep or exclude
        {
            if(strlen(code)<4)//only 4 chars
            {   c=0;
                code[strlen(code)] = convertToChar(nch);
                prev = nch;
            }else
            {
                break;
            }
        }
    }
    while(strlen(code)<4)
    {
        code[strlen(code)] = '0';
    }

    FILE *fPtr;
    char filePath[100];


    fPtr = fopen("Lexicon.txt", "a");
    if (fPtr == NULL)
    {

        cout<<"\nUnable to open"<< filePath<<"file.\n";
        exit(EXIT_FAILURE);
    }
    fputs(code, fPtr);
    fputs(" ", fPtr);

    fputs(testword, fPtr);

    fputs("\n", fPtr);

    fclose(fPtr);


}


//so that every time the programme runs there are no two instances of the same lexicon
void cleanFile(){

    FILE *fPtr;
    char filePath[100];


    fPtr = fopen("Lexicon.txt", "w");
    if (fPtr == NULL)
    {

        cout<<"\nUnable to open"<< filePath<<"file.\n";
        exit(EXIT_FAILURE);
    }

    fputs("", fPtr);


    fclose(fPtr);


}

//driver code to initialise the lexicon then asking and comparing the user input with the soundex lexicon and displaying the matched words
int main()
{
    cout<< "Please WAIT, the Program is Processing !!!\n"<<endl;
    cout<< "*******Your Patience is Appreciated ******"<<endl;

    //reading from the file readtxt.txt	
    fstream file;
    string word, t, q, filename;

    filename = "readtxt.txt";
    file.open(filename.c_str());

    cleanFile();
     //writing into lexicon.txt
    while (file >> word)
     {
     string s = word;
      int n = s.length();
        char char_array[n + 1];
        strcpy(char_array, s.c_str());
        soundex(char_array);
     }

    cout<<"\nSoundex Lexicon successfully stored\n"<<endl;

     //asking for user input
    string temp ;
    cout<<"Enter the query WORD :: ";

    cin>>temp;

    char testword[temp.length()+1];
    strcpy(testword, temp.c_str());
    soundex_user(testword);


    return 0;
}
