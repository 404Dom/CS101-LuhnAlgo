#include <iostream>
using namespace std;

int main()
{
    char input[17];     // after testing, 16 digits exactly breaks this, so I had to make it 17.
    int digits[16];     // reading up on it, it seems that it needs 17 for the null character, \0.
    int total = 0;      // total sum var

    cout << "Enter your 16-digit card number: ";
    cin >> input;       // user input goes here

    int len = 0;    // length var
    while (input[len] != '\0')  // checks the length of the input number
    {
        len++;      // length goes up until it hits the null, making sure it's 16
    }

    if (len != 16)
    {
        cout << "That's not 16. You can't scam me!" << endl;    // if not 16 long, ends
        return 0;
    }

    for (int i = 0; i < 16; i++)    // this section converts char to int (0-9)
    {
        if (input[i] >= '0' && input[i] <= '9')     // if valid number, it goes into the array
        {
            digits[i] = input[i] - '0';     // i had to look into ASCII codes to make this work proprely. you're looking at an if statement that took 3 hours to finish.
        }                                   // and it's only technically two lines. quite the learning experience.
        else    // if given letter, end program.
        {
            cout << "It seems you gave me a letter, and not a number. You're going to the shadow realm for that one." << endl;
            return 0;
        }
    }

    for (int j = 15; j >= 0; j--)       // Luhn time. starting from the rightmost digit
    {
        int num = digits[i];
        if ((15 - j) % 2 == 1)      // every second one gets doubled (from the end)
        {
            num *= 2;
            if (num > 9)        // if number is higher than 9, it gets split up
            {
                num = (num % 10) + 1; // add digits together
            }
        }
        total += num;
    }

    if (total % 10 == 0)        // last step- checking for modulo 10 equaling 0.
    {
        cout << "Thank you for your card info. You have sponsered my upcoming shopping spree!" << endl;
    }
    else
    {
        cout << "Why would you lie to me like this. Your card number is just like the cake- a lie." << endl;
    }
    return 0;
}