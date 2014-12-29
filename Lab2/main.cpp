#include <iostream> // gives you cout, cin, endl, etc.
using namespace std; // so you don’t have to say std::cout, std::endl, etc.

int main()
{
    unsigned int array_size; // upper limit of numbers to check for primes
    unsigned int counter;
    cout << "Find primes from 0 to what? "; // ask user for upper limit
    cin >> array_size; // get size from user
    array_size++; // add one slot for 0 to the size

    bool prime_numbers[array_size]; // make the bool array for
    // the numbers 0 to upper limit

    //flips everything to true except 0 and 1
    for (int i=0;i<array_size;i++)
    {   if (i==0||i==1)
            prime_numbers[i]=false;
        else
            prime_numbers[i]=true;
    }

    counter=2;

    //flips everything that doesn't satisfy the prime number conditions to false
    while (counter<array_size)
    {
        for (int j=0;j<array_size;j++) //
        {
            if (j%counter==0&&j!=counter)
                prime_numbers[j]=false;
        }
        counter++;
    }

    for (unsigned int k = 0; k < array_size; k++)
    cout << k << " " << prime_numbers[k] << endl;


}
