#include <stdio.h>
#include <string.h>


void printBody(int mistakes) {
	switch(mistakes) {

        case 0: printf( "\n-------\n"
                        "|     |\n"
                        "|     0 \n"
                        "|    /|\\ \n"
                        "|     | \n"
                        "|    | | \n"
                        "|\n"
                        "|\n"
                        "|---------\n");
                break;

		case 1: printf( "\n-------\n"
                        "|     |\n"
                        "|     0 \n"
                        "|    /|\\ \n"
                        "|     | \n"
                        "|\n"
                        "|\n"
                        "|\n"
                        "|---------\n");
                break;
		case 2: printf( "\n-------\n"
                        "|     |\n"
                        "|     0\n"
                        "|    /|\\ \n"
                        "|\n"
                        "|\n"
                        "|\n"
                        "|\n"
                        "|---------\n");
                break;
		case 3: printf( "\n-------\n"
                        "|     |\n"
                        "|     0\n"
                        "|\n"
                        "|\n"
                        "|\n"
                        "|\n"
                        "|\n"
                        "|---------\n");
                break;
		case 4: printf( "\n-------\n"
                        "|     |\n"
                        "|      \n"
                        "|\n"
                        "|\n"
                        "|\n"
                        "|\n"
                        "|\n"
                        "|---------\n");
                break;
		case 5:
                printf( "\n-------\n"
                        "|\n"
                        "|\n"
                        "|\n"
                        "|\n"
                        "|\n"
                        "|\n"
                        "|---------\n");
                break;
		default: break;

	};
}


char playGame(int stage){
    char guess,success,word[100];
    int i,j,k,m,found,num;
    printf("\nEnter a number from 1-10 for stage %d: ",stage);
    scanf(" %d",&num);

    switch(num) {

        case 1: strcpy(word,"January");
                break;

		case 2: strcpy(word,"February");
                break;

		case 3: strcpy(word,"March");
                break;

		case 4: strcpy(word,"April");
                break;

		case 5: strcpy(word,"June");
                break;

		case 6: strcpy(word,"August");
                break;

        case 7: strcpy(word,"September");
                break;

        case 8: strcpy(word,"October");
                break;

        case 9: strcpy(word,"November");
                break;

        case 10: strcpy(word,"December");
                break;

		default: break;

    }


    int leng = strlen(word);

    //declaring an array to to keep track of correct guess
    int arr[leng];
    for ( i=0; i < leng; ++i) {
        arr[i] = 0;
    }
    //declaring a variable name flag which will determine when to break the while loop
    int flag = 0;
    int mistake = 5;

    int last=leng-1;

    //to give a clue for first and last letter
    arr[0]=1;
    arr[last]=1;

    while (flag == 0) {
    // Print word for unguessed letters
        printf("\n\nThe word is : ");

        for(j=0; j < leng; ++j) {
            if (arr[j] != 0) {
                printf("%c", word[j]);
            }
        else {
            printf("*");
            }
        }

       //  guess the Letter
        printf("\n\nGuess the Letter: ");

        scanf(" %c", &guess);

        found=strchr(word,guess);

        if(found == 0){
            mistake=mistake-1;
            printBody(mistake);
            if(mistake == 0){
                printf("\n\t \t Your chance is over you are hanged. The word was :: %s \n", word);
                success='f';
                break;
            }
        }
        else{
     // Mark true all mask positions corresponding to guess
            for( k=0; k < leng; ++k) {
            if (word[k] == guess) {
                arr[k] = 1;
                }
            }
        printBody(mistake);
        }

        printf("\n\nYou have %d chance left.",mistake);

        // Determine whether the player has won!
        flag = 1;
        for( m = 0; m < leng; ++m) {
          if (arr[m] == 0) {
            flag = 0;
            break;
          }
        }
        if(flag == 1){
            printf("\nWOW you have finished this stage! \n The word was :: %s \n", word);

        }
     success='t';
    }
    return success;
}




int main() {
    int stage=1,extraChance=1;
    char s,choice;
    s=playGame(stage);

    if(s == 't' ){
        stage=stage+1;
        printf("\ndo you want to continue if yes enter 'y': ");
        scanf(" %c", &choice);

     //stage 2 starts
       if(choice == 'y'){
        s=playGame(stage);

        if(s == 't'){
            stage=stage+1;
            printf("\ndo you want to continue if yes enter 'y': ");
            scanf(" %c", &choice);
            //stage 3 starts
             if(choice == 'y'){
                s=playGame(stage);
                if(s == 't'){
                    printf("\n \t \t Congratulation!! you have completed all the stage. \n");
                }
                // if user complete stage 1 he/she gets another chance
                // extra chance for 3rd stage because you didnt use your extra chance in 2nd stage
                else if(extraChance == 1){
                    extraChance=0;

                    printf("\nYou have an extra chance do you want to continue if yes enter 'y': ");
                    scanf(" %c", &choice);
                    //stage 3 starts extra chance
                    if(choice == 'y'){
                        s=playGame(stage);
                        if(s == 't'){
                            printf("\n \t \t Congratulation!! you have completed all the stage. \n");
                        }

                        //game over because the user used all the chances
                        //game over for stage 3.
                        else{
                            printf("\n \t \t GAME OVER \n");
                        }


                    }
                    //else for case when failed to guess in 3rd stage extra chance.
                    else{
                        printf("\n \t \t GAME OVER \n");
                    }


                }

             }
             //2nd stage game over if you dont want to play
             else{
                printf("\n \t \t GAME OVER \n");
            }
        }

        // if user complete stage 1 he/she gets another chance
        //used extra chance in 2nd stage so you dont have any extra chance for 3rd stage
        else if(extraChance == 1){
            extraChance=0;
            printf("\nYou have an extra chance do you want to continue if yes enter 'y': ");
            scanf(" %c", &choice);
            //stage 2 second try starts
             if(choice == 'y'){
                s=playGame(stage);
                if(s == 't'){
                    stage=stage+1;
                    printf("\nDo you want to continue if yes enter 'y': ");
                    scanf(" %c", &choice);
                    //stage 3 starts
                    if(choice == 'y'){
                        s=playGame(stage);
                        if(s == 't'){
                            printf("\n \t \t Congratulation!! you have completed all the stages. \n");
                            }
                    //game over because the user used all the chances
                    //game over for stage 3.
                        else{
                            printf("\n \t \t GAME OVER \n");
                            }
                        }

                        //stage 3 check y or n
                    else{
                        printf("\n \t \t GAME OVER \n");
                        }
                    }

                    //if you failed in extra chance of 2nd stage
                 else{
                    printf("\n \t \t GAME OVER \n");
                    }
             }

             //else if you dont want to play in 2nd stage extra chance
             else{
                printf("\n \t \t GAME OVER \n");
                }
            }

       }

       //checked y or n for stage 2 initial
       else{
        printf("\n \t \t GAME OVER \n");
       }
    }

    //else of stage 1
    else{
        printf("\n \t \t GAME OVER \n");
    }

    return 0;
}


