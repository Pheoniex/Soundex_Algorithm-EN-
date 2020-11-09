# Soundex_Algorithm-EN-
This is an algorithm to find the soundex code of a word and then match it with it's homophones(i.e words with same soundex code)


Description:
This repository includes a Driver Function and Two Text files.

The Driver function(Soundex_driver.cpp) does the following thing:
           #It reads from the text file named as "readtxt.txt".
           #It convert each word into their soundex codes.
           #it writes the words and the soundex code as a pair in another file named as "Lexicon.txt".
           #It asks the user to give an input(string).
           #It converts the input into it's soundex code and compares it with the codes from the lexicon
           #Upon finding the same soundex code it displays the word it is paired with as a alternative to user's input
           
           
Note:      
#Please Note that it takes 6-7 mins or less to initialise the lexicon which it does every time it runs.
#PLease Note that any input other than alphabets is considered invalid.
#Please Note that only a single word could be checked in one instance rather a line.



What to ADD:
#We could make use of other algorithms such as edit distance and such to determine most probable alternatives to our query and thus decreasing 
#The number of suggestions that are displayed per query and also make more accurate.
#We could make a function to update the lexicon rather than reinitialising every time also it could be made optional.
#We could try to make the programme work for a string (group of words containg any charachters).




