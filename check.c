#include <stdio.h>
#include <stdlib.h>
// check for mutiple expressions
int m_expression(char word[]){
	int expression =0;
	int length =0;
	while(word[length]!= '\0'){
		if(word[length] == ';'){
			expression ++;
		}
		length ++;

	}
	return expression+1;

}
//Gets the length of a string
int strlength(char *word){
        int length =0;
        while(word[length] != '\0'){
                length++;
        }
        return length;
}
int counter(char word[], int length){
	int i =0;
	int count =0;
	
	for(i =0; i<length;i++){
		if(word[i] ==' '){
			count++;
		}

	}
	return count+1; 

}
char ** alot_expressions(char *word){
        int length = strlength(word)+1;
	word[length] = '\0';       
        //char * expression = array(word);
        int charNum =0;
        int word_num = 0;
        int count = m_expression(word);
        char **token_expressions  = malloc(count * sizeof(char*));
        int i =0;
        for(i =0; i <count; i++){
                token_expressions[i] = malloc(length * sizeof(char*));

        }
      
        i=0;
        for(i =0; i < length; i++){
                        if(word[i] != ';'){
                                token_expressions[word_num][charNum]= word[i];
                                
                                charNum ++;
                        }
                        else {
                                if(token_expressions[word_num][charNum-1] != '\0'){
                                        token_expressions[word_num][charNum] = '\0';             
                                        word_num++;
                                        charNum =0;
                                }
                        }

      	}
        return token_expressions;

}
//this tokenizes each expression
char ** token_expression(char *word){
	int length = strlength(word);
	word[length] = '\0';
	int charNum =0;
	int word_num =0;
	int count = counter(word,length);
	char ** token_array = malloc(count*sizeof(char*));
	int i =0;
	for(i =0; i< count; i++){
		token_array[i]=malloc(length*sizeof(char*));
	}
	i =0;
	for(i =0; i < length; i++){
		if(word[i] != ' '){
			token_array[word_num][charNum]= word[i];
			charNum++;
		}
		else if(word[i] == ' ' && word[i-1] == ' ' ){
			word_num++;
			token_array[word_num][charNum] == word[i];
			charNum = 0;;
		}
		else{
			if(token_array[word_num][charNum-1]!='\0'){
				token_array[word_num][charNum]= '\0';
				word_num++;
				charNum=0;

			}
			

		}

	}
	return token_array;

}
//compares a strings ascii vales
int strcompare(char ** word,int size){
	int words = 0;
	int and =211 ;
	int or = 161;
	int not = 241 ;
	int i =0;
	int j =0;
	int p =0;
	int total =0;
	//printf("%d\n",size);
			while(i<size){
				for(j =0; j<(sizeof(word[i])/sizeof(word[i][0]));j++){
					total+= word[i][j];
				}
				if(total == and|| total == or|| total == not){
					words =1;
					break;
				}
				else{
					words = 0;
				}
				total =0;
				i++;
		

		}
	
	if(size == 2){
		for(i = 0; i < size; i++){
			
				while(p < size){
					for(j =0; j<(sizeof(word[i])/sizeof(word[i][0])); j++){
						total+=word[p][j];
					}
					if(total == and || total == or|| total == not){
						words = 1;
						break;
					}
					p++;
				}
			


		}
	}
	
	if(size == 3){
		for(i =0; i <size; i++){
			
				while(p<size){
					
					for(j =0; j < (sizeof(word[i])/sizeof(word[i][0])); j++){
						total+=word[p][j];
					}
					for(j =0; j < (sizeof(word[i])/sizeof(word[i][0])); j++){
						total+=word[p][j];
					}
					if(total == and || total == or || total == not){
						words = 1;
						break;

					}			
					p++;
				}

			
		}

	}
	return words;
}// end of function

//adds up ascii values of word and comapres it to the ascii values of AND NOT OR, reuturns 1 if true
int is_logic(char *word){
	int count = 0;
	int and = 211;
	int or = 161;
	int not = 241;
	int total =0;
	int i =0;
	int j =0;

	while(word[i] != '\0'){
		total += word[i];
		i++;
	}
	
	
	if(total == and || total == or){
			count = 1;
			
	}
	
	return count;
}// end of function

//adds up the strings ascii values and compares it to the ascii value of NOT, returns 1 if true
int is_not(char * word){
	int total = 0;
	int not = 241;
	int count = 0;
	int i = 0;
	while(word[i] != '\0'){
		total+= word[i];
		i++;
	}
	if(total == not){
		count = 1;
	}
	return count;
}// end of function

