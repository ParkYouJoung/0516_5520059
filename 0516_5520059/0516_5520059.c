#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct listNode {
	element data;
	struct listNode* link;
} ListNode;

//처음 추가
ListNode* insert_first(ListNode* h, element value, int* Count) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = h;
	h = p;
	(*Count)++;
	return h;
}

// 중간 추가
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

//처음 삭제
ListNode* delete_first(ListNode* head, int* Count) {
	if (head == NULL) return NULL;
	ListNode* remove = head;
	head = remove->link;
	free(remove);
	(*Count)++;
	return head;
}

//중간 삭제 
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

// 이동횟수 나타내는 함수 
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

// main 부분

int main() {
	ListNode* head = NULL;
	int choice, position, n, Count;

	while (1) {
		printf("\n메뉴\n");
		printf("1. 숫자를 위치에 삽입\n");
		printf("2. 위치에서 숫자 삭제\n");
		printf("3. 리스트 출력\n");
		printf("0. 프로그램 종료\n");
		printf("선택하세요: ");
		scanf("%d", &choice);
		printf("\n");

		switch (choice) {
		case 1:
			printf("삽입할 숫자를 입력하세요: ");
			scanf("%d", &n);
			printf("삽입할 위치를 입력하세요: ");
			scanf("%d", &position);

			if (position == 0) {
				head = insert_first(head, n, &Count);
			}
			else {
				ListNode* pre = head;
				for (int i = 0; i < position - 1; i++) {
					if (pre == NULL) {
						printf("잘못된 위치입니다.\n");
						break;
					}
					pre = pre->link;
				}
				if (pre != NULL) {
					head = insert(head, pre, n, &Count);
				}
			}
			printf("삽입시 링크를 따라 이동한 횟수: %d\n", Count);
			break;
		case 2:
			printf("삭제할 위치를 입력하세요: ");
			scanf("%d", &position);

			if (position == 0) {
				head = delete_first(head, &Count);
			}
			else {
				ListNode* pre = head;
				for (int i = 0; i < position - 1; i++) {
					if (pre == NULL || pre->link == NULL) {
						printf("잘못된 위치입니다.\n");
						break;
					}
					pre = pre->link;
				}
				if (pre != NULL && pre->link != NULL) {
					head = delete(head, pre, &Count);
				}
			}
			printf("삭제시 링크를 따라 이동한 횟수: %d\n", Count);
			break;
		case 3:
			print_list(head);
			break;
		case 0:
			exit(0);
		default:
			printf("유효하지 않은 선택입니다.!\n");
		}
	}
	return 0;
}

