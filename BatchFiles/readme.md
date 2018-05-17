# splitpdf.bat 解説
## コード全体
```
@echo off
if exist filename.txt del filename.txt

for %%a in (*.pdf) do (
  echo %%~na >> filename.txt
)

for /f %%a in (filename.txt) do (
 pdftk %%a.pdf burst output output\%%a^-%%d.pdf
)

del filename.txt
```
## １行づつ解説
`@echo off` コマンドの画面表示を消す  
`if exist filename.txt del filename.txt` filename.txtが存在したらfilename.txtを削除  
`for %%a in (*.pdf) do ()` 変数%%aに末尾が.pdfファイルを代入  
`/f` ()のファイルを一行ずつ読み込むオプション   
`~n` %%aのファイル名だけに展開  
`pdftk sample.pdf burst output burstout%%d.pdf` pdftkを用いてpdfを分割して出力  
`^` - など特殊文字表示。


## 参考
1. [pdftkの簡単な使い方とPDFの操作](https://jidouka.work/?p=304)
1. [ファイルを削除する ](https://www.k-tanaka.net/cmd/del.php)
1. [ファイルが存在していない場合にのみコマンドを実行する](http://jj-blues.com/cms/wantto-executeiffileexist/)
1. [バッチファイルでファイルパスからファイル名や拡張子を自由に取り出す方法](http://orangeclover.hatenablog.com/entry/20101004/1286120668)
1. [特殊文字を出力する](https://www.adminweb.jp/command/bat/index3.html)