//adds up the strring's ascii values and compares it to ascii value of true false, returns 1 if true
int logic_check(char * word){
	int correct = 0;
	int i = 0;
	int true1 = 448;
	int false1 = 523;
	int total =0;
	while(word[i] != '\0'){
		total+= word[i];
		i++;

	}
	if(total == true1 || total == false1){
		correct =1;
	}
	return correct;
}// end of function

// comparese charachter ascii values
int is_number(char word){
	int correct =0;
	if(word == '1'|| word == '2' || word == '3' || word == '4' || word == '5' || word == '6' || word == '7' || word == '8' || word == '9' || word == '0'){
		correct =1;
	}
	return correct;
}// end of function

//compares character ascii values
int is_letter(char word){
	int correct =0;
	if(word == 'a'|| word == 'N'|| word == 'b' || word == 'c' || word == 'e' || word == 'f' || word == 'g'|| word == 'h' || word == 'i' || word == 'j' || word == 'k'|| word == 'l'|| word == 'm' || word == 'n' ||word == 'o'|| word == 'p'|| word == 'q'|| word == 'r'|| word == 's'|| word == 't'|| word == 'u'|| word =='v'|| word == 'w' ||word == 'x'||word == 'y'||word == 'z'|| word == 'A' ||word == 'B' ||word =='C' ||word == 'D' ||word == 'E' ||word == 'F' ||word == 'G' || word == 'H'||word == 'I' ||word == 'J' ||word =='K' ||word =='L' ||word == 'M' ||word == 'O' ||word == 'P' || word == 'Q' ||word == 'R' ||word == 'S'|| word == 'T' ||word == 'U' || word == 'V' ||word == 'W' ||word ==  'X' ||word ==  'Y' ||word == 'Z'||word == '!'||word == '@'||word == '#'||word == '$' ||word == '%' ||word ==  '^'||word == '&' ||word == '(' ||word == ')' ||word =='`' ||word == '~' ||word == '_' ||word == '=' ||word == '<' ||word == ',' ||word == '.' ||word =='?' ||word == ':'){
		correct =1;
	}
	return correct;

}//end of function

