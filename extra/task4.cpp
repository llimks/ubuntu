#include<iostream>
int main()
{   int n,i;
    std::cout <<"Enter a number : ";
    std::cin >> n;
    std::cout <<"Prime factors of "<<n<<" are";
    i=2;
    while(n>1)
    {   if(n%i==0)
        {   std::cout <<i<<" ";
            n=n/i;
        }
        else
            i++;
   }
   return 0;
}
