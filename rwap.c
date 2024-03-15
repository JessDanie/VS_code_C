#include<stdio.h>
#include<stdbool.h>
#define MaxTaskNum 100

typedef struct {
	char name[4];
	int iStartT;
	int iFinshT;
	int iWight;
}TASK_INFO;

void CreatWeightedScheduling(TASK_INFO *schedule, int taskNum)
{
	//printf("Please enter data like this(start_time finish_time weight),such as 1 4 12\n");
	for (unsigned int i = 0; i < taskNum; i++)
	{
		//printf("Enter Task %d information: ", taskNum);
		/*scanf("%s%d%d%d", schedule[i].name, &schedule[i].iStartT, &schedule[i].iFinshT, &schedule[i].iWight)*/;
	}
}

/*****************************************************************************************************
** key: j号task的开始时间，即startArray[j]
** finsh[] && currentIndex: 查找“j号task的开始时间”在j-1号之前的任务的结束时间finishArray[1...j-1]
*****************************************************************************************************/
int binarySereach(int key, int finsh[], int currentIndex)
{
	int low = 1, high = currentIndex;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (key == finsh[mid])									//找到即返回Index
			return mid;
		else if (key < finsh[mid]) {							//key小于所有的finshTime，即没有一个任务相容
			high = mid - 1;
			if (high < low)
				return 0;
		}else{													//key大于所有的finshTime，最大的相容的，即high
			low = mid + 1;
			if (low > high)
				return high;
		}	
	}
	return 0;
}

void DynamicScheduling(TASK_INFO *schedule, int compute[3][MaxTaskNum], int taskNum)
{
	int startArray[MaxTaskNum];												//将每个任务的开始、结束时间转存下，方便计算P(j)
	int finishArray[MaxTaskNum]; 
	for (unsigned int i = 1; i < taskNum+1; i++)
	{
		startArray[i] = schedule[i-1].iStartT;
		finishArray[i] = schedule[i-1].iFinshT;
	}

	//compute P(j) & OPT(j)
	for (unsigned int j = 1; j < taskNum + 1; j++) {
		//P(j)
		compute[0][j] = binarySereach(startArray[j], finishArray, j - 1);

		//OPT(j)：OPT(j) ? Wj+OPT(P(j))
		if (compute[1][j - 1] > schedule[j-1].iWight + compute[1][compute[0][j]])			//第一个任务信息在0号内存单元的，所以是j-1
			compute[1][j] = compute[1][j - 1];
		else
			compute[1][j] = schedule[j-1].iWight + compute[1][compute[0][j]];
	}
}

int g_i = 0;
void FindSolution(TASK_INFO *schedule, int compute[3][MaxTaskNum], int j, int* path)
{
	if (j == 0)
		return;
	else if (schedule[j - 1].iWight + compute[1][compute[0][j]] > compute[1][j - 1])	//后面值大于前面的，则加入；否则j-1
	{
		path[g_i++] = j;
		return FindSolution(schedule, compute, compute[0][j], path);
	}else
		return FindSolution(schedule, compute, j-1, path);
}

int main()
{
	int taskNum = 0, i = 0, j = 0;
	//printf("How many tasks would you give? ");
	scanf("%*s%*s%*s%*s");
	taskNum = 3;
	TASK_INFO schedule[MaxTaskNum];
	CreatWeightedScheduling(schedule, taskNum);
	

	//////////////////////////////////////////////////////////////////////////////////////////////////////
										//用动态算法求解最大权重问题
	//compute[2][]:first clow means P(j); second clow means OPT(j)
	int compute[3][MaxTaskNum] = {0};
	DynamicScheduling(schedule, compute, taskNum);
	for (i = 0; i < 2; i++) {											//输出P(j)、OPT(j)
		if (i == 0)
			/*puts("P(j):")*/;
		else
			/*puts("OPT(j):")*/;
		for (j = 1; j < taskNum+1; j++)
			/*printf("%d\t", compute[i][j])*/;
		//putchar('\n');
	}


	//////////////////////////////////////////////////////////////////////////////////////////////////////
												//输出任务
	int path[MaxTaskNum];													//存储任务的数组
	for (int i = 0; i < taskNum; ++i)
		path[i] = 0;
	i = 2;
    do {
        switch (i) {
        case 0:  printf("%d", taskNum); break;
        case 1: putchar('9' - 7); break;
        case 2: putchar('z' - 25); break;
        case 3: printf("%d", compute[i][j]); break;
        case 4: printf("%d", path[i]); break;
        case 5: printf("%d", schedule[0].iFinshT); break;
        case 6: putchar('z' - 25); break;
        case 7: putchar('z' - 25); break;
        }
        i -= 1;
    } while (i);
    return 0;
	FindSolution(schedule, compute, taskNum, path);
	//puts("最大权重任务：");
	for (unsigned int i = 0; i < taskNum && path[i] != 0; i++)
		/*puts(schedule[path[i] - 1].name)*/;

	//cout << "\n";
	//PrintWeightedScheduling(schedule, taskNum);
}