//Detects errors in a logic expression, returns 1 if expression is incorrect
int logic_setup(char ** word, int size,char * word2, int count,int place,int count1,int on){
	int correct =0;
	int i = 0;
	int location = 0;
	// for loop used to find the location of the operator
	for(i = 0; i < count; i++){
		if(is_logic(word[i]) == 1 || is_not(word[i]) == 1){
			location = i;
			break;
		}
		//checks to see if white space befor expression is thier
		if(word[i][0] == '\0' && on == 0){
			printf("Error: Parse error in expression %d: unknown identifier\n\"%s\"\n",place,word[i]);
		}
	}
	i =0;
	if(on == 1){
		//The rest of these if statements check for errors in expression
		if(word2[0] != ' '){
			printf("Parse error in expession %d: incomplete expression\n\"%s\"\n",place,word2);
		}
		for(i =0; i < size; i++){
			if(word2[i] == ' ' && i != 0){
				printf("Error: Parse error in expression %d: unknown identifier\n\"%c\"\n",place,word2[i]);
			}
			if(word2[i] != ' '){
				break;
			}
		}
	}
	if(count1 <= 2 ){
		;
		// true AND
		if(location != 0 ){
			if(is_logic(word[location]) ==1 && logic_check(word[location-1]) == 1){
				printf("Error: Parse error in expression %d: missing operand\n\"%s\"\n",place,word[location-1]);
				return correct;
			}
			//1 AND
			if(is_logic(word[location]) == 1 && is_number(word[location-1][0]) == 1){
				printf("Error: Parse error in expression %d: type mismatch\n\"%s\"\n",place,word[location-1]);
				printf("Error: Parse error in expression %d: unexpected operator\n\"%s\"\n",place,word[location]);
				correct = 1;
				return correct;
			}
			//a AND
			if(is_logic(word[location]) == 1 && is_letter(word[location-1][0]) == 1 && logic_check(word[location-1])!=1){
				printf("Error: Parse error in expression %d: unknown identifier\n\"%s\"\n",place,word[location-1]);
				printf("Error: Parse error in expression %d: unexpected operator\n\"%s\"\n",place,word[location]);
				correct = 1;
				return correct;
			}
			//1 NOT
			if(is_not(word[location]) == 1 && is_number(word[location-1][0]) == 1){
				printf("Error: Parse error in expression %d: type mismatch \n\"%s\"\n",place,word[location-1]);
				correct = 1;
				return correct;
			}
			// a NOT
			if(is_not(word[location]) == 1 && is_letter(word[location -1][0])== 1 && logic_check(word[location-1])!=1 ){
				printf("Error: Parse error in expression %d: unknown identifier\n\"%s\"\n",place,word[location-1]);
				correct = 1;
				return correct;
			}
		}
		
		if(count1 <=2){	//AND true
			if(is_logic(word[location]) == 1 && (logic_check(word[location+1]) == 1|| is_number(word[location+1][0])==1 || is_letter(word[location+1][0]) == 1)){
				printf("Error: Parse error in expression %d: unexpected operator\n\"%s\"\n",place,word[location]);
				correct = 1;
				return correct;
			}
			//NOT 1
			if(is_not(word[location]) == 1 && is_number(word[location+1][0]) == 1){
				printf("Error: Parse error in expression %d: type mismatch\n\"%s\"\n",place,word[location+1]);
				correct = 1;
				return correct;
			}
			//NOT a
			if(is_not(word[location]) == 1 && logic_check(word[location+1]) != 1 && is_letter(word[location+1][0]) == 1){
				printf("Error: Parse error in expression %d: unknown operand\n\"%s\"\n",place,word[location+1]);
				correct = 1;
				return correct;

			}
		}
		
	}
	if(count1 >= 3){
		if(is_not(word[location]) == 1 && word[location+1][0] == '\0'){
			printf("Error: Parse error iin expression %d: unkown operand \n\"%s\"\n",place,word[location+1]);
			return 1;
		}
		//1 NOT true/false
		if(is_not(word[location]) == 1 && is_number(word[location-1][0]) == 1 && logic_check(word[location+1]) == 1){
			printf("Error: Parse error in expression %d: type mismatch \n\"%s\"\n",place,word[location-1]);
			correct = 1;
			return correct;

		}
		//true NOT 1
		if(is_not(word[location]) == 1 && is_number(word[location+1][0]) == 1 && logic_check(word[location-1]) == 1){
			printf("Error: Parse error in expression %d: unexpected operand\n\"%s\"\n",place,word[location+1]);
			printf("Error: Parse error in expression %d: type mismatch\n\"%s\"\n",place,word[location-1]);
			correct = 1;
			return correct;
		}
		//1 NOT 1
		if(is_not(word[location]) == 1 && is_number(word[location+1][0]) == 1 && is_number(word[location-1][0]) == 1){
			printf("Error: Parse error in expression %d: type mismatch\n\"%s,%s\"\n",place,word[location-1],word[location+1]);
			correct = 1;
			return correct;
		}
		//a NOT true/false
		if(is_not(word[location]) == 1 && is_letter(word[location-1][0]) == 1 && logic_check(word[location+1]) == 1 && logic_check(word[location-1])!=1){
			printf("Error: Parse error in expression %d: unkown identifier\n\"%s\"\n",place,word[location-1]);
			correct = 1;
			return correct;
		}
		//true NOT a
		if(is_not(word[location]) == 1 && is_letter(word[location+1][0]) == 1 && logic_check(word[location-1]) == 1 && logic_check(word[location+1])!=1){
			printf("Error: Parse error in expression %d: unknown operand\n\"%s\"\n",place,word[location+1]);
			printf("Error: Parse error in expression %d: unexpected operand\n\"%s\"\n",place,word[location-1]);
			correct = 1;
			return correct;
		}
		// a NOT a
		if(is_not(word[location]) ==1 && is_letter(word[location-1][0])== 1 && logic_check(word[location-1])!= 1 && is_letter(word[location+1][0]) == 1 && logic_check(word[location+1])!=1){
			printf("Error: Pparse error in expression %d: unknown identifier \n\"%s\"\n",place,word[location-1]);
			printf("Error: Parse error in expression %d: unknown identfier \n\"%s\"\n",place,word[location+1]);
			correct = 1;
			return correct;
		}
		//true AND a
		if(is_logic(word[location]) == 1 && logic_check(word[location-1]) == 1 && is_letter(word[location +1][0]) == 1 && logic_check(word[location+1])!=1){
			printf("Error: Parse error in expression %d: unknown operand\n\"%s\"\n",place,word[location+1]);
			correct = 1;
			return correct;
		}
		//a AND a
		if(is_logic(word[location]) == 1 && is_letter(word[location+1][0]) == 1 && logic_check(word[location+1])!= 1 && is_letter(word[location-1][0]) == 1 && logic_check(word[location-1])!=1){
			printf("Error: Parse error in expression %d: unknown identifier \n\"%s\"\n",place,word[location-1]);
			printf("Error: Parse error in expression %d: unexpected operator\n\"%s\"\n",place,word[location]);
			correct = 1;
			return correct;
		}
		//1 AND 1
		if(is_logic(word[location]) == 1 && is_number(word[location+1][0]) == 1 && is_number(word[location-1][0]) == 1){
			printf("Error: Parse error in expression %d: type mismatch\n\"%s,%s\"\n",place,word[location-1],word[location+1]);
			printf("Error: Parse error in expression %d: unexpected operator\n\"%s\"\n",place,word[location]);
			correct = 1;
			return correct;
		}
		//a AND 1
		if(is_letter(word[location-1][0]) == 1 && logic_check(word[location-1])!=1 && is_logic(word[location]) == 1 && is_number(word[location+1][0]) == 1){
			printf("Error: Parse error in expression %d: unknown identifier\n\"%s\"\n",place,word[location-1]);
			printf("Error: Parse error in expression %d: unexpected operator\n\"%s\"\n",place,word[location]);
			printf("Error: Parse error in expression %d: type mismatch\n\"%s\"\n",place,word[location+1]);
			correct = 1;
			return correct;
		}
		//1 AND a
		if(is_letter(word[location+1][0]) == 1 && logic_check(word[location+1])!=1 && is_logic(word[location]) == 1 && is_number(word[location-1][0]) == 1){
			printf("Error: Parse error in expression %d: unknown identifier\n\"%s\"\n",place,word[location+1]);
			printf("Error: Parse error in expression %d: unexpected operator\n\"%s\"\n",place,word[location]);
			printf("Error: Parse error in expression %d: type mismatch\n\"%s\"\n",place,word[location-1]);
			correct = 1;
			return correct;
		} 
		//true AND 1
		if(is_logic(word[location]) == 1 && logic_check(word[location -1]) == 1 && is_number(word[location+1][0]) == 1){
			printf("Error: Parse error in expresion %d: type mismatch\n\"%s\"\n",place,word[location+1]);
			correct = 1;
			return correct;
		}
		//1 AND true
		if(is_logic(word[location]) == 1 && logic_check(word[location +1]) == 1 && is_number(word[location-1][0]) == 1){
			printf("Error: Parse error in expresion %d: type mismatch\n\"%s\"\n",place,word[location-1]);
			correct = 1;
			return correct;
		}
		
		if(word[location +1][0] == '\0'){
			printf("Error: Parse error in expresson %d: unkown operator \n\"%s\"\n",place,word[location +1]);
			correct = 1;
			return correct;
		}
		
	}
	
	return correct;	
}//end of function

