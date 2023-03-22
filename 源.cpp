#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int Minor(int matrix[20][20], int order, int row, int col);

int DET(int matrix[20][20], int order)
{
    //�������Ϊһ�ף���ֱ�ӷ���Ԫ�ر���
    if (order == 1)
        return matrix[0][0];
    //�������Ϊ���ף��򷵻ضԽ��߳˻�֮��
    else if (order == 2)
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    //�������Ϊ�������ϣ��򰴵�һ��չ�����ݹ�����ÿ��Ԫ�صĴ�������ʽ�����ۼӷ��ؽ��
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

//����һ�����������ڼ�������ʽ��ֵ
int Minor(int matrix[20][20], int order, int row, int col)
{
    int minor[20][20];
    //��ԭ�����г��˵�row�к͵�col��֮���Ԫ�ظ��Ƶ�minor������
    for (int i = 0; i < order - 1; i++)
    {
        for (int j = 0; j < order - 1; j++)//�Ŀ�����
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
    //����DET����������minor���������ʽֵ
    return DET(minor, order - 1);
}

//����һ�����������ڼ�������׾��������ʽֵ


//���������������벢������
int main()
{
    int order, matrix[20][20], result = 0, i, j;
    printf("���������:");
    scanf("%d", &order);

    //�ж������Ƿ�Ϸ�
    if (order <= 0)
        printf("���������0��������");
    else
    {
        printf("������%d*%d�ķ���:\n", order, order);

        //���뷽��Ԫ��
        for (i = 0; i < order; i++) {
            printf("��%d��:\n", i + 1);
            for (j = 0; j < order; j++)
                scanf("%d", &matrix[i][j]);
        }
        //����DET����������	
        result = DET(matrix, order);

        printf("�÷��������ʽΪ:%d\n", result);
    }
    return EXIT_SUCCESS;
}