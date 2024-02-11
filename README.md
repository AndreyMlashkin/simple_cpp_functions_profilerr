Example:

void nestedFunction()
{
    TRACK;
    auto lambda = []()
    {
        TRACK;
        std::cout << "lambda body\n";
    };
    std::cout << "nestedFunction body\n";
}

nestedFunction();

Output:
->nestedFunction
->operator()
lambda body
<-operator() exited in 241
nestedFunction body
<-nestedFunction exited in 714
