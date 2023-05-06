/*
 * Author: jeff Daniel
 * Project Version: 1.0
 * Description: SAU Map Assist
 * This code is licensed under the MIT License.
 */

#include "file.h"
#include "ListDijkstra.h"
#include <stdlib.h>
#define Graph ListGraph
#define InType int
// #define _File_  "SauMap.txt"
#define _File_ "SauMap.log"

int main()
{
    FILE **in = NULL, **out = NULL;
    //    char **Path = filePath();
    InType begin, end;
    int F = 1, i, err;
    while (!in) // while loop to check if file is open
    {
        in = NULL;
        if (in = rOpenFile(_File_)) // if file is open for reading
            F = 0;
        else if (out = wOpenFile(_File_)) // if file is open for writing
        {
            if (wSAUMap(out[0])) // write to file
            {
                fclose(out[0]);
                printf("Write %s successfully!\n", _File_);
            }
        }
    }
    const Graph *G = CreateUDN(in[F]); // create graph
    if (!F)
        closeFile(in);
    system("F:/Lab/Map.jpg"); // display map image
n0:
{ // main menu
    system("CLS");
    system("VER");
    system("CHDIR");
    printf("**************SAU**MAP**ASSIST***\n");
    printf("Enter 1 to learn more about the location\n");
    printf("Enter 2 to get the shortest path from begin to end\n");
    printf("Enter 0 to back\n");
    printf("Enter other(what, yes) to go back here, everywhen, everywhere!\nEnter>");
n01:
    switch (getchar())
    {
    case '0':
        goto n00;
    case '1':
        system("CLS");
        goto n10;
    case '2':
        system("CLS");
        goto n20;
    case '\n':
        goto n01;
    default:
        goto n0;
    }
}
n10:
{ // display location information
    for (i = 0; i < G->vexnum; i++)
    {
        printf("[%02d]%-25s", G->vexs[i].vex, G->vexs[i].name);
        if (!(i + 1) % 4)
        {
            putchar('\n');
        }
    }
    err = 0;
    do
    {
        if (err++ > 15)
        {
            goto n0;
        }
        printf("\nEnter [?]>");
        scanf("%d", &begin);                   // get input for vertexType
    } while (-1 == (i = LocateVex(G, begin))); // check if input is valid
    err = 0;
    do
    {
        if (err++ > 15)
        {
            goto n0;
        }
        printf("[%02d]\t%-25s%-s\n", G->vexs[i].vex, G->vexs[i].name, G->vexs[i].info);
        printf("Enter [?] to continue or other to back>");
        scanf("%d", &begin);                   // get input for vertexType
    } while (-1 != (i = LocateVex(G, begin))); // check if input is valid
    system("CLS");
    goto n0;
}

n20:
{ // display shortest path
    for (i = 0; i < G->vexnum; i++)
    {
        printf("[%02d]%-25s", G->vexs[i].vex, G->vexs[i].name);
        if (!(i + 1) % 4)
        {
            putchar('\n');
        }
    }
    putchar('\n');
    err = 0;
    do
    {
        if (err++ > 15)
        {
            goto n0;
        }
        printf("Enter begin[?]>");
        scanf("%d", &begin);             // get input for vertexType
    } while (-1 == LocateVex(G, begin)); // check if input is valid
    err = 0;
    do
    {
        if (err++ > 15)
        {
            goto n0;
        }
        miniSpanTree(G, begin); // find shortest path
        err = 0;
        do
        {
            if (err++ > 15)
            {
                goto n0;
            }
            printf("Enter end[?]>");
            scanf("%d", &end);             // get input for vertexType
        } while (-1 == LocateVex(G, end)); // check if input is valid
        err = 0;

        do
        {
            if (err++ > 15)
            {
                goto n0;
            }
            showtrack(G, begin, end);
            printf("Enter end[?] to continue or other to back>");
            scanf("%d", &end); // ȷ�������Ч
        } while (-1 != LocateVex(G, end));
        printf("Enter begin[?] to continue or other to back>");
        scanf("%d", &begin); // ȷ�������Ч
    } while (-1 != LocateVex(G, begin));
    system("CLS");
    goto n0;
}

n00:
{
    clearGraph((ListGraph *)G); // ǿ��ת��Ϊ��const�ͷ����޷�����
    freeclosedge(theclose);
    return 0;
}
}
/*
7 8
1 2 4
1 3 3
2 4 5
3 4 3
4 5 1
5 7 5
6 7 2
4 6 6
1 6

7 8
1 2 3 4 5 6 7
1 2 4
1 3 3
2 4 5
3 4 3
4 5 1
5 7 5
6 7 2
4 6 6
1 6
*/
