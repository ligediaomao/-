#include"determinant.cpp"

int* fraction(int numerator, int denominator) {

	int count = 0;
	if (numerator < 0) {
		numerator = -numerator;
		count++;
	}if (denominator < 0) {
		denominator = -denominator;
		count++;
	}
	int divisor = 1;
	while (divisor <= numerator && divisor <= denominator) {

		if (numerator % divisor == 0 && denominator % divisor == 0) {
			numerator /= divisor;
			denominator /= divisor;
			divisor = 1;
		}
		divisor++;
	}
	int* arr = new int[2] { count == 1 ? -numerator : numerator, denominator };
	return arr;
}
void print(vector<vector<int>>& v, int sult) {

	if (!sult) {
		cout << "该矩阵不可逆。" << endl;
		return;
	}

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			int* arr = fraction(v[i][j], sult);
			cout << arr[0] << "/" << arr[1] << "  ";
		}
		cout << endl;
	}
}
void moreArr(vector<vector<int>>& v, int k) {
	for (int i = 0; i < k; i++) {
		v.push_back(vector<int>(k));
	}
}
//求伴随矩阵
vector<vector<int>> matrix(vector<vector<int>>& v) {
	int num = v.size();

	//创建2个载体，并扩充成相应的阶数
	vector<vector<int>> z, p;
	moreArr(z, num);//该函数将z扩充为num阶方阵
	moreArr(p, num - 1);

	//以下代码模拟人计算伴随矩阵的过程
	int m = 0, n = 0;
	int k = 0, c = 0;
	for (int y = 0; y < num * num; y++) {
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {

				if (i == m || j == n)
					continue;
				p[k][c] = v[i][j];
				c++;
				if (c == num - 1)
					c = 0;
			}
			if (i != m)
				k++;
			if (k == num - 1)
				k = 0;
		}
		z[m][n] = determinant::result(p);
		n++;
		if (n == num) {
			n = 0;
			m++;
		}
	}
	return z;
}
int main() {
	vector<vector<int>> v;
	determinant::line(v);//构造矩阵(方阵)
	int sult = determinant::result(v);//求行列式
	vector<vector<int>> z = matrix(v);//求矩阵(方阵)的伴随矩阵
	print(z, sult);//打印矩阵的逆
	system("pause");
	return 0;
}
