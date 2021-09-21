#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <array>
#include "myfunction.h"

using namespace std;


 void binarySearch(vector <string> list, string searchString, int len)
 {
 		int middle;
		int first=0;
		int leng=list.size();
		int last=leng-1;
		bool found=false;
		int steps=0;

		while (first<last)
		{
			middle=first+(last-first)/2;
			steps++;

            string dictWord = list[middle].substr(0,len);

            if (dictWord<searchString)
                first=middle+1;
            else if (dictWord>searchString)
                last=middle-1;
            else if (dictWord==searchString){
                last=middle;
            }

        }
        if (list[first].substr(0,len)==searchString)
            int positionFound=first;
}



