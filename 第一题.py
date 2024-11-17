import numpy as np
# 读取一个 n x n 矩阵
def read_matrix(n):
    return np.array([input().split() for _ in range(n)], dtype=float)
# 计算并输出矩阵的逆
def inverse_matrix(matrix):
    if is_invertible(matrix):
        inverse = np.linalg.inv(matrix)
        print("逆矩阵为：\n", inverse)

def is_invertible(matrix):
    det =np.linalg.det(matrix)
    if det ==0:
        return False
    else:
        return True
 
# 主程序
n = int(input("请输入矩阵的阶数 n: "))
matrix = read_matrix(n)
inverse_matrix(matrix)
