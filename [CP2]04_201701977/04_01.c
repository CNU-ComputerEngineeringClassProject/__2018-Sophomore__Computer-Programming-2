#include <stdio.h>

int main(void){

	int numberOfLine=1; //���� ������ ���� �����̰�, 1�� �ʱ�ȭ ���ش�.
	int numberOfColumns, frontBlank, createLine, createSpace; // ���� ����, �� ���� ��ĭ ����, ���� ����, ĭ ������ ���� ������ �����.
	
	printf("����� �Է��ϼ��� : "); // ������ �Է� �ް� �ϴ� �޼����� ����Ѵ�.
	scanf("%d",&numberOfLine); // ���� ������ �Է¹޴´�.
	

	while(numberOfLine < 0 || numberOfLine>20){ //������ ������ 20�̻��� ���� �Է� �޾��� ��� �ٽ� �Է��϶�� �޼����� ����Ѵ�.
		if(numberOfLine < 0 || numberOfLine>20){
		printf("�ٽ� �Է����ּ���!\n\n");
		}
		printf("����� �Է��ϼ��� : "); // ������ �Է� �ް� �ϴ� �޼����� ����Ѵ�.
		scanf("%d",&numberOfLine); // ���� ������ �Է¹޴´�.
		
	}

	if(numberOfLine%2 ==0 ){ //���� �Է¹��� ���� ������ ¦���ϰ��

		numberOfLine = numberOfLine / 2 ; //���� ������ ������ ������. (���κа� �Ʒ��κ��� ���� ����� ���ؼ�)
		numberOfColumns = (numberOfLine * 2) -1; // ���� ������ ����Ѵ�. (�Է¹��� ���� ������ �� *2 -1)
		frontBlank =numberOfLine-1; // ù �࿡�� ����� �� ���� ��ĭ������ ����Ѵ�. (�Է¹��� ���� ������ �� -1)

		
	for(createLine=0 ; createLine<numberOfLine ; createLine++){ //����ڰ� �Է��� ���� ������ �ݸ�ŭ ����ϵ��� �Ѵ�. 
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

	//�Ʒ��κ� ����� (���κ��� �ﰢ���̷� �Ʒ��� ���ﰢ���̱⶧���� �ݴ�� ����ٰ� ������.)

	frontBlank = 0; //���� ��ĭ ������ 0���� �ʱ�ȭ �Ѵ�.

	for(createLine =0 ; createLine<numberOfLine ; createLine++){ //����ڰ� �Է��� ���� ������ �ݸ�ŭ ����ϵ��� �Ѵ�. 

		for(createSpace=1 ; createSpace<= numberOfColumns ; createSpace++){ // ĭ������ ���� ������ŭ�� ����������� �Ѵ�.
			
			if(createSpace <= frontBlank || createSpace > numberOfColumns-frontBlank){ 
				// ĭ���� ������ ������ ��ĭ ������ ���ų� ������(�� �պκ��� ��ĭ�� �����ϱ� ���ؼ�), 
				// �Ǵ� ĭ���� ������ ���ǰ������� ���� ���� ������ �� ���� Ŭ�� (�� �޺κ��� ��ĭ�� �����ϱ����ؼ�) ��ĭ�� �����Ѵ�.
				putchar(' ');
			}else{ //�׿ܿ��� ���� ����Ѵ�.
				printf("*");
			}
		
		}//�� ���� ��ĭ�� ���� ��� ��µǾ����� ���´�.

		frontBlank=frontBlank+1;// �� �� ��ĭ ������ �ϳ� �ø���.
		putchar('\n'); //���� �����ٷ� �ٲ۴�.
	}
	}
	
	
	else{//���� ������ Ȧ���ϰ��

		numberOfLine = numberOfLine / 2 +1; //Ȧ���� �߰��� ���� ����� �����ֱ⶧���� ���� �������� 2�� ���� �ϳ��� �����ش�. (���κ��� �Ʒ��ٺ��� ���� �� ����� ���ؼ�)
		numberOfColumns = (numberOfLine * 2) -1; // ���� ������ ����Ѵ�. (numberOfLine *2 -1)
		frontBlank =numberOfLine-1; // ù �࿡�� ����� �� ���� ��ĭ������ ����Ѵ�. (numberOfLine -1)

		
	for(createLine=0 ; createLine<numberOfLine ; createLine++){ //����ڰ� �Է��� ���� ������ ��+1 ��ŭ ����ϵ��� �Ѵ�. 
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

	//�Ʒ��κ� ����� (���κ��� �ﰢ���̷� �Ʒ��� ���ﰢ���̱⶧���� �ݴ�� ����ٰ� ������./)
	//�׸��� Ȧ���� �Ʒ��κ��� ���� �� �������Ѵ�. (�Ʒ��κ��� �߰��� ��ĭ���� ���� ��κ��� �������)

	frontBlank = 1; // �� �� ��ĭ ������ 1�� �ʱ�ȭ �Ѵ�.

	for(createLine =1 ; createLine<numberOfLine ; createLine++){ //����ڰ� �Է��� ���� ������ �ݸ�ŭ ����ϵ��� �Ѵ�. 

		for(createSpace=1 ; createSpace<= numberOfColumns ; createSpace++){ // ĭ������ ���� ������ŭ�� ����������� �Ѵ�.
			
			if(createSpace <= frontBlank || createSpace > numberOfColumns-frontBlank){ 
				// ĭ���� ������ ������ ��ĭ ������ ���ų� ������(�� �պκ��� ��ĭ�� �����ϱ� ���ؼ�), 
				// �Ǵ� ĭ���� ������ ���ǰ������� ���� ���� ������ �� ���� Ŭ�� (�� �޺κ��� ��ĭ�� �����ϱ����ؼ�) ��ĭ�� �����Ѵ�.
				putchar(' ');
			}else{ //�׿ܿ��� ���� ����Ѵ�.
				printf("*");
			}
		
		}//�� ���� ��ĭ�� ���� ��� ��µǾ����� ���´�.

		frontBlank=frontBlank+1;// �� �� ��ĭ ������ �ϳ� �ø���.
		putchar('\n'); //���� �����ٷ� �ٲ۴�.
	}




	}

	}