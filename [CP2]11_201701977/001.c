#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dup_check(char **sp,char *temp, int cnt); //�̹� �ִ� �ܾ����� üũ�ϴ� �޼ҵ�

int main(void){

	char temp[100]; //�ӽ� char �迭
	char *word[100] ={0};//�����Ҵ� ������ ������ ������ �迭
	char endWord,startWord; // �����ձ⸦ ���ؼ� ���ܾ��� ������ ���ĺ��� �Է´ܾ��� ù ���ĺ��� �����ϱ����� ������ ����
	int i=0; //�ݺ����� ���� ������ ����

	


	while(i<100) //100���� �ܾ������ �Է¹ޱ����� ���ǽ�
{
		printf("�ܾ��Է� : "); 
		gets(temp); // ���ڿ� �Է�
		
		if(strcmp(temp,"end") == 0){break;} //end�� �ԷµǸ� �ݺ� ����

		startWord = temp[0]; //�Է¹��� �ܾ��� ù��° ���ĺ��� �����Ѵ�.

		if(i!=0){ //���� i�� 0�� �ƴҰ�� (0�̶�� �����ϴ� �ܾ� �̱⶧���� �ߺ����ϵ� �̾����� ���� �ϵ� ����.)
		while(dup_check(word,temp,i)==0 || endWord != startWord){ // �ܾ �̹� �ְų� �� �ܾ�� �̾������ʴ� ���
			if(dup_check(word,temp,i)==0){printf(">�̹� �����ϴ� �ܾ��Դϴ�!\n");} //���� �ܾ �̹� �ִ� ��쿡 �� �޼����� ����Ѵ�.
			else{	printf(">�ܾ� �ձⰡ �Ұ����մϴ�!\n");} //�ƴѰ��(�̾����� �ʴ� ���) �� �޼����� ����Ѵ�.
			printf("�ܾ��Է� : "); 
			gets(temp); //�ٽ� ���ڿ��� �Է¹޴´�.
			if(strcmp(temp,"end") == 0){break;} //end�� �ԷµǸ� �ݺ� ����
			startWord = temp[0]; //�Է¹��� �ܾ��� ù��° ���ĺ��� �����Ѵ�.
		}
		if(strcmp(temp,"end") == 0){break;} //end�� �ԷµǸ� �ݺ� ����
		} 
		endWord = temp[strlen(temp)-1]; //�Է¹��� �ܾ��� ������ ���ĺ��� �����Ѵ�.

		word[i] = (char *) malloc (strlen(temp) +1); //���ڿ� ���� ���� �Ҵ�
		strcpy(word[i],temp); //���� �Ҵ� ������ ���ڿ� ����
		i++; //i�� �ϳ� ������Ų��.

	}
	
	


	if(i==100) //���� i�� 100�̶�� end�� �ƴ� �ܾ 100�� �Է��ؼ� ���°��̹Ƿ�
	{
		printf("�Է°��� �ܾ�� 100�� �Ѿ����ϴ�.\n"); //���̻� �Է��� ���� �ʴ´ٴ� �޼����� ����Ѵ�.
	}


	for(i=0;word[i]!=NULL;i++){ //word�� ����� ���ڿ��� ���� ������
	printf("%s ",word[i]); //word�� ����� ���ڿ� ���
	}

	for(i=0;word[i]!=NULL;i++){ //word�� ����� ���ڿ��� ���� ������
		free(word[i]); //���� �Ҵ� ���� ��ȯ
	}
	return 0;
	
}

int dup_check(char **sp,char *temp, int cnt)//�̹� �ִ� �ܾ����� üũ�ϴ� �޼ҵ�
{
	int i; //�ݺ����� ���� ������ ����
	for(i=0;i<cnt;i++){ //word�� ����� �ܾ��� ������ŭ �ݺ�
		if(strcmp(*sp++,temp) == 0){ //sp�� ����Ű�� ������ �迭�� ��ҿ� temp�� ���� �ܾ��� ���
		return 0;} //0�� �����Ѵ�.
	}
	
	return 1; //�ߺ��ܾ ���� ��� 1�� �����Ѵ�.
}