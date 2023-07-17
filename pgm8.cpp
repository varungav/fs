#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<iostream>

void merge_file(char* file1, char* file2, char* filename)
{
    char name[20];
    char usn[20];
    int i, k;
    k = 0;
    FILE* f1, * f2;
    f1 = fopen(file1, "r");
    f2 = fopen(file2, "r");
    while (!feof(f1))
    {
        fscanf(f1, "%[^|]|%[^\n]\n", name, usn);
        k++;
    }
    while (!feof(f2))
    {
        fscanf(f2, "%[^|]|%[^\n]\n", name, usn);
        k++;
    }
    fseek(f1, 0, SEEK_SET);
    fseek(f2, 0, SEEK_SET);
    char** recd = new char* [k];
    for (i = 0; i < k; i++)
        recd[i] = new char[40];

    i = 0;
    while (!feof(f1))
    {
        fscanf(f1, "%[^|]|%[^\n]\n", recd[i], recd[i] + 20);
        i++;
    }
    while (!feof(f2))
    {
        fscanf(f2, "%[^|]|%[^\n]\n", recd[i], recd[i] + 20);
        i++;
    }

    char temp[40];
    for (int t = 0; t < k - 1; t++)
    {
        for (int y = 0; y < k - t - 1; y++)
        {
            if (strcmp(recd[y], recd[y + 1]) > 0)
            {
                strcpy(temp, recd[y]);
                strcpy(recd[y], recd[y + 1]);
                strcpy(recd[y + 1], temp);
            }
        }
    }

    FILE* temp1;
    temp1 = fopen(filename, "w");
    for (int t = 1; t < k - 1; t++)
        fprintf(temp1, "%s\n", recd[t]);

    fclose(f1);
    fclose(f2);
    fclose(temp1);

    for (i = 0; i < k; i++)
        delete[] recd[i];
    delete[] recd;
}

void kwaymerge()
{
    char fname[8][8] = { "1.txt","2.txt","3.txt","4.txt","5.txt","6.txt","7.txt","8.txt" };
    char filename[7][20] = { "11.txt","22.txt","33.txt","44.txt","111.txt","222.txt","1111.txt" };
    int i, k;
    k = 0;
    for (i = 0; i < 8; i += 2)
    {
        merge_file(fname[i], fname[i + 1], filename[k++]);
    }
    k = 4;
    for (i = 0; i < 4; i += 2)
    {
        merge_file(filename[i], filename[i + 1], filename[k++]);
    }
    merge_file(filename[4], filename[5], filename[6]);
}

int main()
{
    int i;
    printf("enter no of records\n");
    int no;
    scanf("%d", &no);

    char fname[8][8] = { "1.txt","2.txt","3.txt","4.txt","5.txt","6.txt","7.txt","8.txt" };
    FILE* file[8];
    for (i = 0; i < 8; i++)
        file[i] = fopen(fname[i], "w");

    printf("\nenter the details\n");
    char name[20];
    char usn[20];
    for (i = 0; i < no; i++)
    {
        printf("Name:");
        scanf("%s", name);
        printf("Usn:");
        scanf("%s", usn);
        fprintf(file[i % 8], "%s|%s\n", name, usn);
    }

    for (i = 0; i < 8; i++)
        fclose(file[i]);

    kwaymerge();

    FILE* result;
    result = fopen("1111.txt", "r");
    printf("sorted records\n");
    char line[40];
    while (fgets(line, sizeof(line), result))
    {
        sscanf(line, "%[^|]|%[^\n]", name, usn);
        printf("\nName: %s\nUsn: %s\n", name, usn);
    }

    fclose(result);

    getch();
    return 0;
}


