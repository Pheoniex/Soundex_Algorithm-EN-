#include <cstring>
#include <cstdio>
#include <cctype>
#include <iostream>

#include <bits/stdc++.h>
using namespace std;


char numch[] = {'a','e','i','o','u','w','h','y','b','f','p','v','c','g','j','k','q','s','x','z','d','t','l','m','n','r'};
int numint[] = {8,8,8,8,8,9,9,9,1,1,1,1,2,2,2,2,2,2,2,2,3,3,4,5,5,6};



void readFile(FILE * fPtr)
{
    char ch;

    do
    {
        ch = fgetc(fPtr);

        putchar(ch);

    } while (ch != EOF);
}


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

char convertToChar(int nch)
{
    char ch;
    ch = nch + '0';

    return ch;
}


void display(char token[4])
{

             ifstream input;
		size_t pos;
              string line;
    int counter=0;
		input.open("test.txt");
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


void soundex_user(char* testword){

    char code[5]={};
    char squeezed[5]={};
    //lower case all alphabets
    for (int i=0; i<strlen(testword); i++)
    {
        testword[i] = tolower(testword[i]);
    }

    //first letter in always kept
    code[0]=squeezed[0]=testword[0];

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
                squeezed[strlen(squeezed)] = testword[i];
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

void soundex(char* testword){

    char code[5]={};
    char squeezed[5]={};
    //lower case all alphabets
    for (int i=0; i<strlen(testword); i++)
    {
        testword[i] = tolower(testword[i]);
    }

    //first letter in always kept
    code[0]=squeezed[0]=testword[0];

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
                squeezed[strlen(squeezed)] = testword[i];
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


    fPtr = fopen("test.txt", "a");
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

void cleanFile(){

    FILE *fPtr;
    char filePath[100];


    fPtr = fopen("test.txt", "w");
    if (fPtr == NULL)
    {

        cout<<"\nUnable to open"<< filePath<<"file.\n";
        exit(EXIT_FAILURE);
    }

    fputs("", fPtr);


    fclose(fPtr);


}


int main()
{
    cout<< "Please WAIT, the Program is Processing !!!\n"<<endl;
    cout<< "****** Your Patience is Appreciated ******"<<endl;


    fstream file;
    string word, t, q, filename;

    filename = "readtxt.txt";
    file.open(filename.c_str());

    cleanFile();
    while (file >> word)
     {
     string s = word;
      int n = s.length();
        char char_array[n + 1];
        strcpy(char_array, s.c_str());
        soundex(char_array);
     }

    cout<<"\nSoundex Lexicon successfully stored\n"<<endl;


    string temp ;
    cout<<"Enter the WORD :: ";

    cin>>temp;

    char testword[temp.length()+1];
    strcpy(testword, temp.c_str());
    soundex_user(testword);


    return 0;
}
