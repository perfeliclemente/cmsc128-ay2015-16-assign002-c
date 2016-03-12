int getHammingDistance(char *str1, char *str2);
int countSubstrPattern(char *original, char *pattern);
int isValidString(char *str1, char *str2);
int getSkew(char *str, int n);
int getMaxSkewN(char *str, int n);

int getHammingDistance(char *str1, char *str2){							// This function gets the hamming distance of 2 strings.
	int i = 0;
	int acc = 0;
	int str1Len = strlen(str1);
	int str2Len = strlen(str2);
	
	if ((str1Len == str2Len) && (str1Len > 0) && (str2Len > 0)){			// This checks if the inputs are in a valid form.
		
		for (i = 0; i < str1Len; i++){								// This is a loop for checking if there are inversions in every character in the two string.
			if (str1[i] != str2[i]){
				acc++;
			}		
		}
		
		printf("Hamming Distance: %i\n", acc);											// This returns the number of inversions between two strings.
		return acc;	
		
	}else{														// This consists of the conditions not met for the function.
		if (str1Len != str2Len){
			printf("Strings are not equal!\n");
			return -1;
		}
		
		if (str1Len <= 0){
			printf("Str1 is invalid!\n");
			return -1;
		}
		
		if (str2Len <= 0){
			printf("Str2 is invalid!\n");
			return -1;
		}
	}	
}


int countSubstrPattern(char *original, char *pattern){						// This function counts the occurences of the string pattern from the original string.
	int i = 0;
	int j = 0;
	int flag = 0;
	int acc = 0;
	int originalLen = strlen(original);
	int patternLen = strlen(pattern);
	
	if ((originalLen > 0) && (patternLen > 0) && originalLen >= patternLen){	// This checks of the conditions are met for the function to process the inputs.
		for(i = 0; i < originalLen; i++){								// This loop traverses through the original string.
			
			for (j = 0;j < patternLen; j++){							// This loop traverses through the string pattern and checks if the pattern is a substring of the original
			
				if (original[i+j] != pattern[j]){
					flag = 1;
				}	
			
			}
			
			if (flag == 0){										// Flag for having substring.
				acc++;
			}else {
				flag = 0;
			}
		}
		
		printf("Count: %i\n", acc);
		return acc;
			
	}else{														// These are manifestations that the inputs may be valid.
		
		if (originalLen <= 0){
			printf("Original str is invalid!\n");
			return -1;
		}
		
		if (patternLen <= 0){
			printf("Pattern str is invalid!\n");
			return -1;
		}
		
		if (originalLen < patternLen){
			printf("0");
			return 0;
		}
	}	
}

int isValidString(char *str, char *alphabet){							// This function checks if a string is valid based on the alphabet given.
	int i = 0;
	int j = 0;
	int acc = 0;
	
	int strLen  = strlen(str);
	int alphabetLen = strlen(alphabet);
	int flag = 0;
	int validFlag = 0;
	
	for (i = 0; i < alphabetLen; i++){									// This loop checks if the alphabet consists of unique characters.
		for (j = 0; j < alphabetLen; j++){
			if(alphabet[i] == alphabet[j]){
				acc++;
			}
			
		}
		if (acc > 1){
			flag = 1;
		}
		acc = 0;
	}
	
	acc = 0;
	
	if (flag == 0){												// Checks if alphabet is valid.
		
		for (i = 0; i < strLen; i++){									// This loop checks if all the characters in the input string is present in the alphabet.
			for (j = 0; j < strLen; j++){								// This loop traverses through the alphabet for checking the presence of sppecific character from string.
				if(str[i] == alphabet[j]){
					acc++;
				}	
			}
			
			if (acc > 0){
				validFlag = 1;
			}else {
				validFlag = 0;
			}
			
			acc = 0;
		}
	
	
		if (validFlag == 0){										// These are conditions met.
			printf("Invalid!\n");
			return -1;
		}else {
			printf("Valid!\n");
			return 1;
		}
		
	}else{
		printf("Invalid Alphabet!\n");
	}
	
	
}

int getSkew(char *str, int n){										// This function gets the skew of a string based on n.
	int i = 0;
	int skew = 0;
	int strLen = strlen(str);
	
	
	if ((strLen > 0) && strLen >= n){				
		for (i = 0; i <= n-1; i++){									// This loop traverses the string to checks if there are G's (skew++), and C's (skew--).
			if (str[i] == 'G'){
				skew++;
			}
			if (str[i] == 'C'){
				skew--;
			}
		}
		printf("Skew in %i: %i\n", n, skew);
		return skew;
	
	}else {														// These are conditions met.
		if(strLen <= 0){
			printf("Invalid String.\n");
			return -1;
		}
		
		if (strLen < n){
			printf("Invalid n.\n");
			return -1;
		}
	}	
}

int getMaxSkewN(char *str, int n){										// This function gets the maximum skew with a input range.
	int i = 0;
	int maxSkew = 0;
	int j = 0;
	
	for(i = 1; i < n+1; i++){										// This loop utilizes the former function (getSkew()).
		j = getSkew(str, i);
		
		if (j > maxSkew){											// Updates when there is a skew more than present value of maxSkew.
			maxSkew = j;
		}		
	}
	printf("MAX SKEW: %i\n", maxSkew);
	return maxSkew;

}