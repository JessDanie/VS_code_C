/*
 * Author: jeff Daniel
 * Project Version: 1.0
 * Description: SAU Map Assist
 * This code is licensed under the MIT License.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/**
 * @brief This function opens a file for reading and returns a pointer to the file.
 *
 * @param file_path The path of the file to be opened.
 * @return FILE** A pointer to the opened file.
 */
FILE **rOpenFile(const char *file_path)
{
    FILE **input_file;
    input_file = (FILE **)malloc(sizeof(FILE *) * 2);
    if (input_file == NULL)
    {
        return NULL;
    }
    input_file[1] = stdin;
    input_file[0] = fopen(file_path, "r");
    if (input_file[0] == NULL)
    {
        free(input_file);
        fprintf(stderr, "Error opening file %s\n", file_path);
        return NULL;
    }
    return input_file;
}

/**
 * @brief This function opens a file for writing and returns a pointer to the file.
 *
 * @param file_path The path of the file to be opened.
 * @return FILE** A pointer to the opened file.
 */
FILE **wOpenFile(const char *file_path)
{
    FILE **output_file;
    output_file = (FILE **)malloc(sizeof(FILE *) * 2);
    if (output_file == NULL)
    {
        return NULL;
    }
    output_file[1] = stdout;
    output_file[0] = fopen(file_path, "w");
    if (output_file[0] == NULL)
    {
        free(output_file);
        fprintf(stderr, "Error opening file %s\n", file_path);
        return NULL;
    }
    return output_file;
}

/**
 * @brief This function closes a file and frees the memory allocated to the file pointer.
 *
 * @param file The file to be closed.
 * @return true If the file was successfully closed.
 * @return false If the file could not be closed.
 */
bool closeFile(FILE **file)
{
    fclose(file[0]);
    free(file);
    return true;
}

/**
 * @brief This function writes the SAUMap to a file.
 *
 * @param file The file to which the SAUMap is to be written.
 * @return true If the SAUMap was successfully written to the file.
 * @return false If the SAUMap could not be written to the file.
 */
bool wSAUMap(FILE *file)
{
    int tmp1, tmp2, tmp3 = 0, tmp4, tmp5;
    char *name = (char *)malloc(sizeof(char) * 40);
    char *information = (char *)malloc(sizeof(char) * 240);
    if (name == NULL || information == NULL)
    {
        free(name);
        free(information);
        return false;
    }
    printf("Start Input SAUMap\n");
    printf("Input vexnum:");
    scanf("%d", &tmp1);
    printf("Input arcnum:");
    scanf("%d", &tmp2);
    fprintf(file, "%d\t%d\n", tmp1, tmp2);
    printf("Input %d vexs name information:", tmp1);
    while (tmp3++ < tmp1)
    {
        scanf("%d%s%s", &tmp4, name, information);
        fprintf(file, "%-d\t%-s\t%-s\n", tmp4, name, information);
    }
    free(name);
    free(information);
    tmp3 = 0;
    printf("Input %d begin end weight:", tmp2);
    while (tmp3++ < tmp2)
    {
        scanf("%d%d%d", &tmp1, &tmp4, &tmp5);
        fprintf(file, "%-4d\t%-4d\t%-4d\n", tmp1, tmp4, tmp5);
    }
    return true;
}
