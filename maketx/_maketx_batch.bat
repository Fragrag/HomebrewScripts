for /r %%I in (*); do echo %%I
    REM $original = "%%I"
    REM $txfile = "%%~dI%%~pI%%~nI.tx"
    if exist "%%~dI%%~pI%%~nI.tx"; then
            if [[date -r "%%~dI%%~pI%%~nI.tx" + "%s" -ge date -r "%%I" +"%s"]]; then
                REM do C:\ProgramData\Autodesk\ApplicationPlugins\MAXtoA\maketx.exe -v -u --oiio $original -o $txfile
                echo "tx file was found and is older than the non-tx file!"
            else; then
                echo "tx file was found and is newer than the non-tx file!"

    if ! exist "%%~dI%%~pI%%~nI.tx"; then
            REM do C:\ProgramData\Autodesk\ApplicationPlugins\MAXtoA\maketx.exe -v -u --oiio $original -o $txfile
            echo "No tx file was found!"
