
/* 给你一个只包含正整数的非空数组 nums。
 * 请你编写程序
 * 判断是否可以将这个数组分割成两个子集
 * 使得两个子集的元素和相等。
 * ---------------------------------
 * 这个是二维数组的版本.
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
         * 这是一个“01背包问题”
         */
        int capacity = sum1 / 2;
        int dp[n + 1][capacity + 1];
        /*
         * dp[i][j]:能不能从前i个物品(数字)中选出几样，完全装满j的容量(和为sum2)
         * nums[k] :第k个物品的大小(数字的值)
         */

        /*这里是对零行的初始化，
         * 比如从前i个物品中选出0个一定可以装满容量0
         * 所以dp[i][0]=1
         */
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }
        /*
         * 相同的
         * 从0个物品里面选的话，
         * 除非容量为0，否则绝对装不满
         */
        for (int j = 1; j <= capacity; j++)
        {
            dp[0][j] = 0;
        }

        /*
         * 【!】这里是动态规划的主要段落。
         * 两个for循环可以遍历列表中的剩余元素
         */
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= capacity; j++)
            {
                /*
                 * [if]:确保下面的j-nums[i-1]不会超出范围变成负数
                 * [ef]:如果只用前i-1个物品就可以填满背包j，那用前i个物品也是可以的
                 *      如果前i-1个物品刚好可以填满j-nums[i-1](注意这个是第i个物品)
                 *      那加上一个物品nums[i-1]刚刚好填满
                 * [el]:那如果是其他情况就肯定不可以了
                 */
                if (j < nums[i-1])
                {
                    dp[i][j] = dp[i-1][j];
                }else if (dp[i-1][j] == 1||dp[i-1][j-nums[i-1]])
                {
                    dp[i][j] = 1;
                }else
                {
                    dp[i][j] = 0;
                }
            }
        }
        /*最后再返回二维数组最后一个数字*/
        return dp[n][capacity];
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
