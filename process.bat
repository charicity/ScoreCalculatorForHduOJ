@echo off
echo 编译中...
g++ csvs2marks.cpp -o csvs2marks
g++ marks2final.cpp -o marks2final
g++ merge.cpp -o merge
echo 删除原本的统计结果...
del "./result/final.csv"
del "./result/merge.csv"
echo 预处理部分完成
pause
for /l %%i in (1,1,10) do csvs2marks < "./source/2023“钉耙编程”中国大学生算法设计超级联赛（%%i）.csv" > "./result/%%i.csv"

echo 分段完成
pause
for /l %%i in (1,1,10) do marks2final < "./result/%%i.csv"

echo 总分计算完成
pause
for /l %%i in (1,1,10) do merge < "./result/%%i.csv"

echo 合并完成
move final.csv "./result/final.csv"
move MERGE.csv "./result/MERGE.csv"
echo 已结束
pause