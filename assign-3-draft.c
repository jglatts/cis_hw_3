#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// KEEP TRACK OF HOW MANY GUESSES
// WHEN USER QUITS, DISPLAY IF THEY WON OR LOST

//function prototypes
void play_game();
void generate_secret_number(int *, int *, int *);
int is_guess_correct(int, int, int, int);
void print_hint(int, int, int, int); 


int main(int argc, char const *argv[])
{
	int play_again_check;

	do
	{
		printf("\nDo You Want To Play Fermi Pico Bagel?\n");
		play_game(); //call play_game to start the game
		printf("Play Again?\n");
		printf("Enter 1 For Yes\n");
		scanf("%d", &play_again_check);
	} while (play_again_check = 1);	

    printf("OK Thanks for playing!\n");
	

    // add the final results

    return 0;
}

// start of fermi, pico, bagel game. This function will call the other functions of the game
// go back and refractor before due date
void play_game()
{
    int user_guess, remainder, correct_check;
    int guess_digit_one, guess_digit_two, guess_digit_three, full_generated_number;
    int number_of_guesses;
    int digit_one, digit_two, digit_three; // location for the generated number
    int *digit_one_ptr = NULL, *digit_two_ptr = NULL, *digit_three_ptr = NULL;  // pointers to the generated digits

    digit_one_ptr = &digit_one;
    digit_two_ptr = &digit_two;
    digit_three_ptr = &digit_three;

    generate_secret_number(digit_one_ptr, digit_two_ptr, digit_three_ptr);

    // begin the game
    printf("\nEnter A 3 Digit Number To Play\n");
    printf("Enter 0 To Quit At Anytime\n");
    do
    {
    	printf("Enter Guess\n");
        scanf("%d", &user_guess); // put this at the beginning and add an if statement to stop before playing a new game
        
        if (user_guess != 0)
        {
	        printf("\nGenerated Number: %d%d%d\n", digit_one, digit_two, digit_three);            
	        correct_check = is_guess_correct(digit_one, digit_two, digit_three, user_guess);       
        }        
        else{
            printf("OK Thanks for playing!\n");
            break;           
        }
        
    } while (user_guess != 0 && correct_check != 1); // change this to stop if "is_guess_correct()" returns the right value

}


// generate random number that the user will try and guess. 
void generate_secret_number(int *one_generate, int *two_generate, int *three_generate)
{
    int digit_one_generated, digit_two_generated, digit_three_generated;

    srand(time(NULL)); //seed for random number  

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

    if (guess_digit_one == digit_one_generated_check && 
    	guess_digit_two == digit_two_generated_check && 
    	guess_digit_three == digit_three_generated_check)
    {
        printf("\nYOU'VE WON!!!\n");
        return 1;   
    }
    else
    {
		print_hint(digit_one_generated_check, digit_two_generated_check, digit_three_generated_check, user_input);
    }


    return 0; // return a value if true or false -- come back to this 
}

// REWORK SOME OF THE SORT ALGORTIHIMS, NOT QUITE THERE 
void print_hint(int digit_one_check, int digit_two_check, int digit_three_check, int user_input_check)
{
    int guess_digit_one, guess_digit_two, guess_digit_three, remainder;

    guess_digit_one = user_input_check / 100;
    remainder = user_input_check % 100;
    guess_digit_two = remainder / 10;
    remainder = remainder % 10;
    guess_digit_three = remainder;

    // start of the user vs. comp check. Another check maybe needed before this for a winning guess
    if (guess_digit_one == digit_one_check && guess_digit_two == digit_two_check || guess_digit_one == digit_one_check && guess_digit_three == digit_three_check || guess_digit_two == digit_two_check && guess_digit_three == digit_three_check)
    {
        printf("Guess = %d, Fermi Fermi\n", user_input_check);
        /* start more evaluation here */
    }
    else if (guess_digit_one == digit_one_check && guess_digit_two == digit_three_check && guess_digit_three == digit_two_check || guess_digit_one == digit_two_check && guess_digit_three == digit_three_check || guess_digit_one == digit_three_check && guess_digit_two == digit_two_check)
    {
        printf("\nGuess = %d, Fermi Pico Pico\n", user_input_check);
        /* start more evaluation here */
    }
    // Fermi Pico
    else if (guess_digit_one == digit_one_check && guess_digit_two == digit_three_check && guess_digit_three != digit_two_check || 
        guess_digit_one == digit_one_check && guess_digit_three == digit_two_check && guess_digit_two != digit_three_check || 
        guess_digit_two == digit_two_check && guess_digit_three == digit_one_check && guess_digit_one != digit_three_check || 
        guess_digit_two == digit_two_check && guess_digit_one == digit_three_check && guess_digit_three != digit_one_check || 
        guess_digit_three == digit_three_check && guess_digit_two == digit_one_check && guess_digit_one != digit_two_check || 
        guess_digit_three == digit_three_check && guess_digit_one == digit_two_check && guess_digit_two != digit_one_check)
    {    
        printf("Guess = %d, Fermi Pico \n", user_input_check);
        /* start more evaluation here */
    }    
    else if (guess_digit_one == digit_two_check && guess_digit_two == digit_one_check && guess_digit_three != digit_three_check || guess_digit_three == digit_two_check && guess_digit_two == digit_three_check && guess_digit_one != digit_one_check|| guess_digit_one == digit_three_check && guess_digit_three == digit_one_check && guess_digit_two != digit_two_check)
    {
        printf("Guess = %d, Pico Pico\n", user_input_check);
        /* start more evaluation here */
    }
    else if (guess_digit_one == digit_one_check || guess_digit_two == digit_two_check || guess_digit_three == digit_three_check)
    {
        printf("Guess = %d, Fermi\n", user_input_check);
        /* start more evaluation here */
    }
    else if (guess_digit_one == digit_two_check || guess_digit_two == digit_three_check || guess_digit_three == digit_one_check)
    {
        printf("Guess = %d, Pico\n", user_input_check);
        /* start more evaluation here */
    }
    else
    {
        printf("Guess = %d, Bagels\n\n", user_input_check);
    }


}