//flag to determin if arithmetic operator exits
int is_arithmetic(char ** word, int size){
	int count =0;
	int i =0;
	int j =0;
	for(i =0; i <=size-1;i++){
		for(j =0; j <(sizeof(word[i])/sizeof(word[i][0]));j++){
			if(word[i][j] == '+'|| word[i][j]== '-' || word[i][j]== '*' ||word[i][j]=='/'){
				count = 1;
				
			}
		
		}
	}
	return count;
}// end of function

//counting the number of arithmetic operators 
int is_arith(char word){
	int count =0;
	if(word == '+'|| word == '-' || word == '*' || word == '/'){
		count = 1;

		}

	return count;

}// end of function

//checking if the arithmetic expression is correct, return 1 if not incorrect
int arithmetic_setup(char ** word, int size,char *word2, int place, int count1,int length,int on){
	int correct =0;
	int i =0;
	int j =0;
	int count2 = 0;
	int count = 0;
	int num = 0;
	int location = 0;
	for(j = 0; j < size; j++){
		if(is_arith(word2[j]) == 1){
			location = j;
		}
			
	}
	j =0;
	int location2 = 0;
	for(j = 0; j< count1; j++){
		if(is_arith(word[j][0]) == 1){
			location2 = j;	
			
		}
		if(word[j][0] == '\0' && on!=1){
			printf("Error: Parse error in expression %d: unknown identifier\n\"%s\"\n",place,word[j]);
		}

	}
	if(on == 1){
		if(word2[0] != ' '){
			printf("Error: Parse error in expression %d: incomplete expression\n\"%s\"\n",place,word2);
		}
		//j =1;
		for(j = 0; j < size; j++){
			if(word2[j] == ' ' && j!=0){
				printf("Error1: Parse error in expression %d: unknown identifier\n\"%c\"\n",place,word2[j]);
				
			}
			if(word2[j]!= ' '){
				break;
			}
		}
	}
	j = 0;
	// deals with the 1 +
	if(location2 == count1-2 && length != 1 && location2 != 0 ||(is_arith(word[1][0]) == 1 && count1 == 2 && length!=1 && location2 != 0 )){
		//modifications hear
		if(count1 > 2){
			if(is_number(word[location2 -1][0]) == 1 && is_number(word[location2 +1][0]) != 1 && logic_check(word[location2+1])!=1 && is_letter(word[location2+1][0])!=1){
				printf("Error: Parse error in expresion %d: missing operand after \n\"%s\"\n",place,word[location2]);
			}
		}
		if(count1 == 2 && is_number(word[location2-1][0]) == 1){
			printf("Error: Parse error in expression %d: missing operand after \n \"%s\"\n",place,word[location2]);
		}
		if(count1 < 3){
			if(is_letter(word[location2 -1][0]) == 1 && logic_check(word[location2-1]) !=1){
				printf("Error: Parse error in expression %d: unknown identifier\n\"%s\"\n",place, word[location2-1]);
				printf("Error: Parse error in expression %d: unexpected operator\n\"%s\"\n",place,word[location2]);
				correct = 1;
			}
		}
		if(count1 < 3){
			if(logic_check(word[location2-1])== 1){
				printf("Error: Parse error in expression %d: type mismatch\n\"%s\"\n",place,word[location2-1]);
				correct = 1;
			}
		}
	}
	//deals with the + 2
	if((location != size-1 && length > 1 && length < 3 )|| (location == 0 && length > 1 && length < 3)){
		if(is_number(word[location2+1][0]) == 1){
			printf("Error: Parse error in expression %d: unexpected operator\n\"%s\"\n",place,word[location2]);
			correct = 1;
		}
		if(is_letter(word[location2+1][0]) == 1 && logic_check(word[location2+1]) != 1){
			printf("Error: Parse error in expression %d: unexpected operator\n\"%s\"\n",place,word[location2]);
			printf("Error: Parse error in expression %d: unknown operator\n\"%s\"\n",place,word[location2+1]);
			correct = 1;
		}
		if(logic_check(word[location2+1]) == 1){
			printf("Error: Parse error in expression %d: unexpecter operator\n\"%s\"\n",place,word[location2]);
			printf("Error: Parse error in expression %d: type mismatch\n\"%s\"\n",place,word[location2+1]);
			correct = 1;
		}	
	}
	//deals with the true + false
	if(length >= 3 ){
		//deals with mistypes
		if(logic_check(word[location2 -1]) == 1 && logic_check(word[location2 +1]) != 1){
			printf("Error: Parse error in expression %d: operand type mismatch\n\"%s\"\n",place,word[location2 - 1]);
			correct = 1;

		}
		//deals with mistypes
		if(logic_check(word[location2 +1]) == 1 && logic_check(word[location2 -1]) != 1){
			printf("Error: Parse error in expression %d: operand type mismatch\n\"%s\"\n",place,word[location2 +1]);
			correct = 1;

		}
		//deals with mistypes
		if(logic_check(word[location2 + 1]) == 1 && logic_check(word[location2 -1]) == 1){
			printf("Error: Parse error in expression %d: operand type mismatch\n \"%s\" and \"%s\"\n",place,word[location2 + 1],word[location2 -1]);
			printf("Error: Parse error in expression %d: operator type mismatch\n \"%s\"\n",place,word[location2]);
			correct = 1;
		}
		//deals with unknown operand 1 + q
		if(is_letter(word[location2+1][0]) == 1 && logic_check(word[location2+1])!=1 && is_number(word[location2-1][0]) == 1){
			printf("Error: Parse error in expression %d: unkown operand\n\"%s\"\n",place,word[location2+1]);
			correct = 1;
		}
		if(is_letter(word[location2-1][0]) == 1 && logic_check(word[location2-1])!= 1 && is_number(word[location2+1][0])==1){
			printf("Error: Parse error in expression %d: unknown identifier\n\"%s\"\n",place,word[location2-1]);
			printf("Error: Parse error in expresion %d: unexpected operator\n\"%s\"\n",place,word[location2]);
			correct = 1;	
		}
		//deals with 2 unknown operands q + q
		if(is_letter(word[location2+1][0]) == 1 && logic_check(word[location2+1])!= 1 && is_letter(word[location2-1][0]) ==1 && logic_check(word[location2-1]) != 1){
			printf("Error: Parse error in expression %d: unknown identifier\n \"%s\"\n",place,word[location2-1]);
			printf("Error: Parse error in expresion %d: unexpected operator\n\"%s\"\n",place,word[location2]);
			printf("Error: Parse error in expression %d: unknown operand \n\"%s\"\n",place,word[location2 +1]);
			correct = 1;
		}
	
	}
		
	
	return correct;

}// end of function
//deals with input that dose not conatin an operator such as scan errors or empty input
int unknown_op(char ** word1, char * word2,int count,int i){
	int correct = 0;
	if(count == 3){
		if(is_number(word1[0][0])==1 && is_number(word1[2][0])==1 && is_arith(word1[1][0])!=1 && is_logic(word1[1])!=1 && is_not(word1[1])!= 1 || logic_check(word1[0]) ==1 && logic_check(word1[2]) ==1 && is_logic(word1[1]) != 1 && is_arith(word1[1][0])!=1){
			printf("Error: Parse error in expression %d: unknown operator\n\"%s\"\n",i,word1[1]);
			correct = 1;
		}
	}
	if(count == 2 && is_number(word1[0][0]) == 1){
		printf("Error: Parse error in expression %d: unknown operator\n\"%s\"\n",i,word1[0]);
	}
	if(count == 2 && is_number(word1[0][0]) != 1){
		if((logic_check(word1[0]) == 1 || is_number(word1[0][0]) == 1) && (is_logic(word1[1])!=1 && is_arith(word1[1][0])!=1)){
			printf("Error: Parse error in expression %d: unknown operator\n\"%s\"\n",i,word1[1]);
		}
	}

	if(count == 1){
		if(is_number(word1[0][0]) ==1 || logic_check(word1[0]) == 1){
			printf("Error: Parse error in expression %d: missing operator\n\"%s\"\n",i,word1[0]);
			correct = 1;
		}
		if(is_number(word1[0][0]) !=1 && is_letter(word2[0])!=1 && word2[0] != ' ' && is_not(word1[0])!= 1 && is_arith(word1[0][0]) != 1){
			printf("Error: Scan error in expression %d: incomplete expression.\n",i);
		}
		if(is_letter(word1[0][0]) ==1 && is_logic(word1[0])!=1){
			printf("Error: Parse error in expression %d: unknown identifier\n\"%s\"\n",i,word2);
		}
		if(is_arith(word1[0][0]) == 1 || (is_logic(word1[0]) ==1 && is_not(word1[0])!=1 )){
			printf("Error: Parse error in expression %d: unexpected operator.\n\"%s\"\n",i,word2);
		}
		if(is_not(word1[0]) == 1){
			printf("Error: Parse error in expression %d: missing operand\n\"%s\"\n",i,word2);
		}
	}
	return correct;
}//end of function

