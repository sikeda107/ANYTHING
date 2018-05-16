@echo off
if exist filename.txt del filename.txt

for %%a in (*.pdf) do (
  echo %%~na >> filename.txt
)

for /f %%a in (filename.txt) do (
 pdftk %%a.pdf burst output output\%%a^-%%d.pdf
)

del filename.txt