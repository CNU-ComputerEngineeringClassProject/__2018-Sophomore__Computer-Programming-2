

#include <stdio.h>
#include <string.h>



int main(void){

	char inchar[16] = {0}; //�Է¹��� �ܾ �����ϴ� ���ڿ� ����
	char allchar[201] = {0} ; //�Է¹��� ���ڵ��� ����������� �����ϴ� ���ڿ� ����

	char copy[201] = {0}; //inchar�� allchar�� ���ڵ��� ���ϱ����ؼ� allchar�� ���ڿ��� �����Ͽ� �����ϴ� ���ڿ� ����
	char storage [201] = {0}; //copy�� inchar�� ���Ͽ� ����������� �����ϴ� ���ڿ� ����
	char clean [201] = {0}; //�ʱ�ȭ�� ������ �ϱ����� �ʱ�ȭ�� ���ڿ� clean�� ����� �� ���ڿ��� �����Ҽ��ֵ��� �Ѵ�.

	int i=0; // �ݺ������� ����ϱ����� ������ ����
	int x=0,y=0; //copy�� �տ��ִ� ù�ܾ �ڸ��� ���� ������ ����



	while(1){ //while�� ���� ������ ����ؼ� �ݺ��Ѵ�(break�� ������쿡�� ��������)

		printf("�ܾ� �Է� : "); 
		scanf("%s",inchar); //�ܾ �Է¹ް� inchar�� �����Ѵ�.

		if(inchar[0] == 'e' && inchar[1] == 'n' && inchar[2] == 'd'&&inchar[3] == '\0') break; //���� �Է¹��� �ܾ end��� ���α׷��� �����Ѵ�.(�ҹ��ڸ� ����)

		if(strlen(inchar) > 15){ //�Է¹��� ���ڿ��� ���̰� 16�̻��ϰ��
			printf("���� : �ܾ���̰� �ʹ� ��ϴ�.\n"); // ��ٴ� �����޼����� ����ϰ� allchar�� ���������ʴ´�.
		}
		
		else if( strlen(allchar) + strlen(inchar)+1 > 200){ //������ �Է¹��� ���ڵ��� ���������� ����Ǿ��� allchar�� ���� �Է¹��� inchar�� ���ڿ� ������ ���� 200�� �������
				printf("���� : ���̻� �Է� ���� �� �����ϴ�.\n");//���̻� �Է¹����� ���ٴ� �޼����� ����Ѵ�.
				break;//�׸��� ���α׷��� �����Ѵ�.
			}

		else{ //���Է¹��� ���ڰ� end�� �ƴϰ� ���ڿ��� ���̰� 15������ ���

			if(strlen(allchar)==0){ //ó�� �Է¹޴� ���
				strcpy(allchar,inchar); //�ʱ�ȭ�Ǿ��ִ� allchar�� �Է¹��� ���ڸ� �����Ѵ�.
				allchar[strlen(allchar)] = ' ' ; //�׸��� ������ ���� �ٷ� ������ ' '�� �����Ѵ�.
				printf("������� ���ڿ� : %s\n",allchar); // ������� ���ڿ��� ����Ѵ�.
			}
			else{ //ó�� �Է¹޴� ��� �ƴҰ��

				strncpy(storage,clean,strlen(storage)); //���������� �����ϴ� ���ڿ� storage�� �ʱ�ȭ �Ѵ�.
				strncpy(copy,clean,strlen(copy)); //copy�� �ʱ�ȭ�Ѵ�.
				strcpy(copy,allchar); //allchar�� ������ copy�� �����Ͽ� �����Ѵ�.

				while(1){ //while�� ���� ������ ����ؼ� �ݺ��Ѵ�(break�� ������쿡�� ��������)

					if( copy[0]==0){ //copy���� ������ ���� ��� - (2) allchar�� ��� �ܾ�� inchar�� ���� �����ϰ�� ����
						strcat(storage, inchar);  // storage�ȿ� allchar������ �� ����Ǿ����Ƿ� ���������� inchar�� �ٿ��ִ´�. 
						storage[strlen(storage)]=' '; //�׸��� storge�� ����� inchar���� �ڿ� ' '�� �����Ѵ�.
						break; //�׸��� while���� ���´�.
					}
					else if(strcmp(copy, inchar) >0 ){ //copy�� �մܾ inchar���� ���� ������ �����϶�

						strcat(storage, inchar); //storage�� inchar�� �ٿ��ִ´�.

						storage[strlen(storage)]=' '; //�׸��� storge�� ����� inchar���� �ڿ� ' '�� �����Ѵ�.
					
						strcat(storage, copy); //�׸��� storage�� ������ copy�� �ٿ��ִ´�.
			
						break; //while���� ���´�.
					}
					else { //copy�� �� �ܾ inchar�ܾ�� ���� ������ �����϶� 

						for(i=0;i<16;i++){ //copy�� �մܾ��� ���̸� �ݺ����� ���� �˾Ƴ���.
							if(copy[i] == 32) {break;} //���ڿ��� ' '�϶� �ݺ����� ���´�.
						}

						strncat(storage, copy, ++i); //storage�� copy�� �մܾ�(+' ')�� �����Ͽ� �ٿ��ִ´�.

						for(y=0 ; i+y < 200 ; y++){ //copy �մܾ �ڸ��� ������ ���ڿ��� ������ ���� ���� �ݺ���(i�� �մܾ�+' '�� ���ڿ� �ε����̴�)
							if(copy[i+y]!= 0){ //�������� ���ڰ� '\0'�� �ƴҰ��
							copy[y] = copy[i+y];} //y��°���ڿ��� i+y��° ���ڿ��� �ִ´�.
							else{ copy[y]=0; } //'\0'�ϰ�� �޺κ��� ��� �ܾ ����Ǿ����� �ʴٴ� �ǹ��̱⶧���� ���ܾ ����. �׷��Ƿ� y��°�� 0�� �ִ´�. 
						}
					}
				}

 			strcpy(allchar,storage); //while���� ���Դٸ� storage�ȿ� �������� ���ڰ� ���������� �����Ǿ��ִٴ°��̹Ƿ� allchar�ȿ� storage������ �����Ͽ� �����Ѵ�.
			printf("������� ���ڿ� : %s\n",allchar); // ������� ���ڿ��� ����Ѵ�.

			}
		}

	}

	return 0;
}

