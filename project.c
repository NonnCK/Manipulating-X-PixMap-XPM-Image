#include <stdio.h>
#include <string.h>
// C:\Users\admin\OneDrive\Desktop\test.xpm
int main()
{

    char file[100];
    int user;
    int color1;
    int color2;
    printf("Please enter XPM file : ");
    scanf("%s", &file);
    printf("[1.Change color 2.xxxxxx] select function: ");
    scanf("%d", &user);
    while (user >= 3 || user <= 0)
    {
        printf("Please enter 1-2:");
        scanf("%d", &user);
    }
    // file pointer variable
    FILE *image;
    FILE *result;

    // point pointer variable to file
    image = fopen(file, "r");
    // file location of result
    result = fopen("C:\\Users\\admin\\OneDrive\\Desktop\\answer.xpm", "w");
    // change color function
    if (user == 1)
    {
        printf("[1.Red , 2.Yellow , 3.Blue , 4.Green , 5.Black , 6.White] choose first color(number):");
        scanf("%d", &color1);
        while (color1 >= 7 || color1 <= 0)
        {
            printf("Please enter 1-6:");
            scanf("%d", &color1);
        }
        printf("[1.Red , 2.Yellow , 3.Blue , 4.Green , 5.Black , 6.White] choose second color(number):");
        scanf("%d", &color2);
        while (color2 >= 7 || color2 <= 0)
        {
            printf("Please enter 1-6:");
            scanf("%d", &color2);
        }
        // change color from user
        char c;
        int round = 1;
        while ((c = fgetc(image)) != EOF)
        {
            if (c == '#')
            {
                while (1)
                {
                    c = fgetc(image);
                    if (c == '\n')
                    {
                        if (round == 1)
                        {
                            switch (color1)
                            {
                            case 1:
                                // red
                                fprintf(result, "#FF0000");
                                printf("#FF0000");
                                break;
                            case 2:
                                // yellow
                                fprintf(result, "#fff700");
                                printf("#fff700");
                                break;
                            case 3:
                                // blue
                                fprintf(result, "#003cff");
                                printf("#003cff");
                                break;
                            case 4:
                                // green
                                fprintf(result, "#1aff00");
                                printf("#1aff00");
                                break;
                            case 5:
                                // black
                                fprintf(result, "#000000");
                                printf("#000000");
                                break;
                            case 6:
                                // white
                                fprintf(result, "#ffffff");
                                printf("#ffffff");
                                break;
                            default:
                                break;
                            }
                        }
                        else if (round == 2)
                        {
                            switch (color2)
                            {
                            case 1:
                                // red
                                fprintf(result, "#FF0000");
                                printf("#FF0000");
                                break;
                            case 2:
                                // yellow
                                fprintf(result, "#fff700");
                                printf("#fff700");
                                break;
                            case 3:
                                // blue
                                fprintf(result, "#003cff");
                                printf("#003cff");
                                break;
                            case 4:
                                // green
                                fprintf(result, "#1aff00");
                                printf("#1aff00");
                                break;
                            case 5:
                                // black
                                fprintf(result, "#000000");
                                printf("#000000");
                                break;
                            case 6:
                                // white
                                fprintf(result, "#ffffff");
                                printf("#ffffff");
                                break;
                            default:
                                break;
                            }
                        }
                        round += 1;
                        break;
                    }
                }
            }
            fprintf(result, "%c", c);
            printf("%c", c);
        }
    }
    // else if (user==2)
    // {

    // }

    // close file
    fclose(image);
    fclose(result);

    return 0;
}