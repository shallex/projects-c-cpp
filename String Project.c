

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void PrefixFunc(char * str, int * PF, int n);

int main(int argc,  char * argv[]){
	FILE * f1;
	FILE * f2;
	int chet=0, i, j;
	f1=fopen(argv[1], "r");
	f2=fopen("in1.txt", "w");
	char c;
	int flag=0;
	int k=atoi(argv[2]);
	switch(k){
		case 1:
		{
			char str[5000];
			char s[5000];
			int l = strlen(argv[3]);
			
			for(i=0; i<l; i++){
				str[i]=argv[3][i];
			}
			str[l]='#';
			
			while(1){
				
				c=fgetc(f1);
				
				if(flag==1){
						
						fclose(f1);
					fclose(f2);
						f1=fopen(argv[1], "w");
						f2=fopen("in1.txt", "r");
	
						while(1){
						c=fgetc(f2);
						if(c==EOF){
							fclose(f1);
							fclose(f2);
							return 0;
							}
							else{
							fputc(c, f1);
							}
						}	
						
				}
				if(c!='\n'){
					s[chet]=c;
					chet++;
				}
				if(c=='\n' || c==EOF){
					printf("%d %d\n",l,chet, s);
					for(i=0; i<chet; i++){
						str[i+l+1]=s[i];
					}
					//str[l+1+chet]='\0';
					
					int PrefMas[chet+l+1];
					PrefMas[0]=0;
					printf("%s\n", str);
					PrefixFunc(str, PrefMas, l+1+chet);
					for (i=0;i<chet+l+1;i++) printf("%d ",PrefMas[i]);
					printf("\n");
					for(i=0;i<chet+l+1; i++) {
						if(PrefMas[i]==l){
							for(j=0; j<chet; j++){
							fputc(s[j],f2);
							}
							fputc('\n', f2);
							break;
						}
					}
					chet=0;
					if(c==EOF) flag++;
				}
			}
			
				
			break;		
		}
			
		
		
		case 2 :{
			char str[5000];
			while(1){
				c=fgetc(f1);
				 if(flag==1){
					fclose(f1);
					fclose(f2);
						f1=fopen(argv[1], "w");
						f2=fopen("in1.txt", "r");
	
						while(1){
						c=fgetc(f2);
						if(c==EOF){
							fclose(f1);
							fclose(f2);
							return 0;
							}
							else{
							fputc(c, f1);
							}
						}	
				 }
				else{
					if(c!='\n'){
						str[chet]=c;
						chet++;
						
					}
					if(c=='\n' || c==EOF){
						printf("%d\n", chet);
						if(chet<52){
							for(i=0; i<chet; i++){
								fputc(str[i], f2);
								printf("%c", str[i]);
							}
							printf("\n");
							fputc('\n', f2);
						}
						if(c==EOF) {
								fclose(f1);
								fclose(f2);
								f1=fopen(argv[1], "w");
								f2=fopen("in1.txt", "r");
	
								while(1){
									c=fgetc(f2);
										if(c==EOF){
										fclose(f1);
										fclose(f2);
										return 0;
										}
										else{
										fputc(c, f1);
										}
								}	
						} 
						chet=0;
					}
					
					
					
				}
			}
			
			
			break;
		}
		
		case 3 :{
			
			while(1){
				c=fgetc(f1);
				
				if(c==EOF){
					fclose(f1);
					fclose(f2);
						f1=fopen(argv[1], "w");
						f2=fopen("in1.txt", "r");
	
						while(1){
						c=fgetc(f2);
						if(c==EOF){
							fclose(f1);
							fclose(f2);
							return 0;
							}
							else{
							fputc(c, f1);
							}
						}	
				}
				
				else{
					
						
						if(chet<50 && c!='\n'){
							fputc(c, f2);
							chet++;
						}
						if(c=='\n') {
							chet=0;
							fputc('\n', f2);
						}
						
					
				}
			}
			
			break;
		}
	}
	
	/*
	fclose(f1);
	fclose(f2);
	
	f1=fopen(argv[1], "w");
	f2=fopen("in1.txt", "r");
	
	while(1){
		c=fgetc(f2);
		if(c==EOF){
			fclose(f1);
			fclose(f2);
			return 0;
		}
		else{
			fputc(c, f1);
		}
	}
	*/
	
	
	return 0;
}

void PrefixFunc(char * str, int * PF, int n){
	int i;
	for(i=1;i<n;i++){
		int j=PF[i-1];//j содержит значение префикс функциии предыдцщего шага
		while (j>0 && str[i]!=str[j]){// str[i] - новый символ в рассматриваемой в строке
		j=PF[j-1];//это нахождение макс префикса совпадающего с суфиксом
		}
		if(str[i]==str[j]) j++;
		PF[i]=j;
	}
	return;
}


