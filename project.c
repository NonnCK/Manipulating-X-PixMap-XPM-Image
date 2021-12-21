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
        while ((c = fgetc(image)) != EOF)
        {
            if (c == '#')
            {
                while (0)
                {
                    c = fgetc(image);
                    if (c == '\n')
                    {
                        printf("Mimi");
                        switch (color1)
                        {
                        case 1:
                            // red
                            printf("#FF0000");
                            break;
                        case 2:
                            // yellow
                            printf("#fff700");
                            break;
                        case 3:
                            // blue
                            printf("#003cff");
                            break;
                        case 4:
                            // green
                            printf("#1aff00");
                            break;
                        case 5:
                            // black
                            printf("#000000");
                            break;
                        case 6:
                            // white
                            printf("#ffffff");
                            break;
                        default:
                            break;
                        }
                    }
                }
            }
            printf("%c", c);
        }
    }
    // close file
    fclose(image);

    return 0;
}