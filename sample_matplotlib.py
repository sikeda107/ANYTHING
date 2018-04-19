import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# 描画範囲の指定
x = np.arange(0, 6, 0.1)

# 計算式
y1 = np.sin(x)
y2 = np.cos(x)

# グラフ描画設定
plt.plot(x, y1, label="sin") # y1グラフに、ラベル「sin」付与。
plt.plot(x, y2, linestyle="--", label="cos") # y2グラフに、ラベル「cos」付与。linestyleで線のスタイルを指定。
plt.xlabel("x")
plt.xlabel("y")
plt.title('sin & cos')

# ラベルの描画
plt.legend()
# グラフの描画実行
plt.show()
