#include <stdio.h>
#include <stdlib.h>

typedef struct link {
  int dt;
  struct link *nxt;
} node;

node *head = NULL;

node *make() {
  node *temp = (node *)malloc(sizeof(node));
  if (temp == NULL) {
    perror("malloc failed");
    exit(EXIT_FAILURE);
  }
  printf("\nEnter no: ");
  scanf("%d", &temp->dt);
  temp->nxt = NULL;
  return temp;
}

void create() {
  int x;
  node *ptr = NULL; // Initialize ptr here

  while (1) {
    node *new_node = make(); // Create a new node

    if (head == NULL) {
      head = new_node; // Assign the new node to head
      ptr = new_node;  // ptr also points to the new node
    } else {
      ptr->nxt = new_node; // Link the current last node to the new node
      ptr = new_node;      // Move ptr to the new last node
    }

    printf("Do you want to continue (1 for Yes / 0 for No): ");
    scanf("%d", &x);
    if (x == 0) break;
  }
}

void Display() {
  node *ptr = head; // Use a local ptr for traversal
  while (ptr != NULL) {
    printf("%d ", ptr->dt);
    ptr = ptr->nxt;
  }
  printf("\n"); // Add a newline for better formatting
}

int main() {
  create();
  printf("Linked list: ");
  Display();
  return 0;
}
