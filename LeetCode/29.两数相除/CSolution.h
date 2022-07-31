#pragma once

#include <iostream>

class CSolution
{
public:
    int divide(int x, int y) 
    {
        //���Ǳ��������������
        if (INT_MIN == x)
        {
            if (1 == y)
                return INT_MIN;
            if (-1 == y)
                return INT_MAX;
        }

        if (0 == x)
            return 0;

        //���ǳ������������
        if (INT_MIN == y)
            return INT_MIN == x ? 1 : 0;

        //���������������������,������������Ϊ����
        bool flag = false;
        if (x > 0) x = -x, flag = !flag;
        if (y > 0) y = -y, flag = !flag; 
		return (flag ? -1 : 1) * binarySearch(1, INT_MAX, x, y);
    }

private:
	//x < 0, y < 0, z >= 0, �ж�y * z >= x�Ƿ����
    bool check(int x, int y, int z)
    { 
		//��д�Ŀ��ٳ��㷨
        int ret = 0, add = y;
        while (z) 
        {
            if (z & 1) 
            {
                //ret, add, xʼ��Ϊ����,���ret + add < x, y * z >= x ������
                if (ret < x - add) 
                    return false;
                //���ٳ˼���y * z��ֵ
                ret += add;
            }

            if (z != 1) 
            {
                //ret, add, xʼ��Ϊ����,�������addС����x, ret + add ��Զ������>=x
                if (add < x - add) 
                    return false;
                add += add;
            }

            z >>= 1;
        }
        return true;
    }

    //���ֲ���
    int binarySearch(int left, int right, int x, int y)
    {
        int ret = 0;
        while (left <= right)
        {
            //(left + right) >> 1 �����������, ��������ķ�ʽ����mid
            int mid = left + ((right - left) >> 1);
            bool check = this->check(x, y, mid);
            if (check)
            {
                ret = mid;
                if (INT_MAX == ret)
                    break;
                left = mid + 1;
            }
            else right = mid - 1;
        }
        return ret;
    }
};
