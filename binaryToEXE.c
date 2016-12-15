#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void ADD(float* reg3,float* reg1,float* reg2);
void ADi(float *reg1, int constant);
void SUB(float* reg3,float* reg1,float* reg2);
void SUi(float *reg1, int constant);
void MOV(float*reg1,float*reg2);
float MOi(float reg,int x);
int CMi(float* reg1,int);
void MUL(float* reg3,float* reg1,float* reg2);
void MUi(float *reg1, int constant);
void DIV(float* reg3,float* reg1,float* reg2);
void DIi(float *reg1, int constant);
int CMP(float* reg1,float* reg2);
void JLT(int addr);
void JGT(int addr);
void JEQ(int* addr);
void JMP(int* addr);
void HALT();

FILE *fp;

int main()
{
	
	fp= fopen("code2_binary.txt", "r");
	int m[32]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};//mask for 27 bit opcode
	float r[16];
	int count,flag=0;
	int b[32],result[32];
	int a[50][32];
   	 char c;
  	  
  	  int j=0,i,k=0,reg1,reg2,reg3,constant,n=0;
  	if (fp == NULL)
        return 0; //could not open file
	
 	else
	{
   	 while ((c = fgetc(fp)) != EOF)
    	{
		while(c!='\n')
		{
		a[j][n] =  c-'0';//converting to int
		//a[j][n] =atoi(c);		
		n++;
		c=fgetc(fp);
		}
		j++;
		n=0;
    	}
	

	/*if(fp == NULL)
		printf("FILE NOT FOUND\n");
	else
	{
		while(fscanf(fp, "%s", string)!=EOF)
		{
			strcpy(a[i],string);//each instruction in a string
			i++;	
		}*/
		flag=0;
		for(i=0;i<j;)//each instruction
		{	
			
			
			count=0;
			//for(k=0;k<32;k++)//each bit
			//	b[k]=atoi(a[j][k]);//string to int array
			result[0]=0;
			
			for(k=0;k<17;k++)
			{
	

				result[k]=a[i][k];//checking opcode of length 17
			
			}
			for(k=0;k<4;k++)
				count=count+result[16-k]*pow(2,k);//4 bits of end
			switch (count)
			{
				case 0://ADD of adding so 3 registers
					printf("ADD ");
					reg1=0,reg2=0,reg3=0;
					for(k=0;k<4;k++)
						reg1=reg1+a[i][21-k]*pow(2,k);//4 bits of end
					for(k=0;k<4;k++)
						reg2=reg2+a[i][26-k]*pow(2,k);
					for(k=0;k<4;k++)
						reg3=reg3+a[i][31-k]*pow(2,k);
					ADD(&r[reg1],&r[reg2],&r[reg3]);
					printf("%f\n",r[reg1]);
					i++;
					break;
				case 1://SUB 3 reg
					 reg1=0,reg2=0,reg3=0;
					printf("SUB ");
					for(k=0;k<4;k++)
						reg1=reg1+a[i][21-k]*pow(2,k);//4 bits of end
					for(k=0;k<4;k++)
						reg2=reg2+a[i][26-k]*pow(2,k);
					for(k=0;k<4;k++)
						reg3=reg3+a[i][31-k]*pow(2,k);
					SUB(&r[reg1],&r[reg2],&r[reg3]);
					printf("%f\n",r[reg1]);
					i++;
					break;
				case 2://mulitply
					printf("MUL ");
					 reg1=0,reg2=0,reg3=0;
					for(k=0;k<4;k++)
						reg1=reg1+a[i][21-k]*pow(2,k);//4 bits of end
					for(k=0;k<4;k++)
						reg2=reg2+a[i][26-k]*pow(2,k);
					for(k=0;k<4;k++)
						reg3=reg3+a[i][31-k]*pow(2,k);
					MUL(&r[reg1],&r[reg2],&r[reg3]);
					printf("%f\n",r[reg1]);
					i++;
					break;
				case 3://divide
					printf("DIV ");
					 reg1=0,reg2=0,reg3=0;
					for(k=0;k<4;k++)
						reg1=reg1+a[i][21-k]*pow(2,k);//4 bits of end
					for(k=0;k<4;k++)
						reg2=reg2+a[i][26-k]*pow(2,k);
					for(k=0;k<4;k++)
						reg3=reg3+a[i][31-k]*pow(2,k);
					DIV(&r[reg1],&r[reg2],&r[reg3]);
					printf("%f\n",r[reg1]);
					i++;
					break;
				case 4://adi 1 reg then constant
					printf("ADi ");
					 reg1=0,constant=0;
					for(k=0;k<4;k++)
						reg1=reg1+a[i][21-k]*pow(2,k);//4 bits of end
					for(k=0;k<10;k++)
						constant=constant+a[i][31-k]*pow(2,k);
					ADi(&r[reg1],constant);
					printf("%f\n",r[reg1]);
					i++;
					break;
				case 5://Sui
					 reg1=0,constant=0;
					printf("SUi ");
					for(k=0;k<4;k++)
						reg1=reg1+a[i][21-k]*pow(2,k);//4 bits of end
					for(k=0;k<10;k++)
						constant=constant+a[i][31-k]*pow(2,k);
					SUi(&r[reg1],constant);
					printf("%f\n",r[reg1]);
					i++;
					break;
				case 6:
					 reg1=0,constant=0;
					printf("MUi ");
					for(k=0;k<4;k++)
						reg1=reg1+a[i][21-k]*pow(2,k);//4 bits of end
					for(k=0;k<10;k++)
						constant=constant+a[i][31-k]*pow(2,k);
					MUi(&r[reg1],constant);
					printf("%f\n",r[reg1]);
					i++;
					break;
				case 7:
					 reg1=0,constant=0;
					printf("DIi ");
					for(k=0;k<4;k++)
						reg1=reg1+a[i][21-k]*pow(2,k);//4 bits of end
					for(k=0;k<10;k++)
						constant=constant+a[i][31-k]*pow(2,k);
					DIi(&r[reg1],constant);
					printf("%f\n",r[reg1]);
					i++;
					break;
				case 8:
					printf("MOi ");
					 reg1=0,constant=0;
					for(k=0;k<4;k++)
						reg1=reg1+a[i][21-k]*pow(2,k);//4 bits of end
					
					for(k=0;k<10;k++)
						constant=constant+(a[i][31-k]*pow(2,k));
					
					r[reg1]=MOi(r[reg1],constant);
					printf("%f\n",r[reg1]);
					i++;
					break;
				case 9:
					printf("CMi ");
					reg1=0,constant=0;
					for(k=0;k<4;k++)
						reg1=reg1+a[i][21-k]*pow(2,k);//4 bits of end
					for(k=0;k<10;k++)
						constant=constant+a[i][31-k]*pow(2,k);
					flag=CMi(&r[reg1],constant);
					printf("flag %d\n",flag);
					i++;
					break;
				default:
					count=0;
					
					for(k=0;k<22;k++)
						result[k]=a[i][k];//checking opcode of length 22
					for(k=0;k<2;k++)
						count=count+result[21-k]*pow(2,k);//2 bits of end
					switch (count)
					{
						case 0://MOV
							 reg1=0,reg2=0;
							printf("MOV ");
							for(k=0;k<4;k++)
								reg1=reg1+a[i][26-k]*pow(2,k);
							for(k=0;k<4;k++)
								reg2=reg2+a[i][31-k]*pow(2,k);
							MOV(&r[reg1],&r[reg2]);
							printf("%f\n",r[reg1]);
							i++;
							break;
						case 1://CMP
							printf("CMP ");
							 reg1=0,reg2=0;
							for(k=0;k<4;k++)
								reg1=reg1+a[i][26-k]*pow(2,k);
							for(k=0;k<4;k++)
								reg2=reg2+a[i][31-k]*pow(2,k);
							flag=CMP(&r[reg1],&r[reg2]);
							i++;
							printf("flag %d\n",flag);
							break;
						default:
							count=0;
							
							for(k=0;k<27;k++)
							result[k]=a[i][k];//checking opcode of length 27
							for(k=0;k<3;k++)
							count=count+result[26-k]*pow(2,k);//2 bits of end
							switch (count)			
							{
								case 0:
									printf("JMP ");
									 reg1=0;
									for(k=0;k<5;k++)
									reg1=reg1+a[i][31-k]*pow(2,k);
									
									printf("%d\n",reg1);
									i=reg1-1;
									break;
								case 1:
									if(flag==0)
									{
									reg1=0;
									printf("JEQ ");
									for(k=0;k<5;k++)
									reg1=reg1+a[i][31-k]*pow(2,k);
									i=reg1-1;
									printf("%d\n",reg1);
									}
									else
									{
										i++;
										
									}
									break;
										
								case 2:
									if(flag==1)
									{
									 reg1=0;
									printf("JGT ");
									for(k=0;k<5;k++)
									reg1=reg1+a[i][31-k]*pow(2,k);
									i=reg1-1;
									printf("%d\n",reg1);
									}
									else
									{
										i++;
										
									}
									break;
								case 3:
									if(flag<1)
									{
									reg1=0;
									printf("JLT ");
									for(k=0;k<5;k++)
									{
										
										reg1=reg1+a[i][31-k]*pow(2,k);
									}
									printf("%d\n",reg1);
									i=reg1-1;
									
									}
									else
									{
										i++;
										
									}
									break;
								default:
									count=0;
									for(k=0;k<4;k++)
										count=count+a[i][31-k]*pow(2,k);
									switch (count)
									{
										case 0:
											printf("HLT\n");
											HALT();
											break;
										case 1:
										case 2:
										case 3:
										case 4:
											i++;
											break;
									}

									break;		
							}//switch 27
					break;
					}//switch 22
			break;
			}//switch 17
			
			
				
		}//for all instruction
	}//else loop
	/*FILE *fptr;
	fptr=fopen("result.txt","w");
	if(fptr==NULL)
	{
     	 printf("Error!");
      	exit(1);
   	}
	for(i=0;i<16;i++)
   	fprintf(fptr,"Reg %f\n",r[i]);
   	fclose(fptr);*/
	fclose(fp);
	return 0;
}





