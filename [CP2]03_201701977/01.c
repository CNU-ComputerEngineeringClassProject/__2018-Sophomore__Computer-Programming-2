#include <stdio.h>

int main(void){

	int numberOfLine=1; //���� ������ ���� �����̰�, 1�� �ʱ�ȭ ���ش�.
	int numberOfColumns, frontBlank, createLine, createSpace; // ���� ����, �� ���� ��ĭ ����, ���� ����, ĭ ������ ���� ������ �����.
	
	while(numberOfLine !=0 ){ //0�� �Է� �ޱ� ������ ����ؼ� ���α׷��� �����Ų��.

	printf("������ �Է��� �ּ��� : [���� : 0]\n"); // ������ �Է� �ް� �ϴ� �޼����� ����Ѵ�.
	scanf("%d",&numberOfLine); // ���� ������ �Է¹޴´�.
	
	if(numberOfLine ==0){ //������ 0�� �Է¹޾��� ��� ���α׷��� �����Ѵ�. 
		return 0;
	}
	else if(numberOfLine < 0 || numberOfLine>10){ //������ ������ 10�̻��� ���� �Է� �޾��� ��� �ٽ� �Է��϶�� �޼����� ����Ѵ�.
		printf("�ٽ� �Է����ּ���!\n\n");

	}else{	// ������ 0���� ũ�� 10���� ���ų� ���� ���� �Է¹޾��� ���.

		numberOfColumns = (numberOfLine * 2) -1; // ���� ������ ����Ѵ�. (�Է¹��� ���� ���� *2 -1)
		frontBlank =numberOfLine-1; // ù �࿡�� ����� �� ���� ��ĭ������ ����Ѵ�. (�Է¹��� ���� ���� -1)

		
	for(createLine=0 ; createLine<numberOfLine ; createLine++){ //����ڰ� �Է��� ���� ������ŭ ����ϵ��� �Ѵ�. 
		for(createSpace=1 ; createSpace<= numberOfColumns ; createSpace++){ // ĭ������ ���� ������ŭ�� ����������� �Ѵ�.
			
			if(createSpace <= frontBlank || createSpace > numberOfColumns-frontBlank){ 
				// ĭ���� ������ ������ ��ĭ ������ ���ų� ������(�� �պκ��� ��ĭ�� �����ϱ� ���ؼ�), 
				// �Ǵ� ĭ���� ������ ���ǰ������� ���� ���� ������ �� ���� Ŭ�� (�� �޺κ��� ��ĭ�� �����ϱ����ؼ�) ��ĭ�� �����Ѵ�.
				putchar(' ');
			}else{ //�׿ܿ��� ���� ����Ѵ�.
				printf("*");
			}
		
		}//�� ���� ��ĭ�� ���� ��� ��µǾ����� ���´�.

		frontBlank=frontBlank-1;// �� �� ��ĭ ������ �ϳ� ���δ�.
		putchar('\n'); //���� �����ٷ� �ٲ۴�.
	}
		
	}
	
	}
}