/*
Assignment 3
DUE DATE: 10/23
FERMI PICO unit test
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//function prototypes
void play_game();
void generate_secret_number(int *, int *, int *);
int is_guess_correct(int, int, int, int);
void print_hint(int, int, int, int); 


int main(int argc, char const *argv[])
{
    srand(time(NULL));  

    play_game(); // call play_game to start the game
    return 0;
}


// start of fermi, pico, bagel game. This function will call the other functions of the game
// go back and refractor before due date
void play_game()
{
    int play_again_check;
    int user_guess;
    int remainder;
    int guess_digit_one, guess_digit_two, guess_digit_three, full_generated_number;
    int digit_one, digit_two, digit_three; // location for the generated number
    int *digit_one_ptr = NULL, *digit_two_ptr = NULL, *digit_three_ptr = NULL;  // pointers to the generated digits

    digit_one_ptr = &digit_one;
    digit_two_ptr = &digit_two;
    digit_three_ptr = &digit_three;
 
    generate_secret_number(digit_one_ptr, digit_two_ptr, digit_three_ptr);

    do
    {
        printf("\n\nDo you want to play Fermi, Pico, Bagel?\n");
        printf("Press 1 for YES\n");
        scanf("%d", &play_again_check);

        if (play_again_check == 1){
            // begin the game
            printf("\nEnter A 3 Digit Number Please\n");
            scanf("%d", &user_guess); // put this at the beginning and add an if statement to stop before playing a new game

            printf("\nGenerated Number: %d%d%d\n", digit_one, digit_two, digit_three);            
            is_guess_correct(digit_one, digit_two, digit_three, user_guess);

        }
        else{

            printf("OK Thanks for playing!\n");
            break;           
        }
        
    } while (10 > 0); // change this to stop if "is_guess_correct()" returns the right value
    
}


// generate random number that the user will try and guess. 
void generate_secret_number(int *one_generate, int *two_generate, int *three_generate)
{
    int digit_one_generated, digit_two_generated, digit_three_generated;

    // secret number
    digit_one_generated = (rand() % 9) + 1; // first digit cannot be zero;
    digit_two_generated = rand() % 10;
    digit_three_generated = rand() % 10;
        
    *one_generate = digit_one_generated;
    *two_generate = digit_two_generated;
    *three_generate = digit_three_generated;

}


int is_guess_correct( int digit_one_generated_check, int digit_two_generated_check, int digit_three_generated_check, int user_input)
{
    int guess_digit_one, guess_digit_two, guess_digit_three, remainder;

    guess_digit_one = user_input / 100;
    remainder = user_input % 100;
    guess_digit_two = remainder / 10;
    remainder = remainder % 10;
    guess_digit_three = remainder;

    if (guess_digit_one == digit_one_generated_check && guess_digit_two == digit_two_generated_check && guess_digit_three == digit_three_generated_check)
    {
        printf("\nYOU'VE WON!!!\n");
        // ADD A RETURN THAT WILL GO BACK TO play_game() AND ALERT THE USER
        return 1; // for now  
    }
    else
    {
        print_hint(digit_one_generated_check, digit_two_generated_check, digit_three_generated_check, user_input);
    }


    return 0; // return a value if true or false -- come back to this 
}


// Fermi Pico, unit testing
void print_hint(int d_one, int d_two, int d_three, int user_input_check)
{
    int guess_one, guess_two, guess_three, remainder;

    guess_one = user_input_check / 100;
    remainder = user_input_check % 100;
    guess_two = remainder / 10;
    remainder = remainder % 10;
    guess_three = remainder;

    /* 

    Fermi Pico, unit testing
    Test Points:
        generated number = 345 -> ABC
    542 -> dig1 = C && dig2 = B && dig3 != A
        -> dig1 = A && dig2 = C && dig3 != B
        -> dig1 = B && dig2 = A && dig3 != C

    */
    if ( guess_one == d_three && guess_two == d_two && guess_three != d_one || guess_one == d_one && guess_two == d_three && guess_three != d_two || guess_one == d_two && guess_two == d_one && guess_three != d_three)
    {
        printf("\n\nGuess = %d, Fermi Pico\n\n", user_input_check);
        /* start more evaluation here */
    }
    else
    {
        printf("\n\nGuess = %d, Bagels\n\n", user_input_check);
    }

}
