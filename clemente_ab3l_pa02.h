int getHammingDistance(char *str1, char *str2);

int getHammingDistance(char *str1, char *str2){							
	int i = 0;
	int acc = 0;
	int str1Len = strlen(str1);
	int str2Len = strlen(str2);
	
	if ((str1Len == str2Len) && (str1Len > 0) && (str2Len > 0)){			
		
		for (i = 0; i < str1Len; i++){								
			if (str1[i] != str2[i]){
				acc++;
			}		
		}
		
		printf("Hamming Distance: %i\n", acc);											
		return acc;	
		
	}else{														
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