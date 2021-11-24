/*

1. 01背包
2. 完全背包
3. 多重背包
4. 分组背包


1.状态表示 f(i,j)
    1.1 集合
        1.1.1   所有选法
        1.1.2   条件
            1） 只从前i个物品中选择
            2） 总体积 <= j
    1.2 属性
        max,min,数量等

2.状态计算 --- 集合的划分
    类比一下推导斐波那契数列
    当前状态 = 前一个状态 + 考虑到当前元素的状态
    （爬某一层台阶 = 前一个台阶爬一步过来）

*/