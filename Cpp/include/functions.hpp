int division(int a, int b)
{
    if (0 == b)
    {
        std::cout << "Math error: Attempted to divide by Zero" << std::endl;
        return 0;
    }
    return a / b;
}