# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int  main(void){

	char *a;
	char *b;
	char c ;
	int i = 0;

	a = (char *)(malloc(100*sizeof(char)));

	b = (char *)(malloc(100*sizeof(char)));

	printf("enter first string \n");
 	c=getchar();
 	while(c != '\n'){
 		*a = c;
 		a++;
 		c = getchar();
 	}
 	*a='\0';

 	printf("enter second string \n");
 	c=getchar();
 	while(c != '\n'){
 		*b= c;
 		b++;
 		c = getchar();
 	}
 	*b = '\0';

 	printf("printing details of array a \n");

 	for(i=0;i<100;i++){
 		if(*(a+i) != '\0'){
 			printf("%c",*(a+i));

 		}
 	}

 	printf("printing details of array b \n");
 		for(i=0;i<100;i++){
 		if(*(b+i) != '\0'){
 			printf("%c",*(b+i));

 		}
 	}


 
 		
 	

}