//functions
void ADD(float* reg3,float* reg1,float* reg2)
{
	*reg3=*reg1+*reg2;
	
}
void ADi(float *reg1, int constant)
{
	*reg1=(*reg1)+constant;
	
}
void SUB(float* reg3,float* reg1,float* reg2)
{
	*reg3=*reg2-*reg1;
	
}
void SUi(float *reg1, int constant)
{
	*reg1=constant-*reg1;
	
}
void MOV(float*reg1,float*reg2)
{
	*reg1=*reg2;
	
}
float MOi(float reg,int x)
{
	 reg=x;
	return reg;
}
void DIV(float* reg3,float* reg1,float* reg2)
{
	*reg3=(*reg2)/(*reg1);
	
}
void DIi(float *reg1, int constant)
{
	*reg1=*reg1/constant;
	printf(" %f\n",*reg1);
}
void MUL(float* reg3,float* reg1,float* reg2)
{
	*reg3=(*reg2)*(*reg1);
	
}
void MUi(float *reg1, int constant)
{
	*reg1=*reg1*constant;
}
int CMP(float* reg1,float* reg2)
{
	if((*reg2)==(*reg1))
		return 0;
	else if((*reg2)<(*reg1))
		return -1;
	else
		return 1;
}
int CMi(float* reg1,int x)
{	
	if((*reg1)==x)
		return 0;
	else if((*reg1)>x)
		return -1;
	else
		return 1;
}
void JMP(int* addr)
{
	fseek(fp,32*(*addr),SEEK_SET);
}
void JEQ(int* addr)
{
	fseek(fp,32*(*addr),SEEK_SET);
}
void JGT(int addr)
{
	fseek(fp,32*(addr),SEEK_SET);
}
void JLT(int addr)
{
	printf("%d",addr);
	fseek(fp,33*(addr-1),SEEK_SET);
}
void HALT()
{
	exit(0);
}

