/*************************************************************************
	> File Name: solution_no_extra_memory.cc
	> Author: MarkWoo
	> Mail:wcgwuxinwei@gmail.com 
	> Created Time: Tue 25 Aug 2015 12:49:25 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#define DEBUG std::cout << "DEBUG" << std::endl;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
			if (!head || !head->next) {
				return head;
			}

			ListNode *ptr = head->next;

			while (ptr != NULL) {
				ListNode *tmp = ptr->next;
				ptr->next = head;
				head = ptr;
				ptr = tmp;
			}

			return head;
		}
};

int main(void) {
	Solution s1;
	ListNode *head = new ListNode(0);
	ListNode *ptr = head;
	srand(time(NULL));

	std::cout << "before: " << std::endl;
	for (int i = 0; i < 5; ++i) {
		ListNode *new_node = new ListNode(rand());
		std::cout << new_node->val << " ";
		ptr->next = new_node;
		ptr = ptr->next;
	}
	std::cout << std::endl;

	head->next = s1.reverseList(head->next);

	ptr = head->next;
	std::cout << "after: " << std::endl;
	for (int i = 0; i < 5; ++i) {
		std::cout << ptr->val << " ";
		ptr = ptr->next;
	}
	std::cout << std::endl;
	return 0;
}
