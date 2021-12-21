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
    printf("[1.Change color 2.Create Borders] select function: ");
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
        // check # address
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
                        // color 1
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
                        // color 2
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
    // create borders
    else if (user == 2)
    {
        int start = 0;
        int b;
        int c_b;
        char c;
        int round = 1;
        const int data_length = 4;
        int data[data_length];
        char code_color[10];
        printf("Size of borders:");
        scanf("%d", &b);
        printf("[1.Red , 2.Yellow , 3.Blue , 4.Green , 5.Black , 6.White] choose borders color(number):");
        scanf("%d", &c_b);
        while (c_b >= 7 || c_b <= 0)
        {
            printf("Please enter 1-6:");
            scanf("%d", &c_b);
        }
        // check color borders
        if (c_b == 1)
        {
            strcpy(code_color, "#FF0000"); // red
        }
        else if (c_b == 2)
        {
            strcpy(code_color, "#fff700"); // yellow
        }
        else if (c_b == 3)
        {
            strcpy(code_color, "#003cff"); // blue
        }
        else if (c_b == 4)
        {
            strcpy(code_color, "#1aff00"); // green
        }
        else if (c_b == 5)
        {
            strcpy(code_color, "#000000"); // black
        }
        else if (c_b == 6)
        {
            strcpy(code_color, "#ffffff"); // white
        }
        while ((c = fgetc(image)) != EOF)
        {

            if (start == 0 && round > 4)
            {
                for (int x = 0; x < b; x++)
                {
                    fprintf(result, "c");
                    printf("c");
                }
                start = 1;
            }
            else if (round > 4 && c == '\n')
            {
                for (int y = 0; y < b; y++)
                {
                    fprintf(result, "c");
                    printf("c");
                }
                start = 0;
            }
            fprintf(result, "%c", c);
            printf("%c", c);

            if (round == 1 && c == '\n')
            {
                while (1)
                {
                    for (int i = 0; i < data_length; i++)
                    {
                        fscanf(image, "%2d", &data[i]);
                    }
                    // set width
                    data[0] = data[0] + (2 * b);
                    fprintf(result, "%d", data[0]);
                    printf("%d", data[0]);
                    data[1] = data[1] + (2 * b);
                    fprintf(result, " %d", data[1]);
                    printf(" %d", data[1]);
                    data[2] = data[2] + 1;
                    fprintf(result, " %d", data[2]);
                    fprintf(result, " %d", data[3]);
                    printf(" %d", data[2]);
                    printf(" %d", data[3]);
                    break;
                }
            }
            else if (round == 4 && c == '\n')
            {
                fprintf(result, "c c %s\n", code_color);
                printf("c c %s\n", code_color);
                for (int k = 0; k < b; k++)
                {
                    for (int j = 0; j < data[0]; j++)
                    {
                        fprintf(result, "c");
                        printf("c");
                    }
                    fprintf(result, "\n");
                    printf("\n");
                }
            }

            if (c == '\n')
            {
                round += 1;
            }
        }

        for (int r = 0; r < b; r++)
        {
            fprintf(result, "c");
            printf("c");
        }
        fprintf(result, "\n");
        printf("\n");
        for (int k = 0; k < b; k++)
        {
            for (int j = 0; j < data[0]; j++)
            {
                fprintf(result, "c");
                printf("c");
            }
            fprintf(result, "\n");
            printf("\n");
        }
    }
    fclose(image);
    fclose(result);

    return 0;
}
