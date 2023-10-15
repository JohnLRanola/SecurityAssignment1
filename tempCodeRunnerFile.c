 for (i = 0, j = 0; i < inputLength; ++i) {

        char curChar = input[i];

         if ((curChar >= 'a' && curChar <= 'z') || (curChar >= 'A' && curChar <= 'Z')) {
            char base = (curChar >= 'a' && curChar <= 'z') ? 'a' : 'A';
            input[i] = (curChar + keyword[j] - 2 * base) % 26 + base;
            ++j;

            if (j == keywordLength) {
                j = 0; 
            }
         }