#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define WORDS_LENGTH 13

char words[][WORDS_LENGTH] =    {
                                "apple",
                                "juice",
                                "beer",
                                "rabbit",
                                "jaguar"
                                };

         char hints[][100] =    {
                                "Fruit.",
                                "You can drink it.",
                                "Men love to drinks it.",
                                "Small animal.",
                                "Wild animal"
                                };

int printMenu(void);

int printHangman(int choice);

int main()

{

    int choosedWordLength = 0;

    int i;

    int wrongLoopChar;

    char menuChoice;

    int succesChar = 0;

    int wrongChar = 0; //max 5;

    int wrongCharMax = 5;

    int random;

    int wordsArraySize = sizeof(words) / WORDS_LENGTH;

    char charChoice[100];

    srand(time(0));

        do {

        random = rand() % wordsArraySize; //get random numbers from 0 to 4

        printMenu();

        printf("\n\n Enter your choice: ");

        scanf("%s", &menuChoice);

           if (menuChoice == 1 + '0' ) {

                printf("\n\n -- You started new game. -- \n\n");

                choosedWordLength = strlen(words[random]);

                char guessWord[choosedWordLength];

                for(i = 0; i < choosedWordLength; i++ ) {

                    guessWord[i] = '_';

                }

                    do {

                    printf("\n -- HINT: %s -- \n\n", hints[random]);

                    printf(" Try to guess word: ", choosedWordLength );
                    for(i = 0; i < choosedWordLength; i++) {

                        printf(" %c ", guessWord[i]);

                    }

                    printf("\n\n");

                    printf("\n -- Enter your character to guess the word: ");

                    scanf("%s", &charChoice);

                    for(i = 0; i < choosedWordLength; i++) {

                            if( (charChoice[0] == words[random][i] ) && guessWord[i] != '_'  ) {
                                printf("\n -- You get wrong letter because you spam \'%c\' letter. -- \n", charChoice[0]);
                                wrongChar++;
                                break;
                            }

                            if( (charChoice[0] == words[random][i] )  && guessWord[i] == '_' ) {
                                guessWord[i] = charChoice[0];
                                succesChar++;
                            }

                            if( charChoice[0] != words[random][i] ) {
                                wrongLoopChar++;
                            }
                            
                    }

                    if(wrongLoopChar == choosedWordLength) {
                                wrongChar++;
                    }

                              wrongLoopChar = 0;

                    if(charChoice != words[random])
                    printf("\n Properly letters: %d", succesChar);
                    printf("\n Chances: %d to wrong letter\n\n", wrongCharMax - wrongChar);

                    printHangman(wrongChar);

                    printf("\n\n");


                    } while(wrongChar < 5 && succesChar != choosedWordLength);


                    for(i = 0; i < choosedWordLength; i++) {
                            
                        printf(" %c ", guessWord[i]);
                        
                    }

                    if(wrongChar == 5){ 
                        printf("\n\n - - - - - You Lose! - - - - - -");
                    } else if(succesChar == choosedWordLength) {
                        printf("\n\n - - - - - You Win! - - - - - -");
                    }

                    succesChar = 0;
                    wrongChar = 0;
                    choosedWordLength = 0;

            } else if(menuChoice == 0 + '0') {

                printf("\n\n --- You quit! --- \n");

            } else {

                printf("\n\n --- Invalid choice ---\n");
                
                if(isalpha(menuChoice) != 0 ) {

                printf(" -- This is not number! -- ");
                
                }
            }

        } while(menuChoice != 0 + '0');
    printf("\n\n\n");
    return 0;
}

printMenu(void) {
 
    printf("\n\n--------------HANGMAN----------------");
    printf("\n\n -- 1. Press 1 to start new game -- ");
    printf("\n -- 2. Press 0 to quit from game -- ");
    printf("\n\n NOTE: If you CAPS LOCK is ON, stop it. Only english letters and words.");


}


printHangman(int wrongChar) {
                    /*
                    if(wrongChar == 0){
                        printf("   \n");
                        printf("|      \n");
                        printf("|      \n");
                        printf("|      \n");
                        printf("|      \n");
                        printf("|      \n");
                        printf("|___________|      \n");
                        printf("|___________|");
                      }
                    */
                     //else
                     if(wrongChar == 1) {

                        printf(" ________  \n");
                        printf("|       |\n");
                        printf("|      \n");
                        printf("|      \n");
                        printf("|      \n");
                        printf("|      \n");
                        printf("|___________|      \n");
                        printf("|___________|");

                    } else if(wrongChar == 2) {

                        printf(" ________  \n");
                        printf("|       |\n");
                        printf("|       0 \n");
                        printf("|      \n");
                        printf("|      \n");
                        printf("|      \n");
                        printf("|___________|      \n");
                        printf("|___________|");

                    } else if(wrongChar == 3) {
                        printf(" ________  \n");
                        printf("|       |\n");
                        printf("|       0 \n");
                        printf("|      \\|/   \n");
                        printf("|      \n");
                        printf("|      \n");
                        printf("|___________|      \n");
                        printf("|___________|");

                    } else if(wrongChar == 4) {

                         printf(" ________  \n");
                        printf("|       |\n");
                        printf("|       0 \n");
                        printf("|      \\|/   \n");
                        printf("|       |\n");
                        printf("|      /\n");
                        printf("|___________|      \n");
                        printf("|___________|");

                    } else if(wrongChar == 5) {

                        printf(" ________  \n");
                        printf("|       |\n");
                        printf("|       0 \n");
                        printf("|      \\|/   \n");
                        printf("|       |\n");
                        printf("|      / \\ \n");
                        printf("|___________|      \n");
                        printf("|___________|");

                    }

}
