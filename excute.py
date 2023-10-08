import os

def remove_file(file_path):
    if os.path.exists(file_path):
        os.remove(file_path)
        print(f"已删除文件: {file_path}")
    else:
        print(f"文件不存在: {file_path}")

print("编译中...")
os.system("g++ csvs2marks.cpp -o csvs2marks")
os.system("g++ marks2final.cpp -o marks2final")
os.system("g++ merge.cpp -o merge")
print("删除原本的统计结果...")
remove_file("./result/final.csv")
remove_file("./result/merge.csv")
print("预处理部分完成")
input("按 Enter 键继续...")

for i in range(1, 11):
    os.system(f'csvs2marks < "./source/2023“钉耙编程”中国大学生算法设计超级联赛（{i}）.csv" > "./result/{i}.csv"')

print("分段完成")
input("按 Enter 键继续...")

for i in range(1, 11):
    os.system(f'marks2final < "./result/{i}.csv"')

print("总分计算完成")
input("按 Enter 键继续...")

for i in range(1, 11):
    os.system(f'merge < "./result/{i}.csv"')

print("合并完成")
os.rename("final.csv", "./result/final.csv")
os.rename("MERGE.csv", "./result/MERGE.csv")
print("已结束")
input("按 Enter 键退出...")