//reutns the number of arrays that do not contain the null terminator '\0'
int to_long(char ** words,int count,char *word2){
	int i =0;
	int j =0;
	int number = 0;
	for(i =0; i< count;i++){
		if(is_number(words[i][0])==1  || is_letter(words[i][0])==1 || is_arith(words[i][0]) ==1){
			for(j =i; j < count; j++){
				number++;
			}
			break;
		}
	}
	if(word2[0]== ' '){
		return number-1;
	}
	return number;	

}//end of function

//the function handle all the expression that have over 3 arrays 
int larger_expression(char **words,char * word2,int count,int place,int on){
	int i =0;
	int correct = 0;
	int end = 0;
	if(on == 1 ){
		if(word2[0] != ' '){
			printf("Error: Parse error in expression %d: incomplete expression \n\"%s\"\n",place,word2);
		}
	}
	for(i =0; i < count; i++){
		if(words[i][0] == '\0' || logic_check(words[i])!=1 && is_letter(words[i][0]) == 1 && is_logic(words[i])!=1 && is_not(words[i])!=1){
			printf("Error: Parse error in expression %d: unknown identifier\n\"%s\"\n",place,words[i]);
			
		}
		if(i < 1){
			// + 2 || + a
			if(is_arith(words[i][0]) == 1 || is_logic(words[i]) == 1){
				printf("Error: Parse error in expression %d: unexpected operator\n\"%s\"\n",place,words[i]);
				break;
			}
			// 1 +  2 || true AND  false
			if(is_number(words[i][0]) == 1 && is_arith(words[i+1][0]) == 1 && words[i+2][0] == '\0' || logic_check(words[i]) == 1 && is_logic(words[i+1]) == 1 && words[i+2][0] == '\0'){
				printf("Error: Parse error in expression %d: unknown operand\n\"%s\"\n",place,words[i+2]);
				break;
			}
			// 1  + 2 || true  AND false
			if(is_number(words[i][0]) == 1 && words[i+1][0] == '\0' && is_arith(words[i+2][0]) == 1|| logic_check(words[i]) == 1 && words[i+1][0] == '\0' && is_logic(words[i+2]) == 1 ){
				printf("Error: Parse error in expression %d: unkown operator\n\"%s\"\n",place,words[i+1]);
				printf("Error: Parse error in expression %d: unexpected operator\n\"%s\"\n",place,words[i+2]);
				break;
			}
			//1 + 2 A 1 + 2 || true AND false A false OR true || NOT true a NOT false
			if(is_number(words[i][0]) == 1 && is_arith(words[i+1][0]) == 1 && is_number(words[i+2][0]) == 1 ||logic_check(words[i]) == 1&& is_logic(words[i+1]) == 1 && logic_check(words[i+2]) == 1 || is_not(words[i]) == 1 && logic_check(words[i+1]) == 1){
				printf("Error: Parse error in expression %d: expression not ended\n\"%s\"\n",place,words[i+2]);
				break;
			}
			//1 a 2 + 3
			if(is_number(words[i][0]) == 1 && is_letter(words[i+1][0]) == 1 && is_number(words[i+2][0]) == 1 && (is_arith(words[i+3][0]) == 1|| is_logic(words[i+3]) == 1 || is_not(words[i+3]) ==1) || logic_check(words[i]) == 1 && is_letter(words[i+1][0]) == 1 && logic_check(words[i+2]) == 1 && (is_arith(words[i+3][0]) == 1 || is_logic(words[i+3]) == 1 || is_not(words[i + 3]) == 1 )){
				printf("Error: Parse error in expression %d: unknown operator\n\"%s\"\n",place,words[i+1]);
				printf("Error: Parse error in expression %d: expression not ended\n\"%s\"\n",place,words[i+2]);
				printf("Error: Parse error in expression %d: unexpected operator\n\"%s\"\n",place,words[i+3]);
				break;
			}
		
		}	
		if(i >=1){
			if(is_arith(words[i][0]) == 1 && is_number(words[i-1][0])!=1 || logic_check(words[i-1]) != 1 && is_logic(words[i]) == 1){
				printf("Error1: Parse error in expression %d: unexpected operator\n\"%s\"\n",place,words[i]);
				break;
			}
			if(is_number(words[i][0]) == 1 && is_arith(words[i+1][0]) == 1 && words[i+2][0] == '\0' || logic_check(words[i]) == 1 && is_logic(words[i+1]) == 1 && words[i+2][0] == '\0'){
				printf("Error: Parse error in expression %d: unknown operand\n\"%s\"\n",place,words[i+2]);
				break;
			}
			if(is_number(words[i][0]) == 1){
				if(words[i+1][0] == '\0'){
					printf("Error: Parse error in expression %d: expecting operator after \n\"%s\"\n",place,words[i]);
					if(is_arith(words[i+2][0]) == 1 || is_logic(words[i+2]) == 1 || is_not(words[i+2]) == 1 ){
						printf("Error Parse error in expression %d: unexpected operator\n\"%s\"\n",place,words[i+2]);
						break;
					}
				}
				if(words[i+2][0] == '\0'){
					printf("Error: Parse error in expression %d expecting operand \n\"%s\"\n",place,words[i]);
					break;
				}
			}
			if(logic_check(words[i]) == 1 && (is_logic(words[i+1])==1 || is_arith(words[i+1][0]) == 1) && words[i+2][0] == '\0'){
				printf("Error: Parse error in expression %d expecting operand after the \n\"%s\"\n",place,words[i+1]);
				break;
			}
			if(is_arith(words[i][0]) ==1 ){
				printf("Error: Parse error in expression %d unexpected operator \n\"%s\"\n",place,words[i]);
				break;
			}

		}
		if(i>0){
			if(is_arith(words[i][0]) == 1 && is_number(words[i-1][0]) !=1){
				printf("Error: Parse error in expression %d unexpected operator \n\"%s\"\n",place,words[i]);
				break;
			}
			if(logic_check(words[i]) == 1 && (is_logic(words[i+1]) == 1 ||is_arith(words[i+1][0]) ==1) && words[i+2][0] == '\0'){
				printf("Error: Parse error in expression %d: expecting operand after the \n\"%s\"\n",place,words[i+1]);
				break;
			}
			if(logic_check(words[i]) == 1 && words[i+1][0] == '\0'){
				printf("Error: Parse error in expression %d: expected operator after \n\"%s\"\n",place,words[i]);
				break;
			}
			if(words[i][0] == '\0' && is_number(words[i-1][0]) != 1 && is_arith(words[i+2][0] != 1)){
				printf("Error: Parse error in expression %d: unknown identifier\n\"%s\"\n",place,words[i]);
			}
			if(is_number(words[i][0]) == 1 && is_arith(words[i+1][0]) != 1 && is_letter(words[i+1][0])!=1){
				printf("Error: Parse error in expression %d: unexpected operand\n\"%s\"\n",place,words[i]);
			}
			if(is_number(words[i][0]) == 1  && words[i+1][0] == '\0'){
				printf("Error: Parse error in expression %d: expecting operator after\n\"%s\"\n",place,words[i]); 
			}
		}
	}
	return correct;
			
}
/*Basic procdure in main
 *-makes sure that thier is only 2 arguments inputed
 *-check if semi colon is present
 *	-if > 1 semi colan is presnet then the input is parsed 2 times and input is analyzed
 *	-if < i semi colon is present then the input is parsed 1 time only based off of white spaces and input is analyzed
 */
