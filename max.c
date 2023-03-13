#include <stdio.h>
//Function That Find the Max value From File with recursion
int Max_File(int Number[],int d){
	if(d == 1)
	return Number[0] ;
	else {
		if(Number[d-1] > Max_File(Number,d-1))
		return Number[d-1] ;
		else 
		return Max_File(Number,d-1);
	}
}
int main (){
	int n , i = 1 , num;
	//Open File
	FILE *write = fopen("Max.txt","w") ;
	//Tapping Howa Many Number You want In files
	do{
	printf("How Many Number : ") ;
	scanf("%d",&n) ;
	}while(n<=0) ;
	//Create an array That will Takes The Values from File
	int Arr[n] ;
	//Writing Values in File
	while(i <= n){
		printf("Enter Num : ") ;
		scanf("%d",&num) ;
		fprintf(write,"%d ",num) ;
		i++ ;
	}
	//close file
	fclose(write) ;
	int line ;
	i = 0 ;
	//open file in read mode
	write = fopen("Max.txt","r") ;
	//Adding values At an Array
	for(i = 0 ; i < n ; i++){
		fscanf(write,"%d",&line);
		Arr[i] = line ;
	}	
	//num that will take maximum value
	num = Max_File(Arr,n-1) ;
	fclose(write) ;
	//printf that value
	printf("%d",num) ;
}
