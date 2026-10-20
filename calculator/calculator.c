#include <stdio.h>

#define MAX 100

double plus(double nums[], int n);
double minus(double nums[], int n);
double divide(double nums[], int n);
double multiply(double nums[], int n);

int main(void)
{
    double nums[MAX];
    double result;
    char operator;
    int n;

    // Enter total count
    printf("How many numbers? ");
    scanf("%d", &n);

    if (n < 2 || n > MAX)
    {
        printf("Please a enter a number between %d & %d\n", 2, MAX);
        return 1;
    }

    // Loop through total count
    for (int i = 0; i < n; i++)
    {
        printf("Enter number %d\n", i + 1);
        scanf("%lf", &nums[i]);
    }

    // Enter operator
    printf("Please enter operator: ");
    scanf(" %c", &operator);

    switch (operator)
    {
    case '+':
        result = plus(nums, n);
        break;
    case '-':
        result = minus(nums, n);
        break;
    case '/':
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                printf("Cannot divide by 0 \n");
                return 1;
            }
        }
        result = divide(nums, n);
        break;
    case '*':
        result = multiply(nums, n);
        break;
    default:
        printf("Invalid operator '%c'\n", operator);
        return 1;
    }

    printf("Result: %g\n", result);

    return 0;
}

double plus(double nums[], int n)
{
    double total = nums[0];
    for (int i = 1; i < n; i++)
    {
        total += nums[i];
    }
    return total;
}

double minus(double nums[], int n)
{
    double total = nums[0];
    for (int i = 1; i < n; i++)
    {
        total -= nums[i];
    }
    return total;
}

double divide(double nums[], int n)
{
    double total = nums[0];
    for (int i = 1; i < n; i++)
    {
        total /= nums[i];
    }
    return total;
}

double multiply(double nums[], int n)
{
    double total = nums[0];
    for (int i = 1; i < n; i++)
    {
        total *= nums[i];
    }
    return total;
}