int main(int argc, char* argv[]){
       
	//couting the number of argumenst in argc	
       	if(argc == 1|| argc > 2){
		printf("Fatal Error: found %d arguments, was expecting 2\n",argc);
		exit(0);
	}
	
	int size = counter(argv[1],strlength(argv[1]+1));
	int semi = m_expression(argv[1]);
	int i =0;
	int count =0;
	int count2 = 0;
	int total = 0;
	int total2 = 0;
	int l =0;
	int a = 0;
	char ** express;	
	if(m_expression(argv[1]) > 1){
		
		char ** alot = alot_expressions(argv[1]);
		if(alot == NULL){
			printf("Malloc failure\n");
		}
		count= m_expression(argv[1]);
		for(i =0; i <count; i ++){
			int size1 = counter(alot[i],strlength(alot[i]));
			express = token_expression(alot[i]);
			count2 = counter(alot[i],strlength(alot[i]));
			//making sure that the memory got allocated
			if(express == NULL){
				printf("Malloc failure\n");
			}//end of if
	
			int tolong = to_long(express,count2,alot[i]);
			
			if(tolong <= 3){	
				if(is_arithmetic(express,size1) == 1 && size1 != 1){
					l = arithmetic_setup(express,strlength(alot[i]),alot[i],i,size1,tolong,1);
					if(l == 1){
						l =0;					
					}
					else{
						total++;;
					}	
				}//end of if
			
				else if(strcompare(express,count2) ==1 && size1 != 1){
					a =logic_setup(express,strlength(alot[i]),alot[i],count2,i,tolong,1);
					if(a == 1){
						a =0;
					}
					else{
						total2++;
					}
				
				}//end of else if
				else if(is_arithmetic(express,size1)!= 1|| strcompare(express,count2)!=1||((is_arithmetic(express,size1)==1 || strcompare(express,count2)==1) && size1 == 1)){
					unknown_op(express,alot[i],size1,i);
				}//end of else if
			}//end of if statement
			else if (tolong >3){
				larger_expression(express,alot[i],size1,i,1);
			}//end of else if
			size = 0;
			count2 = 0;			
		}//end of for loop

		printf("Found %d expressions: %d logical %d arithmetic.\n",i,total2,total);
		i =0;
		//freeing my memory
		for(i =0; i < semi-1; i++){
			free(alot[i]);
		}
		i =0;
		for(i = 0; i < count2; i++){
			free(express[i]);
		}		
	}//end of if statement
	else if (semi < 2){
		int i = 0;
		int k =0;
		int l =0;
		int a = 0;
		int u =0;
		char ** words = token_expression(argv[1]);
		if(words == NULL){
			printf("Error: failuer to allocate memory\n");
		}
		size = counter(argv[1],strlength(argv[1]+1));
		int tolong=to_long(words,size,argv[1]);
		if(tolong <=3 ){
			if(is_arithmetic(words,size)==1 && size !=1){
				l = arithmetic_setup(words,strlength(argv[1]),argv[1],i,size,tolong,0);
				if(l == 1){
					l =0;
				}
				else{
					l = 1;
				}
			}
			else if(strcompare(words,size)==1 && size != 1){
				a = logic_setup(words,strlength(argv[1]),argv[1],size,i,tolong,0);
				if(a == 1){
					a =0;
				}
				else{
					a =1;
				}
			}
			else if(is_arithmetic(words,size)!=1 && strcompare(words,size)!=1 || ((strcompare(words,size) ==1 || is_arithmetic(words,size) ==1) && size == 1)) {	
				//need to handle "AND" "+" ect
				unknown_op(words,argv[1],size, i);
			
			}
		}
		else if(tolong > 3){	
			larger_expression(words,argv[1],size,i,0);

		}
		//freeing the memory
		for(k =0; k < size; k++){	
			free(words[k]);
		}
		printf("Found %d expressions: %d logical and %d arithmetic.\n",i+1,a,l);
	}	

        
		
        return(0);
}


