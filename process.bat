@echo off
echo ������...
g++ csvs2marks.cpp -o csvs2marks
g++ marks2final.cpp -o marks2final
g++ merge.cpp -o merge
echo ɾ��ԭ����ͳ�ƽ��...
del "./result/final.csv"
del "./result/merge.csv"
echo Ԥ���������
pause
for /l %%i in (1,1,10) do csvs2marks < "./source/2023�����ұ�̡��й���ѧ���㷨��Ƴ���������%%i��.csv" > "./result/%%i.csv"

echo �ֶ����
pause
for /l %%i in (1,1,10) do marks2final < "./result/%%i.csv"

echo �ּܷ������
pause
for /l %%i in (1,1,10) do merge < "./result/%%i.csv"

echo �ϲ����
move final.csv "./result/final.csv"
move MERGE.csv "./result/MERGE.csv"
echo �ѽ���
pause