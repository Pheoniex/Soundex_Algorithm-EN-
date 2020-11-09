# Soundex_Algorithm-EN-
This is an algorithm to find the soundex code of a word and then match it with it's homophones(i.e words with same soundex code)

           We created this repository to show how the words are converted into soundex codes and also to show how phonetically same words are matched.
           To show this we tried to make a soundex lexicon which holds the soundex codes for few words and compare them with the imput word and try to provide a phonetically same word.

RULES OF SOUNDEX ALGORITHM FOR ENGLISH LANGUAGE:

           #1 Retain the first letter of the name and drop all other occurrences of a, e, i, o, u, y, h, w.
           #2 Replace consonants with digits as follows (after the first letter):
                b, f, p, v → 1                                             || The letters having similar pronounciation are grouped together in 
                c, g, j, k, q, s, x, z → 2                                 || the same numeric group and are categorised by the same number.
                d, t → 3                                                   ||
                l → 4                                                      || The vowels being too fluid and the silent letters  'h' , 'w' , 'y' are neglected from the code
                m, n → 5                                                   || code
                r → 6                                                      ||
           #3 If two or more letters with the same number are adjacent in the original name (before step 1), only retain the first letter; also two letters with the same number
                separated by 'h' or 'w' are coded as a single number, whereas such letters separated by a vowel are coded twice. This rule also applies to the first letter.
           #4 If you have too few letters in your word that you can't assign three numbers, append with zeros until there are three numbers. If you have four or more numbers,
                retain only the first three.
                



Description:                                                                                            
This repository includes a Driver Function and Two Text files.

The Driver function(Soundex_driver.cpp) does the following thing:

           # It reads from the text file named as "readtxt.txt".
           # It convert each word into their soundex codes.
           # It writes the words and the soundex code as a pair in another file named as "Lexicon.txt".
           # It asks the user to give an input(string).
           # It converts the input into it's soundex code and compares it with the codes from the lexicon
           # Upon finding the same soundex code it displays the word it is paired with as a alternative to user's input
           
           
Note:   

           #Please Note that it takes 6-7 mins or less to initialise the lexicon which it does every time it runs.
           #PLease Note that any input other than alphabets is considered invalid.
           #Please Note that only a single word could be checked in one instance rather a line.



What we can ADD:

           # We could make use of other algorithms such as edit distance and such to determine most probable alternatives to our query and thus decreasing 
           # The number of suggestions that are displayed per query and also make more accurate.
           # We could make a function to update the lexicon rather than reinitialising every time also it could be made optional.
           # We could try to make the programme work for a string (group of words containg any charachters).




