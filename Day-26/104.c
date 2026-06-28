#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice, ans, score;
    int asked[10];
    int q;

    do {
        printf("\n===== QUIZ GAME =====\n");
        printf("1. Start Quiz\n");
        printf("2. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        if(choice == 1) {

            score = 0;

            for(int i=0;i<10;i++)
                asked[i]=0;

            printf("\n----- Quiz Started -----\n");

            for(int i=0;i<5;i++) {

                do{
                    q = rand()%10;
                }while(asked[q]==1);

                asked[q]=1;

                switch(q){

                case 0:
                    printf("\n1. Capital of India?\n");
                    printf("1.Mumbai\n2.Delhi\n3.Chennai\n");
                    scanf("%d",&ans);
                    if(ans==2) score++;
                    break;

                case 1:
                    printf("\n2. 5 + 3 = ?\n");
                    printf("1.6\n2.7\n3.8\n");
                    scanf("%d",&ans);
                    if(ans==3) score++;
                    break;

                case 2:
                    printf("\n3. Which language is used for C programs?\n");
                    printf("1.C\n2.Java\n3.HTML\n");
                    scanf("%d",&ans);
                    if(ans==1) score++;
                    break;

                case 3:
                    printf("\n4. 10 * 5 = ?\n");
                    printf("1.15\n2.50\n3.55\n");
                    scanf("%d",&ans);
                    if(ans==2) score++;
                    break;

                case 4:
                    printf("\n5. Which planet is known as Red Planet?\n");
                    printf("1.Mars\n2.Earth\n3.Venus\n");
                    scanf("%d",&ans);
                    if(ans==1) score++;
                    break;

                case 5:
                    printf("\n6. Largest ocean?\n");
                    printf("1.Indian\n2.Pacific\n3.Arctic\n");
                    scanf("%d",&ans);
                    if(ans==2) score++;
                    break;

                case 6:
                    printf("\n7. 9 - 4 = ?\n");
                    printf("1.4\n2.5\n3.6\n");
                    scanf("%d",&ans);
                    if(ans==2) score++;
                    break;

                case 7:
                    printf("\n8. National Animal of India?\n");
                    printf("1.Lion\n2.Tiger\n3.Elephant\n");
                    scanf("%d",&ans);
                    if(ans==2) score++;
                    break;

                case 8:
                    printf("\n9. 12 / 3 = ?\n");
                    printf("1.3\n2.4\n3.5\n");
                    scanf("%d",&ans);
                    if(ans==2) score++;
                    break;

                case 9:
                    printf("\n10. Sun rises in?\n");
                    printf("1.West\n2.North\n3.East\n");
                    scanf("%d",&ans);
                    if(ans==3) score++;
                    break;
                }
            }

            printf("\n=====================\n");
            printf("Your Score = %d/5\n",score);

            if(score==5)
                printf("Excellent!\n");
            else if(score>=3)
                printf("Good Job!\n");
            else
                printf("Keep Practicing!\n");

        }
        else if(choice==2){
            printf("Thank You!\n");
        }
        else{
            printf("Invalid Choice!\n");
        }

    }while(choice!=2);

    return 0;
}