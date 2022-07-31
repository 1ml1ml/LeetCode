#pragma once

#include <iostream>

class CSolution
{
public:
    int divide(int x, int y) 
    {
        //考虑被除数的特殊情况
        if (INT_MIN == x)
        {
            if (1 == y)
                return INT_MIN;
            if (-1 == y)
                return INT_MAX;
        }

        if (0 == x)
            return 0;

        //考虑除数的特殊情况
        if (INT_MIN == y)
            return INT_MIN == x ? 1 : 0;

        //负数变正数存在溢出风险,将所有正数变为负数
        bool flag = false;
        if (x > 0) x = -x, flag = !flag;
        if (y > 0) y = -y, flag = !flag; 
		return (flag ? -1 : 1) * binarySearch(1, INT_MAX, x, y);
    }

private:
	//x < 0, y < 0, z >= 0, 判断y * z >= x是否成立
    bool check(int x, int y, int z)
    { 
		//改写的快速乘算法
        int ret = 0, add = y;
        while (z) 
        {
            if (z & 1) 
            {
                //ret, add, x始终为负数,如果ret + add < x, y * z >= x 不成立
                if (ret < x - add) 
                    return false;
                //快速乘计算y * z的值
                ret += add;
            }

            if (z != 1) 
            {
                //ret, add, x始终为负数,如果增量add小于了x, ret + add 永远不可能>=x
                if (add < x - add) 
                    return false;
                add += add;
            }

            z >>= 1;
        }
        return true;
    }

    //二分查找
    int binarySearch(int left, int right, int x, int y)
    {
        int ret = 0;
        while (left <= right)
        {
            //(left + right) >> 1 存在溢出风险, 改用下面的方式计算mid
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
