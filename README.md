# speller_application_data_structures
I attempted to create a speller application which helps the user look up words in 4 different dictionary files (txt files) of different lengths and words. I used the STL Vector as a data structure. STL Vectors are preferable in this case because they are dynamic, unlike arrays. A vector is able to resize itself automatically
when an element is inserted or deleted unlike an array. Also a vector can expand its memory at run time and it is not necessary to know the numbers of words in the dictionary to store them.

My Program consists of two seperate cpp files. The first cpp file contains the main program titles finalone.cpp. It is responsible for the main flow of the program. The second cpp file called myfunctions contains the function definition of the binary search function I created.

My program starts with storing the words from the dictionary into a vector. Then it asks the user for input through a while loop. The input from the user is divided into 4 different cases:

1. If the user searches for a complete word, our program will go to the condition of
searching for a full word (word that doesn't contain a “*” or a “?”). Then it will call the
binary search function for searching through the dictionary. Then the program prints if
the keyword was found or not with the number of comparisons done.

2. If the user searches for a word that has a prefix (indicated with “*”), it calls the binary
search function which takes arguments the list, the prefix which is the letters altogether
from start till the “*” and x which is the location of the “*”.

3. If the user searches for a word that has a “?”, it will call the binary search function which
in this case takes the arguments the list, the prefix which is the letters from start till the
“?” and y which is the location of the “?”.

4. If the user inputs exit or quit the program will terminate.

For the function that searches through the dictionary, I implemented a binary search function
because the data is already sorted. The binary search method is faster than other methods because it
doesn’t search through the whole vectors. It starts in the middle, it compares if the word we are are
looking for is smaller, greater than, or equal to the middle word. If its smaller, it moves the ending to the
middle, excluding the upper half than the middle from searching and searches the lower half.

When the user enters a word with a “*”, the program will find the location of the word and save it in an
integer value x. Then if the integer value x is greater than 0 and x is less than the length of the search
string, then it will store a prefix in a string that starts from the 0 to x (location of the “*”). Then, the
binary search function will be called with arguments (list, prefix and x) to search for the matching word to
the prefix provided by the user. We then create another vector to store the words found, titled “words
Found”. While the substring of the word found matches the prefix, the NumEntries will increase (which is
the words matching in this case). After that, the words found will be printed with the word comparisons
done.

When the user enters a word with a ?, the same algorithmic design is implemented as the “*”. We save the
position of the “?” in an integer value y. The only difference here is that we also create a string titled
suffix to save the search string substring after the “?”.Then we call the binary search function with
arguments (list, prefix and y (location of “?”). While the word in the dictionary matches the prefix and the
suffix then it's a match. The number of entries are printed as well as the words found and the word
comparisons.
