@echo off
for %%a in (*.pdf) do (
 pdftk "%%a" burst output "output\%%~na-%%d.pdf"
)
