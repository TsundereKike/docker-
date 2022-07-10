#include <main.h>
/*《剑指Offer10》:写一个函数，输入n,斐波那契数列的第n项（即F(n)）。斐波那契数列的定义如下：
*   F(0) = 0，F(1) = 1;
*   F(n) = F(n-1) + F(n-2)，其中n>1
*答案需要取模1e9+7(1000000007)，如计算的结果为1000000008，请返回1.
*例：
*   输入：n = 2
*   输出：1
*   输入：n = 5
*   输出：5    
*/
/*生成gdb.txt的方法：
*   set loggin on 
*/
int main(int argc, char const *argv[])
{
    int p = 0,q = 1,m,n;
    int i = 0;
    printf("输入: n = ");
    scanf("%d",&n);
    if(n<2)
    {
        printf("输出: %d\r\n",n);
        return -1;        
    }
    for(i=2;i<=n;i++)
    {
        m = (p + q)%1000000007;
        p = q;
        q = m;
    }
    printf("输出: %d\r\n",m);
    return 0;
}
