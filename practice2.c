
/* 给你一个只包含正整数的非空数组 nums。
 * 请你编写程序，
 * 判断是否可以将这个数组分割成两个子集，
 * 使得两个子集的元素和相等。
 * ---------------------------------
 * 已经尝试过二维数组的情况，现在尝试一维数组
 * ctling
 */
#include<stdio.h>

/*具体的分割函数division,传入两个参数整数n和数组nums*/
int division(int n, int nums[n])
{
    /*
     * 如果能分割，那求和以后是一个偶数
     * 如果是奇数，就直接输出False
     * 如果是偶数，在进行下一步判断
     */
    int sum1 = 0;
    for (int k = 0; k < n; k++)
    {
        sum1 = sum1 + nums[k];
    }

    /*首先判断是不是偶数*/
    if (sum1 % 2 != 0)
    {
        return 0;
    }else
    {
        /*
         * 如果是偶数的话，问题可以转化成：
         * 是否可以在数组中找到一组数
         * 使得这组数的和为求和的一半
         * 这是一个“完全背包问题”
         */
        int capacity = sum1 / 2;
        int dp[capacity + 1];
        /*
         * 由于之前二维数组的尝试，发现了其实
         * 要写出另外的一列只需要参考前面一列：
         * 意思是要知道dp[i][?]的情况，只需要知道dp[i-1][?]的情况就好
         * 【!】值得注意的是：
         * 接下来的dp[?]中的?是关于容量也就是dp[i][j]中的j的
         */

        /*
         * 所以在初始化的时候，我们考虑的是第一列
         * 第一次循环只考虑0个物品，那么第一列就是1 0 0 ... 0
         */
        for (int l = 0; l <= capacity; l++)
        {
            dp[l] = 0;
        }
        dp[0] = 1;

        /*
         * 两个for循环，
         * [for1]:这个循环用来遍历所有的物品，由于之前我们选定的指标是容量
         *        所以现在第一个循环指标就是考虑物品
         * [for2]:由于一维数组重要操作是“覆盖”，所以可以直接通过
         *        p >= nums[m]这一行直接跳过之前的if操作
         *        意思是：如果第m+1个物品的重量已经大于总容量，那必然不选择它
         *        所以如果第m+1个物品它的重量很大
         *        那就只考虑前m个物品能不能装满即可，不会改变结果
         */
        for (int m = 0; m < n; m++)
        {
            for (int p = capacity; p >= nums[m]; p--)
            {
                if (dp[p] == 1 || dp[p-nums[m]] == 1)
                {
                    dp[p] = 1;
                }else
                {
                    dp[p] = 0;
                }
            }
        }
        return dp[capacity];
    }
}

/*主函数*/
int main()
{
    int n;
    scanf("%d",&n);
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    int result = division(n, nums);
    if (result == 1)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
    return 0;
}