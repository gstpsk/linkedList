#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _node {
  int value;
  struct _node *next;
} node;

void debug(char* message) {
    char stamp[5];
    unsigned int now = (unsigned)time(NULL);
    stamp[0] = now / 10 / 10 / 10 % 10 + '0';
    stamp[1] = now / 10 / 10 % 10 + '0';
    stamp[2] = now / 10 % 10 + '0';
    stamp[3] = now % 10 + '0';
    stamp[4] = '\0';

    printf("\n%s | %s", stamp, message);
}

node* createNode() {
  node *result = (node *)malloc(sizeof(node));
  result->value = 0;
  result->next = NULL;
  debug("Created new node.");
  return result;
}

node* addNode(node* head, int value) {
  node *temp, *p;
  temp = createNode();
  temp->value = value;
  if (head == NULL) { // if the list is empty
    debug("HEAD is null, setting as genesis.");
    head = temp;
  } else {
    p = head;
    while (p->next != NULL) {
        p = p->next; // walk from head down to the last pointer
    }
    p->next = temp;
  }
  char s[255];
  sprintf(s, "Added node with value %d", value);
  debug(s);
  return head;
}

void printList(node* head) {
    printf("\n[");

    while (head != NULL) {
        printf(" %d ]-[", head->value);
        head = head->next;
    }

    printf(" end ]");
}

int main() {
  node *genesis = addNode(NULL, 69);
  for (int i = 0; i < 10; i++) {
    addNode(genesis, i+1);
  }
  printList(genesis);
}