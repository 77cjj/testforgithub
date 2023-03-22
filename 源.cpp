#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int Minor(int matrix[20][20], int order, int row, int col);

int DET(int matrix[20][20], int order)
{
    //如果矩阵为一阶，则直接返回元素本身
    if (order == 1)
        return matrix[0][0];
    //如果矩阵为二阶，则返回对角线乘积之差
    else if (order == 2)
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    //如果矩阵为三阶以上，则按第一行展开，递归地求出每个元素的代数余子式，并累加返回结果
    else
    {
        int result = 0;
        for (int i = 0; i < order; i++)
        {
            result += ((i % 2 == 0) ? 1 : -1) * matrix[0][i] * Minor(matrix, order, 0, i);
        }
        return result;
    }
}

//定义一个函数，用于计算余子式的值
int Minor(int matrix[20][20], int order, int row, int col)
{
    int minor[20][20];
    //将原矩阵中除了第row行和第col列之外的元素复制到minor矩阵中
    for (int i = 0; i < order - 1; i++)
    {
        for (int j = 0; j < order - 1; j++)//四块区域
        {
            if (i < row && j < col)
                minor[i][j] = matrix[i][j];
            else if (i >= row && j < col)
                minor[i][j] = matrix[i + 1][j];
            else if (i < row && j >= col)
                minor[i][j] = matrix[i][j + 1];
            else
                minor[i][j] = matrix[i + 1][j + 1];
        }
    }
    //调用DET函数，返回minor矩阵的行列式值
    return DET(minor, order - 1);
}

//定义一个函数，用于计算任意阶矩阵的行列式值


//定义主函数，输入并输出结果
int main()
{
    int order, matrix[20][20], result = 0, i, j;
    printf("请输入阶数:");
    scanf("%d", &order);

    //判断输入是否合法
    if (order <= 0)
        printf("请输入大于0的整数！");
    else
    {
        printf("请输入%d*%d的方阵:\n", order, order);

        //输入方阵元素
        for (i = 0; i < order; i++) {
            printf("第%d行:\n", i + 1);
            for (j = 0; j < order; j++)
                scanf("%d", &matrix[i][j]);
        }
        //调用DET函数计算结果	
        result = DET(matrix, order);

        printf("该方针的行列式为:%d\n", result);
    }
    return EXIT_SUCCESS;
}