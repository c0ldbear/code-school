int add(int number_a, int number_b)
{
    return number_a + number_b;
}

int main()
{
    int sum = 5;
    sum = add(sum, add(5,10));

    return sum;
}