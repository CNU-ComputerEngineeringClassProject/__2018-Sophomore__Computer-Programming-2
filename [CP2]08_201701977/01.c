

#include <stdio.h>
#include <string.h>



int main(void){

	char inchar[16] = {0}; //입력받은 단어를 저장하는 문자열 변수
	char allchar[201] = {0} ; //입력받은 문자들을 사전순서대로 저장하는 문자열 변수

	char copy[201] = {0}; //inchar와 allchar의 문자들을 비교하기위해서 allchar의 문자열을 복사하여 저장하는 문자열 변수
	char storage [201] = {0}; //copy와 inchar를 비교하여 사전순서대로 저장하는 문자열 변수
	char clean [201] = {0}; //초기화를 빠르게 하기위해 초기화된 문자열 clean을 만들어 이 문자열을 복사할수있도록 한다.

	int i=0; // 반복문에서 사용하기위한 정수형 변수
	int x=0,y=0; //copy의 앞에있는 첫단어를 자르기 위한 정수형 변수



	while(1){ //while문 안의 내용을 계속해서 반복한다(break를 만날경우에만 나오도록)

		printf("단어 입력 : "); 
		scanf("%s",inchar); //단어를 입력받고 inchar에 저장한다.

		if(inchar[0] == 'e' && inchar[1] == 'n' && inchar[2] == 'd'&&inchar[3] == '\0') break; //만약 입력받은 단어가 end라면 프로그램을 종료한다.(소문자만 인정)

		if(strlen(inchar) > 15){ //입력받은 문자열의 길이가 16이상일경우
			printf("오류 : 단어길이가 너무 깁니다.\n"); // 길다는 오류메세지를 출력하고 allchar에 저장하지않는다.
		}
		
		else if( strlen(allchar) + strlen(inchar)+1 > 200){ //이전에 입력받은 문자들이 사전순으로 저장되었는 allchar와 지금 입력받은 inchar의 문자열 길이의 합이 200을 넘을경우
				printf("오류 : 더이상 입력 받을 수 없습니다.\n");//더이상 입력받을수 없다는 메세지를 출력한다.
				break;//그리고 프로그램을 종료한다.
			}

		else{ //문입력받은 문자가 end가 아니고 문자열의 길이가 15이하일 경우

			if(strlen(allchar)==0){ //처음 입력받는 경우
				strcpy(allchar,inchar); //초기화되어있는 allchar에 입력받은 문자를 저장한다.
				allchar[strlen(allchar)] = ' ' ; //그리고 저장한 문자 바로 다음에 ' '를 저장한다.
				printf("현재까지 문자열 : %s\n",allchar); // 현재까지 문자열을 출력한다.
			}
			else{ //처음 입력받는 경욱 아닐경우

				strncpy(storage,clean,strlen(storage)); //사전순으로 저장하는 문자열 storage를 초기화 한다.
				strncpy(copy,clean,strlen(copy)); //copy를 초기화한다.
				strcpy(copy,allchar); //allchar이 내용을 copy에 복사하여 저장한다.

				while(1){ //while문 안의 내용을 계속해서 반복한다(break를 만날경우에만 나오도록)

					if( copy[0]==0){ //copy안의 내용이 없을 경우 - (2) allchar의 모든 단어보다 inchar가 제일 나중일경우 가능
						strcat(storage, inchar);  // storage안에 allchar내용이 다 저장되었으므로 마지막으로 inchar를 붙여넣는다. 
						storage[strlen(storage)]=' '; //그리고 storge에 저장된 inchar내용 뒤에 ' '를 저장한다.
						break; //그리고 while문을 나온다.
					}
					else if(strcmp(copy, inchar) >0 ){ //copy의 앞단어가 inchar보다 사전 순으로 나중일때

						strcat(storage, inchar); //storage에 inchar를 붙여넣는다.

						storage[strlen(storage)]=' '; //그리고 storge에 저장된 inchar내용 뒤에 ' '를 저장한다.
					
						strcat(storage, copy); //그리고 storage에 나머지 copy를 붙여넣는다.
			
						break; //while문을 나온다.
					}
					else { //copy의 앞 단어가 inchar단어보다 사전 순으로 먼저일때 

						for(i=0;i<16;i++){ //copy의 앞단어의 길이를 반복문을 통해 알아낸다.
							if(copy[i] == 32) {break;} //문자열이 ' '일때 반복문을 나온다.
						}

						strncat(storage, copy, ++i); //storage에 copy의 앞단어(+' ')를 복사하여 붙여넣는다.

						for(y=0 ; i+y < 200 ; y++){ //copy 앞단어를 자르고 나머지 문자열을 앞으로 당기기 위한 반복문(i는 앞단어+' '의 문자열 인덱스이다)
							if(copy[i+y]!= 0){ //당기기위한 문자가 '\0'이 아닐경우
							copy[y] = copy[i+y];} //y번째문자열에 i+y번째 문자열을 넣는다.
							else{ copy[y]=0; } //'\0'일경우 뒷부분은 모두 단어가 저장되어있지 않다는 의미이기때문에 당길단어가 없다. 그러므로 y번째에 0을 넣는다. 
						}
					}
				}

 			strcpy(allchar,storage); //while문은 나왔다면 storage안에 이제까지 문자가 사전순으로 정리되어있다는것이므로 allchar안에 storage내용을 복사하여 저장한다.
			printf("현재까지 문자열 : %s\n",allchar); // 현재까지 문자열을 출력한다.

			}
		}

	}

	return 0;
}

