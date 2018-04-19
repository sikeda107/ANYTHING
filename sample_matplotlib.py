import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# 描画範囲の指定
x = np.arange(0, 20, 0.1)

# 計算式
y1 = np.sin(x)*10+15
y2 = np.cos(x)*10+15

#CSVファイル操作
df = pd.read_csv("sample.csv", names=['ID', 'VALUE'])# CSVファイル読み込み
print(df.describe())# 各columnのデータ数、平均、分散などの統計量表示

# グラフ描画設定
plt.plot(df['ID'],df['VALUE'],marker="x",label="sampleCSV")# x軸にID y軸にVALUE
plt.plot(x, y1, label="sin") # y1グラフに、ラベル「sin」付与。
plt.plot(x, y2, linestyle="--", label="cos") # y2グラフに、ラベル「cos」付与。linestyleで線のスタイルを指定。
plt.xlabel("x & ID")
plt.ylabel("y & VALUE")
plt.legend(loc='upper right') # 凡例表示
# loc 場所一覧表
# best
# upper right
# upper left
# lower left
# lower right
# right
# center left
# center right
# lower center
# upper center
# center
plt.title('sin & cos & sample.csv')
plt.show()
