for /r %%I in (*) do C:\ProgramData\Autodesk\ApplicationPlugins\MAXtoA\maketx.exe -v -u --oiio "%%I" -o "%%~dI%%~pI%%~nI.tx"
REM for /r %%I in (*) do echo %%~dI%%~pI%%~nI.tx
REM for /r %%I in (*) do echo %%I
