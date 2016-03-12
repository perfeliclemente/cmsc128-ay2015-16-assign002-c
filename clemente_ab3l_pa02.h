int getHammingDistance(char *str1, char *str2);

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