#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct listNode {
	element data;
	struct listNode* link;
} ListNode;

//ó�� �߰�
ListNode* insert_first(ListNode* h, element value, int* Count) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = h;
	h = p;
	(*Count)++;
	return h;
}

// �߰� �߰�
ListNode* insert(ListNode* head, ListNode* pre, element value, int* Count) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	if (pre == NULL) {
		fprintf(stderr, "Insert parameter error in pre == NULL");
		return head;
	}
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	(*Count)++;
	return head;
}

//ó�� ����
ListNode* delete_first(ListNode* head, int* Count) {
	if (head == NULL) return NULL;
	ListNode* remove = head;
	head = remove->link;
	free(remove);
	(*Count)++;
	return head;
}

//�߰� ���� 
ListNode* delete(ListNode* h, ListNode* pre, int* Count) {
	if (pre == NULL || pre->link == NULL) {
		fprintf(stderr, "Delete parameter error");
		return h;
	}
	ListNode* remove = pre->link;
	pre->link = remove->link;
	free(remove);
	(*Count)++;
	return h;
}

// �̵�Ƚ�� ��Ÿ���� �Լ� 
int Count(ListNode* h, ListNode* target) {
	int Count = 0;
	while (h != target) {
		Count++;
		h = h->link;
	}
	return Count;
}


void print_list(ListNode* h) {
	while (h != NULL) {
		printf("%d-> ", h->data);
		h = h->link;
	}
	printf("NULL\n");
}

// main �κ�

int main() {
	ListNode* head = NULL;
	int choice, position, n, Count;

	while (1) {
		printf("\n�޴�\n");
		printf("1. ���ڸ� ��ġ�� ����\n");
		printf("2. ��ġ���� ���� ����\n");
		printf("3. ����Ʈ ���\n");
		printf("0. ���α׷� ����\n");
		printf("�����ϼ���: ");
		scanf("%d", &choice);
		printf("\n");

		switch (choice) {
		case 1:
			printf("������ ���ڸ� �Է��ϼ���: ");
			scanf("%d", &n);
			printf("������ ��ġ�� �Է��ϼ���: ");
			scanf("%d", &position);

			if (position == 0) {
				head = insert_first(head, n, &Count);
			}
			else {
				ListNode* pre = head;
				for (int i = 0; i < position - 1; i++) {
					if (pre == NULL) {
						printf("�߸��� ��ġ�Դϴ�.\n");
						break;
					}
					pre = pre->link;
				}
				if (pre != NULL) {
					head = insert(head, pre, n, &Count);
				}
			}
			printf("���Խ� ��ũ�� ���� �̵��� Ƚ��: %d\n", Count);
			break;
		case 2:
			printf("������ ��ġ�� �Է��ϼ���: ");
			scanf("%d", &position);

			if (position == 0) {
				head = delete_first(head, &Count);
			}
			else {
				ListNode* pre = head;
				for (int i = 0; i < position - 1; i++) {
					if (pre == NULL || pre->link == NULL) {
						printf("�߸��� ��ġ�Դϴ�.\n");
						break;
					}
					pre = pre->link;
				}
				if (pre != NULL && pre->link != NULL) {
					head = delete(head, pre, &Count);
				}
			}
			printf("������ ��ũ�� ���� �̵��� Ƚ��: %d\n", Count);
			break;
		case 3:
			print_list(head);
			break;
		case 0:
			exit(0);
		default:
			printf("��ȿ���� ���� �����Դϴ�.!\n");
		}
	}
	return 0;
}

