#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){

	char temp[32]; // �ӽ� char�迭
	char *ps, *pt; // �Ҵ��� ���� ������ ������ ������
	int len =1; //
	ps = (char *)calloc(1,1); //1���� ��������� �Ҵ��Ѵ�.
	while (1){ 
		printf("�޸��Է� : ");
		fgets(temp, sizeof(temp), stdin); //stdin���κ��� ���ڿ��� �Է¹޾Ƽ� �迭 temp�� ���� ��ŭ �迭�� ����
		temp[strlen(temp) -1] = '\0'; // temp�� ���ڿ� �������� �ִ� ���๮�ڸ� �ι��ڷ� �ٲ� �ִ´�.
		if(strcmp(temp, "end") == 0) break; //end�� �ԷµǸ� �ݺ� ����
		len += strlen(temp) +1; // len�� temp ���ڿ��� ����+1�� ���Ͽ� len�� �����Ѵ�.
		pt = (char*) realloc(ps, len); //  ps ���̰� len�� char�� �迭�� Ȯ���Ͽ� ���Ҵ��� �޸� �ּҸ� pt�� �����Ѵ�.
		if (pt == NULL) //�����Ҵ翡 �����ϸ� NULL ������ ��ȯ
		{
		printf("�޸� ����...\n"); //�޼��� ���
		break; //����
		}
		ps=pt; // �迭�� ���������� ���Ҵ�Ǿ��ٸ� ps�� ps�� ���� ���Ҵ�� pt�� �Ҵ��Ѵ�.
		strcat(ps, temp); //ps���� ���ڿ��� temp�� �̾���δ�.
		strcat(ps, " "); //temp�� ���� �ٷ� ���� �ڸ��� " "(white space)�� ���δ�.
	}
	printf("%s\n",ps); //�Է��� ������ ���
	free(ps); //���� �Ҵ� ���� ���� �ݳ�
	return 0;
}