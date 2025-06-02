#include <stdio.h>


/* prototyping functions  :D */
// addition block
double add(double inp_1, double inp_2) {
  double sum;
  sum = inp_1+inp_2;
  return sum;
}

// subtraction block
double sub(double inp_1, double inp_2) {
  double sub_out;
  sub_out = inp_1-inp_2;
  return sub_out;
}

// multiply block
double multiply(double inp_1, double inp_2) {
  double product;
  product = inp_1*inp_2;
  return product;
}


// division block
double divide(double inp_1, double inp_2) {
  double divide_out;
  divide_out = inp_1/inp_2;
  return divide_out;
}

// Main block
int main() {
  double input_1,input_2;
  char operation;

  //user input
  printf("Welcome!!\n");
  printf("Enter a number or value: ");
  scanf("%lf",&input_1);
  printf("Enter another number or value: ");
  scanf(" %lf",&input_2);
  printf("\nEnter operation to perform (+,-,*,/) -> ");
  scanf(" %c",&operation);

  //condition checking 
  if (operation == '+') {
    printf("The sum of two numbers is %lf \n",add(input_1,input_2));
  } else if (operation == '-') {
    printf("The difference between two numbers is %lf \n",sub(input_1,input_2));
  } else if (operation == '*') {
    printf("The product of two numbers is %lf \n",multiply(input_1,input_2));
  } else if (operation == '/') {
    if (input_2 == 0) {
      printf("Error: Division by zero is not allowed.\n");
    } else {
      printf("The quotient of two numbers is %f \n",divide(input_1,input_2));
    }
  } else {
    printf("Invalid operator. Please enter a valid operator (+, -, *, /).\n");
  }

  return 0;
}
