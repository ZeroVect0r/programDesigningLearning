/*
任务描述

本关任务：编写一个能计算背包中能装下最多价值金子的程序。

相关知识

为了完成本关任务，你需要掌握：如何对数组元素排序。

题目描述

小明迷路了，偶然间发现了非常多的金子，并且旁边没有一个可以任意分割金子的工具（和上题不同） 。

这些金子每种纯度不同、重量不同，并且已经在其上标好了这些数据，并且，每一种相同的金子有好几块。小明很想把这些金子都带回去，但只有一个能装下固定重量金子的背包，并且小明非常的贪心，他一定要将背包装满再走，他想求助你：怎么样能带走最多价值的金子。

输入输出描述

输入第一行包含两个整数n和s，n表示共有n块金子，s表示背包最多容纳的重量，之后共n行，每行包含三个整数a、b和c，分别表示这种类型的金子的价值、重量和块数。数据保证n<=1000，s<=5000，所有数据在int范围内。

输出共一行，包含一个整数，表示背包在装满的情况下能容纳的最多金子价值，如果无论如何背包都无法装满，输出-1。

例如：

输入1

3 10
14 3 3
15 5 2
16 4 1
输出1

44
输入2

3 10
14 3 1
15 5 1
16 4 1
输出2

-1
*/
#include<stdio.h>
#define MAX(a , b) ((a) > (b) ? (a) : (b))
int decision(int n, int capacity, int value[n], int weight[n], int number[n]){
	int  newValue[10000];
	int newWeight[10000];
	int count = 0;
	
	for (int i = 0; i < n; i++){
		int num = number[i];	
		for (int k = 1; k <= num; k = k * 2){
			newValue[count]  =  value[i] * k;
			newWeight[count] = weight[i] * k; 
			count            = count + 1;
			num              = num - k;
		}
		if (num > 0) {
			newValue[count]  =  value[i] * num; 
			newWeight[count] = weight[i] * num;
			count            = count + 1;
		}
	}
	int dp[capacity + 1];
    
    // 初始化DP数组：除了容量0，其他都设为-1表示不可达
    	for (int j = 0; j <= capacity; j++){
        	dp[j] = -1;
    	}
    	dp[0] = 0;
    
    // 01背包动态规划
    	for (int i = 0; i < count; i++){
        	for (int j = capacity; j >= newWeight[i]; j--){
            		if (dp[j - newWeight[i]] != -1){
                		int newVal = dp[j - newWeight[i]] + newValue[i];
                		if (dp[j] == -1 || newVal > dp[j]){
                    			dp[j] = newVal;
                		}
            		}
        	}
	}
    
    return dp[capacity];
}

int main(){
	int n;
	int capacity;
	scanf("%d %d", &n, &capacity);
	int value[n];
	int weight[n];
	int number[n];
	for (int i = 0; i < n; i++){
		scanf("%d %d %d",&value[i], &weight[i], &number[i]);
	}
	int deci = decision(n, capacity, value, weight, number);
	printf("%d", deci);
	return 0;
}






























